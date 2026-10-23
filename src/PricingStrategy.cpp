#include "PricingStrategy.h"
#include <algorithm>
#include <cmath>
#include<stdexcept>


HourlyPricingStrategy::HourlyPricingStrategy(double ratePerHour):ratePerHour(ratePerHour){
    if(ratePerHour<0){
        throw std::invalid_argument("Hourly rate cant  be negative ");
    }
}

double HourlyPricingStrategy::calculateFee(std::chrono::system_clock::time_point entryTime, std::chrono::system_clock::time_point exitTime)const{
    if(exitTime<entryTime){
        throw  std::invalid_argument("Exit time can not be earlier than entry time");
    }
    std::chrono::duration<double, std::ratio<3600>>duration= exitTime-entryTime;
     double hours = duration.count();

     double chargedHours= std::max(1.0 , std::ceil(hours));
     return chargedHours* ratePerHour;

}
