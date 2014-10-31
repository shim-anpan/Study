#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main()
{
    std::string index = "grade,class,name,english,math,japanese";
    ofstream fout("dummy.csv");
    fout << index << endl;

    srand( (unsigned int)time(NULL));

    for(int i = 0; i < 1000000; i++)
    {
        stringstream ss;
        string tmp;
        
        // grade
        ss << rand()%3 + 1;
        ss >> tmp;
        fout << tmp << ",";
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       

        // class
        ss << rand()%5 + 1;
        ss >> tmp;
        fout << tmp << ",";
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       

        // name 
        ss << rand();
        ss >> tmp;
        fout << tmp << ",";
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       

        // english
        ss << rand()%100 + 1;
        ss >> tmp;
        fout << tmp << ",";
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       

        // math
        ss << rand()%100 + 1;
        ss >> tmp;
        fout << tmp << ",";
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       
        
        // japanese
        ss << rand()%100 + 1;
        ss >> tmp;
        fout << tmp << endl;
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       
    }


}
