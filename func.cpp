#pragma once
#include"func.h"

int InitList(LIST &L,int GNum,int CNum){
    L.Stu_Num=0;
    //先把每个年级、每个班、占位特殊节点建好
    for(int i=0;i<GNum;i++){
        L.Grade[i].Grade_Num=i;
        for(int j=0;j<CNum;j++){
            STU* p=new STU;
            p->Class_Name=2048;
            p->Grade_Name=2048;
            p->name="ludwig";
            p->ID="kelvin";
            p->Mark=NULL;
            p->next=NULL;
            L.Grade[i].Class[j].Class_Num=j;
            L.Grade[i].Class[j].FirsrStu=p;
        }
    }
    //将占位特殊节点相连
    for(int j=0;j<GNum;j++){
        for(int i=0;i<CNum;i++){
            if(j==GNum-1&&i==CNum-1){
                L.Grade[j].Class[i].FirsrStu->next=NULL;
                break;
            }
            else if(i==CNum-1){
                L.Grade[j].Class[i].FirsrStu->next=L.Grade[j+1].Class[0].FirsrStu;
                break;
            }
            L.Grade[j].Class[i].FirsrStu->next=L.Grade[j].Class[i+1].FirsrStu;
        }
    }
    return 0;
}

int Insert(LIST&L,int GNum,int CNum){
    STU*p=new STU;
    LESSON*m=new LESSON;
    m->eng=62;
    m->math=61;
    m->phy=60;
    p->Class_Name=CNum;
    p->Grade_Name=GNum;
    p->ID="2022180032";
    p->name="ludwig";
    p->Mark=m;
    p->next=L.Grade[GNum-1].Class[CNum-1].FirsrStu->next;
    L.Grade[GNum-1].Class[CNum-1].FirsrStu->next=p;
    return 0;
}

int PrintAll(LIST L){
    STU*p=new STU;
    p=L.Grade[0].Class[0].FirsrStu;
    while(p){
        if(p->Mark!=NULL){
            cout<<"年级："<<p->Grade_Name<<" ";
            cout<<"班级："<<p->Class_Name<<"\n";
        }
        p=p->next;
    }
    return 0;
}

int PrintG(LIST L,int GNum){
    STU*p=new STU;
    p=L.Grade[GNum-1].Class[0].FirsrStu;
    while(p){
        if(p->Mark!=NULL&&p->Grade_Name==GNum){
            cout<<"年级："<<p->Grade_Name<<" ";
            cout<<"班级："<<p->Class_Name<<"\n";
        }
        else if(p->Grade_Name == GNum+1){
            break;
        }
        p=p->next;
    }
    return 0;
}

int PrintC(LIST L,int GNum,int CNum){
    STU*p=new STU;
    p=L.Grade[GNum-1].Class[CNum-1].FirsrStu;
    while(p){
        if(p->Mark!=NULL&&p->Class_Name==CNum){
            cout<<"年级："<<p->Grade_Name<<" ";
            cout<<"班级："<<p->Class_Name<<"\n";
        }
        else if(p->Class_Name == CNum+1|| p->Grade_Name == GNum + 1){
            break;
        }
        p=p->next;
    }
    return 0;
}