#include <iostream>
#include <string>

using namespace std;

enum RoboType
{
    Industrial,
    Humanoid,
    Aerial
};
enum PowerSource
{
    Battery,
    Solar,
    Fuel
};

class Robot
{

    int uid;
    RoboType type;           // (industrial, humanoid, aerial)
    PowerSource powerSource; // (battery, solar, fuel)
    int maximum_Speed;       // (in meters per second)
    double Weight;           // (in kilograms)
};

int main()
{

    cout << "sfsadf";

    return 0;
}