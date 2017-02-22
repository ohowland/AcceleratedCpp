#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cctype>
#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>

class Str {

friend std::istream& operator>>(std::istream&, Str&);

public:
    Str& operator+=(const Str& s) {
        std::copy(s.begin(), s.end(), std::back_inserter(*this));
        return *this;
    }
    
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;
    typedef char value_type;
    typedef std::ptrdiff_t difference_type;
    typedef char& reference;
    typedef const char& const_reference;

    /* Constructors */
    /* Default */
    Str() { create(); } 

    /* From null terminated String */
    Str(const char* cp) {
        create();
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(*this));
    }
   
    /* From iterators */
    Str(const_iterator b, const_iterator e) { create(b,e); }

    void push_back(const char& c) {
        std::cout << "CALLED: PUSH BACK" << std::endl;; 
        if (avail == limit)
            grow();
        unchecked_append(c);
    }

    /* Copy Constructor */
    Str(const Str& a) { create(a.begin(), a.end()); }
    
    Str& operator=(const Str&);
    ~Str() { uncreate(); };

    iterator begin() { return head; }
    const_iterator begin() const { return head; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    reference operator[](size_type i) { return *(head + i); }
    const_reference operator[](size_type i) const { return *(head + i); }
    size_type size() const { return avail - head; }
    void clear() { uncreate(); }

    iterator c_str() {
        std::cout << "CALLED: C_STR" << std::endl;
        uncreate_ref(ref_head, ref_avail);
        create_ref(ref_head, ref_avail);
        *ref_avail = '\0';
        return ref_head;
    }

    iterator data() {
        std::cout << "CALLED: DATA" << std::endl;
        uncreate_ref(ref_head, ref_avail);
        create_ref(ref_head, ref_avail);
        return ref_head;
    }

private:
    iterator head;
    iterator avail;
    iterator limit;

    iterator ref_head;
    iterator ref_avail;

    std::allocator<char> alloc;

    void create();
    void create(const_iterator, const_iterator);
    void create_ref(iterator&, iterator&);
    
    void uncreate();
    void uncreate_ref(iterator&, iterator&);

    void grow();
    void unchecked_append(const char&);
};

void Str::create()
{
    std::cout << "CALLED: CREATE OBJ (default)" << std::endl;
    head = avail = limit = 0;
    ref_head = ref_avail = 0;
}

void Str::create(const_iterator i, const_iterator j)
{
    std::cout << "CALLED: CREATE OBJ (by iterator)" << std::endl;
    head = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, head);
    ref_head = ref_avail = 0;
}

void Str::create_ref(iterator& new_head, iterator& new_avail)
{
    std::cout << "CALLED: CREATE_REF OBJ" << std::endl;
    new_head = alloc.allocate(avail - head);
    new_avail = std::uninitialized_copy(head, avail, new_head);
}

void Str::uncreate()
{
    std::cout << "CALLED: UNCREATE OBJ" << std::endl;
    if (head) {
        iterator it = avail;
        while (it != head)
            alloc.destroy(--it);

        alloc.deallocate(head, limit - head);
    }
    head = limit = avail = 0;
}

void Str::uncreate_ref(iterator& old_head, iterator& old_avail)
{
    std::cout << "CALLED: UNCREATE_REF OBJ (by pointer)" << std::endl;
    if (old_head) {
        iterator it = old_avail;
        while (it != old_head)
            alloc.destroy(--it);
        alloc.deallocate(old_head, old_avail - old_head);
    }
    old_head = old_avail = 0;
}

void Str::grow()
{
    std::cout << "CALLED: GROW OBJ ";
    size_type new_size = std::max(2 * (limit - head), ptrdiff_t(1));
    std::cout << "(NEW SIZE: " << new_size << ")" << std::endl;
    iterator new_head = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(head, avail, new_head);

    uncreate();

    head = new_head;
    std::cout << "NEW_DATA: " << head;
    avail = new_avail;
    std::cout << ", NEW_AVAIL: " << avail - head; 
    limit = head + new_size;
    std::cout << ", NEW_LIMIT: " << limit - head << std::endl;
}

void Str::unchecked_append(const char& c)
{
    std::cout << "CALLED: UNCHECKED APPEND";
    std::cout << " (CHAR: " << c << ", AVAIL: " << avail
              << ")" << std::endl;
    alloc.construct(avail++, c);
}

Str& Str::operator=(const Str& rhs)
{
    std::cout << "CALLED: ASSIGN OP" << std::endl;
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    std::cout << "CALLED: OUT STREAM" << std::endl;
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
    std::cout << "CALLED: IN STREAM" << std::endl;
    
    // read and discard leading whitespace
    Str::value_type c;
    is.get(c)
        ;
    if (is) {
        do s.push_back(c);
        while (is.get(c) && !isspace(c)); 
        // if whitespace is read, put it back on the stream.
        if (is)
            is.unget();
    }

    return is;
}

Str operator+(const Str& s, const Str& t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = s;
    r += t;
    return r;
}

#endif
