
count = 100;

grade = list()

for n in range(5000):
    grade.append("owen 50 60 90 10 10")
    grade.append("kate 90 90 90 90 90")

with open('students.txt', 'w') as f:
    for item in grade:
        f.write("%s\n" % item)
