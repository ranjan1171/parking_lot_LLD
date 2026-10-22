#pragma once 

#include"Vehicle.h"
#include <string>


class ParkingSpot{
    private:
    std:: string id ;
    VehicleType supportedType;
    std::string parkedRegistration;
    public:
    ParkingSpot( std:: string id , VehicleType supportedType);

    std::string getid() const;
    VehicleType getSupportedType() const;
    bool isAvailable() const;
    bool canFit(const Vehicle &vehicle ) const;

    bool park(const Vehicle&vehicle);
    void release();

};
