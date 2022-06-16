#include "module.h"

float countCust(int age, int n)
{
    float res;
    float disc = 1. - (float)age/100;
    if (age > 60)
        disc*= 0.95;
    res = 100*n*disc;
    return res;
}

float countTake(vector<customer> data, tm now)
{
    float res = 0;
    if (!data.empty())
    {
        int len = data.size();
        for (int i = 0; i < len; ++i)
        {
        int age = getAge(data[i].birthday, now);
        float val = countCust(age, data[i].numOfStaff);
        res += val;
        }
    }
    
        
    return res;
}

void findMore250(const vector<customer> source, vector<customer>& res, tm now)
{
    if (!source.empty())
    {
        int len = source.size();
        for (int i = 0; i < len; ++i)
        {
            int age = getAge(source[i].birthday, now);
            float val = countCust(age, source[i].numOfStaff);
            if (val - 250 > 10e-3)
                res.push_back(source[i]);
        }
    }
}

void getCustomer(customer& a, tm now)
{
    cout << "Enter surname: ";
    cin >> a.lastName;
    cout << "Enter gender (m - male, f - famale): ";
    string g;
    cin >> g;
    if (g == "m")
        a.gend = male;
    else if (g == "f")
        a.gend = female;
    else
        a.gend = undefined;
    int day, month, year;
    cout << "Enter day of birth: ";
    cin >> day;
    cout << "Enter month of birth: ";
    cin >> month;
    a.birthday.tm_mon -= 1;
    cout << "Enter year of birth: ";
    cin >> year;
    a.birthday = now;
    a.birthday.tm_year = year - 1900;
    if (month <= 12 && month >= 1)
        a.birthday.tm_mon = month - 1;
    if (day <= 31 && day >= 1)
        a.birthday.tm_mday = day;
    cout << "Number of goods bought: ";
    cin >> a.numOfStaff;
}

int getAge(tm birth, tm now)
{
    int res = now.tm_year - birth.tm_year -1;
    int months = now.tm_mon - birth.tm_mon;
    int days = now.tm_mday - birth.tm_mday;
    if (months > 0 || (months == 0 && days > 0)) {
        res++; 
    }
       
    if (res > 100)
        res = 100;
    
    return res;
}

void getLocalDate(tm& dateRes)
{   
    time_t secounds = (time(NULL));
    localtime_s(&dateRes, &secounds);
}

string inputFileName(string info)
{
    cout << info << " file name: ";
	string a;
	cin >> a;
	return a;
}

string inputOpenMode()
{
    cout << "Enter open mode (E - open (extend) existing file, R - create (rewrite) file): ";
    string mode;
    cin >> mode;
    if (mode != "E" && mode != "R") 
    {
        cout << "Error: unknown mode, set to R"<<endl;
        mode = "R";
    }
        
    return mode;
}

void inputFile(vector<customer>& data, string info, tm now)
{
    bool flag = true;
    while (flag)
    {
        cout << "Add new customer to flie " << info << " ? (y/n): ";
        string ans;
        cin >> ans;
        if (ans == "y")
            flag = true;
        else
            flag = false;
        if (flag) {
            customer newCustomer;
            getCustomer(newCustomer, now);
            data.push_back(newCustomer);
        }
    }
}

void openFile(string name, vector<customer> data, string mode)
{
    if (mode == "E")
        updateFile(name, data);
    else
        reWriteFile(name, data);
}

void reWriteFile(string name, vector<customer> data)
{

    ofstream file(name,  ios::binary | ios::out | ios::trunc);
    if (!file)
    {
        cout << "Cannot open file";
        return;
    }
    int lenght;

    if (data.empty())
    {
        lenght = 0;
        file.write((char*)&lenght, sizeof(int));
    }
    else
    {
        lenght = data.size();
        file.write((char*)&lenght, sizeof(int));
        file.write((char*)&data[0], (long long)sizeof(customer) * lenght);
    }
    
    if (!file)
    {
        cout << "Data writing error";
        return;
    }

    file.close();
}

void updateFile(string name, vector<customer> data)
{
    if (!data.empty())
    {
        fstream file(name, ios::binary | ios::in | ios::out);
        if (!file) {
            cout << "Cannot open file";
            return;
        }

        int lenght;
        file.read((char*)&lenght, sizeof(int));
        if (!file) {
            cout << "Data reading error";
            return;
        }
        lenght += data.size();
        file.seekp(0, ios_base::beg);
        file.write((char*)&lenght, sizeof(int));
        file.seekp(0, ios_base::end);
        file.write((char*)&data[0], (long long)sizeof(customer) * data.size());//!!!!!!!!!
        if (!file) {
            cout << "Data writing error";
            return;
        }
        file.close();
    }
    
}

void readFile(string name, vector<customer>& data)
{
    ifstream file(name, ios::binary | ios::in);
    if (!file) {
        cout << "Cannot open file";
        return;
    }
    int lenght;
    file.read((char*)&lenght, sizeof(int));
    if (lenght != 0)
    {
        data.resize(lenght);
        file.read((char*)&data[0], (long long)sizeof(customer) * lenght);
        if (!file) {
            cout << "Data reading error";
            return;
        }
    }
    
    file.close();
}

void showCustomer(customer a)
{
    cout << "Surname: " << a.lastName << endl;
    cout << "gender: ";
    switch (a.gend)
    {
    case 0:
        cout << "male" << endl;
        break;
    case 1:
        cout << "female" << endl;
        break;
    default:
        cout << "undefined" << endl;
        break;
    }
    char *dateString = new char[100];
    strftime(dateString, 100, "date of birth: %x\n", &a.birthday);
    cout << dateString;
    delete[] dateString;
    cout << "N: " << a.numOfStaff;
}

void displayCustList(vector<customer> data, string info)
{
    cout << info << endl;
    if (!data.empty())
    {
        size_t length = data.size();
        for (size_t i = 0; i < length; i++)
        {
            cout << "Customer " << i + 1 << endl;
            showCustomer(data[i]);
            cout << endl;
        }
    }
    else
        cout << "No customers";
}

void profitOutput(float profit, tm now)
{
    char* dateString = new char[100];
    strftime(dateString, 100, "\nShop's profit for %x is ", &now);
    cout << dateString;
    delete[] dateString;
    cout << fixed << profit << endl;
}
