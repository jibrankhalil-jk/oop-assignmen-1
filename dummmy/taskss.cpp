#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    int apple;
    int box;
    int *s;

    A(){};
    A(int apple, int box)
    {
        this->apple = apple;
        this->box = box;
        // s = &box;
    }

    void display()
    {
        cout << endl;
        cout << "apple : " << apple << endl;
        cout << "box : " << box << endl;
        cout << "s : " << s << endl;
    }
};

int main()
{

    A c(10, 20);
    c.display();

    A d;
    d = c;

    d.display();

    // c.apple = 22;
    // c.box = 22;
    // // *c.s = 3;

    

    c.display();
    d.display();

    cout<< (&c.apple) <<endl;
    cout<< (&d.apple) <<endl;

    return 0;
}