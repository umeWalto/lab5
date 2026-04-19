#include <iostream>
using namespace std;

void run1();
void run2();

int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "\n===== лаборатрная работа 5 =====\n";
        cout << "1 - Виртуальные методы\n";
        cout << "2 - Невиртуальное перекрытие\n";
        cout << "0 - Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: run1(); break;
        case 2: run2(); break;
        case 0: cout << "Выход\n"; break;
        }

    } while (choice != 0);
}