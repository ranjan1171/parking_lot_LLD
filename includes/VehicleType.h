#pragma once

enum class VehicleType {
    BIKE,
    CAR,
    TRUCK
};

// Scoped values such as VehicleType::CAR are clear and avoid implicit integer conversions.