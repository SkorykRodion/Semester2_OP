#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "module.h"
#include <time.h>
using namespace std;

int main()
{
	string sourceFileName = inputFileName("Data");
	string mode1 = inputOpenMode();
	vector<customer> dataSource;
	tm nowDate;
	getLocalDate(nowDate);
	inputFile(dataSource, sourceFileName, nowDate);
	openFile(sourceFileName, dataSource, mode1);
	dataSource.clear();
	vector<customer> data;
	readFile(sourceFileName, data);
	displayCustList(data, "\nAll customers:\n");
	float profit = countTake(data, nowDate);
	profitOutput(profit, nowDate);
	vector<customer> dataMore250;
	findMore250(data, dataMore250, nowDate);
	displayCustList(dataMore250, "\nCustomers, who bought things for more then 250:\n");
	reWriteFile("custMore250.bin", dataMore250);
	data.clear();

}


