#include <iostream>
using namespace std;

// ================= BASE CLASS =================
class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    // ================ default constructor ===================

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "not set";
        model = "not set";
        year = 0;
    }

    // ================ parameterized constructor ===================

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    // ==============destructor============

    ~Vehicle()
    {
    }

    //============== Setters===============

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string manu)
    {
        manufacturer = manu;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    void setYear(int yr)
    {
        year = yr;
    }

    // ================Getters=============
    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    virtual void display()
    {
        cout << "\nVehicle ID : " << vehicleID;
        cout << "\nManufacturer : " << manufacturer;
        cout << "\nModel : " << model;
        cout << "\nYear : " << year;
    }
};

int Vehicle::totalVehicles = 0;

// ================= SINGLE INHERITANCE =================
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car()
    {
    }

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr)
    {
        fuelType = fuel;
    }

    void display()
    {
        Vehicle::display();
        cout << "\nFuel Type : " << fuelType << endl;
    }
};

// ================= MULTILEVEL INHERITANCE =================
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar()
    {

        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod,
                int yr, string fuel, int battery) : Car(id, manu, mod, yr, fuel)
    {
        batteryCapacity = battery;
    }

    void display()
    {
        Car::display();
        cout << "Battery Capacity : "
             << batteryCapacity ;
    }
};

// ================= BASE CLASS FOR MULTIPLE =================
class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int range)
    {
        flightRange = range;
    }

    void displayAircraft()
    {
        cout << "Flight Range : "
             << flightRange ;
    }
};

// ================= MULTIPLE INHERITANCE =================
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod,
              int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel),
          Aircraft(range)
    {
    }

    void display()
    {
        Car::display();
        displayAircraft();
    }
};

// ================= MULTILEVEL =================
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod,
              int yr, string fuel,
              int battery, int speed)
        : ElectricCar(id, manu, mod, yr,
                      fuel, battery)
    {
        topSpeed = speed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "Top Speed : "
             << topSpeed ;
    }
};

// ================= HIERARCHICAL =================
class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod,
          int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }

    void display()
    {
        cout << "\n===== Sedan =====";
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod,
        int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }

    void display()
    {
        cout << "\n===== SUV =====";
        Car::display();
    }
};

// ================= REGISTRY CLASS =================
class VehicleRegistry
{
private:
    Vehicle *vehicles[200];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle *v)
    {
        vehicles[count++] = v;
    }

    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "\nNo Vehicles Found!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
        }
    }

    void searchVehicle(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found\n";
                vehicles[i]->display();
                return;
            }
        }

        cout << "\nVehicle Not Found\n";
    }
};

// ================= MAIN =================
int main()
{
    VehicleRegistry registry;

    int choice;

    do
    {
        cout << "\n========== VEHICLE REGISTRY ==========\n";
        cout << "1. Add Sedan\n";
        cout << "2. Add SUV\n";
        cout << "3. Add Electric Car\n";
        cout << "4. Add Sports Car\n";
        cout << "5. View All Vehicles\n";
        cout << "6. Search Vehicle By ID\n";
        cout << "7. Total Vehicles\n";
        cout << "0. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        int id, year, battery, speed;
        string manu, model, fuel;

        if (choice == 1)
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manu;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Fuel Type: ";
            cin >> fuel;

            registry.addVehicle(
                new Sedan(id, manu, model, year, fuel));
        }
        else if (choice == 2)
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manu;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Fuel Type: ";
            cin >> fuel;

            registry.addVehicle(
                new SUV(id, manu, model, year, fuel));
        }
        else if (choice == 3)
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manu;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Fuel Type: ";
            cin >> fuel;
            cout << "Battery Capacity: ";
            cin >> battery;

            registry.addVehicle(
                new ElectricCar(id, manu, model,
                                year, fuel, battery));
        }
        else if (choice == 4)
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manu;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Fuel Type: ";
            cin >> fuel;
            cout << "Battery Capacity: ";
            cin >> battery;
            cout << "Top Speed: ";
            cin >> speed;

            registry.addVehicle(
                new SportsCar(id, manu, model,
                              year, fuel,
                              battery, speed));
        }
        else if (choice == 5)
        {
            registry.displayVehicles();
        }
        else if (choice == 6)
        {
            cout << "Enter Vehicle ID: ";
            cin >> id;

            registry.searchVehicle(id);
        }
        else if (choice == 7)
        {
            cout << "\nTotal Vehicles Registered : "
                 << Vehicle::totalVehicles << endl;
        }
        else if (choice == 0)
        {
            cout << "\nProgram Ended\n";
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}