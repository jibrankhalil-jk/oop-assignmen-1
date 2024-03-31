#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Robot
{
protected:
    string id;
    string type;
    string powerSource;
    double maxSpeed;
    double weight;

public:
    Robot(){};
    // Parameterized constructor
    Robot(string id, string type, string powerSource, double maxSpeed, double weight)
        : id(id), type(type), powerSource(powerSource), maxSpeed(maxSpeed), weight(weight) {}

    // Destructor
    ~Robot() {}

    // Getters for all attributes
    string getId() { return id; }
    string getType() { return type; }
    string getPowerSource() { return powerSource; }
    double getMaxSpeed() { return maxSpeed; }
    double getWeight() { return weight; }

    // Implementing copy constructor to ensure deep copy
    Robot(const Robot &other)
    {
        id = other.id;
        type = other.type;
        powerSource = other.powerSource;
        maxSpeed = other.maxSpeed;
        weight = other.weight;
    }

    // Implementing assignment operator to ensure deep copy
    Robot &operator=(const Robot &other)
    {
        if (this != &other)
        {
            id = other.id;
            type = other.type;
            powerSource = other.powerSource;
            maxSpeed = other.maxSpeed;
            weight = other.weight;
        }
        return *this;
    }

    // Function to display the details of the robot
    void display() const
    {
        cout << "ID: " << id << "\n";
        cout << "Type: " << type << "\n";
        cout << "Power Source: " << powerSource << "\n";
        cout << "Max Speed: " << maxSpeed << " m/s\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "------------------------------------\n";
    }
};

// Function to perform a deep copy of the array/vector of Robot objects
void deepCopy(const vector<Robot> &source, vector<Robot> &destination)
{
    destination.resize(source.size());
    transform(source.begin(), source.end(), destination.begin(), [](const Robot &robot)
              { return Robot(robot); });
}

// Function to perform a shallow copy of the array/vector of Robot objects
void shallowCopy(const vector<Robot> &source, vector<Robot> &destination)
{
    destination = source;
}

int main()
{
    // Create an array of Robot objects
    vector<Robot> robots = {
        Robot("R1", "industrial", "battery", 2.5, 100.0),
        Robot("R2", "humanoid", "solar", 1.2, 80.0),
        Robot("R3", "aerial", "fuel", 12.0, 5.0)};

    // Display the details of each robot
    cout << "Before copy operations:\n";
    for (const Robot &robot : robots)
    {
        robot.display();
    }

    // Perform a deep copy
    vector<Robot> deepCopyRobots;
    deepCopy(robots, deepCopyRobots);

    // Display the details of each robot after deep copy
    cout << "\nAfter deep copy:\n";
    for (const Robot &robot : deepCopyRobots)
    {
        robot.display();
    }

    // Perform a shallow copy
    vector<Robot> shallowCopyRobots;
    shallowCopy(robots, shallowCopyRobots);

    // Display the details of each robot after shallow copy
    cout << "\nAfter shallow copy:\n";
    for (const Robot &robot : shallowCopyRobots)
    {
        robot.display();
    }

    return 0;
}