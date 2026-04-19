#include <iostream>
using namespace std;

void run1();
void run2();
void run3();
void run4();

int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "\n===== лаборатрная работа 5 =====\n";
        cout << "1 - Виртуальные методы\n";
        cout << "2 - Невиртуальное перекрытие\n";
        cout << "3 - classname / isA / cast\n";
        cout << "4 - Передача параметров\n";
        cout << "0 - Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: run1(); break;
        case 2: run2(); break;
        case 3: run3(); break;
        case 4: run4(); break;
        case 0: cout << "Выход\n"; break;
        }

    } while (choice != 0);
}