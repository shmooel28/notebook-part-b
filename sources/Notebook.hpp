#pragma once

#include "Direction.hpp"
#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

namespace ariel
{
    class Notebook
    {
        unordered_map<int,unordered_map<int,char[100]>>note_b;

    
    public:
        Notebook();
        ~Notebook();
        void write(int,int,int,ariel::Direction,string);
        
        string read(int,int,int,Direction,int);

        void erase(int,int,int,Direction,int);

        void show(int);
        
        void check_page_row_col(int,int,int);
    };

}