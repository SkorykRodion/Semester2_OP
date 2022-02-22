def inputFileName(info):
    a = input(info + " file name: ")
    return a


def inputFile(info):
    print("Write " + info + " file text, enter Ctrl + X from new line to end : ")
    data = ""
    line = input()
    while (line != '\x18'):
        data += line + '\n'
        line = input()
    return data


def inputOpenMode():
    mode = input("Enter open mode (E - extend existing file, R - create (rewrite) file): ")
    if (mode == "E"):
        mode = "a"
    elif (mode == "R"):
        mode = "w"
    else:
        print("Error: unknown mode, set to R")
        mode = "w"
    return mode


def writeFile(name, data, mode):
    with open(name, mode) as file:
        file.write(data)


def exportLinesToList(name):
    with open(name, 'r') as file:
        lines = file.readlines()
    return lines


def findNumberOfLines(List):
    return len(List)


def findUniqLinesInList(first, second):
    res = []
    for i in first:
        isUniq = True
        for j in second:
            if (i == j):
                isUniq = False
        if (isUniq):
            res.append(i)
    return res


def listToString(list):
    res = ""
    for i in list:
        res += i
    return res


def displayFile(name):
    print("{}: ".format(name))
    with open(name, 'r') as file:
        print(file.read())
