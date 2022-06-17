from student import *
from teacher import *

if __name__ == '__main__':

    n =int(input("Number of students:"))
    arr1=[]
    for i in range(0, n):
        tmp = Student()
        arr1.append(tmp)
    m = int(input("Number of teachers:"))

    arr2 = []
    for i in range(0, m):
        tmp = Teacher()
        arr2.append(tmp)

    print("------------")

    for i in range(0, n):
        print("\nstudent{}:".format(i))
        arr1[i].display()

    for i in range(0, m):
        print("\nteacher{}:".format(i))
        arr2[i].display()
    age = findBiggestPaymentAge(arr2)
    print("\n\n\nAge of teacher with biggest payment: {}".format(age))

