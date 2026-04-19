#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Конструктор Base\n"; }
    virtual ~Base() { cout << "Деструктор Base\n"; }

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
    Desc() { cout << "Конструктор Desc\n"; }
    ~Desc() { cout << "Деструктор Desc\n"; }

    void method2() {
        cout << "Desc::method2\n";
    }

    void method3() override {
        cout << "Desc::method3\n";
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    cout << "Создаём объект Desc через указатель на Base\n";
    Base* obj = new Desc();

    cout << "\nВызываем method1 (внутри вызываются method2 и method3)\n";
    obj->method1();

    cout << "\nВызываем method2 через Base*\n";
    obj->method2();

    cout << "\nВызываем method3 через Base*\n";
    obj->method3();

    cout << "\nУдаляем объект\n";
    delete obj;
}