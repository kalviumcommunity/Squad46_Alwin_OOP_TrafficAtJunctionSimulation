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
        direction = dir;
        state = "RED";
    }

    void changeState(string newState)
    {
        state = newState;
    }

    string status() const
    {
        return direction + " Light: " + state;
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
        vehicle_id = id;
        direction = dir;
    }

    virtual string status() const
    {
        return "Vehicle " + to_string(vehicle_id) + " heading " + direction;
    }
};

class Car : public Vehicle
{
public:
    Car(int id, string dir) : Vehicle(id, dir) {}

    string status() const override
    {
        return "Car " + to_string(vehicle_id) + " heading " + direction;
    }
};

class Bus : public Vehicle
{
public:
    Bus(int id, string dir) : Vehicle(id, dir) {}

    string status() const override
    {
        return "Bus " + to_string(vehicle_id) + " heading " + direction;
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

    Car car1(1, "North");
    Bus bus1(2, "North");

    cout << light.status() << endl;
    light.changeState("GREEN");
    cout << light.status() << endl;

    cout << car1.status() << endl;
    cout << bus1.status() << endl;

    return 0;
}
