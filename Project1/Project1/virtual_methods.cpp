#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base ctor\n"; }
    virtual ~Base() { cout << "Base dtor\n"; }

    void method1() {
        cout << "Base::method1\n";
        method2();
        method3();
    }

    void method2() {
        cout << "Base::method2\n";
    }

    virtual void method3() {
        cout << "Base::method3\n";
    }
};

class Desc : public Base {
public:
    Desc() { cout << "Desc ctor\n"; }
    ~Desc() { cout << "Desc dtor\n"; }

    void method2() {
        cout << "Desc::method2\n";
    }

    void method3() override {
        cout << "Desc::method3\n";
    }
};

void run1() {
    cout << "\n[มหฮส 1]\n";

    Base* obj = new Desc();

    obj->method1();
    obj->method3();

    delete obj;
}