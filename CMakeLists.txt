cmake_minimum_required(VERSION 3.16)
project(parking_lot_LLD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(parking_lot_LLD
    src/main.cpp
    src/Vehicle.cpp
    src/VehicleFactory.cpp
    src/ParkingSpot.cpp
    src/ParkingFloor.cpp
    src/ParkingLot.cpp
    src/ParkingTicket.cpp
    src/ParkingStrategy.cpp
    src/PricingStrategy.cpp
)

target_include_directories(parking_lot_LLD PRIVATE includes)
