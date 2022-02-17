#include<bits/stdc++.h>
#include<stdlib.h>
#include"BookData.h"
#include"StudentData.h"
#include"Student_Function.h"
#include"LibrarianData.h"
#include"Librarian_Function.h"
#include"Admin_Function.h"
#include"BOOK_RENTAL.h"
using namespace std;
int main()
{
    cout<<"Hello..\n";
    int check = 0;
    while(1)
    {
        cout<<"Enter 1, 2, 3, 4.....\n";
        cout<<"1 Enter in Library as a Student...\n";
        cout<<"2 Enter in Library as a Librarian..\n";
        cout<<"3 Enter in Library as an Admin......\n";
        cout<<"4 Exit......\n";
        cin>>check;
        if(check == 1)
        {
            system("cls");
            student_function();
            system("cls");
        }
        else if(check == 2)
        {
            system("cls");
            Librarian_Function();
            system("cls");
        }
        else if(check == 3)
        {
            system("cls");
            Admin_Function();
            system("cls");
        }
        else if(check == 4)
        {
            break;
        }
        else
        {
            system("cls");
            cout<<"Entered Something Wroung....\n";
            system("cls");
        }
    }
    return 0;
}
