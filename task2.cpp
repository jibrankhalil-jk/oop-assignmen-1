#include <iostream>
#include <string>

using namespace std;

int totalsize = 1;

class Robot
{

private:
    int id;
    string type;        // (industrial, humanoid, aerial)
    string powerSource; // (battery, solar, fuel)
    int maximum_Speed;  // (in meters per second)
    double weight;      // (in kilograms)

public:
    Robot(){};
    Robot(int id, string type, string powerSource, int maximum_Speed, double Weight) : id(id), type(type), powerSource(powerSource), maximum_Speed(maximum_Speed), weight(Weight){};
    // distructor
    ~Robot() {}

    // setters
    void set_id(int id) { id = id; };
    void set_type(string type) { type = type; };
    void set_powerSource(string powerSource) { powerSource = powerSource; };
    void set_maximum_Speed(int maximum_Speed) { maximum_Speed = maximum_Speed; };
    void set_weight(double weight) { weight = weight; };

    // getters
    int get_id() { return id; };
    string get_type() { return type; };
    string get_powerSource() { return powerSource; };
    int get_maximum_Speed() { return maximum_Speed; };
    double get_weight() { return weight; };

    // shallow copy
    // Robot(const Robot &robo)
    // {
    //     cout << "shallow copy applied" << endl;
    //     this->id = robo.id;
    //     this->type = robo.type;
    //     this->powerSource = robo.powerSource;
    //     this->maximum_Speed = robo.maximum_Speed;
    //     this->weight = robo.weight;
    // }

    // deep copy constructor
    Robot(Robot &robo)
    {
        // cout << "deep copy applied" << endl;
        this->id = *(new int(robo.id));
        this->type = *(new string(robo.type));
        this->powerSource = *(new string(robo.powerSource));
        this->maximum_Speed = *(new int(robo.maximum_Speed));
        this->weight = *(new int(robo.weight));
    }

    // Assignment operator for shallow copy
    // Robot &operator=(const Robot &robo)
    // {
    //     if (this != &robo)
    //     {
    //     this->id = *(new int(robo.id));
    //     this->type = *(new string(robo.type));
    //     this->powerSource = *(new string(robo.powerSource));
    //     this->maximum_Speed = *(new int(robo.maximum_Speed));
    //     this->weight = *(new int(robo.weight));
    //     }
    //     return *this;
    // }

    // Assignment operator for deep copy
    // Robot &operator=(Robot &&robo)
    // {
    //     if (this != &robo)
    //     {
    //         this->id = *(new int(robo.id));
    //         this->type = *(new string(robo.type));
    //         this->powerSource = *(new string(robo.powerSource));
    //         this->maximum_Speed = *(new int(robo.maximum_Speed));
    //         this->weight = *(new int(robo.weight));
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

void shallowCopy(Robot *robots)
{
    ++totalsize;
    Robot *newRobo = new Robot[totalsize];
    for (int i = 0; i < totalsize - 1; i++)
    {
        newRobo[i] = robots[i];
    }
    // Robot a1(1, "humanoid", "solar", 100, 20.2);
    robots[totalsize - 1] = robots[0];
    // b1->display();
    // robots[0].set_weight(11.1);
    // robots[0].display();
    // b1->display();
    // robots[1] = *b1;
    // robots[1].display();
    // delete[] robots;
    robots = newRobo;
};
void deepCopy(Robot *robots)
{
    // Robot a1(1, "humanoid", "solar", 100, 20.2);
    robots[0].display();
    Robot *b1;
    // AutonomousVehicle *b1(&a1);
    b1 = &robots[0];
    // b1->display();
    robots[0].set_weight(11.1);
    // robots[0].display();
    // b1->display();
    robots[1] = *b1;
    robots[1].display();
};

int main()
{
    Robot *robots = new Robot[totalsize];

    robots[0] = Robot(1, "humanoid", "solar", 100, 20.2);

    shallowCopy(robots);

    // for (int i = 0; i < totalsize; i++)
    // {
    //     robots[i].display();
    // }
    

    // shallow copy
    // Robot a1(1, "humanoid", "solar", 100, 20.2);
    // robots[0].display();
    // Robot *b1;
    // // AutonomousVehicle *b1(&a1);
    // b1 = &robots[0];
    // b1->display();
    // robots[0].set_weight(11.1);
    // robots[0].display();
    // b1->display();

    // Robot *c = new Robot(1, "humanoid", "solar", 100, 20.2);
    // c->display();
    // AutonomousVehicle d(*c); // deep copy constructor
    // d.display();
    // c->setMaxSpeed(3000);
    // c->display();
    // d.display();

    return 0;
}