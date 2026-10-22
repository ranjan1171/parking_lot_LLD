#pragma once 
#include"Vehicle.h"
#include<memory>
#include<string>


class VehicleFactory{
    public:
    static std::unique_ptr<Vehicle>create(VehicleType type , const std :: string &registrationNumber );

};