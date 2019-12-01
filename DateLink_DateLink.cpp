#include"DateLink.h"
DateLink::DateLink(char * const pname):PipeName(pname){

    BOOL LinkExist = WaitNamedPipe(TEXT(PipeName),0);
    if(!LinkExist){
    //printf("*************");
        NamedPipe = CreateNamedPipe(PipeName,PIPE_ACCESS_DUPLEX|FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
        /*CreateNamedPipe(
            TEXT(PipeName),                        //管道名
            PIPE_ACCESS_DUPLEX,                                 //管道类型
            PIPE_TYPE_MESSAGE|PIPE_READMODE_MESSAGE|PIPE_WAIT,  //管道参数
            PIPE_UNLIMITED_INSTANCES,                           //管道能创建的最大实例数量
            100,                                                  //输出缓冲区长度 0表示默认
            100,                                                  //输入缓冲区长度 0表示默认
            NMPWAIT_WAIT_FOREVER,                               //超时时间
            NULL);                                              //模板创建文件的句柄*/
        if (INVALID_HANDLE_VALUE == NamedPipe)
        {
            printf("Create DateLink Error(%d)\n",GetLastError());
        }
        else
        {
            printf("Waiting For Connection...\n");
            if(ConnectNamedPipe(NamedPipe, NULL)==NULL) //阻塞等待客户端连接。
            {
                printf("Connection failed!\n");
            }
            else
            {
                printf("Connection Success!\n");
            }
        }
    DateLink_Wrire("");
    }
    else{
        NamedPipe = CreateFile(PipeName,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        /*CreateFile(                           //管道属于一种特殊的文件
            TEXT(PipeName),                             //创建的文件名
            GENERIC_READ | GENERIC_WRITE,               //文件模式
            0,                                          //是否共享
            NULL,                                       //指向一个SECURITY_ATTRIBUTES结构的指针
            OPEN_EXISTING,                              //创建参数
            FILE_ATTRIBUTE_NORMAL,                      //文件属性(隐藏,只读)NORMAL为默认属性
            NULL);*/
        if (INVALID_HANDLE_VALUE == NamedPipe){
            printf("Create link failed!\n");
        }
        else{
            printf("Create link success!\n");
        }
    }

}
