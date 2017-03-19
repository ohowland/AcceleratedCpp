#include <vector>
#include <string>

#include "Ptr.hpp"
#include "Picture.h"

class Picture; // forward declaration

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;
   
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
    
public:
    virtual ~Pic_base() { }

protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
        while (beg != end) {
            os << " ";
            ++beg;
        }
    }
};


class String_Pic: public Pic_base { 
    friend Picture;
    std::vector<std::string> data;
    String_Pic(const std::vector<std::string>& v): data(v) { }

    wd_sz width() const;
    ht_sz height() const { return data.size(); }
    void display(std::ostream&, ht_sz, bool) const;
};

Pic_base::wd_sz String_Pic::width() const
{
    Pic_base::wd_sz n = 0;
    for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
        n = std::max(n, data[i].size());
    return n;
}

void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
    wd_sz start = 0;

    if (row < height()) {
        os << data[row];
        start = data[row].size();
    }

    if (do_pad)
        pad(os, start, width());
}


class Frame_Pic: public Pic_base {
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic): p(pic) { }

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;
};

void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
    if (row >= height()) {
        if (do_pad)
            pad(os, 0, width());
    } else {
        if (row == 0 || row == height() - 1) {

            // top or bottom row
            os << std::string(width(), '*');

        } else if (row == 1 || row == height() - 2) {
            
            // second from top or bottom row
            os << "*";
            pad(os, 1, width() - 1);
            os << "*";

        } else {

            // interior row
            os << "*";
            p->display(os, row - 2, true);
            os << "*";
        }
    }
}


class VCat_Pic: public Pic_base { 
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base> t, const Ptr<Pic_base> b):
        top(t), bottom(b) { }

    wd_sz width() const
        { return std::max(top->width(), bottom->width()); }
    ht_sz height() const
        { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
};
    
void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
        wd_sz w = 0;
        if (row < top->height()) {
            top->display(os, row, do_pad);
            w = top->width();
        } else if (row < height()) {
            bottom->display(os, row - top-height(), do_pad);
            w = bottom->width();
        }
        if (do_pad)
            pad(os, w, width());
    }


class HCat_Pic: public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base> l, const Ptr<Pic_base> r):
        left(l), right(r) { }

    wd_sz width() const
        { return left->width() + right->width(); }
    ht_sz height() const
        { return std::max(left->height(), right->height()); }
    void display(std::ostream&, ht_sz, bool) const;
};

void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
    left->display(os, row, do_pad || row < right->height());
    right->display(os, row, do_pad);
}

