#pragma once

#include <string>

#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/Ultrasonic.h>

#include "SparkDrive.h"
#include "Ultra.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  frc::Joystick *js1;
  rev::CANSparkMax *lFront;
  rev::CANSparkMax *rFront;
  rev::CANSparkMax *lBack;
  rev::CANSparkMax *rBack; 
  SparkDrive *sparkDrive;
  Ultra *ultra;

  bool turbodumb;
  int count;
  
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string AutoDefault = "Default";
  const std::string Auto2 = "Auto 2";
  const std::string Auto3 = "Auto 3";
  std::string m_autoSelected;
};
