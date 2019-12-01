#include"DateLink.h"
bool DateLink::DateLink_Wrire(char buf[256]){
    DWORD wlen = 0;
    if(WriteFile(NamedPipe,buf,256,&wlen,0)==FALSE)             //向发送信息
    {
        printf("Send date failed!\n");
        return false;
    }
    return true;
}
