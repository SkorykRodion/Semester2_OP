from person import *


class Teacher(Person):
    def __init__(self):
        super(__class__, self).__init__()
        self.paymentForEachHour = 250
        self.subjects = []
        self.subjectsHours = []
        flag = True
        while flag:
            a=input("Enter subject: ")
            b=int(input("Enter hours: "))
            self.subjects.append(a)
            self.subjectsHours.append(b)
            ans=input("Add another subject(y/n)?")
            if(ans != "y"):
                flag=False

    def countPayment(self):
        res=0
        for i in self.subjectsHours:
            res+=self.paymentForEachHour*i
        return res

    def display(self):
        print(self.fullName)
        date = self.birth.strftime("%d/%m/%Y")
        print("date of birth: " + date)
        print("age: " + str(self.getAge()))
        subjStr=''
        for i in range(0, len(self.subjects)):
            subjStr+="{}, {}; ".format(self.subjects[i],
                                       self.subjectsHours[i])
        print("subjects: " + subjStr)
        print("payment: " + str(self.countPayment()))

def findBiggestPaymentAge(arr):
    biggestPayment = 0
    age = 0
    for a in arr:
        tmp = a.countPayment()
        if(tmp - biggestPayment > 0):
            biggestPayment=tmp
            age= a.getAge()
    return age