#include <iostream>
#include <string>

using namespace std;

class Robot
{

private:
    int id;
    string type;        // (industrial, humanoid, aerial)
    string powerSource; // (battery, solar, fuel)
    int maximum_Speed;  // (in meters per second)
    double weight;      // (in kilograms)

public:
    Robot() {};
    Robot(int id, string type, string powerSource, int maximum_Speed, double Weight) : id(id), type(type), powerSource(powerSource), maximum_Speed(maximum_Speed), weight(Weight){};

    // distructor
    ~Robot() {}

    // shallow copy
    // Robot(const Robot &robo)
    // {
    //     this->id = robo.id;
    //     this->type = robo.type;
    //     this->powerSource = robo.powerSource;
    //     this->maximum_Speed = robo.maximum_Speed;
    //     this->weight = robo.weight;
    // }
    // {
    //     cout << "shallow copy applied" << endl;
    //     this->id = robo.id;
    //     this->type = robo.type;
    //     this->powerSource = robo.powerSource;
    //     this->maximum_Speed = robo.maximum_Speed;
    //     this->weight = robo.weight;
    // }

    // deep copy constructor
    // Robot(Robot &&robo)
    // {
    //     cout << "deep copy applied" << endl;
    //     this->id = robo.id;
    //     this->type = robo.type;
    //     this->powerSource = robo.powerSource;
    //     this->maximum_Speed = robo.maximum_Speed;
    //     this->weight = robo.weight;
    // }

    // Assignment operator for shallow copy
    // Robot &operator=(const Robot &robo)
    // {
    //     if (this != &robo)
    //     {
    //         id = robo.id;
    //         type = robo.type;
    //         powerSource = robo.powerSource;
    //         maximum_Speed = robo.maximum_Speed;
    //         weight = robo.weight;
    //     }
    //     return *this;
    // }

    // // Assignment operator for deep copy
    // Robot &operator=(Robot &&robo)
    // {
    //     if (this != &robo)
    //     {
    //         id = move(robo.id);
    //         type = move(robo.type);
    //         powerSource = move(robo.powerSource);
    //         maximum_Speed = move(robo.maximum_Speed);
    //         weight = move(robo.weight);
    //     }
    //     return *this;
    // }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Robot id : " << id << "\t\t(" << &id << ")" << endl;
        cout << "Type : " << type << "\t\t(" << &type << ") " << endl;
        cout << "Power source : " << powerSource << "\t(" << &powerSource << ")" << endl;
        cout << "Max speed : " << maximum_Speed << "m/s\t(" << &maximum_Speed << ")" << endl;
        cout << "Weight : " << weight << "kg\t\t(" << &weight << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    }
};

int main()
{
    Robot robs(1, "Aereal", "Battery", 200, 20.2);

    robs.display();

    Robot a;

    a = robs;

    // Robot a(move(robs));

    a.display();

    return 0;
}