#include"DateLink.h"
bool DateLink::DateLink_Read(char buf[256]){
    DWORD rlen = 0;
    if(ReadFile(NamedPipe,buf,256,&rlen,NULL)==FALSE)       //接受信息
    {
        printf("Read Data From Pipe Failed!\n");
        return false;
    }
    return true;
}
