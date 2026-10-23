#include "ParkingLot.h"

#include <stdexcept>
#include<utility>


ParkingLot::ParkingLot(std::string name , std::unique_ptr<PricingStrategy>pricingStrategy , std::unique_ptr<ParkingStrategy> parkingStrategy ): name(std::move(name)),
parkingStrategy(std::move(parkingStrategy)), pricingStrategy(std::move(pricingStrategy)),nextTicketNumber(1){

    if( this->name.empty()){
        throw std::invalid_argument("Parking lot name cannot be empty");
    }

    if(!this->parkingStrategy|| !this->pricingStrategy){
        throw std::invalid_argument("Parking and pricing strategies  are required");
    }
}


void ParkingLot::addFloor( ParkingFloor floor){
    floors.push_back(std::move(floor));

}

std::string ParkingLot::parkVehicle(const Vehicle&vehicle){
    ParkingSpot* spot= parkingStrategy->findSpot(floors, vehicle.getType());

    if(spot== nullptr){
        throw std::runtime_error("No  suitable parking spot availble");
    }

    std::string ticketId= "TICKET_"+std::to_string(nextTicketNumber);

    if(!spot->park(vehicle)){
        throw std::runtime_error("Unable to park the vehicle");

    }

    try{
         tickets.emplace (ticketId, ParkingTicket(ticketId, vehicle , spot->getid()));
    }catch(...){
        spot->release();
        throw;
    }
    nextTicketNumber++;
     return ticketId;
}

double ParkingLot::unparkVehicle(const std::string& ticketId){
    auto it = tickets.find(ticketId);
    if(it==tickets.end()){
        throw std::invalid_argument("invalid ticket ID ");
    }

    ParkingTicket& ticket= it->second;
    if(!ticket.isActive()){
        throw  std::logic_error("Ticket is alredy  closed");

    }

    auto exitTime= std::chrono::system_clock::now();
    double fee= pricingStrategy->calculateFee(ticket.getEntrytime(),exitTime);


    ParkingSpot* spot= nullptr;
    for (auto &floor: floors){
        spot = floor.findSpotByid(ticket.getSpotId());
        if(spot!= nullptr){
          break;
        }
      
    }

    if( spot == nullptr){
        throw std::runtime_error("Parking spot associated wiht the ticket was not found");
    }

    spot->release();
    ticket.close(fee);
    return  fee;
}


int ParkingLot::getAvailableSpots(VehicleType type)const{
 int total =0;
 
 for ( const auto& floor:floors){
    total+=floor.availableCount(type);
 }

 return total;

}

const ParkingTicket* ParkingLot::getTicket(const std::string& ticketId)const {
 auto it = tickets.find(ticketId);
 if(it==tickets.end()){
    return nullptr;
 }

 return &it->second;
}