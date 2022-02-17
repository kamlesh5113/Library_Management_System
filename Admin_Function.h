#ifndef ADMIN_FUNCTION_H_INCLUDED
#define ADMIN_FUNCTION_H_INCLUDED

#include<bits/stdc++.h>
#include"LibrarianData.h"
#include"StudentData.h"

void Admin_Function()
{

    int l,k;
    while(1)
    {
        cout<<"Enter 4 to Exit..else 1 to continue..\n";
        cin>>l;
        system("cls");
        if(l==4)
        {
            return;
        }
        while(1){
    cout<<"Enter Admin ID:    ";
    cin>>k;
    cout<<"\nEnter Admin Password:   ";
    string s;
    cin>>s;
    if(k == 1234 && s == "Kamlesh@123#7427")
    {
        system("cls");
        while(1){
        cout<<"Enter 1, 2, 3, 4, 5\n";
        cout<<"1 View All Students..\n";
        cout<<"2 View All Librarian.\n";
        cout<<"3 Delete A Student...\n";
        cout<<"4 Delete A Librarian.\n";
        cout<<"5 Logout.............\n";
        cin>>k;
        if(k==5)
        {
            break;
        }
        else if(k==1)
        {
            Student s1;
            s1.printAll();
            cout<<"Enter any key to continue...\n";
            int j;
            cin>>j;
        }
        else if(k==2)
        {
            Librarian l1;
            l1.printAll();
            cout<<"Enter any key to continue...\n";
            int j;
            cin>>j;
        }
        else if(k==3)
        {
            Student s1;
            cout<<"Enter Student ID:   ";
            cin>>k;
            s1.delete_student(k);
            cout<<"Enter any key to continue...\n";
            int j;
            cin>>j;
        }
        else if(k==4)
        {
            Librarian l1;
            cout<<"Enter Librarian ID:   ";
            cin>>k;
            l1.delete_librarian(k);
            cout<<"Enter any key to continue...\n";
            int j;
            cin>>j;
        }
        system("cls");
    }
    if(k==5)
    {
        break;
    }
    }
    else
    {
        cout<<"Wrong...\n";
        cout<<"Enter 4 To Exit Else any key to continue:  \n";
        cin>>k;
        if(k==4)
        {
            return;
        }
        system("cls");
    }
    }
    }

}



#endif // ADMIN_FUNCTION_H_INCLUDED
