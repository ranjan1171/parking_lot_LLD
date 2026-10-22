#include"ParkingSpot.h"
#include <utility>
#include <stdexcept>

ParkingSpot::ParkingSpot(std::string id, VehicleType SupportedType ):id(std::move(id)),supportedType(supportedType){
    if(this->id.empty()){
        throw std::invalid_argument("parking spot-id  cant be empty");

    }
}

std::string ParkingSpot::getid() const {
    return id;
}

VehicleType ParkingSpot::getSupportedType()const {
    return supportedType;
}

bool ParkingSpot::isAvailable() const{
    return parkedRegistration.empty();

}
bool ParkingSpot::canFit(const Vehicle &vehicle)const {
   return isAvailable() &&supportedType== vehicle.getType();
}

bool ParkingSpot::park(const Vehicle &vehicle){
    if(!canFit(vehicle)){
        return false;

    }
    parkedRegistration =vehicle.getRegistrationNumber();
    return true;
}

void ParkingSpot::release(){
    parkedRegistration.clear();

}

