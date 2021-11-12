#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL {
	enum {RISK_A, RISK_B, RISK_C};
	
	double RiskRatio(int risk_level) {
		switch (risk_level) {
		case RISK_A: return 0.3; break;
		case RISK_B: return 0.2; break;
		case RISK_C: return 0.1; break;
		}
	}
}

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money) {
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {
	}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
	}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

};

class ForeignSalesWorker :public SalesWorker{
private:
	int riskLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int riskLevel)
		: SalesWorker(name, money, ratio), riskLevel(riskLevel){
	}
	int GetRisk() const{
		return SalesWorker::GetPay() * (RISK_LEVEL::RiskRatio(riskLevel));
	}
	int GetPay() const {
		return SalesWorker::GetPay() *(1 + RISK_LEVEL::RiskRatio(riskLevel));
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRisk() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0){ }
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const{
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		cout << "salary num: " << sum << endl << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main_a(void) {
	// ���� ���� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// �ؿ� ������ ���
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Toon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Toon", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();

	return 0;
}