#include <iostream>
#include "Text.h"
#include "function.h"
using namespace std;
int main() {
    int n;
    cout<<"Number of texts:";
    cin>>n;
    Text *arr = new Text[n];
    initialize(arr, n);
    findForEach(arr, n);
    char mostFreq;
    float freq;
    findInArrey(mostFreq, freq, arr, n);
    display(mostFreq, freq);
    delete[] arr;
}
