#include <iostream>
#include <string>

using namespace std;

enum VehicleType
{
    Suv_Type = 1,
    Sedan_Type
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
    // AutonomousVehicle(const AutonomousVehicle &vehical)
    // {
    //     id = *(new int(vehical.id));
    //     type = *(new VehicleType(vehical.type));
    //     battery_capacity = *(new int(vehical.battery_capacity));
    //     maximum_speed = *(new int(vehical.maximum_speed));
    // }

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
    Sedan(){};
    Sedan(int id, int battery_capacity, int maximum_speed)
        : AutonomousVehicle(id, VehicleType::Sedan_Type, battery_capacity, maximum_speed){};

    // deep copy
    Sedan(const Sedan &vehical)
    {
        id = *(new int(vehical.id));
        type = *(new VehicleType(vehical.type));
        battery_capacity = *(new int(vehical.battery_capacity));
        maximum_speed = *(new int(vehical.maximum_speed));
    }

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

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "Type : ";
        switch (type)
        {
        case Sedan_Type:
            cout << "Sedan";
            break;
        case Suv_Type:
            cout << "Sedan";
            break;
        }
        cout << "\t\t(" << &type << ") " << endl;
        cout << "Battery Capacity : " << battery_capacity << "\t(" << &battery_capacity << ")" << endl;
        cout << "Max speed : " << maximum_speed << "m/s\t(" << &maximum_speed << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    };
};

class Suv : protected AutonomousVehicle
{
public:
    Suv(){};
    Suv(int id, int battery_capacity, int maximum_speed)
        : AutonomousVehicle(id, VehicleType::Suv_Type, battery_capacity, maximum_speed){};

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

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "Type : ";
        switch (type)
        {
        case Sedan_Type:
            cout << "Sedan";
            break;
        case Suv_Type:
            cout << "Sedan";
            break;
        }
        cout << "\t\t(" << &type << ") " << endl;
        cout << "Battery Capacity : " << battery_capacity << "\t(" << &battery_capacity << ")" << endl;
        cout << "Max speed : " << maximum_speed << "m/s\t(" << &maximum_speed << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    };
};

int main()
{
    Sedan a(1, 20, 30);
    cout << "=> A" << endl
         << endl;
    a.display();
    Sedan *b;

    cout << "\n------ Creating Object using Shallow Copy ------" << endl;
    b = &a; //  shallow copy
    cout << "\n------ Creating Object using Deep Copy ------" << endl
         << endl;
    Sedan c(a); // deep copy constructor

       cout << "=> B (Shallow Copy Object)" << endl
         << endl;
    b->display();
    cout << "=> C (Deep Copy Object)" << endl
         << endl;
    c.display();

    cout << "changing the maximum speed of original object" << endl
         << endl;
    a.setMaxSpeed(3000);
    cout << "=> A (Origianl Object)" << endl
         << endl;
    a.display();
    cout << "=> B (Shallow Copy Object)" << endl
         << endl;
    b->display();
    cout << "=> C (Deep Copy Object)" << endl
         << endl;
    c.display();

    return 0;
}