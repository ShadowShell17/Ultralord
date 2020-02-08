#pragma once

#include <frc/WPILib.h>
#include <frc/Ultrasonic.h>

class Ultra
{
public:
    Ultra();
    float DistanceToWall();
    frc::Ultrasonic *m_UltraSensor = new frc::Ultrasonic(0, 1);
};