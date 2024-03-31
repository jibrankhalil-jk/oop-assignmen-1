#include <iostream>
#include <string>

using namespace std;

enum VehicleType
{
    Suv = 1,
    Sedan
};

class AutonomousVehicle
{
protected:
    int id;
    VehicleType type;
    int battery_capacity;
    int maximum_speed;

public:
    AutonomousVehicle(){};
    AutonomousVehicle(int id, VehicleType type, int battery_capacity, int maximum_speed) : id(id), type(type), battery_capacity(battery_capacity), maximum_speed(maximum_speed){};

    // getters
    int getId() { return id; }
    VehicleType getType() { return type; }
    int getBatteryCapacity() { return battery_capacity; }
    int getMaxSpeed() { return maximum_speed; }

    // setters
    void setId(int id) { id = id; }
    void setType(VehicleType type) { type = type; }
    void setBatteryCapacity(int cap) { battery_capacity = cap; }
    void setMaxSpeed(int mxs) { maximum_speed = mxs; }

    // shallow copy
    //  AutonomousVehicle(const AutonomousVehicle &other)
    //  {
    //      cout << "shallow copy" << endl;
    //      id = other.id;
    //      type = other.type;
    //      battery_capacity = other.battery_capacity;
    //      maximum_speed = other.maximum_speed;
    //  }

    // deep copy
    AutonomousVehicle(const AutonomousVehicle &vehical)
    {
        id = *(new int(vehical.id));
        type = *(new VehicleType(vehical.type));
        battery_capacity = *(new int(vehical.battery_capacity));
        maximum_speed = *(new int(vehical.maximum_speed));
    }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "Type : " << type << "\t\t(" << &type << ") " << endl;
        cout << "Battery Capacity : " << battery_capacity << "\t(" << &battery_capacity << ")" << endl;
        cout << "Max speed : " << maximum_speed << "m/s\t(" << &maximum_speed << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    };
};

class Sedan : protected AutonomousVehicle
{
public:
    Sedan(int id, int battery_capacity, int maximum_speed)
        : AutonomousVehicle(id, VehicleType::Sedan, battery_capacity, maximum_speed){};
};

class Suv : protected AutonomousVehicle
{
    Suv(int id, int battery_capacity, int maximum_speed)
        : AutonomousVehicle(id, VehicleType::Suv, battery_capacity, maximum_speed){};
};

int main()
{
    cout << "\n------------------------ Shallow Copy ------------------------\n";
    // shallow copy
    AutonomousVehicle a1(1, Suv, 20, 30);
    a1.display();
    AutonomousVehicle *b1;
    // AutonomousVehicle *b1(&a1);
    b1 = &a1;
    b1->display();
    a1.setMaxSpeed(3000);
    a1.display();
    b1->display();
    cout << "\n------------------------ Deep Copy ------------------------\n";
    // deep copy
    AutonomousVehicle *c = new AutonomousVehicle(1, Suv, 20, 30);
    c->display();
    AutonomousVehicle d(*c); // deep copy constructor
    d.display();
    c->setMaxSpeed(3000);
    c->display();
    d.display();



    return 0;
}