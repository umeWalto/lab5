#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual string classname() { return "Base"; }
    virtual bool isA(string n) { return n == "Base"; }
    virtual ~Base() {}
};

class Desc : public Base {
public:
    string classname() override { return "Desc"; }

    bool isA(string n) override {
        return n == "Desc" || Base::isA(n);
    }

    void special() {
        cout << "Desc method\n";
    }
};

void run3() {
    cout << "\n[ÁËÎÊ 3]\n";

    Base* obj = new Desc();

    cout << obj->classname() << endl;
    cout << obj->isA("Desc") << endl;

    Desc* d = dynamic_cast<Desc*>(obj);
    if (d) d->special();

    Base* fake = new Base();
    Desc* bad = (Desc*)fake;

    cout << "unsafe cast âûïîëíåí\n";

    delete obj;
    delete fake;
}