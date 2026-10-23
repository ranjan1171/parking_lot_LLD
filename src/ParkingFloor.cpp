#include"ParkingFloor.h"
#include <utility>

ParkingFloor::ParkingFloor(int floorNumber):floorNumber(floorNumber){}

void ParkingFloor::addSpot(ParkingSpot spot){
    spots.push_back(std::move(spot));

}

ParkingSpot* ParkingFloor::findAvailableSpot(VehicleType type){
    for(auto &spot :spots){
        if(spot.isAvailable()&&spot.getSupportedType()==type){
            return &spot;
        }
    }
     return nullptr;
}


ParkingSpot* ParkingFloor::findSpotByid(const std::string& spotid){
    for (auto &spot :spots){
        if(spot.getid()==spotid){
            return &spot;
        }
    }
    return nullptr;
}


int ParkingFloor::availableCount(VehicleType type )const {
    int count =0;
    for ( const auto &spot : spots){
        if(spot.isAvailable() &&spot.getSupportedType()==type){
            count++;
        }
    }
    return count ;

}


int ParkingFloor::getFloorNumber()const {
    return floorNumber;
}