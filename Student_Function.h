#ifndef STUDENT_FUNCTION_H_INCLUDED
#define STUDENT_FUNCTION_H_INCLUDED

#include<bits/stdc++.h>
#include<stdlib.h>
#include"StudentData.h"
#include"BookData.h"
#include"BOOK_RENTAL.h"
void student_function(){
    Student s1;
    Book b1;
    BookRental b;
    int id;
    string title;
    cout<<"Hello Student..\n";
    while(1)
    {
    int k;
    int kkk=0;
    cout<<"Enter 4 To exit...else 1..\n";
    cin>>k;
    if(k==4)
    {
        return;
    }
    system("cls");
    cout<<"Press 1 To Enter Library...\n";
    cout<<"Press 2 To Register....\n";
    cout<<"4 Exit From Library....\n";
    cin>>k;
    if(k==4)
    {
        return;
    }
    else if(k == 2)
    {
        system("cls");
        s1.add_student();
        s1.store_data();
    }
    else if(k==1)
    {
    while(1)
    {
    system("cls");
    cout<<"Enter Your Registration Number:       ";
    cin>>k;
    id = k;
    cout<<"\nEnter your Name:   ";
    char s[50];
    cin>>s;
    Student s1;
    if(s1.search_student(k,s))
    {
    system("cls");
    cout<<"Enter 1, 2, 3, 4.....\n";
    while(1)
    {
        cout<<"1 View All Books Available in Library...\n";
        cout<<"2 Take A Book on Rent.....\n";
        cout<<"3 Return Book....\n";
        cout<<"4 Logout....\n";
        cin>>k;
        if(k == 1)
        {
            system("cls");
            b1.showAll();
            k=0;
            while(k!=1)
            {
                cout<<"Enter 1 to move back..\n";
                cin>>k;
            }system("cls");
        }
        else if(k == 2)
        {
            system("cls");
            cout<<"Enter Book Details...\n";
            cout<<"Enter Book title:   ";
            cin>>s;
            if(kkk==0){
                    kkk=1;
            title = s;}
            if(b1.searchBook(s))
            {
                system("cls");
                if(b.SEARCH_DATA(id)==1)
                {
                    cout<<"First Return The Previous Book....\n";
                    cout<<"Enter any key to continue...\n";
                    string lk;
                    cin>>lk;
                    kkk=0;
                }
                else if(b.SEARCH_DATA(id) == 2 || b.SEARCH_DATA(id) == 0)
                {
                    cout<<"Alloted...\n";
                    b.ADD_DATA(id,true);
                    b.STORE_DATA();
                    cout<<"Enter any key to continue...\n";
                    string lk;
                    cin>>lk;
                }
                system("cls");
            }
            else
            {
                cout<<"Enter correct book title...\n";
                while(k!=1)
            {
                cout<<"Enter 1 to move back..\n";
                cin>>k;
            }system("cls");

            }
        }
        else if(k == 3)
        {
            cout<<title<<" - "<<"This Book is returned Successfully....\n";
            b.DELETE_DATA(id);
            cout<<"Enter 1 to move back..\n";
            cin>>k;
            system("cls");
        }
        else if(k == 4)
        {
            break;
        }
        else
        {
            cout<<"Entered Something Wroung!..\n";
        }
    }
    system("cls");
    if(k==4)
    {
        break;
    }
    }
    else
    {
        system("cls");
        cout<<"Entered Somethin Wroung..\n";
        cout<<"Enter 1 To Change Details....\n";
        cout<<"Enter any digit Else....\n";
        cout<<"Enter 4 To exit...\n";
        cin>>k;
        if(k==4)
        {
            break;
        }
        if(k==1)
        {
            cout<<"Enter Your Registered Number:  \n";
            cin>>k;
            Student sss;
            sss.update_student(k);
            cout<<"Enter Any Digit: ";
            cin>>k;
        }
        system("cls");
    }
    }
    }
    else
    {
        cout<<"Entered Something Wroung...\n";
    }
    }
    return;
}



#endif // STUDENT_FUNCTION_H_INCLUDED
