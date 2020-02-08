#include <Ultra.h>
#include <frc/WPILib.h>
#include <frc/Ultrasonic.h>

Ultra::Ultra()
{
m_UltraSensor->SetAutomaticMode(true);
}
float Ultra::DistanceToWall()
{
return m_UltraSensor->GetRangeInches();
//    return Ultra->GetRangeInches();
}