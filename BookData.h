#ifndef BOOKDATA_H_INCLUDED
#define BOOKDATA_H_INCLUDED

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include"CHECK.h"
using namespace std;
class Book
{
    int Bookid;
    char title[50];
    char authorName[50];
    float price;
public:
    Book()
    {
        Bookid = 0;
        strcpy(title,"Not Title");
        strcpy(authorName,"Not Name");
        price = 0;
    }
    void Add_data()
    {
        cout<<"Enter Book Details id,title,author name and price respectively..\n";
        cin>>Bookid;
        cin>>title;
        cin>>authorName;
        cin>>price;

    }
    void updataBook(string t)
    {
        fstream inf;
        bool f=false;
        inf.open("Book.txt",ios::in | ios::out | ios::ate | ios::binary );
        inf.seekg(0);
        if(!inf)
        {
            cout<<"No Data Found!..\n";
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(t==title)
            {
                Add_data();
                f=true;
                inf.seekp(inf.tellg() - sizeof(*this));
                inf.write((char*)this,sizeof(*this));
            }
            inf.read((char*)this,sizeof(*this));
        }
        if(f==true)
        {
            cout<<"Updated SuccessFully....\n";
        }
        inf.close();
    }
    bool searchBook(string t)
    {
        fstream inf;
        bool f=false;
        inf.open("Book.txt",ios::in | ios::binary );
        if(!inf)
        {
            cout<<"No Data Found!..\n";
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(t==title)
            {
                show();
                f=true;
                break;
            }
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
        return f;
    }
    void show()
    {
        cout<<"ID: "<<Bookid<<" "<<"Title: "<<title<<" "<<"Author: "<<authorName<<" "<<"Price: "<<price<<"\n";
    }
    void showAll()
    {
        ifstream inf;
        inf.open("Book.txt",ios::in | ios::binary);
        if(!inf)
        {
            cout<<"No Data Found!";
            return;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            show();
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
    }
    void storeData()
    {
        if(Bookid == 0)
        {
            return;
        }
        ofstream outf;
        outf.open("Book.txt",ios::app | ios::binary);
        outf.write((char*)this, sizeof(*this));
        outf.close();
    }
    void deleteBook(string t)
    {
        ifstream inf;
        ofstream outf;
        bool f = false;
        inf.open("Book.txt",ios::in | ios::binary);
        outf.open("Book1.txt",ios::out | ios::binary);
        if(!inf)
        {
            cout<<"No Data Found!";
            return;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(t != title)
            {
                outf.write((char*)this,sizeof(*this));
            }
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
        outf.close();
        remove("Book.txt");
        rename("Book1.txt", "Book.txt");
        cout<<"Deleted Successfull..\n";
    }
};


#endif // BOOKDATA_H_INCLUDED
