#include <frc/WPILib.h>
#include <frc/Ultrasonic.h>

#include "Ultra.h"

Ultra::Ultra()
{
m_UltraSensor->SetAutomaticMode(true);
}
float Ultra::DistanceToWall()
{
return m_UltraSensor->GetRangeInches();
//    return Ultra->GetRangeInches();
}