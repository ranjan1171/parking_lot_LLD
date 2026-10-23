#include "Vehicle.h"
#include<utility>
#include<stdexcept>



Vehicle::Vehicle(std::string registrationNumber , VehicleType type):registrationNumber(std::move(registrationNumber)), type(type){

    if(this->registrationNumber.empty()){
        throw std::invalid_argument("Registration Number is cant  be empty ");

    }
}
// return_type -  class_name( just from  where it  belonging )    calling function 
std::string Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}
//return_type class_name   function 
VehicleType Vehicle::getType() const{
    return type;
}

// class -- constructor 
Car::Car(std::string registrationNumber):Vehicle( std::move(registrationNumber), VehicleType::CAR){}
Bike::Bike(std::string registrationNumber):Vehicle( std::move(registrationNumber), VehicleType::BIKE){}
Truck::Truck(std::string registrationNumber):Vehicle( std::move(registrationNumber), VehicleType::TRUCK){}
Bus::Bus(std::string registrationNumber):Vehicle( std::move(registrationNumber), VehicleType::BUS){}