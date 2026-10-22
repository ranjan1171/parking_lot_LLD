#include "VehicleFactory.h"
#include <stdexcept>

std::unique_ptr<Vehicle>create(VehicleType type, const std::string &registrationNumber){
    switch(type){
        case VehicleType::CAR:
        return std::make_unique<Car>(registrationNumber);
        case VehicleType::BIKE:
        return std::make_unique<Bike>(registrationNumber);
        case VehicleType::TRUCK:
        return std::make_unique<Truck>(registrationNumber);
       

    }
    throw std::invalid_argument("Unsupported  vehicle type");

}