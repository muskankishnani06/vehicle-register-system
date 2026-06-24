Video Link :- https://drive.google.com/file/d/14bLA8VYiM39_-Ku4FP7U1K0sii8Nq7jg/view?usp=sharing

GDB Online Link :- https://onlinegdb.com/1jhY1-lNv


# Vehicle Registry System

A console-based C++ program demonstrating Object-Oriented Programming (OOP) concepts — including all major types of inheritance — through a simple vehicle management system.

## Overview

The program lets you register different types of vehicles (Sedans, SUVs, Electric Cars, Sports Cars), store them in a registry, view them, search by ID, and track the total number of vehicles created.

## Features

- Add a Sedan, SUV, Electric Car, or Sports Car
- View all registered vehicles
- Search for a vehicle by its ID
- Track total vehicles created (via a static counter)
- Polymorphic display of vehicle details using virtual functions

## Class Hierarchy & OOP Concepts Demonstrated

| Class | Inherits From | Inheritance Type |
|---|---|---|
| `Vehicle` | — | Base class |
| `Car` | `Vehicle` | Single Inheritance |
| `ElectricCar` | `Car` | Multilevel Inheritance |
| `SportsCar` | `ElectricCar` | Multilevel Inheritance |
| `Sedan`, `SUV` | `Car` | Hierarchical Inheritance |
| `Aircraft` | — | Base class |
| `FlyingCar` | `Car`, `Aircraft` | Multiple Inheritance |

**Other concepts used:**
- **Encapsulation** — protected/private data members with public getters/setters
- **Polymorphism** — `virtual void display()` overridden across the hierarchy
- **Constructors/Destructors** — default and parameterized constructors, with base-class initialization via constructor chaining
- **Static Members** — `Vehicle::totalVehicles` tracks the number of vehicles created across the program
- **Composition via Registry** — `VehicleRegistry` stores `Vehicle*` pointers, enabling runtime polymorphism

## Class Descriptions

### `Vehicle` (Base Class)
Holds common attributes: `vehicleID`, `manufacturer`, `model`, `year`. Provides getters/setters and a virtual `display()` method. Tracks `totalVehicles` as a static counter.

### `Car` (extends `Vehicle`)
Adds `fuelType`. Overrides `display()` to include fuel information.

### `ElectricCar` (extends `Car`)
Adds `batteryCapacity`. Demonstrates multilevel inheritance (`Vehicle → Car → ElectricCar`).

### `SportsCar` (extends `ElectricCar`)
Adds `topSpeed`. Extends the multilevel chain further (`Vehicle → Car → ElectricCar → SportsCar`).

### `Aircraft` (Base Class)
A separate base class with `flightRange`, used for multiple inheritance.

### `FlyingCar` (extends `Car` and `Aircraft`)
Combines two unrelated base classes, demonstrating multiple inheritance.

### `Sedan` / `SUV` (extend `Car`)
Both inherit from `Car` independently, demonstrating hierarchical inheritance.

### `VehicleRegistry`
Manages a fixed-size array of `Vehicle*` pointers (max 200). Supports adding, listing, and searching vehicles by ID using runtime polymorphism (calls to `display()` resolve to the correct derived class).

## Program Menu

```
========== VEHICLE REGISTRY ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. View All Vehicles
6. Search Vehicle By ID
7. Total Vehicles
0. Exit
```

## How to Compile & Run

```bash
g++ -o vehicle_registry vehicle_registry.cpp
./vehicle_registry
```

On Windows (with MinGW):
```bash
g++ -o vehicle_registry.exe vehicle_registry.cpp
vehicle_registry.exe
```

## Sample Usage

```
Enter Choice : 1
Enter ID: 101
Manufacturer: Toyota
Model: Camry
Year: 2023
Fuel Type: Petrol

Enter Choice : 5

===== Sedan =====
Vehicle ID : 101
Manufacturer : Toyota
Model : Camry
Year : 2023
Fuel Type : Petrol
```

## Known Limitations / Notes

- `VehicleRegistry` uses a fixed-size raw array (`Vehicle* vehicles[200]`) with no bounds checking — adding more than 200 vehicles will cause undefined behavior.
- Memory allocated with `new` in the menu options is never explicitly `delete`d, resulting in memory leaks on program exit (acceptable for a learning/demo project, but should be fixed for production code — consider using `std::vector<Vehicle*>` with proper cleanup, or smart pointers like `std::unique_ptr<Vehicle>`).
- `FlyingCar` does not override the `totalVehicles` increment logic differently from other classes — since it inherits from both `Car` (which inherits `Vehicle`) and `Aircraft`, be aware of the **diamond-shaped** risk if `Aircraft` ever also inherited from `Vehicle` (it currently does not, so this is safe here).
- Input is read with `cin >>`, so manufacturer/model names containing spaces will not be captured correctly.

## Possible Improvements

- Replace the raw array in `VehicleRegistry` with `std::vector<Vehicle*>` or smart pointers
- Add input validation for numeric fields
- Add a "Delete Vehicle" and "Edit Vehicle" feature
- Persist registry data to a file (CSV/JSON) for storage between runs
- Use `std::cin.ignore()` / `getline()` to support multi-word manufacturer/model names

## License

This project is provided as-is for educational purposes.
