#include <iostream>
#include <string>

using namespace std;

class AutonomousVehicle
{
protected:
    int id;
    string vehicleType;
    int batteryCapacity;
    int maxSpeed;

public:
    AutonomousVehicle(){};
    AutonomousVehicle(int id, string vehicleType, int batteryCapacity, int maxSpeed) : id(id), vehicleType(vehicleType), batteryCapacity(batteryCapacity), maxSpeed(maxSpeed){};

    int getId() { return id; }
    string getvehicleType() { return vehicleType; }
    int getBatteryCapacity() { return batteryCapacity; }
    int getMaxSpeed() { return maxSpeed; }

    // setters
    void setid(int id) { this->id = id; }
    void settype(string vehicleType) { this->vehicleType = vehicleType; }
    void setbatteryCapacity(int cap) { this->batteryCapacity = cap; }
    void setmaxSpeed(int mxs) { this->maxSpeed = mxs; }

    // shallow copy
    //  AutonomousVehicle(const AutonomousVehicle &other)
    //  {
    //      cout << "shallow copy" << endl;
    //      id = other.id;
    //      vehicleType = other.vehicleType;
    //      batteryCapacity = other.batteryCapacity;
    //      maxSpeed = other.maxSpeed;
    //  }

    // deep copy
    // AutonomousVehicle(const AutonomousVehicle &vehical)
    // {
    //     id = *(new int(vehical.id));
    //     vehicleType = *(new VehiclevehicleType(vehical.vehicleType));
    //     batteryCapacity = *(new int(vehical.batteryCapacity));
    //     maxSpeed = *(new int(vehical.maxSpeed));
    // }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "vehicleType : " << vehicleType << "\t\t(" << &vehicleType << ") " << endl;
        cout << "Battery Capacity : " << batteryCapacity << "\t(" << &batteryCapacity << ")" << endl;
        cout << "Max speed : " << maxSpeed << "m/s\t(" << &maxSpeed << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    };
};

class Sedan : protected AutonomousVehicle
{
public:
    Sedan(){};
    Sedan(int id, int batteryCapacity, int maxSpeed)
        : AutonomousVehicle(id, VehiclevehicleType::VehicleSedan, batteryCapacity, maxSpeed){};

    // deep copy
    Sedan(const Sedan &vehical)
    {
        id = *(new int(vehical.id));
        vehicleType = *(new VehiclevehicleType(vehical.vehicleType));
        batteryCapacity = *(new int(vehical.batteryCapacity));
        maxSpeed = *(new int(vehical.maxSpeed));
    }

    // getters
    int getId() { return id; }
    string getvehicleType() { return vehicleType; }
    int getBatteryCapacity() { return batteryCapacity; }
    int getMaxSpeed() { return maxSpeed; }

    // setters
    void setId(int id) { id = id; }
    void setvehicleType(string vehicleType) { vehicleType = vehicleType; }
    void setBatteryCapacity(int cap) { batteryCapacity = cap; }
    void setMaxSpeed(int mxs) { maxSpeed = mxs; }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "vehicleType : " << vehicleType << "\t\t(" << &vehicleType << ") " << endl;
        cout << "Battery Capacity : " << batteryCapacity << "\t(" << &batteryCapacity << ")" << endl;
        cout << "Max speed : " << maxSpeed << "m/s\t(" << &maxSpeed << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    };
};

class Suv : protected AutonomousVehicle
{
public:
    Suv(){};
    Suv(int id, int batteryCapacity, int maxSpeed)
        : AutonomousVehicle(id, "Suv", batteryCapacity, maxSpeed){};

    // getters
    int getId() { return id; }
    string getvehicleType() { return vehicleType; }
    int getBatteryCapacity() { return batteryCapacity; }
    int getMaxSpeed() { return maxSpeed; }

    // setters
    void setId(int id) { id = id; }
    void setvehicleType(VehiclevehicleType vehicleType) { vehicleType = vehicleType; }
    void setBatteryCapacity(int cap) { batteryCapacity = cap; }
    void setMaxSpeed(int mxs) { maxSpeed = mxs; }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Id : " << id << "\t\t\t(" << &id << ")" << endl;
        cout << "vehicleType : ";
        switch (vehicleType)
        {
        case VehicleSedan:
            cout << "Sedan";
            break;
        case VehicleSuv:
            cout << "Sedan";
            break;
        }
        cout << "\t\t(" << &vehicleType << ") " << endl;
        cout << "Battery Capacity : " << batteryCapacity << "\t(" << &batteryCapacity << ")" << endl;
        cout << "Max speed : " << maxSpeed << "m/s\t(" << &maxSpeed << ")" << endl;
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
    // b = &a; //  shallow copy
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