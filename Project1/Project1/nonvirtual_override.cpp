#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base\n";
    }
};

class Desc : public Base {
public:
    void show() {
        cout << "Desc\n";
    }
};

void run2() {
    cout << "\n[มหฮส 2]\n";

    Desc d;

    Base* pb = &d;
    Desc* pd = &d;

    pb->show();
    pd->show();
}