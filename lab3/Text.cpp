#include "Text.h"

Text::Text()
{
    textRows="";
}

Text::Text(const std::string &a) {
        textRows=a;
}

float Text::getCharFrequency(char a) {
    int inText=0;
    for (char b : textRows)
        if(a == b)
            inText++;
    int len = textRows.size();
    return (float)inText/(float)len;
}

void Text::addLine(const std::string &a) {
    textRows+='\n'+a;
}

void Text::findMostCommon(char& a, float& frequency) {
    frequency = 0;
    for (char b : textRows) {
        float tmp = getCharFrequency(b);
        if(tmp - frequency> 0) {
            frequency = tmp;
            a = b;
        }
    }
}

void findInArrey(char &a, float &frequency, Text* mas, int n) {
    a='!';
    std::string text="";
    for(int i =0;i<n;++i)
        text+=mas[i].textRows;
    Text arr = Text(text);
    arr.findMostCommon(a, frequency);
}

std::ostream &operator<<(std::ostream &os, const Text &text) {
    os << text.textRows;
    return os;
}


