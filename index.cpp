#include <iostream>

using namespace std;

class TrafficLight
{
private:
    string direction;
    string state;

public:
    TrafficLight(string dir)
    {
        this->direction = dir;
        this->state = "RED";
    }

    void changeState(string newState)
    {
        this->state = newState;
    }

    string status() const
    {
        return this->direction + " Light: " + this->state;
    }
};

class Vehicle
{
protected:
    int vehicle_id;
    string direction;

    static int vehicleCount;

public:
    Vehicle(int id, string dir)
    {
        this->vehicle_id = id;
        this->direction = dir;
        ++vehicleCount;
    }

    virtual string status() const
    {
        return "Vehicle " + to_string(this->vehicle_id) + " heading " + this->direction;
    }
};

// Initialize the static variable
int Vehicle::vehicleCount = 0;

class Car : public Vehicle
{
public:
    Car(int id, string dir) : Vehicle(id, dir) {}

    string status() const override
    {
        return "Car " + to_string(this->vehicle_id) + " heading " + this->direction;
    }
};

class Bus : public Vehicle
{
public:
    Bus(int id, string dir) : Vehicle(id, dir) {}

    string status() const override
    {
        return "Bus " + to_string(this->vehicle_id) + " heading " + this->direction;
    }
};

void displayDirections()
{
    cout << "Directions:" << endl;
    cout << "^ North" << endl;
    cout << "v South" << endl;
    cout << "-> East" << endl;
    cout << "<- West" << endl;
    cout << endl;
}

int main()
{
    displayDirections();

    // Use dynamic memory allocation for TrafficLight
    TrafficLight *light = new TrafficLight("North");

    // Create vehicle objects using dynamic memory allocation
    const int numVehicles = 3;
    Vehicle *vehicles[numVehicles];
    vehicles[0] = new Car(1, "North");
    vehicles[1] = new Bus(2, "North");
    vehicles[2] = new Car(3, "North");

    cout << light->status() << endl;

    light->changeState("GREEN");

    cout << light->status() << endl;

    // Display vehicle statuses
    for (int i = 0; i < numVehicles; ++i)
    {
        cout << vehicles[i]->status() << endl;
    }

    // Clean up dynamically allocated memory
    delete light;
    for (int i = 0; i < numVehicles; ++i)
    {
        delete vehicles[i];
    }

    return 0;
}
