#include "ParkingStrategy.h"

ParkingSpot* FirstAvailableStrategy::findSpot(std::vector<ParkingFloor>& floors, VehicleType type){
    for( auto & floor: floors){
        ParkingSpot* spot = floor.findAvailableSpot(type);
        if(spot!= nullptr){
            return spot;
        }
    }
    return nullptr;
}