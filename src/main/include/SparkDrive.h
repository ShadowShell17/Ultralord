#pragma once

#include <rev/CANSparkMax.h>

class SparkDrive
{
    public:
    SparkDrive(rev::CANSparkMax *lFront_m, rev::CANSparkMax *rFront_m, rev::CANSparkMax *lBack_m, rev::CANSparkMax *rBack_m);

    void TankDrive(double xAxis, double yAxis, double rot, bool turboButton, bool slowButon);

    private:
    rev::CANEncoder lFrontEncoder;
    rev::CANEncoder rFrontEncoder;
    rev::CANEncoder lBackEncoder;
    rev::CANEncoder rBackEncoder;

    rev::CANPIDController lFrontPID;
    rev::CANPIDController lBackPID;
    rev::CANPIDController rFrontPID;
    rev::CANPIDController rBackPID;

    rev::CANSparkMax *lFront;
    rev::CANSparkMax *lBack;
    rev::CANSparkMax *rFront;
    rev::CANSparkMax *rBack;
};