#include "ParkingTicket.h"
#include <utility>
#include<stdexcept>


ParkingTicket::ParkingTicket(std:: string ticketId , const Vehicle& vehicle , std::string spotId):
ticketId(std::move(ticketId)), registrationNumber(vehicle.getRegistrationNumber()), spotId(std::move(spotId)),

entryTime(std::chrono::system_clock::now()), exitTime(), fee(0.0), active(true){


    if( this->ticketId.empty()){
        throw std::invalid_argument("Ticket id and Parking  spot cannot be  Empty");

    }
}


std::string ParkingTicket::getTicketId()const {
    return ticketId;
}

std:: string ParkingTicket::getRegistrationNumber() const {
    return registrationNumber;
}

std:: string ParkingTicket::getSpotId() const {
    return spotId;
}

std :: chrono::system_clock::time_point ParkingTicket::getEntrytime() const {
    return entryTime;
}
std:: chrono::system_clock::time_point ParkingTicket::getExitTime() const {
    return exitTime;
}


double ParkingTicket::getFee() const {
    return fee;

}

double ParkingTicket::isActive() const {
    return active;

}


void ParkingTicket::close(double calculatedFee){
    if(!active){
        throw std::logic_error("Ticket is alredy closed");
    }

    if( calculatedFee<0){
        throw std::invalid_argument("Parking fee cant be  negative");

    }
    exitTime = std::chrono::system_clock::now();
    fee= calculatedFee;
    active= false;
}