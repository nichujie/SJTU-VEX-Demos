#include "robot-config.h"


vex::competition    Competition;

void pre_auton( void ) {}

void autonomous( void ) {}

void usercontrol( void ) {
  Motor1.resetRotation();
    
  while (1) {
    if (Controller.ButtonA.pressing()) {
        // This while loop is used to eliminate continuous button signal
        // to implement "one button".
        while (Controller.ButtonA.pressing()) {}
        
        Motor1.startRotateFor(360, vex::rotationUnits::deg);
        // This sleep is only intended for you to feel the execution of the previous command.
        vex::task::sleep(100);
    } else if (Controller.ButtonB.pressing()) {
        while (Controller.ButtonB.pressing()) {}
        
        Motor1.rotateFor(360, vex::rotationUnits::deg);
    } else {
        Motor1.stop(vex::brakeType::coast);
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