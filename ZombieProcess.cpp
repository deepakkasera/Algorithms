#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    int count = 0;
    while (fork() > 0)
    {
        count++;
        cout<<count<<" ";
    }
}