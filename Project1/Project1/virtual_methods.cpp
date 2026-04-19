#include <iostream>
#include <memory>
#include <string>
using namespace std;

// =========================
// БЛОК 1
// =========================
class Base1 {
public:
    Base1() { cout << "Base1: конструктор\n"; }
    virtual ~Base1() { cout << "Base1: деструктор\n"; }

    void method1() {
        cout << "Base1::method1\n";
        method2();
        method3();
    }

    void method2() {
        cout << "Base1::method2\n";
    }

    virtual void method3() {
        cout << "Base1::method3\n";
    }
};

class Desc1 : public Base1 {
public:
    Desc1() { cout << "Desc1: конструктор\n"; }
    ~Desc1() { cout << "Desc1: деструктор\n"; }

    void method2() {
        cout << "Desc1::method2\n";
    }

    void method3() override {
        cout << "Desc1::method3\n";
    }
};

void run1() {
    cout << "\n=== БЛОК 1: виртуальные и невиртуальные методы ===\n";
    Base1* obj = new Desc1();

    cout << "Вызов method1:\n";
    obj->method1();

    cout << "Удаление объекта:\n";
    delete obj;
}