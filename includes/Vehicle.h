#pragma once
#include "VehicleType.h"
#include<string>

class Vehicle {
    private:
    std::string registrationNumber;
    VehicleType type;

    public:
    Vehicle(std::string registrationNumber , VehicleType type );
    virtual ~Vehicle()=default;
    //i am using  getters here just to get the  read access to private data 
    std::string getRegistrationNumber()  const ;
    VehicleType getType() const ;


};

class Car:public Vehicle{

    public:
     // Prevents a registration number from being implicitly converted to a Car.
    explicit Car(std::string registrationNumber );

};

class Bike:public Vehicle{

    public:
    explicit Bike(std::string registrationNumber );

};

class Truck:public Vehicle{

    public:
    explicit Truck(std::string registrationNumber );

};

class Bus:public Vehicle{

    public:
    explicit Bus(std::string registrationNumber );

};

//explicit is an extra safety measure: it makes the code explicitly ask to create a Truck, instead of letting C++ silently convert a registration number into one.
