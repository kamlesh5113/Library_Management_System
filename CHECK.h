#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED
#include<string>
#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int i=0;
    while(s[i])
    {
        if(isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}


#endif // CHECK_H_INCLUDED
