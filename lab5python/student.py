from person import *


class Student(Person):
    def __init__(self):
        super(__class__, self).__init__()
        self.groupnumber = input("Enter student's groupnumber: ")
        self.raiting = float(input("Enter student's raiting: "))
        self.styp = self.findStyp()

    def findStyp(self):
        if(self.raiting - 95 >= 0 ):
            styp = "increased"
        elif(self.raiting - 85 >= 0 ):
            styp = "ordinary"
        else:
            styp = "none"
        return styp

    def countPayment(self):
        if (self.styp == "increased"):
            payment = 2500
        elif (self.styp == "ordinary"):
            payment = 2000
        else:
            payment = 0
        return payment

    def display(self):
        print(self.fullName)
        date = self.birth.strftime("%d/%m/%Y")
        print("date of birth: " + date)
        print("age: " + str(self.getAge()))
        print("group number: " + self.groupnumber)
        print("raiting: " + str(self.raiting))
        print("stypendium: " + self.styp)
        print("payment: " + str(self.countPayment()))



