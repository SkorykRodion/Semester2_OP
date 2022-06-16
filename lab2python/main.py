from module2 import *


def main():
    sourceFileName = inputFileName("Enter")
    nowDate = datetime.now()
    mode1 = inputOpenMode()
    openFile(sourceFileName, mode1, nowDate)
    data = readFile(sourceFileName)
    displayCustList(data, "\nAll customers:\n")
    profit = countTake(data, nowDate)
    profitOutput(profit, nowDate)
    dataMore250 = findMore250(data, nowDate)
    displayCustList(dataMore250, "\nCustomers, who bought things for more then 250:\n")
    reWriteFile("custMore250.bin", dataMore250)

if __name__ == '__main__':
    main()
