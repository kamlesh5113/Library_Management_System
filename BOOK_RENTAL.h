#ifndef BOOK_RENTAL_H_INCLUDED
#define BOOK_RENTAL_H_INCLUDED

#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class BookRental
{
    int id;
    bool status;
public:
    void ADD_DATA(int n,bool f)
    {
        id = n;
        status = f;
    }
    void STORE_DATA()
    {
        ofstream outf;
        outf.open("BOOK_RENTAL_STATUS.txt",ios::app | ios::binary);
        outf.write((char*)this,sizeof(*this));
        outf.close();
    }
    int SEARCH_DATA(int k)
    {
        ifstream inf;
        inf.open("BOOK_RENTAL_STATUS.txt",ios::in | ios::binary);
        if(!inf)
        {
            return 0;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(k == id)
            {
                return 1;
            }
            inf.read((char*)this,sizeof(*this));
        }
        return 2;
    }
    void DELETE_DATA(int k)
    {
        ifstream inf;
        ofstream outf;
        inf.open("BOOK_RENTAL_STATUS.txt",ios::in | ios::binary);
        if(!inf)
        {
            cout<<"SUCCESSFULL!\n";
            return;
        }
        outf.open("BOOK_RENTAL_STATUS1.txt",ios::app | ios::binary);
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(k!=id)
            {
                outf.write((char*)this,sizeof(*this));
            }
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
        outf.close();
        remove("BOOK_RENTAL_STATUS.txt");
        rename("BOOK_RENTAL_STATUS.txt1", "BOOK_RENTAL_STATUS.txt");
    }
};


#endif // BOOK_RENTAL_H_INCLUDED
