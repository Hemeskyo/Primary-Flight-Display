#include <iostream>
#include "SimulatedSource.h"
#include <thread>
#include <chrono>
int main()
{
    SimulatedSource sim;
    IFlightDataSource &src = sim;

    for (int i = 0; i < 12; i++)
    {
        sim.setHeadingTarget(280);
        sim.setAp(true);
        FlightData d = src.next(1.0);
        
        std::cout << "Altitude: " << d.altitude_ft
                  << "\nIAS: " << d.ias_kt
                  << "\nHDG: " << d.heading_deg;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    };

    return 0;
};