#pragma once
#include"func.h"

int InitList(LIST& L, int GNum, int CNum) {
    L.Stu_Num = 0;
    //先把每个年级、每个班、占位特殊节点建好
    for (int i = 0; i < GNum; i++) {
        L.Grade[i].Grade_Num = i + 1;
        for (int j = 0; j < CNum; j++) {
            STU* p = new STU;
            p->Class_Name = 2048;
            p->Grade_Name = 2048;
            p->name = "NULL";
            p->ID = "NULL";
            p->Mark = NULL;
            p->next = NULL;
            L.Grade[i].Class[j].Class_Num = j + 1;
            L.Grade[i].Class[j].FirsrStu = p;
        }
    }
    //将占位特殊节点相连
    for (int j = 0; j < GNum; j++) {
        for (int i = 0; i < CNum; i++) {
            if (j == GNum - 1 && i == CNum - 1) {
                L.Grade[j].Class[i].FirsrStu->next = NULL;
                break;
            }
            else if (i == CNum - 1) {
                L.Grade[j].Class[i].FirsrStu->next = L.Grade[j + 1].Class[0].FirsrStu;
                break;
            }
            L.Grade[j].Class[i].FirsrStu->next = L.Grade[j].Class[i + 1].FirsrStu;
        }
    }
    return 0;
}

//测试用
int Insert(LIST& L) {
    STU* p = new STU;
    LESSON* m = new LESSON;
    p->Mark = m;
    cout << "年级：";
    cin >> p->Grade_Name;
    cout << "班级：";
    cin >> p->Class_Name;
    cout << "姓名：";
    cin >> p->name;
    cout << "学号：";
    cin >> p->ID;
    cout << "分别输入英语、数学、语文成绩(以空格隔开): ";
    cin >> p->Mark->Lesson[0] >> p->Mark->Lesson[1] >> p->Mark->Lesson[2];
    p->next = L.Grade[p->Grade_Name - 1].Class[p->Class_Name - 1].FirsrStu->next;
    L.Grade[p->Grade_Name - 1].Class[p->Class_Name - 1].FirsrStu->next = p;
    L.Stu_Num++;
    return 0;
}

int PrintAll(LIST L) {
    STU* p = new STU;
    p = L.Grade[0].Class[0].FirsrStu;
    while (p) {
        if (p->Mark != NULL) {
            cout << "年级：" << p->Grade_Name << " ";
            cout << "班级：" << p->Class_Name << " ";
            cout << "成绩: 英语：" << p->Mark->Lesson[0] << " 数学：" << p->Mark->Lesson[1] << " 语文：" << p->Mark->Lesson[2] << " ";
            cout << "姓名：" << p->name << "\n";
        }
        p = p->next;
    }
    return 0;
}

int PrintG(LIST L, int GNum) {
    STU* p = new STU;
    p = L.Grade[GNum - 1].Class[0].FirsrStu;
    while (p) {
        if (p->Mark != NULL && p->Grade_Name == GNum) {
            cout << "年级：" << p->Grade_Name << " ";
            cout << "班级：" << p->Class_Name << " ";
            cout << "成绩: 英语：" << p->Mark->Lesson[0] << " 数学：" << p->Mark->Lesson[1] << " 语文：" << p->Mark->Lesson[2] << " ";
            cout << "姓名：" << p->name << "\n";
        }
        else if (p->Grade_Name == GNum + 1) {
            break;
        }
        p = p->next;
    }
    return 0;
}

int PrintC(LIST L, int GNum, int CNum) {
    STU* p = new STU;
    p = L.Grade[GNum - 1].Class[CNum - 1].FirsrStu;
    while (p) {
        if (p->Mark != NULL && p->Grade_Name == GNum && p->Class_Name == CNum) {
            cout << "年级：" << p->Grade_Name << " ";
            cout << "班级：" << p->Class_Name << " ";
            cout << "成绩: 英语：" << p->Mark->Lesson[0] << " 数学：" << p->Mark->Lesson[1] << " 语文：" << p->Mark->Lesson[2] << " ";
            cout << "姓名：" << p->name << "\n";
        }
        else if (p->Class_Name == CNum + 1 || p->Grade_Name == GNum + 1) {
            break;
        }
        p = p->next;
    }
    return 0;
}

