vex::brain Brain;

vex::controller Controller = vex::controller();

// choose port, gear setting, and rotate direction
vex::motor Motor1 = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1, true);
