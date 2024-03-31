#include <iostream>

using namespace std;

// Class representing a simple object
class SimpleObject {
private:
    int data;

public:
    // Constructor
    SimpleObject(int _data) : data(_data) {}

    // Getter for data
    int getData() const {
        return data;
    }

    // Setter for data
    void setData(int _data) {
        data = _data;
    }
};

// Class representing a container of SimpleObject instances
class ObjectContainer {
private:
    SimpleObject* object;

public:
    // Constructor
    ObjectContainer(SimpleObject* _object) : object(_object) {}

    // Destructor
    ~ObjectContainer() {
        delete object;
    }

    // Shallow copy constructor
    ObjectContainer(const ObjectContainer& other) : object(other.object) {}

    // Deep copy constructor
    ObjectContainer(const ObjectContainer& other, bool deep) {
        if (deep) {
            object = new SimpleObject(other.object->getData());
        } else {
            object = other.object;
        }
    }

    // Display object's data
    void display() const {
        cout << "Data: " << object->getData() << endl;
    }
};

int main() {
    // Create an original object
    SimpleObject* originalObject = new SimpleObject(42);

    // Create an original container
    ObjectContainer originalContainer(originalObject);

    // Display original container
    cout << "Original Container:" << endl;
    originalContainer.display();
    cout << endl;

    // Shallow copy the container
    ObjectContainer shallowCopyContainer(originalContainer);
    shallowCopyContainer.display(); // Display shallow copy container

    // Deep copy the container
    ObjectContainer deepCopyContainer(originalContainer, true);
    deepCopyContainer.display(); // Display deep copy container

    // Change data in original object
    originalObject->setData(100);

    // Display all containers to demonstrate the effects of shallow and deep copy
    cout << "Containers after changing original object data:" << endl;
    cout << "Original Container:" << endl;
    originalContainer.display();
    cout << "Shallow Copy Container:" << endl;
    shallowCopyContainer.display();
    cout << "Deep Copy Container:" << endl;
    deepCopyContainer.display();

    // Clean up memory
    delete originalObject;

    return 0;
}
