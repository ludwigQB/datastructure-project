#include<iostream>
using namespace std;

#define MAX_GRADE 4
#define MAX_CLASS 10
#define MAX_STU 30

typedef struct LESSON{
    int math;
    int eng;
    int phy;
}Lesson;

typedef struct STU{
    int Grade_Name;
    int Class_Name;
    string name;
    string ID;
    Lesson*Mark;
    STU*next;
}STU;

typedef struct CLASS{
    int Class_Num;
    STU*FirsrStu;
}CLASS;

typedef struct GRADE{
    int Grade_Num;
    CLASS Class[MAX_CLASS];
}Grade;

typedef struct LIST
{
    int Stu_Num;
    GRADE Grade[MAX_GRADE];
}LIST;

int InitList(LIST &L,int GNum,int CNum){
    L.Stu_Num=0;
    for(int i=0;i<GNum;i++){
        L.Grade[i].Grade_Num=i;
        for(int j=0;j<CNum;j++){
            STU* p=new STU;
            p->Class_Name=NULL;
            p->Grade_Name=NULL;
            p->name='\0';
            p->ID='\0';
            p->Mark=NULL;
            p->next=NULL;
            L.Grade[i].Class[j].Class_Num=j;
            L.Grade[i].Class[j].FirsrStu=p;
        }
    }
    for(int j=0;j<GNum;j++){
        for(int i=0;i<CNum;i++){
            if(i=CNum){
                L.Grade[j].Class[i].FirsrStu->next=NULL;
            }
            L.Grade[j].Class[i].FirsrStu->next=L.Grade[j].Class[i+1].FirsrStu;
        }
    }
}
