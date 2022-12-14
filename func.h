#pragma once
#include<iostream>
using namespace std;

#define MAX_GRADE 4
#define MAX_CLASS 10
#define LESSON_NUM 3

//课程与成绩(临时
typedef struct LESSON {
    int Lesson[LESSON_NUM];
}Lesson;
//学生信息--链表
typedef struct STU {
    int Grade_Name;
    int Class_Name;
    string name;
    string ID;
    Lesson* Mark;
    STU* next;
}STU;
//班级--顺序表
typedef struct CLASS {
    int Class_Num;
    STU* FirsrStu;
}CLASS;
//年级--顺序表
typedef struct GRADE {
    int Grade_Num;
    CLASS Class[MAX_CLASS];
}Grade;

typedef struct LIST
{
    int Stu_Num;
    GRADE Grade[MAX_GRADE];
}LIST;

int InitList(LIST& L, int GNum, int CNum);
int Insert(LIST& L);
int PrintAll(LIST L);
int PrintG(LIST L, int GNum);
int PrintC(LIST L, int GNum, int CNum);
int Swap(STU& s1, STU& s2);
int Sort(LIST& L, int GNum, int CNum, int lesson);
int SearchA(LIST& L);
int Delete(LIST&L);