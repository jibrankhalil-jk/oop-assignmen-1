#include <iostream>
#include <string>

using namespace std;

int totalsize = 1;

class Robot
{

private:
    int *id;
    string *type;        // (industrial, humanoid, aerial)
    string *powerSource; // (battery, solar, fuel)
    int *maximum_Speed;  // (in meters per second)
    double *weight;      // (in kilograms)

public:
    Robot(){};
    Robot(int id, string type, string powerSource, int maximum_Speed, double weight) : id(&id), type(&type), powerSource(&powerSource), maximum_Speed(&maximum_Speed), weight(&weight){};
    // distructor
    ~Robot() {}

    // setters
    void set_id(int &id) { this->id = &id; };
    void set_type(string &type) { this->type = &type; };
    void set_powerSource(string &powerSource) { this->powerSource = &powerSource; };
    void set_maximum_Speed(int &maximum_Speed) { this->maximum_Speed = &maximum_Speed; };
    void set_weight(double weight) { this->weight = &weight; };

    // getters
    int get_id() { return *id; };
    string get_type() { return *type; };
    string get_powerSource() { return *powerSource; };
    int get_maximum_Speed() { return *maximum_Speed; };
    double get_weight() { return *weight; };

    // shallow copy
    void shallow_copy(const Robot &robo)
    {
        cout << "shallow copy applied" << endl;
        *id = *robo.id;
        *type = *robo.type;
        *powerSource = *robo.powerSource;
        *maximum_Speed = *robo.maximum_Speed;
        *weight = *robo.weight;
    }

    // deep copy constructor
    void deep_copy(Robot &robo)
    {
        cout << "deep copy applied" << endl;
        id = new int(*robo.id);
        type = new string(*robo.type);
        powerSource = new string(*robo.powerSource);
        maximum_Speed = new int(*robo.maximum_Speed);
        weight = new double(*robo.weight);
    }

    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Robot id : " << *id << "\t\t(" << &id << ")" << endl;
        cout << "Type : " << *type << "\t\t(" << &type << ") " << endl;
        cout << "Power source : " << *powerSource << "\t(" << &powerSource << ")" << endl;
        cout << "Max speed : " << *maximum_Speed << "m/s\t(" << &maximum_Speed << ")" << endl;
        cout << "Weight : " << *weight << "kg\t\t(" << &weight << ")" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
    }
};

int main()
{
    Robot robots[3];

    robots[0] = Robot(1, "humanoid", "solar", 100, 1.11);

    // robots[0].set_weight(22.2);
    robots[0].display();

    robots[1].shallow_copy(robots[0]);
    robots[2].deep_copy(robots[0]);

    for (int i = 1; i < 3; i++)
    {
        robots[i].display();
    }

    // robots[0].set_type("industrial");
    // robots[0].set_powerSource("fuel");
    // robots[0].set_maximum_Speed(1);
    // robots[0].set_weight(1.1);

    // cout << "values changed" << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     robots[i].display();
    // }

    return 0;
}