#include<iostream>
#include"func.h"
#include"func.cpp"
using namespace std;

int main(){
    LIST L;
    InitList(L,3,4);//初始化一个三个年级，每个年级四个班的链表；
    //随便插入几个学生节点
    Insert(L,3,4);
    Insert(L,3,3);
    Insert(L,2,4);
    Insert(L,2,4);
    Insert(L,2,4);
    Insert(L,2,3);
    Insert(L,2,4);
    Insert(L,2,2);
    Insert(L,2,2);
    Insert(L,1,2);
    Insert(L,1,1);
    //打印全部学生
    PrintAll(L);
    printf("\n");
    //打印某个年级学生
    PrintG(L,2);
    printf("\n");
    //打印某个班级的学生
    PrintC(L,2,4);
    return 0;
}
