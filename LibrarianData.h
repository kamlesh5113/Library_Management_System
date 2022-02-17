#ifndef LIBRARIANDATA_H_INCLUDED
#define LIBRARIANDATA_H_INCLUDED
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include"CHECK.h"
using namespace std;
class Librarian
{
    int id;
    char name[50];
public:
    Librarian()
    {
        id = 0;
        strcpy(name,"No Name");
    }
    void add_librarian()
    {
        cout<<"Enter Details:  \n";
        cout<<"Enter Librarian Id:   ";
        cin>>id;
        cout<<"\nEnter librarian Name:  ";
        cin>>name;
    }
    void store_data()
    {
        ofstream outf;
        if(search_librarian(this->id, this->name))
        {
            cout<<"Data Already Exist...\n";
            cout<<"Enter any Digit To exit..\n";
            string lk;
            cin>>lk;
            return;
        }
        outf.open("librarianData.txt",ios::app|ios::binary);
        if(id == 0)
        {
            cout<<"No data to stror.\n";
            return;
        }
        outf.write((char*)this,sizeof(*this));
        outf.close();
    }
    bool search_librarian(int k,string n)
    {
        ifstream inf;
        bool f = false;
        inf.open("librarianData.txt",ios::in | ios::binary);
        if(!inf)
        {
            cout<<"No data Found!\n";
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(k == id && n == name)
            {
                f = true;
            }
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
        if(f == true)
        {
            return true;
        }
        return false;
    }
    void delete_librarian(int k)
    {
        ifstream inf;
        ofstream outf;
        bool f = false;
        inf.open("librarianData.txt",ios::in | ios::binary);
        outf.open("librarianData1.txt",ios::out | ios::binary);
        if(!inf)
        {
            cout<<"No Data Found!";
            return;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            if(k != id)
            {
                outf.write((char*)this,sizeof(*this));
            }
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
        outf.close();
        remove("librarianData.txt");
        rename("librarianData1.txt", "librarianData.txt");
    }
    void update_librarian(int k)
    {
        fstream outf;
        bool f = false;
        outf.open("librarianData.txt",ios::in | ios::out | ios::ate | ios::binary);
        if(!outf)
        {
            cout<<"No Data found!\n";
        }
        outf.seekg(0);
        outf.read((char*)this,sizeof(*this));
        while(!outf.eof())
        {
            if(k == id)
            {
                add_librarian();
                f=  true;
                outf.seekg(outf.tellg()-sizeof(*this));
                outf.write((char*)this,sizeof(*this));
            }
            outf.read((char*)this,sizeof(*this));
        }
        if(f == true)
        {
            cout<<"Updated Successfull!\n";
        }
        else
        {
            cout<<"No librarian Found!\n";
        }
        outf.close();
    }
    void show_librarian()
    {
        cout<<"ID: "<<id<<"  Name: "<<name<<"\n";
    }
    void printAll()
    {
        ifstream inf;
        inf.open("librarianData.txt",ios::in | ios::binary);
        if(!inf)
        {
            cout<<"No Data Found!";
            return;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            show_librarian();
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
    }
};


#endif // STUDENTDATA_H_INCLUDED
