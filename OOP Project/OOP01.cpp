/*
* Banking System Ver 0.1
* 작성자 : 이효원
* 내  용 : OOP 단계별 프로젝트의 기본 틀 구성
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
		cout << "선택: ";
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
	cout << "1. 계좌계설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CreateAccount(AccountInfo arr[], int &count) {
	int ID, money;
	char name[20];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	arr[count].ID = ID;
	strcpy(arr[count].name, name);
	arr[count].money = money;
	count++;
}

void Deposit(AccountInfo arr[], int &count) {
	int ID, money, IdNum;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "입금액: ";
	cin >> money;
	for (int i = 0; i < count; i++) {
		if (arr[i].ID == ID) arr[i].money += money;
	}
	cout << "입금완료" << endl;
}

void Withdraw(AccountInfo arr[], int& count) {
	int ID, money, IdNum;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "출금액: ";
	cin >> money;
	for (int i = 0; i < count; i++) {
		if (arr[i].ID == ID) arr[i].money -= money;
	}
	cout << "출금완료" << endl;
}

void ShowAccountInfo(AccountInfo arr[], int& count) {
	for (int i = 0; i < count; i++) {
		cout << "계좌ID: " << arr[i].ID << endl;
		cout << "이 름: " << arr[i].name << endl;
		cout << "잔 액: " << arr[i].money << endl;
		cout << endl;
	}
}
