#include <iostream>
using namespace std;

struct Car
{
	char model[10];
	char kpp[10];
	char color[8];
	int v; 
	int r;
};
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <conio.h>

using namespace std;

double a = 0;
int p = 0;
int cina = 0;

struct Employee {
    int phone;
    double kWt_month;
    double time_day;
    double Max_power_h;
};

vector<Employee> employees;

void loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ���� ������� ����: " << filename << endl;
        return;
    }

    Employee emp;
    while (file >> emp.phone >> emp.kWt_month >> emp.time_day >> emp.Max_power_h) {
        employees.push_back(emp);
    }

    file.close();
}

void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ���� ��������: " << filename << endl;
        return;
    }

    for (const auto& emp : employees) {
        file << emp.phone << " " << emp.kWt_month << " " << emp.time_day << " " << emp.Max_power_h << endl;
    }

    file.close();
}

void addEmployee() {
    cout << "#---------------------------------------------#" << endl;
    Employee emp;
    cout << "������ ����� ��������: ";
    cin >> emp.phone;
    cout << "������ ������� ��� � �����: ";
    cin >> emp.kWt_month;
    cout << "������ ������� ���� ��� ���� �����: ";
    cin >> emp.time_day;
    cout << "������ ����������� ��'��� ���: ";
    cin >> emp.Max_power_h;
    employees.push_back(emp);
    cout << "#---------------------------------------------#" << endl;
}

void editEmployee() {
    int phone;
    cout << "Enter phone of the employee to edit: ";
    cin >> phone;
    cout << "#---------------------------------------------#" << endl;
    for (auto& emp : employees) {
        if (emp.phone == phone) {
            cout << "  ������ ������� ��� � ����� ";
            cin >> emp.kWt_month;
            cout << "  ������ ������� ���� ��� ���� ����� ";
            cin >> emp.time_day;
            cout << "  ������ ����������� ��'��� ���: ";
            cin >> emp.Max_power_h;
            cout << "  ��� ������!" << endl;
            cout << "#---------------------------------------------#" << endl;
            return;
        }
    }

    cout << "Employee with phone " << phone << " �� ��������." << endl;
}

void searchEmployee() {
    system("cls");
    int phone;
    cout << "������ ����� �������� ��� ������: ";
    cin >> phone;
    cout << "#---------------------------------------------#" << endl;

    for (const auto& emp : employees) {
        if (emp.phone == phone) {
            cout << "�������: " << emp.phone << "\n"
                << "    ��� �����: " << emp.kWt_month << "\n"
                << "    ���� ����� � ����: " << emp.time_day << "\n"
                << "    ����������� ��'��� ���: " << emp.Max_power_h << endl;
            cout << "#---------------------------------------------#" << endl;
            p = emp.Max_power_h;
            a = double((emp.kWt_month / 30 * emp.time_day) / 24);
            if (a >= 0.0 && a <= 2) {
                cout << "  ������� 2 ��� �� 100�" << endl;
                cina = 7030 * 2;
                cout << "#---------------------------------------------#" << endl;
            }
            if (a > 2 && a <= 4) {
                cout << "   ������� 4 ��� �� 100�" << endl;
                cina = 7030 * 4;
                cout << "#---------------------------------------------#" << endl;
            }
            if (a > 5) {
                cout << "   ������� 6 ��� �� 100�" << endl;
                cina = 7030 * 6;
                cout << "#---------------------------------------------#" << endl;
            }

            if (p > 0.0 && p <= 1.0) {
                cout << "   ������� 5 ����� �� 580��" << endl;
                cina = cina + (5 * 5200) + 12000;
                cout << "#  ������� ��������   3,0 ���                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    ֳ�� ��������� - " << cina << " ���               #" << endl;
            }
            if (p > 1.0 && p <= 2.0) {
                cout << "   ������� 5 ������ �� 580��" << endl;
                cina = cina + (5 * 5200) + 12000;
                cout << "#  ������� ��������   3,0 ���                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    ֳ�� ��������� - " << cina << " ���               #" << endl;
            }
            if (p > 2.0 && p <= 3.0) {
                cout << "   ������� 8 ������ �� 580��" << endl;
                cina = cina + (10 * 5200) + 12000;
                cout << "#  ������� ��������   3,0 ���                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    ֳ�� ��������� - " << cina << " ���               #" << endl;
            }
            if (p > 3.0 && p <= 4.0) {
                cout << "   ������� 8 ������ �� 580��" << endl;
                cina = cina + (8 * 5200) + 17500;
                cout << "#  ������� ��������   4,5 ���                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    ֳ�� ��������� - " << cina << " ���               #" << endl;
            }
            if (p > 4.0 && p <= 5.0) {
                cout << "   ������� 12 ������ �� 580��" << endl;
                cina = cina + (12 * 5200) + 175000;
                cout << "#  ������� ��������   4,5 ���                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    ֳ�� ��������� - " << cina << " ���               #" << endl;
            }
            if (p > 5.0) {
                cout << "   �� ������� ��������� ���������" << endl;
                cout << "#---------------------------------------------#" << endl;
            }

            return;
        }
    }

    cout << "������� " << phone << " �� ��������." << endl;
}

void displayAllEmployees() {
    cout << "#---------------------------------------------#" << endl;
    cout << "������ ��� �볺���:" << endl;
    for (const auto& emp : employees) {
        cout << "�������: " << emp.phone << "\n"
            << "    ��� �����: " << emp.kWt_month << "\n"
            << "    ���� ����� � ����: " << emp.time_day << "\n"
            << "    ����������� ��'��� ���: " << emp.Max_power_h << endl;
        cout << "#---------------------------------------------#" << endl;
    }
}

int main() {
    const string filename = "input.txt";
    loadFromFile(filename);

    int choice;
    cout << "��������� ��� ���������� ������� �������� �������" << endl;
    do {
        cout << "1. ������ ������\n"
            << "2. ���������� ������\n"
            << "3. ����� �� ���������� �������\n"
            << "4. ³��������� ��� �볺���\n"
            << "5. �������� �� �����\n"
            << "������� ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            editEmployee();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            displayAllEmployees();
            break;
        case 5:
            saveToFile(filename);
            cout << "��������� � ����:  " << endl;
            cout << "#---------------------------------------------#" << endl;
            break;
        default:
            cout << "�� ����� ����� 䳿 ������� �����" << endl;
            cout << "#---------------------------------------------#" << endl;
        }
        _getch();
    } while (choice != 5);

    return 0;
}