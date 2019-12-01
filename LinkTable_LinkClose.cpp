#include"LinkTable.h"
void LinkTable::LinkTable_LinkClose(void){
    statu = false;
    delete link;
}
