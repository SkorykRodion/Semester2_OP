#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include "structs.h"
using namespace std;

int getAge(tm birth, tm now);

float countCust(int age, int n);

float countTake(vector<customer> data, tm now);

void findMore250(const vector<customer> source, vector<customer>& res, tm now);

void getCustomer(customer& a, tm now);

void getLocalDate(tm& dateRes);

string inputFileName(string info);

string inputOpenMode();

void inputFile(vector<customer>& data, string info, tm now);

void openFile(string name, vector<customer> data, string mode);

void reWriteFile(string name, vector<customer> data);

void updateFile(string name, vector<customer> data);

void readFile(string name, vector<customer>& data);

void showCustomer(customer a);

void displayCustList(vector<customer> data, string info);

void profitOutput(float profit, tm now);