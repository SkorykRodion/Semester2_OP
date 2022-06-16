#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


string inputFileName(string info);

string inputOpenMode();

string inputFile(string info);

void writeFile(string name, string data, string mode);

vector<string> exportLinesToVector(string name);

int findNumberOfLines(vector<string> vect);

vector<string> findUniqLinesInVector(vector<string> first, vector<string> second);

string vectorToString(vector<string> vect);

void displayFile(string name);