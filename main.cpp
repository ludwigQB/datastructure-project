#include<iostream>
#include"func.h"
#include"func.cpp"
using namespace std;

int main() {
	LIST L;
	InitList(L, 3, 4);
	int op;
	while (1) {
		cout << "请输入你想要的实现的操作(1--插入学生信息，2--删除学生信息，3--查找学生信息，4--批量输出学生信息，5--学生成绩排序，6--退出系统)：";
		cin >> op;
		switch (op) {
		case 1:
			while (1) {
				cout << "请输入学生各项信息(按1录入，按0结束)：";
				int flag;
				cin >> flag;
				if (flag == 0)
					break;
				if (flag == 1) {
					int k = Insert(L);
					if (k == 0)
						cout << "插入成功" << endl;
					else
						cout << "插入失败" << endl;
				}
			}
			break;
		case 2:
            Delete(L);
			break;
		case 3:
			SearchA(L);
			break;
        case 4:
            cout<<"1--输出全体学生信息，2--输出某年级学生信息，3--输出某班级学生信息：";
            int temp4;
            switch(temp4){
                case 1:
                    PrintAll(L);
                    break;
                case 2:
                    int temp5;
                    cout<<"请输入要输出的年级号：";
                    cin>>temp5;
                    PrintG(L,temp5);
                    break;
                case 3:
                    int temp6,temp7;
                    cout<<"请输入要输出班级的年级号与班级号：";
                    cin>>temp6>>temp7;
                    PrintC(L,temp6,temp7);
                    break;
                default:
                    break;
            }
            break;
		case 5:
            int temp1, temp2, temp3;
			cout << "请输入需要排序班级的年级号与班级号(空格号分隔开）：";
			cin >> temp1 >> temp2;
			cout << "请输入需要排序的科目(英语—1，数学-2，语文-3）：";
			cin >> temp3;
			Sort(L, temp1, temp2, temp3); 
            break;
		case 6:
			return 0;
		default:
			break;
		}
	}
	return 0;
}