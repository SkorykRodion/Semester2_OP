//
// Created by ROS on 15.06.2022.
//
#include "function.h"

void initialize(Text *mas, int n) {
    for(int i = 0;i < n;i++){
        mas[i]= Text();
        bool flag = true;
        while(flag)
        {
            std::cout<<"Add line to text"<< i <<" ?(y/n):";
            std::string ans;
            std::cin>>ans;
            if(ans == "y"){
                std::string a;
                std::cout<<"input line:";
                std::cin.ignore();
                std::getline(std::cin, a);
                mas[i].addLine(a);
            }
            else
                flag = false;
        }
    }
}

void findForEach(Text *mas, int n) {
    std::cout<<"\n-------------\n";
    for(int i = 0;i < n;i++){
        char a;
        float b;
        mas[i].findMostCommon( a,b);
        std::cout<<"Text"<<i<<":"<<
                 mas[i]<<std::endl<<
                 "The most frequent character is '"
                 << a <<"' with frequency "<<b<<'\n';
    }

}

void display(char a, float b) {
    std::cout<<"\n-------------\n";
    std::cout<<"For all texts most frequent character is '"<<a
             <<"' with frequency "<<b<<'\n';
}
