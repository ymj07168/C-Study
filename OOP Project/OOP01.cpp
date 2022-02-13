/*
* Banking System Ver 0.1
* �ۼ��� : ��ȿ��
* ��  �� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct AccountInfo {
	int ID;
	char name[20];
	int money;
};

void ShowMenuInfo();
void CreateAccount(AccountInfo arr[], int &count);
void Deposit(AccountInfo arr[], int& count);
void Withdraw(AccountInfo arr[], int& count);
void ShowAccountInfo(AccountInfo arr[], int& count);

int main(void) {
	AccountInfo arr[100];
	int count = 0;
	int menuNum;
	while (1) {
		ShowMenuInfo();
		cout << "����: ";
		cin >> menuNum;
		cout << endl;
		switch (menuNum) {
		case 1: CreateAccount(arr, count); break;
		case 2: Deposit(arr, count); break;
		case 3: Withdraw(arr, count); break;
		case 4: ShowAccountInfo(arr, count); break;
		case 5: return 0; break;
		}
		cout << endl;
	}
}

void ShowMenuInfo() {
	cout << "----Menu----" << endl;
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void CreateAccount(AccountInfo arr[], int &count) {
	int ID, money;
	char name[20];
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> ID;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	arr[count].ID = ID;
	strcpy(arr[count].name, name);
	arr[count].money = money;
	count++;
}

void Deposit(AccountInfo arr[], int &count) {
	int ID, money, IdNum;
	cout << "����ID: ";
	cin >> ID;
	cout << "�Աݾ�: ";
	cin >> money;
	for (int i = 0; i < count; i++) {
		if (arr[i].ID == ID) arr[i].money += money;
	}
	cout << "�ԱݿϷ�" << endl;
}

void Withdraw(AccountInfo arr[], int& count) {
	int ID, money, IdNum;
	cout << "����ID: ";
	cin >> ID;
	cout << "��ݾ�: ";
	cin >> money;
	for (int i = 0; i < count; i++) {
		if (arr[i].ID == ID) arr[i].money -= money;
	}
	cout << "��ݿϷ�" << endl;
}

void ShowAccountInfo(AccountInfo arr[], int& count) {
	for (int i = 0; i < count; i++) {
		cout << "����ID: " << arr[i].ID << endl;
		cout << "�� ��: " << arr[i].name << endl;
		cout << "�� ��: " << arr[i].money << endl;
		cout << endl;
	}
}
