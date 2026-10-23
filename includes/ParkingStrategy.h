#pragma once 
#include"ParkingFloor.h"
#include <vector> 
 
class ParkingStrategy{
    public:
    virtual ParkingSpot* findSpot(std::vector<ParkingFloor>& floors, VehicleType type)=0;

    virtual ~ParkingStrategy()=default;

};

class  FirstAvailableStrategy:public ParkingStrategy{
    public:
    ParkingSpot * findSpot(std::vector<ParkingFloor>& floors , VehicleType type)override;
};
