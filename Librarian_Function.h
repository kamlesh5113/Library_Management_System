#ifndef LIBRARIAN_FUNCTION_H_INCLUDED
#define LIBRARIAN_FUNCTION_H_INCLUDED

#include"LibrarianData.h"
#include"BookData.h"
#include<iostream>
#include"CHECK.h"


void Librarian_Function()
{

        int k,l;
    Librarian l1;
    while(1){
    cout<<"Hello Librarian.....\n";
    cout<<"Press 4 to exit else 1 to continue....\n";
    cin>>k;
    system("cls");
    if(k==1)
    {
        while(1){
        cout<<"Enter Details...\n";
        cout<<"1 Login...\n";
        cout<<"2 Move Back...\n";
        cin>>k;
        system("cls");
        if(k==1)
        {
            cout<<"Enter details....\n";
            cout<<"Enter ID:  \n";
            cin>>k;
            cout<<"Password:   \n";
            string s;
            cin>>s;
            system("cls");
            if(l1.search_librarian(k,s))
            {
                cout<<"Enter details...\n";
                while(1){
                    cout<<"1 Add a Book To Library.....\n";
                    cout<<"2 Enter to Show All Books...\n";
                    cout<<"3 Enter to update a Book....\n";
                    cout<<"4 Enter to Delete a Books...\n";
                    cout<<"5 Enter to Search a Book....\n";
                    cout<<"6 Logout.\n";
                    cin>>k;
                    if(k==6)
                    {
                        system("cls");
                        break;
                    }
                    else if(k==2)
                    {
                        Book b1;
                        b1.showAll();
                        cout<<"Enter any key to continue..\n";
                        char j;
                        cin>>j;
                    }
                    else if(k==3)
                    {
                        Book b1;
                        string s;
                        cout<<"Enter Book title:  \n";
                        cin>>s;
                        if(b1.searchBook(s))
                        {
                           b1.updataBook(s);
                        }
                        else{
                            cout<<"Entered Wrong Details...\n";
                        }
                        cout<<"Enter any key to continue..\n";
                        char j;
                        cin>>j;
                    }
                    else if(k==4)
                    {
                        Book b1;
                        cout<<"Enter Book Title:  \n";
                        string s;
                        cin>>s;
                        if(b1.searchBook(s))
                        {
                           b1.deleteBook(s);
                        }
                        else
                        {
                            cout<<"Entered Wrong Details..\n";
                        }
                        cout<<"Enter Any key To Continue..\n";
                        char j;
                        cin>>j;
                    }
                    else if(k==5)
                    {
                        Book b1;
                        cout<<"Enter Book title:  \n";
                        string s;
                        cin>>s;
                        if(b1.searchBook(s))
                        {
                           cout<<"Found\n";
                        }
                        else
                        {
                            cout<<"No Data Found....\n";
                        }
                        cout<<"Enter any key to continue..\n";
                        char j;
                        cin>>j;
                    }
                else if(k==1)
                {
                    Book b1;
                    b1.Add_data();
                    b1.storeData();
                    cout<<"Added Successfully..\n";
                    cout<<"Enter any key to continue..\n";
                    char j;
                    cin>>j;
                }
                    else
                    {
                        cout<<"Entered Something Wrong..\n";
                        cout<<"Enter any key To continue..\n";
                        char j;
                        cin>>j;
                    }
                    system("cls");
                }

            }
            else
            {
                cout<<"Entered Something Wrong...\n";
                cout<<"Enter 1 To Change Password Details..\n";
                cout<<"Enter 2 To move Back...\n";
                int ll;
                cin>>ll;
                if(ll==1)
                {
                    Librarian lll;
                    cout<<"Enter Your Id:  \n";
                    cin>>ll;
                    lll.update_librarian(ll);
                }
            }
        }
        else if(k==2)
        {
            break;
        }
        else
        {
            cout<<"Entered Something Wrong...\n";
            cout<<"Enter any key to continue..\n";
            char j;
            cin>>j;
        }
        }
    }
    else if(k==4)
    {
        return;
    }
    else
    {
        cout<<"Entered Something Wrong...\n";
        cout<<"Enter any key To continue..\n";
                        char j;
            cin>>j;
    }
}



}


#endif // LIBRARIAN_FUNCTION_H_INCLUDED
