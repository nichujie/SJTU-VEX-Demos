#include "robot-config.h"


vex::competition    Competition;

void pre_auton( void ) {}

void autonomous( void ) {}

void usercontrol( void ) {
  int C1 = 0;
    
  while (1) {
    C1 = Controller.Axis1.position(vex::percentUnits::pct);

    if (Controller.ButtonA.pressing()) {
      Motor1.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
    } else if (C1) {
      Motor1.spin(vex::directionType::fwd, C1, vex::velocityUnits::pct);
    } else {
      Motor1.stop(vex::brakeType::brake);
    }
      
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }

}


int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    // Ni Chujie: Do not write any code in this while loop!!
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}