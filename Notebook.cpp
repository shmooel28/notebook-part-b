#include"Direction.hpp"
#include<string>
#include<iostream>
#include"Notebook.hpp"
#include<vector>

using namespace std;


namespace ariel
{
    Notebook::Notebook()
    {
    }
    void Notebook::erase(int page,int row,int col,Direction d,int number_of_char)
    {
        Notebook::check_page_row_col(page,row,col);
        if (d == Direction::Horizontal)
        {
            if (number_of_char + col > 100)
            {
                throw runtime_error("not over 100");
            }
            else
            {
                for (int i = 0; i < number_of_char; i++)
                {
                    note_b[page][row][col+i] = '~';
                }
                
            }
        }
        else
        {
            for (int i = 0; i < number_of_char; i++)
            {
                note_b[page][row+i][col] = '~';
            }
            
        }
        
        cout<<"deleted"<<page<<endl;
    }
    string Notebook::read(int page,int row,int col,Direction d,int number_of_char)
    {
        Notebook::check_page_row_col(page,row,col);
        string ans;
        if (d == Direction::Horizontal)
        {
            if (number_of_char + col > 100)
            {
                throw runtime_error("not over 100");
            }
            else
            {
                for (int i = 0; i < number_of_char; i++)
                {
                    ans += note_b[page][row][col+i];
                }
            }
        }
        else
        {
            for (int i = 0; i < number_of_char; i++)
            {
                ans += note_b[page][row+i][col];
            }
            
        }
        return ans;
    }

    void Notebook::write(int page,int row,int col,Direction d,string str)
    {   
        Notebook::check_page_row_col(page,row,col);
        if (d == Direction::Horizontal)
        {
            if (int(str.length()) + col > 100)
            {
                throw runtime_error("not over 100");
            }
            else
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if (note_b[page][row][col+i] == '~' || isalpha(note_b[page][row][col+i]) || isdigit(note_b[page][row][col+i]))
                    {
                        throw runtime_error("alredy write");
                    }
                    note_b[page][row][col+i] = str[(unsigned int)i];
                }
                
            }
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
                {
                    if (note_b[page][row+i][col] == '~' || isalpha(note_b[page][row][col+i]) || isdigit(note_b[page][row][col+i]))
                    {
                        throw runtime_error("alredy write");
                    }
                    note_b[page][row+i][col] = str[(unsigned int)i];
                }
        }
        cout<<"write"<<endl;
    }

    void Notebook::show(int page)
    {
        cout<<"show"<<endl;
    }
    void Notebook::check_page_row_col(int page,int row, int col)
    {
        if (page < 0 || row < 0 || col < 0 || col > 100)
            throw runtime_error("connot be udner 0");
    }


}