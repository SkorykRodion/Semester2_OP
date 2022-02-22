from module1 import *


def main():
    name1 = inputFileName("First")
    data1 = inputFile("first")
    mode1 = inputOpenMode()
    writeFile(name1, data1, mode1)
    name2 = inputFileName("Second")
    data2 = inputFile("second")
    mode2 = inputOpenMode()
    writeFile(name2, data2, mode2)
    exportedData1 = exportLinesToList(name1)
    exportedData2 = exportLinesToList(name2)
    resDataList = findUniqLinesInList(exportedData1, exportedData2)
    numberOfLines = findNumberOfLines(resDataList)
    print("Number of unique lines: {}".format(numberOfLines))
    data3 = listToString(resDataList)
    name3 = "result.txt"
    writeFile(name3, data3, "w")
    displayFile(name1)
    displayFile(name2)
    displayFile(name3)


main()
