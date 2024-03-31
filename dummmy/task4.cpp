#include <iostream>
#include <string>

using namespace std;

enum RoboType
{
    Industrial = 1,
    Humanoid,
    Aerial
};
enum PowerSource
{
    Battery = 1,
    Solar,
    Fuel
};

class Robot
{
private:
    int id;
    RoboType type;           // (industrial, humanoid, aerial)
    PowerSource powerSource; // (battery, solar, fuel)
    int maximum_Speed;       // (in meters per second)
    double weight;           // (in kilograms)

public:
    Robot() {}
    Robot(int id, RoboType type, PowerSource powerSource, int maximum_Speed, double Weight) : id(id), type(type), powerSource(powerSource), maximum_Speed(maximum_Speed), weight(Weight){};

    // distructor
    ~Robot() {}

    // shallow copy
    Robot(const Robot& other) = default;
    // Robot(const Robot &robo)
    // // id(robo.id),
    // //                            type(robo.type),
    // //                            powerSource(robo.powerSource),
    // //                            maximum_Speed(robo.maximum_Speed),
    // //                            weight(robo.weight)
    // {
    //     cout << "shallow copy applied" << endl;
    //     this->id = (robo.id);
    //     this->type = move(robo.type);
    //     this->powerSource = move(robo.powerSource);
    //     this->maximum_Speed = (robo.maximum_Speed);
    //     this->weight = (robo.weight);
    // }

    // deep copy constructor
    Robot(Robot &&robo)
    {
        cout << "deep copy applied" << endl;
        this->id = move(robo.id);
        this->type = move(robo.type);
        this->powerSource = move(robo.powerSource);
        this->maximum_Speed = move(robo.maximum_Speed);
        this->weight = move(robo.weight);
    }

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
        cout << "Type : ";
        switch (type)
        {
        case (RoboType::Aerial):
            cout << "Aerial";
            break;
        case (RoboType::Humanoid):
            cout << "Humanoid";
            break;
        case (RoboType::Industrial):
            cout << "Industrial";
            break;
        }
        cout << "\t\t(" << &type << ")" << endl;
        cout << "Power source : ";
        switch (powerSource)
        {
        case (PowerSource::Battery):
            cout << "Battery";
            break;
        case (PowerSource::Fuel):
            cout << "Fuel";
            break;
        case (PowerSource::Solar):
            cout << "Solar";
            break;
        }
        cout << "\t(" << &powerSource << ")" << endl;
        cout << "Max speed : " << maximum_Speed << "m/s\t(" << &maximum_Speed << ")" << endl;
        cout << "Weight : " << weight << "kg\t\t(" << &weight << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    }
};

int main()
{
    Robot robs(1, RoboType::Aerial, PowerSource::Battery, 200, 20.2);

    robs.display();

    Robot a(robs);
    // Robot a(move(robs));

    a.display();
    return 0;
}