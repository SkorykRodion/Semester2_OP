from datetime import *

class Person:
    def __init__(self):
        now = datetime.now()
        self.fullName=input("Enter full name: ")
        day = int(input("Enter day of birth: "))
        month = int(input("Enter month of birth: "))
        year = int(input("Enter year of birth: "))
        self.birth = datetime(year, month, day)
        if (int((now - self.birth).days) < 0):
            self.birth = now
    def getAge(self):
        now = datetime.now()
        delta = now - self.birth
        age = int(delta.days) // 365
        return age

    def countPayment(self):
        pass
