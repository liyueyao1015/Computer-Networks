#ifndef PORTTABLE_H_INCLUDED
#define PORTTABLE_H_INCLUDED
#include"DateLink.h"
class LinkTable
{
public:
    DateLink* link;
    bool statu;
    PortTable* next;
    char * const pipename;

    LinkTable(char *const ptr);
    void LinkTable_LinkClose(void);
    void LinkTable_LinkOpen(void);
};

#endif // PORTTABLE_H_INCLUDED
