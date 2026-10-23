#include "Vehicle.h"
#include<chrono>
#include<string>

class ParkingTicket{
    private:
    std::string ticketId;
    std::string registrationNumber;
    std::string spotId;

    std::chrono::system_clock::time_point entryTime;
    std::chrono::system_clock::time_point exitTime;
    
    double fee;
    bool active ;

    public :
    ParkingTicket(std::string ticketId, const Vehicle & vehicle , std::string spotId);

    std::string getTicketId() const ;
    std::string getRegistrationNumber() const;
    std::string getSpotId() const;

    std::chrono::system_clock::time_point getEntrytime() const;
    std::chrono::system_clock::time_point getExitTime() const;
    
    double getFee() const ;
    double isActive() const;

    void close (double calculatedFee);

    
    

};