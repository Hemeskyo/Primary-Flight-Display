#pragma once
#include "FlightData.h"

struct IFlightDataSource{
    virtual ~IFlightDataSource() = default;
    virtual FlightData next(double dt_s) = 0;
};