#pragma once
#include "ParkingSpot.h"
#include <string>
#include <vector>


class ParkingFloor{
    private:
    int floorNumber;
    std::vector<ParkingSpot>spots;

    public :
    explicit ParkingFloor(int floorNumber);
    void addSpot(ParkingSpot spot);

    ParkingSpot * findAvailableSpot(VehicleType  type);
    ParkingSpot * findSpotByid(const std::string& spotid);

    int availableCount(VehicleType type)const;
    int getFloorNumber() const ;



};