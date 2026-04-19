#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "virtual_methods.cpp"

// =========================
// БЛОК 2
// =========================
class Base2 {
public:
    void show() {
        cout << "Base2::show\n";
    }
};

class Desc2 : public Base2 {
public:
    void show() {
        cout << "Desc2::show\n";
    }
};

void run2() {
    cout << "\n=== БЛОК 2: перекрытие без virtual ===\n";

    Desc2 d;
    Base2* pb = &d;
    Desc2* pd = &d;

    cout << "Base2*: ";
    pb->show();

    cout << "Desc2*: ";
    pd->show();
}

// =========================
// БЛОК 3
// =========================
class Base3 {
public:
    virtual string classname() { return "Base3"; }

    virtual bool isA(string name) {
        return name == "Base3";
    }

    virtual ~Base3() {}
};

class Desc3 : public Base3 {
public:
    string classname() override { return "Desc3"; }

    bool isA(string name) override {
        return name == "Desc3" || Base3::isA(name);
    }

    void special() {
        cout << "Desc3::special\n";
    }
};

void run3() {
    cout << "\n=== БЛОК 3: classname / isA / приведения типов ===\n";

    Base3* obj = new Desc3();

    cout << "classname: " << obj->classname() << endl;

    cout << "isA Desc3: " << obj->isA("Desc3") << endl;

    Desc3* d = dynamic_cast<Desc3*>(obj);
    if (d) d->special();

    Base3* fake = new Base3();
    Desc3* bad = (Desc3*)fake;

    cout << "Выполнено небезопасное приведение типов\n";

    delete obj;
    delete fake;
}

// =========================
// БЛОК 4
// =========================
class Base4 {
public:
    Base4() { cout << "Base4()\n"; }
    Base4(Base4&) { cout << "Base4 copy\n"; }
    virtual ~Base4() { cout << "~Base4()\n"; }
};

class Desc4 : public Base4 {
public:
    Desc4() { cout << "Desc4()\n"; }
    Desc4(Desc4&) { cout << "Desc4 copy\n"; }
    ~Desc4() { cout << "~Desc4()\n"; }
};

void func1(Base4 obj) { cout << "func1 (value)\n"; }
void func2(Base4* obj) { cout << "func2 (ptr)\n"; }
void func3(Base4& obj) { cout << "func3 (ref)\n"; }

void run4() {
    cout << "\n=== БЛОК 4: передача параметров ===\n";

    Desc4 d;

    func1(d);
    func2(&d);
    func3(d);
}

// =========================
// БЛОК 5
// =========================
class Base5 {
public:
    Base5() { cout << "Base5()\n"; }
    Base5(const Base5&) { cout << "Base5 copy\n"; }
    ~Base5() { cout << "~Base5()\n"; }
};

Base5 funcA() {
    static Base5 obj;
    return obj;
}

Base5* funcB() {
    static Base5 obj;
    return &obj;
}

Base5& funcC() {
    static Base5 obj;
    return obj;
}

Base5 funcD() {
    return *(new Base5());
}

Base5* funcE() {
    return new Base5();
}

Base5& funcF() {
    return *(new Base5());
}

void run5() {
    cout << "\n=== БЛОК 5: возврат объектов ===\n";

    Base5 a = funcA();
    Base5* b = funcB();
    Base5& c = funcC();

    Base5 d = funcD();

    Base5* e = funcE();
    delete e;

    Base5& f = funcF();
}

// =========================
// БЛОК 6
// =========================
class Test {
public:
    Test() { cout << "Test создан\n"; }
    ~Test() { cout << "Test уничтожен\n"; }
};

void run6() {
    cout << "\n=== БЛОК 6: умные указатели ===\n";

    cout << "unique_ptr:\n";
    {
        unique_ptr<Test> p1 = make_unique<Test>();
    }

    cout << "\nshared_ptr:\n";
    {
        shared_ptr<Test> p1 = make_shared<Test>();
        cout << "count = " << p1.use_count() << endl;

        {
            shared_ptr<Test> p2 = p1;
            cout << "count = " << p1.use_count() << endl;
        }

        cout << "count = " << p1.use_count() << endl;
    }
}

// =========================
// MAIN МЕНЮ
// =========================
int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    
    do {
        cout << "\n=============================\n";
        cout << "Лабораторная работа 5\n";
        cout << "1 - Виртуальные методы\n";
        cout << "2 - Перекрытие без virtual\n";
        cout << "3 - classname / isA / cast\n";
        cout << "4 - Передача параметров\n";
        cout << "5 - Возврат объектов\n";
        cout << "6 - Умные указатели\n";
        cout << "0 - Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: run1(); break;
        case 2: run2(); break;
        case 3: run3(); break;
        case 4: run4(); break;
        case 5: run5(); break;
        case 6: run6(); break;
        case 0: cout << "Выход\n"; break;
        default: cout << "Неверный выбор\n";
        }

    } while (choice != 0);
}