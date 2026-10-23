#include "ParkingLot.h"
#include"VehicleFactory.h"
#include<iostream>
#include<memory>
#include<stdexcept>


int main (){
    try{
        ParkingLot parkingLot("City Parking", std::make_unique<HourlyPricingStrategy>(100.0), std::make_unique<FirstAvailableStrategy>());

        ParkingFloor floor1(1);
        floor1.addSpot(ParkingSpot("B1", VehicleType::BIKE));
        floor1.addSpot(ParkingSpot("B2", VehicleType::BIKE));
        floor1.addSpot(ParkingSpot("B3", VehicleType::BIKE));
        floor1.addSpot(ParkingSpot("C1", VehicleType::CAR));
        floor1.addSpot(ParkingSpot("C2", VehicleType::CAR));
        floor1.addSpot(ParkingSpot("C3", VehicleType::CAR));
        floor1.addSpot(ParkingSpot("C4", VehicleType::CAR));
        floor1.addSpot(ParkingSpot("T1", VehicleType::TRUCK));
        floor1.addSpot(ParkingSpot("T2", VehicleType::TRUCK));
        floor1.addSpot(ParkingSpot("T3", VehicleType::TRUCK));

        parkingLot.addFloor(std::move(floor1));

        auto car = VehicleFactory::create(VehicleType::CAR, "JH013559");
        

        std::string ticketId = parkingLot.parkVehicle(*car);
        std::cout<<"Vehicle parked successfully"<<std::endl;
        std::cout<<"Registration:"<<car->getRegistrationNumber()<<std::endl;
        std::cout<<"Ticket ID:"<<ticketId<<std::endl;

        std::cout<<"Available car spots:" <<parkingLot.getAvailableSpots(VehicleType::CAR)<<std::endl;


        double fee = parkingLot.unparkVehicle(ticketId);
        std::cout<<"Vehicle unparked successfully"<<std::endl;
        std::cout<<"parking Fee:"<<fee<<std::endl;


        std::cout<<"available car spots:"<<parkingLot.getAvailableSpots(VehicleType::CAR)<<std::endl;



    }catch(const std::exception& error){
        std::cerr<<"Error:"<<error.what()<<std::endl;
        return 1;
    }

    return 0;

    


}