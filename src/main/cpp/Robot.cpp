#include "Robot.h"

void Robot::RobotInit() 
{
  m_chooser.SetDefaultOption(AutoDefault, AutoDefault);
  m_chooser.AddOption(Auto2, Auto2);
  m_chooser.AddOption(Auto3, Auto3);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  js1 = new frc::Joystick(0);
  lFront = new rev::CANSparkMax(10, rev::CANSparkMax::MotorType::kBrushless);
  rFront = new rev::CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushless);
  lBack = new rev::CANSparkMax(2, rev::CANSparkMax::MotorType::kBrushless);
  rBack = new rev::CANSparkMax(3, rev::CANSparkMax::MotorType::kBrushless);
  sparkDrive = new SparkDrive(lFront, lBack, rFront, rBack);
  ultra = new Ultra();
  
}

void Robot::RobotPeriodic() 
{

}

void Robot::AutonomousInit() 
{
  m_autoSelected = m_chooser.GetSelected();
}

void Robot::AutonomousPeriodic() 
{  
  if(m_autoSelected == AutoDefault)
  {
    std::cout << "auto" << std::endl;
  }
  else if(m_autoSelected == Auto2)
  {
    sparkDrive->TankDrive(0, -.5, 0, 0, 0);
  }
  else if(m_autoSelected == Auto3)
  {
    std::cout << "auto" << std::endl;
  }
}

void Robot::TeleopInit() 
{
  turbodumb = false;
  m_autoSelected = m_chooser.GetSelected();
}

void Robot::TeleopPeriodic() 
{
  SmartDashboard::PutNumber("Ultra Distance",ultra->DistanceToWall());
  if(js1->GetRawButton(3) && turbodumb == false && count > 10)
  {
    turbodumb = true;
    count = 0;
  }
  else if(js1->GetRawButton(3) && turbodumb == true && count > 10)
  {
    turbodumb = false;
    count = 0;
  }
  count++;
sparkDrive->TankDrive(false, -(js1->GetRawAxis(1)), js1->GetRawAxis(2), turbodumb, false);
}

void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
