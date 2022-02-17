#ifndef STUDENTDATA_H_INCLUDED
#define STUDENTDATA_H_INCLUDED

#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include"CHECK.h"
using namespace std;
class Student
{
    int id;
    char name[50];
public:
    Student()
    {
        id = 0;
        strcpy(name,"No Name");
    }
    void add_student()
    {
        cout<<"Enter Details:  \n";
        cout<<"Enter Student Registration Number:   ";
        cin>>id;
        cout<<"\nEnter Student Name:  ";
        cin>>name;
    }
    void store_data()
    {
        ofstream outf;
        if(search_student(this->id, this->name))
        {
            cout<<"Data Already Exist...\n";
            cout<<"Enter any Digit To exit..\n";
            string lk;
            cin>>lk;
            return;
        }
        outf.open("StudentData.txt",ios::app|ios::binary);
        if(id == 0)
        {
            cout<<"No data to strore.\n";
            return;
        }
        outf.write((char*)this,sizeof(*this));
        outf.close();
        cout<<"Successfull!\n";
    }
    bool search_student(int k,string n)
    {
        ifstream inf;
        bool f = false;
        inf.open("StudentData.txt",ios::in | ios::binary);
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
    void delete_student(int k)
    {
        ifstream inf;
        ofstream outf;
        bool f = false;
        inf.open("StudentData.txt",ios::in | ios::binary);
        outf.open("StudentData1.txt",ios::out | ios::binary);
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
        remove("StudentData.txt");
        rename("StudentData1.txt", "StudentData.txt");
    }
    void update_student(int k)
    {
        fstream outf;
        bool f = false;
        outf.open("StudentData.txt",ios::in | ios::out | ios::ate | ios::binary);
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
                add_student();
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
            cout<<"No Student Found!\n";
        }
        outf.close();
    }
    void show_student()
    {
        cout<<"ID: "<<id<<"  Name: "<<name<<"\n";
    }
    void printAll()
    {
        ifstream inf;
        inf.open("StudentData.txt",ios::in | ios::binary);
        if(!inf)
        {
            cout<<"No Data Found!";
            return;
        }
        inf.read((char*)this,sizeof(*this));
        while(!inf.eof())
        {
            show_student();
            inf.read((char*)this,sizeof(*this));
        }
        inf.close();
    }
};


#endif // STUDENTDATA_H_INCLUDED
