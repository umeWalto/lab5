#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base\n"; }
    Base(Base&) { cout << "copy Base\n"; }
    virtual ~Base() { cout << "~Base\n"; }
};

class Desc : public Base {
public:
    Desc() { cout << "Desc\n"; }
    Desc(Desc&) { cout << "copy Desc\n"; }
    ~Desc() { cout << "~Desc\n"; }
};

void f1(Base b) { cout << "by value\n"; }
void f2(Base* b) { cout << "by pointer\n"; }
void f3(Base& b) { cout << "by ref\n"; }

void run4() {
    cout << "\n[มหฮส 4]\n";

    Desc d;

    f1(d);
    f2(&d);
    f3(d);
}