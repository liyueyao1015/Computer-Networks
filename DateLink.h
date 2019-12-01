#ifndef DATELINK_H_INCLUDED
#define DATELINK_H_INCLUDED
#include <cstdio>
#include <windows.h>

class DateLink
{
private:
    HANDLE NamedPipe;
    char * const PipeName;
public:
    DateLink(char * const pname);
    ~DateLink(){
        CloseHandle(NamedPipe);
    }
    bool DateLink_Wrire(char buf[256]);
    bool DateLink_Read(char buf[256]);
};


#endif // DATELINK_H_INCLUDED
