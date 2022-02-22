#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "module.h"

using namespace std;

int main()
{
    
    string name1 = inputFileName("First");
    string data1;
    data1 = inputFile("first");
    string mode1= inputOpenMode();
    writeFile(name1, data1, mode1);

    string name2= inputFileName("Second");
    string data2;
    data2 = inputFile("second");
    string mode2 = inputOpenMode();
    writeFile(name2, data2, mode2);

    vector<string> exportedData1 = exportLinesToVector(name1);
    vector<string> exportedData2 = exportLinesToVector(name2);
    vector<string> resDataVector= findUniqLinesInVector(exportedData1, exportedData2);

    int numberOfLines = findNumberOfLines(resDataVector);
    cout << "Number of unique lines: " << numberOfLines << endl;
    string data3 = vectorToString(resDataVector);
    string name3 = "result.txt";
    writeFile(name3, data3, "R");

    displayFile(name1);
    displayFile(name2);
    displayFile(name3);

    exportedData1.clear();
    exportedData2.clear();
    resDataVector.clear();
}


