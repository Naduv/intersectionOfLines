// test_z.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct pt {
	int x, y; //���������� ������ � �����
};

inline bool getIntersect(int a, int b, int c, int d) { //������� �������� ����������� ���� ������
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return (max(a, c) <= min(b, d));
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���������� ������" <<endl;
	cin >> n;
	if (n > 1) { //������� ��������� ����, ���� ����� ������������ ���������� ������ 
	pt *a = new pt[n]; //������������ ������ ��� �������� �����
	bool flag = true; //������� ���������� ����������, ����� �� ������������ ������
	int i = 0, j = 0;
	while (i < n){
		cout << "������� ���������� " << i + 1 << "-� ������" << endl;
		cin >> a[i].x >> a[i].y;
		while (j < i){ //���� ������ ���������� i-��� ������ �� ����� ���������������
			if (getIntersect(a[i].x, a[i].y, a[j].x, a[j].y)) flag = true;
			else {
				flag = false; 
				break; //���� ���� ���� ������������ � ������ ���� � ������� �� �����
			}
			j++;
		}
		if (!flag) break; //�� ������ ������ ��������
		i++;
	}

	if (flag) cout << "���� ����� �����" << endl;
	else cout << "��� �����" << endl;
	delete[] a;
	}
	else cout << "������� ������������ ���������� ������ (���� 2 ��� ������)" << endl;
	return 0;
}