int Print(STU& p) {
    cout << "年级：" << p.Grade_Name << " ";
    cout << "班级：" << p.Class_Name << " ";
    cout << "成绩: 英语：" << p.Mark->Lesson[0]<<" 数学："<< p.Mark->Lesson[1] << " 语文：" << p.Mark->Lesson[2] ;
    cout << "姓名：" << p.name << "\n";
    return 0;
}

//交换节点
int Swap(STU& s1, STU& s2) {
    STU* p = new STU;
    p->Class_Name = s1.Class_Name;
    p->Grade_Name = s1.Grade_Name;
    p->ID = s1.ID;
    p->Mark = s1.Mark;
    p->name = s1.name;
    s1.Class_Name = s2.Class_Name;
    s1.Grade_Name = s2.Grade_Name;
    s1.ID = s2.ID;
    s1.Mark = s2.Mark;
    s1.name = s2.name;
    s2.Class_Name = p->Class_Name;
    s2.Grade_Name = p->Grade_Name;
    s2.ID = p->ID;
    s2.Mark = p->Mark;
    s2.name = p->name;
    return 0;
}

//排序
int Sort(LIST& L, int GNum, int CNum, int lesson) {
    STU* p = new STU;
    STU* q = new STU;
    p = L.Grade[GNum - 1].Class[CNum - 1].FirsrStu->next;
    for (p = L.Grade[GNum - 1].Class[CNum - 1].FirsrStu->next; p->Class_Name == CNum; p = p->next) {
        if (!p->next) {
            break;
        }
        for (q = p->next; q->Class_Name == CNum; q = q->next) {
            if (q->Mark->Lesson[lesson - 1] > p->Mark->Lesson[lesson - 1]) {
                Swap(*q, *p);
            }
            if (!q->next) {
                break;
            }
        }
    }
    p = L.Grade[GNum - 1].Class[CNum - 1].FirsrStu;
    while (p) {
        if (p->Mark != NULL && p->Grade_Name == GNum && p->Class_Name == CNum) {
            cout << "年级：" << p->Grade_Name << " ";
            cout << "班级：" << p->Class_Name << " ";
            cout << "成绩" << p->Mark->Lesson[lesson-1];
            cout << "姓名：" << p->name << "\n";
        }
        else if (p->Class_Name == CNum + 1 || p->Grade_Name == GNum + 1) {
            break;
        }
        p = p->next;
    }
    return 0;
}

int SearchA(LIST& L) {
    string Uid;
    cout << "请输入要查找学生的学号：";
    cin >> Uid;
    STU* p = new STU;
    p = L.Grade[0].Class[0].FirsrStu;
    while (p) {
        if (p->ID == Uid) {
            Print(*p);
        }
        p = p->next;
    }
    return 0;
}

int SortB(LIST& L, int GNum, int lesson) {
    STU* p = new STU;
    STU* q = new STU;
    for (p = L.Grade[GNum - 1].Class[0].FirsrStu->next; p->Grade_Name== GNum; p = p->next) {
        if (!p->next) {
            break;
        }
        for (q = p->next; q->Grade_Name ==GNum; q = q->next) {
            if (q->Mark->Lesson[lesson - 1] > p->Mark->Lesson[lesson - 1]) {
                Swap(*q, *p);
            }
            if (!q->next) {
                break;
            }
        }
    }
    p = L.Grade[GNum - 1].Class[0].FirsrStu;
    while (p) {
        if (p->Mark != NULL && p->Grade_Name == GNum) {
            cout << "年级：" << p->Grade_Name << " ";
            cout << "班级：" << p->Class_Name << " ";
            cout << "成绩: " << p->Mark->Lesson[lesson-1];
            cout << "姓名：" << p->name << "\n";
        }
        else if (p->Grade_Name == GNum + 1) {
            break;
        }
        p = p->next;
    }
    return 0;
}

int Delete(LIST&L){
    string Uid;
    cout<<"请输入要删除学生的学生号：";
    cin>>Uid;
    STU*p=new STU;
    p=L.Grade[0].Class[0].FirsrStu;
    while(p->next){
        if(p->next->ID==Uid){
            p->next=p->next->next;
            return 0;
        }
        p=p->next;
    }
    return 1;
}