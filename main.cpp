﻿#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <conio.h>

using namespace std;


double a = 0;
double p = 0;
int cina = 0;
int s; // кількість часів світлового дня
int h; // часів відключення світла в добі по замовчанню розраховується доба
double pdoba; // потужність приладів яки працюють цілодобово
int pden; //потужніть приладів яки працюють короткочасно в день(болер пральна машинка кухонні прилади)

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
        cerr << "Не можу відкрити файл: " << filename << endl;
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
        cerr << "Не можу видкрити: " << filename << endl;
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
    cout << "Введіть номер телефону: ";
    cin >> emp.phone;
    cout << "Введіть кількість кВт в місяць: ";
    cin >> emp.kWt_month;
    cout << "Введіть кількість часу яку немає світла: ";
    cin >> emp.time_day;
    cout << "Введіть найпотужний об'єкт кВт: ";
    cin >> emp.Max_power_h;
    employees.push_back(emp);
    cout << "#---------------------------------------------#" << endl;
}

void editEmployee() {
    int phone;
    cout << "Введіть номер для редагування кліента: ";
    cin >> phone;
    cout << "#---------------------------------------------#" << endl;
    for (auto& emp : employees) {
        if (emp.phone == phone) {
            cout << "  Введіть кількість кВт в місяць ";
            cin >> emp.kWt_month;
            cout << "  Введіть кількість часу яку немає світла ";
            cin >> emp.time_day;
            cout << "  Введіть найпотужний об'єкт кВт: ";
            cin >> emp.Max_power_h;
            cout << "  Дані внесені!" << endl;
            cout << "#---------------------------------------------#" << endl;
            return;
        }
    }

    cout << "Employee with phone " << phone << " не знайдено." << endl;
}

void searchEmployee() {
    system("cls");
    int phone;
    cout << "Введіть номер телефону для пошуку: ";
    cin >> phone;
    cout << "#---------------------------------------------#" << endl;

    for (const auto& emp : employees) {
        if (emp.phone == phone) {
            cout << "Телефон: " << emp.phone << "\n"
                << "    кВт місяць: " << emp.kWt_month << "\n"
                << "    немає світла в день: " << emp.time_day << "\n"
                << "    Найпотужний об'ект кВт: " << emp.Max_power_h << endl;
            cout << "#---------------------------------------------#" << endl;
            cout << "введить кількість активного сонця -  ";
            cin >> s;
            cout << "Введіть середнью потужність приладів яки працюють цілодобово - ";
            cin >> pdoba;
            cout << "Введіть кількість годин відключення світла в добі -  ";
            cin >> h;
            p = (emp.kWt_month - (pdoba * 24)) / 31 / s + emp.Max_power_h;
            cout << "середня потужність інвертора -  " << p << endl;
            a = double(pdoba * 24) / s;
            cout << "#---------------------------------------------#" << endl;
            cout <<"потрібна ємність аккумулятора кВт - " << a << endl;
            cout << "#---------------------------------------------#" << endl;
            if (a >= 0.0 && a <= 2) {
                cout << "  Потрібно 2 12в акб по 100А" << endl;
                cina = 23030 * 2;
                cout << "#---------------------------------------------#" << endl;
            }
            if (a > 2 && a <= 4) {
                cout << "   Потрібно 4 12в акб по 100А" << endl;
                cina = 23030 * 4;
                cout << "#---------------------------------------------#" << endl;
            }
            if (a > 5) {
                cout << "   Потрібно 6 12в акб по 100А" << endl;
                cina = 23030 * 6;
                cout << "#---------------------------------------------#" << endl;
            }

            if (p > 0.0 && p <= 1.0) {
                cout << "   Потрібно 5 модулі по 580Вт" << endl;
                cina = cina + (5 * 5200) + 12000;
                cout << "#  Потрібен інвертор   3,0 кВт                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    Ціна комплекту - " << cina << " Грн               #" << endl;
            }
            if (p > 1.0 && p <= 2.0) {
                cout << "   Потрібно 5 модулів по 580Вт" << endl;
                cina = cina + (5 * 5200) + 12000;
                cout << "#  Потрібен інвертор   3,0 кВт                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    Ціна комплекту - " << cina << " Грн               #" << endl;
            }
            if (p > 2.0 && p <= 3.0) {
                cout << "   Потрібно 8 модулів по 580Вт" << endl;
                cina = cina + (10 * 5200) + 12000;
                cout << "#  Потрібен інвертор   3,0 кВт                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    Ціна комплекту - " << cina << " Грн               #" << endl;
            }
            if (p > 3.0 && p <= 4.0) {
                cout << "   Потрібно 8 модулів по 580Вт" << endl;
                cina = cina + (8 * 5200) + 17500;
                cout << "#  Потрібен інвертор   4,5 кВт                #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    Ціна комплекту - " << cina << " Грн               #" << endl;
            }
            if (p > 4.0 && p <= 5.0) {
                cout << "   Потрібно 12 модулів по 580Вт" << endl;
                cina = cina + (12 * 5200) + 17500;
                cout << "#  Потрібен інвертор   4,5 кВт!               #" << endl;
                cout << "#---------------------------------------------#" << endl;
                cout << "#    Ціна комплекту - " << cina << " Грн               #" << endl;
            }
            if (p > 5.0) {
                cout << "   на данному обладнанні неможливо" << endl;
                cout << "#---------------------------------------------#" << endl;
            }

            return;
        }
    }

    cout << "Телефон " << phone << " не знайдено." << endl;
}

void displayAllEmployees() {
    cout << "#---------------------------------------------#" << endl;
    cout << "Список всіх клієнтів:" << endl;
    for (const auto& emp : employees) {
        cout << "Телефон: " <<setw(30)<< emp.phone << "\n";  //setw(30) відступ від останнього символу вирівнювання по правому краю
        cout << "кВт місяць: " << setw(27) << emp.kWt_month << "\n";
        cout << "немає світла в день: " << setw(18) << emp.time_day << "\n";
        cout << "Найпотужний об'єкт кВт: " << setw(15) << emp.Max_power_h << endl;
        cout << "#---------------------------------------------#" << endl;
    }
}

int main() {
    const string filename = "input.txt";
    loadFromFile(filename);

    int choice;
    cout << "Программа для розрахунку вартості сонячной станції" << endl;
    do {
        cout << "1. Додати кліента\n"
            << "2. Редагувати кліента\n"
            << "3. Пошук та розрахунок станції\n"
            << "4. Відобразити всіх клієнтів\n"
            << "5. Зберигти та вийти\n"
            << "Виберіть дію: ";
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
            cout << "Збережено у файл:  " << endl;
            cout << "#---------------------------------------------#" << endl;
            break;
        default:
            cout << "Не вірний номер дії виберіть знову" << endl;
            cout << "#---------------------------------------------#" << endl;
        }
        _getch();
    } while (choice != 5);

    return 0;
}