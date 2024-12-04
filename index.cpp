#include <iostream>
#include <vector>

using namespace std;

// Abstract class for traffic light states
class LightState
{
public:
    virtual string getState() const = 0;
    virtual ~LightState() = default;
};

class RedState : public LightState
{
public:
    string getState() const override
    {
        return "RED";
    }
};

class GreenState : public LightState
{
public:
    string getState() const override
    {
        return "GREEN";
    }
};

class YellowState : public LightState
{
public:
    string getState() const override
    {
        return "YELLOW";
    }
};

// Class responsible for managing light states
class LightStateManager
{
private:
    LightState *currentState;

public:
    LightStateManager() : currentState(new RedState()) {}

    void setState(LightState *newState)
    {
        delete currentState;
        currentState = newState;
    }

    string getState() const
    {
        return currentState->getState();
    }

    ~LightStateManager()
    {
        delete currentState;
    }
};

// Class responsible for traffic light operations
class TrafficLight
{
private:
    string direction;
    LightStateManager stateManager;

public:
    TrafficLight(string dir) : direction(dir) {}

    void changeState(LightState *newState)
    {
        stateManager.setState(newState);
    }

    string status() const
    {
        return this->direction + " Light: " + stateManager.getState();
    }
};

// Class responsible for vehicle counting
class VehicleRegistry
{
private:
    static int vehicleCount;

public:
    static void registerVehicle()
    {
        ++vehicleCount;
    }

    static void unregisterVehicle()
    {
        --vehicleCount;
    }

    static int getCount()
    {
        return vehicleCount;
    }
};

int VehicleRegistry::vehicleCount = 0;

// Base class for vehicles
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
        VehicleRegistry::registerVehicle();
    }

    virtual string status() const = 0;

    virtual ~Vehicle()
    {
        VehicleRegistry::unregisterVehicle();
    }
};

// Specific vehicle types
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

// Class responsible for displaying information
class DisplayManager
{
public:
    static void displayDirections()
    {
        cout << "Directions:" << endl;
        cout << "^ North" << endl;
        cout << "v South" << endl;
        cout << "-> East" << endl;
        cout << "<- West" << endl;
        cout << endl;
    }

    static void displayStatus(const string &status)
    {
        cout << status << endl;
    }

    static void displayVehicleCount()
    {
        cout << "Total number of vehicles: " << VehicleRegistry::getCount() << endl;
    }
};

int main()
{
    DisplayManager::displayDirections();

    // Create traffic light
    TrafficLight *light = new TrafficLight("North");

    // Create vehicles
    const int numVehicles = 4;
    Vehicle *vehicles[numVehicles];
    vehicles[0] = new Car(1, "North");
    vehicles[1] = new Bus(2, "North");
    vehicles[2] = new Car(3, "North");
    vehicles[3] = new Car(4, "North");

    // Display initial state
    DisplayManager::displayStatus(light->status());

    // Change and display new state
    light->changeState(new GreenState());
    DisplayManager::displayStatus(light->status());

    // Change state again
    light->changeState(new YellowState());
    DisplayManager::displayStatus(light->status());

    // Display vehicle statuses
    for (int i = 0; i < numVehicles; ++i)
    {
        DisplayManager::displayStatus(vehicles[i]->status());
    }

    DisplayManager::displayVehicleCount();

    // Cleanup
    delete light;
    for (int i = 0; i < numVehicles; ++i)
    {
        delete vehicles[i];
    }

    return 0;
}
