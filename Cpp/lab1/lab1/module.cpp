#include "module.h"

string inputFileName(string info)
{
    cout << info << " file name: ";
	string a;
	cin >> a;
	return a;
}

string inputOpenMode()
{
    cout << "Enter open mode (E - extend existing file, R - create (rewrite) file): ";
    string mode;
    cin >> mode;
    if (mode != "E" && mode != "R") 
    {
        cout << "Error: unknown mode, set to R"<<endl;
        mode = "R";
    }
        
    return mode;
}

string inputFile(string info)
{
    cout << "Write " << info << " file text, enter Ctrl + X from new line to end : " << endl;
    string line;
    cin.ignore();
    getline(cin, line);
    string data="";
    while (int(line[0]) != 24) {
        data += line + '\n';
        getline(cin, line);
    }

    return data;
}

void writeFile(string name, string data, string mode)
{
    ofstream file(name,  mode=="E"? ios::app : ios::trunc | ios::out);
    file << data;

    file.close();
}

vector<string> exportLinesToVector(string name)
{
    vector<string> lines;
    ifstream file(name, ios::in);
    if (!file)
        cout << "Error: cannot open file " << name << endl;
    else {
        string line;
        while (!file.eof()) {
            getline(file, line);
            lines.push_back(line);
        }
        file.close();
    }
        
    return lines;
}

int findNumberOfLines(vector<string> vect)
{
    return vect.size();
}

vector<string> findUniqLinesInVector(vector<string> first, vector<string> second)
{
    vector<string> res;
    int sizeFirst = first.size();
    int sizeSecond = second.size();
    for (int i = 0; i < sizeFirst; i++) {
        bool isUniq = true;
        for (int j = 0; j < sizeSecond && isUniq; j++)
            if (first[i] == second[j])
                isUniq = false;
        if (isUniq)
            res.push_back(first[i]);
    }
    return res;
}

string vectorToString(vector<string> vect)
{
    string res = "";
    int size = vect.size();
    for (int i = 0; i < size; i++) {
        res += vect[i];
        if (i != size - 1)
            res += '\n';
    }
    return res;
}



void displayFile(string name)
{
    cout << name << ": " << endl;
    ifstream file(name, ios::in);
    string line;
    while (!file.eof()) {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}
