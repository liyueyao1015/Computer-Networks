#include<iostream>
#include"DateLink.h"
#include<windows.h>
using namespace std;

int main()
{
    char name[] = "\\\\.\\Pipe\\mypipe";
    char mess[] = "HelloWorld!";
    char buf[256];
    cout << mess << endl;
    DateLink link(name);
    while(true){
        if(link.DateLink_Read(buf)){
          cout << "Receive:" << buf << endl;
        }
        link.DateLink_Wrire(mess);
        Sleep(1000);
    }


    cout << "Hello world!" << endl;
    return 0;
}
