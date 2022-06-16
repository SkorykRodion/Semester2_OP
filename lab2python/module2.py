import pickle
from datetime import *


class customer:
    def __init__(self, name, gend, bitrh, numOfStaff):
        self.name = name
        self.gend = gend
        self.birth = bitrh
        self.numOfStaff = numOfStaff

def getAge(birth, now):
    delta = now - birth
    age = int(delta.days) // 365
    return age

def countCust(age, n):
    disc = float(1 - age / 100)
    if (age > 60):
        disc *= 0.95
    res = 100 * n * disc
    return res

def countTake(data, now):
    res = 0
    for cust in data:
        age = getAge(cust.birth, now)
        val = countCust(age, cust.numOfStaff)
        res += val
    return res

def findMore250(data, now):
    res = []
    for cust in data:
        age = getAge(cust.birth, now)
        val = countCust(age, cust.numOfStaff)
        if (int(val) > 250):
            res.append(cust)
    return res



def getCustomer(now):
    cust1 = customer("", "", now, 0)
    cust1.name = input("Enter surname: ")
    cust1.gend = input("Enter gender: ")
    day = int(input("Enter day of birth: "))
    month = int(input("Enter month of birth: "))
    year = int(input("Enter year of birth: "))
    birthDay = datetime(year, month, day)
    if (int((now - birthDay).days) < 0):
        birthDay = now
    cust1.birth = birthDay
    cust1.numOfStaff = int(input("Number of goods bought: "))
    return cust1


def showCustomer(a):
    print("Surname: " + a.name)
    print("gender: " + a.gend)
    date = a.birth.strftime("%d/%m/%Y")
    print("date of birth:" + date)
    print("N: " + str(a.numOfStaff))


def displayCustList(data, info):
    print(info)
    count = 0
    for cust in data:
        count += 1
        print("Customer" + str(count) + ":")
        showCustomer(cust)


def profitOutput(profit, now):
    date = now.strftime("%d/%m/%Y")
    print("\nShop's profit for " + date + " is " + str(profit))


def inputFileName(info):
    a = input(info + " file name: ")
    return a


def inputFile(info, now):
    res = []
    flag = True
    print()
    while (flag):
        ans = input("Add new customer to file " + info + " ? (y/n): ")
        if (ans == "y"):
            cust = getCustomer(now)
            res.append(cust)
        else:
            flag = False
    return res


def inputOpenMode():
    mode = input("Enter open mode (E - extend existing file, R - create (rewrite) file): ")
    if (mode != "E" and mode != "R"):
        print("Error: unknown mode, set to R")
        mode = "R"
    return mode


def reWriteFile(name, data):
    with open(name, 'wb') as f:
        pickle.dump(data, f)


def readFile(name):
    res = []
    with open(name, 'rb') as file:
        binData = file.read()
        res = pickle.loads(binData)
    return res


def updateFile(name, data1):
    data2 = readFile(name)
    data1.extend(data2)
    reWriteFile(name, data1)


def openFile(name, mode, now):
    dataNew = inputFile(name, now)
    if (mode == "E"):
        updateFile(name, dataNew)
    else:
        reWriteFile(name, dataNew)
