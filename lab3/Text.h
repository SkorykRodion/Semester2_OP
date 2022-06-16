#ifndef LABSC___TEXT_H
#define LABSC___TEXT_H
#include <utility>
#include <vector>
#include <string>
#include <iostream>

class Text {
    std::string textRows;
public:
    Text();
    explicit Text(const std::string& a);
    float getCharFrequency(char a);
    void show();

    friend std::ostream &operator<<(std::ostream &os, const Text &text);

    void addLine(const std::string& a);
    void findMostCommon(char& a, float& requency);
    friend void findInArrey(char& a, float& frequency, Text* mas, int n);
};


#endif //LABSC___TEXT_H
