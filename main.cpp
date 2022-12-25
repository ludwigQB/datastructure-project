#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
#include"FunC.h"
using namespace std;
void gotoxy(int x,int y){
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    LIST L;
	InitList(L, 3, 4);
    int op;
	while (1) {
		gotoxy(10,1);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    	cout << "***                欢迎来到学生信息管理系统                ***" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		gotoxy(22,2);
		cout << "1--插入学生信息        2--删除学生信息\n";
		gotoxy(22,3);
		cout << "3--查找学生信息        4--批量输出学生信息\n";
		gotoxy(22,4);
		cout << "5--学生成绩排序        6--退出系统\n";
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "请输入你想要的实现的操作：";
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> op;
		switch (op) {
		case 1:
			while (1) {
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "请输入学生各项信息(按1录入，按0结束)：";
				int flag;
				SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cin >> flag;
				if (flag == 0){
					system("cls");
					break;
				}	
				if (flag == 1) {
					int k = Insert(L);
					if (k == 0) {
						SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "插入成功！" << endl;
					}
					else {
						SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "插入失败！" << endl;
					}
				}
			}
			break;
		case 2:
			int flag1;
			flag1 = Delete(L);
			if (flag1 == 0) {
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "删除成功！" << endl;
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
			}
			else {
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "未查到该学生信息，删除失败！" << endl;
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
			}	
			break;
		case 3:
			int flag2;
			flag2=SearchA(L);
			if (flag2 == 0) {
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "未查到该学生信息，查找失败！"<<endl;
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
			}
			break;
		case 4:
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "1--输出全体学生信息      2--输出某年级学生信息      3--输出某班级学生信息\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "请输入想实现的操作：" ;
			int temp4;
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cin >> temp4;
			switch (temp4) {
			case 1:
				PrintAll(L);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
				break;
			case 2:
				int temp5;
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "请输入要输出的年级号：";
				SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cin >> temp5;
				PrintG(L, temp5);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
				break;
			case 3:
				int temp6, temp7;
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "请输入要输出班级的年级号与班级号（以空格隔开）：";
				SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cin >> temp6 >> temp7;
				PrintC(L, temp6, temp7);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "按任意键继续";
				getch();
				system("cls");
				break;
			default:
				break;
			}
			break;
		case 5:
			int temp1, temp2, temp3;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "请输入需要排序班级的年级号与班级号（以空格分开）：";
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cin >> temp1 >> temp2;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "1--英语      2--数学      3--语文\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "请输入需要排序的科目：";
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cin >> temp3;
			Sort(L, temp1, temp2, temp3);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "按任意键继续";
			getch();
			system("cls");
			break;
		case 6:
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "欢迎您下次使用！" << endl;
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			return 0;
		default:
			break;
		}
	}
	return 0;
}
