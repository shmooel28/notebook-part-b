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
    Notebook::~Notebook()
    {
    }
    void Notebook::erase(int page,int row,int col,Direction d,int number_of_char)
    {
        const int max_col = 100;
        if (page < 0 || row < 0 || col < 0 || col >= max_col)
        {
            throw runtime_error("connot be udner 0");
        }
        if (number_of_char < 0)
        {
            throw runtime_error("negative langth");
        }
        if (d == Direction::Horizontal)
        {
            if (number_of_char + col > max_col)
            {
                throw runtime_error("not over 100");
            }
            for (int i = 0; i < number_of_char; i++)
            {
                note_b[page][row][col+i] = '~';
            }
        }
        else
        {
            for (int i = 0; i < number_of_char; i++)
            {
                note_b[page][row+i][col] = '~';
            }
            
        }
        
    }
    string Notebook::read(int page,int row,int col,Direction d,int number_of_char)  
    {
        const int max = 126;
        const int minim = 32;
        const int max_col = 100;
        if (page < 0 || row < 0 || col < 0 || col >= max_col)
        {
            throw runtime_error("connot be udner 0");
        }
        if (number_of_char < 0)
        {
            throw runtime_error("negative langth");
        }
        string ans;
        if (d == Direction::Horizontal)
        {
            if (number_of_char + col > max_col)
            {
                throw runtime_error("not over 100");
            }
            for (int i = 0; i < number_of_char; i++)
            {
                if(note_b[page][row][col+i] == '~')
                {
                    ans += note_b[page][row][col+i];
                }
                else
                {
                    if (note_b[page][row][col+i] >= minim && note_b[page][row][col+i] <= max )
                    {
                        ans += note_b[page][row][col+i];
                    }
                    else
                    {
                        ans += '_';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < number_of_char; i++)
            {
                if(note_b[page][row+i][col]=='~')
                {
                    ans += note_b[page][row+i][col];
                }
                else
                {
                    if (note_b[page][row+i][col] >= minim && note_b[page][row+i][col] <= max )
                    {
                        ans += note_b[page][row+i][col];
                    }
                    else
                    {
                        ans += '_';
                    }
                }
            }
            
        }
        return ans;
    }

    void Notebook::write(int page,int row,int col,Direction d,string str)
    {   
        const int max = 125;
        const int minim = 32;
        const int max_col = 100;
        if (page < 0 || row < 0 || col < 0 || col >= max_col)
        {
            throw runtime_error("connot be udner 0");
        }
        if (d == Direction::Horizontal)
        {
            if (int(str.length()) + col > max_col)
            {
                throw runtime_error("not over 100");
            }
            for (int i = 0; i < int(str.length()); i++)
            {
                if (str[(unsigned int)i] > max || str[(unsigned int)i] < minim )
                {
                    throw runtime_error("bad input");
                }
                if (note_b[page][row][col+i] == '~'|| str[(unsigned int)i] == '~')
                {
                    throw runtime_error("alredy write");
                }
                if (note_b[page][row][col+i] < max && note_b[page][row][col+i] > minim )
                {
                    if (note_b[page][row][col+i] == '_')
                    {
                        note_b[page][row][col+i] = str[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("cant writ rwice");
                    }
                }
                else
                {
                    note_b[page][row][col+i] = str[(unsigned int)i];
                }    
            }
        }
        else
        {
            for (int i = 0; i < int(str.length()); i++)
            {
                if (str[(unsigned int)i] > max || str[(unsigned int)i] < minim )
                {
                    throw runtime_error("bad input");
                }
                if (note_b[page][row][col+i] == '~'|| str[(unsigned int)i] == '~')
                {
                    throw runtime_error("alredy write");
                }
                if (note_b[page][row+i][col] < max && note_b[page][row+i][col] > minim )
                {
                    if (note_b[page][row+i][col] == '_')
                    {
                        note_b[page][row+i][col] = str[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("cant writ rwice");
                    }
                }
                else
                {
                    note_b[page][row+i][col] = str[(unsigned int)i];
                }
                
            }
        }
    }

    void Notebook::show(int page)
    {
        if (page < 0)
        {
            throw runtime_error("negative page");
        }
        
        cout<<"show"<<note_b[page][0][0]<<endl;
    }
    
    
}
