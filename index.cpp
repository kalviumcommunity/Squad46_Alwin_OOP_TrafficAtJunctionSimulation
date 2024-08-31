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

public:
    Vehicle(int id, string dir)
    {
        this->vehicle_id = id;
        this->direction = dir;
    }

    virtual string status() const
    {
        return "Vehicle " + to_string(this->vehicle_id) + " heading " + this->direction;
    }
};

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

    TrafficLight light("North");

    // Create vehicle objects
    Car car1(1, "North");
    Bus bus1(2, "North");
    Car car2(3, "North");

    // Use a static array of Vehicle pointers
    const int numVehicles = 3;
    Vehicle *vehicles[numVehicles] = {&car1, &bus1, &car2};

    cout << light.status() << endl;

    light.changeState("GREEN");

    cout << light.status() << endl;

    // Display vehicle statuses
    for (int i = 0; i < numVehicles; ++i)
    {
        cout << vehicles[i]->status() << endl;
    }

    return 0;
}
