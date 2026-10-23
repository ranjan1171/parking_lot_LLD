#pragma once 
#include <chrono>

class PricingStrategy{
    public :
    virtual  double calculateFee(std::chrono::system_clock::time_point entryTime , std::chrono::system_clock:: time_point exitTime)const =0;
     virtual ~PricingStrategy() = default ;

};

class HourlyPricingStrategy:public PricingStrategy{
    private:
    double ratePerHour;
    public:
    explicit HourlyPricingStrategy(double ratePerHour);
    double calculateFee(std::chrono::system_clock::time_point entryTime, std::chrono::system_clock::time_point exitTime)const override;

};