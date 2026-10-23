#pragma once 

#include "ParkingFloor.h"
#include "ParkingStrategy.h"
#include"PricingStrategy.h"
#include "ParkingTicket.h"

#include <memory>
#include <string>
#include<unordered_map>
#include<vector>

class ParkingLot{

    private:
    std::string name ;

    std::vector<ParkingFloor>floors;
    std::unique_ptr<ParkingStrategy> parkingStrategy;
    std::unique_ptr<PricingStrategy>pricingStrategy;

    std:: unordered_map<std::string , ParkingTicket> tickets;

    int nextTicketNumber;

    public :

    ParkingLot(std::string name , std::unique_ptr<PricingStrategy>pricingStrategy , std::unique_ptr<ParkingStrategy> parkingStrategy );

    void addFloor(ParkingFloor  floor);

    std::string parkVehicle(const Vehicle&  vehicle);

    double unparkVehicle(const std::string & ticketId);


    int getAvailableSpots(VehicleType type) const ;

    const ParkingTicket* getTicket(const std::string& ticketId) const ;

};


