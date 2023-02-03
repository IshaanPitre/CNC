#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Stepper.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(11, 12); // change pins later
//Stepper Stepperx(200, 7, 8, 9, 10);
//Stepper Steppery(200, 3, 4, 5, 6); // change pins later
Servo arm;

AccelStepper stepper1(AccelStepper::FULL4WIRE, 7, 8, 9, 10);
AccelStepper stepper2(AccelStepper::FULL4WIRE,2, 4, 5, 6);

int conversion = 1;
bool newData = false;
char endMarker = '~';
char recievedChars[30];

String recievedCharsString;
char xsteps[10];
char ysteps[10];
int current = 0;

MultiStepper steppers;

void setup() {

  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("hello");

  arm.attach(3);

  stepper1.setMaxSpeed(400);
  stepper2.setMaxSpeed(400);

  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);

  // put your setup code here, to run once:



}

void loop() {
//   put your main code here, to run repeatedly:
  readCommand();
  processCommand();

//   BTSerial.write("hello");
//   delay(1000);
//   BTSerial.println("hello1");
//   delay(1000);
//   BTSerial.print("hello1");
//   delay(1000);

}

void readCommand() {

  current = 0;

  while (BTSerial.available() > 0 and newData == false) {

    char rc = BTSerial.read();

    if (rc != endMarker) {
      recievedChars[current] = rc;
      //
      //     no idea why but keep this
      delay(1);
      //      Serial.print(" ");
      //      Serial.println(current);
      current = current + 1;
    }



    else {

//      Serial.println("rc == endmarketr");
      //      Serial.println(recievedChars);
      current = 0;
      newData = true;
    }
  }
}

// x1000y1000, numbers is prob steps

void processCommand() {

  //  Serial.println("in process command");
  //  Serial.println(recievedChars[0]);
  if (recievedChars[0] != 'q') {
    Serial.println(recievedChars);
    // Coordinate
    if (recievedChars[0] == 'c') {

      recievedCharsString = recievedChars;
      //
      //
      //      recievedCharsString.substring(2, 6).toCharArray(xsteps, 5);
      //      recievedCharsString.substring(7, 11).toCharArray(ysteps, 5);
      //
      //      Serial.print("Recieved: ");
      //      Serial.println(recievedCharsString);
      //
      //      Serial.print("xsteps: ");
      //      Serial.println(xsteps);
      //
      //      Serial.print("ysteps: ");
      //      Serial.println(ysteps);
      //
      //      int xpos = atoi(xsteps);
      //      int ypos = atoi(ysteps);
      //
      //      Serial.print("xpos: ");
      //      Serial.println(xpos);
      //
      //      Serial.print("ypos: ");
      //      Serial.println(ypos);
      //
      //      Steppery.setSpeed(100);
      //      Stepperx.setSpeed(100);
      //
      //      Serial.print("Y is stepping: ");
      //
      //      float ystep = (float) ypos/abs( (float) xpos);
      //
      //      Serial.println( ystep );
      //
      //      Serial.print("X is stepping: ");
      //      Serial.println(round (abs( (float) xpos)/ (float) xpos) );
      //
      //      Serial.print(abs(xpos));
      //      Serial.println(" times");
      //
      //      float count = 0;
      //
      //      for (int i = 0; i < abs(xpos); i++) {
      //
      //        Stepperx.step( round( abs((float) xpos)/ (float) xpos) );
      //
      //        count += ystep;
      //
      //
      //        Steppery.step( round(count) );
      //        count -= round(count);



    }



    else if (recievedChars[0] == 'd') {
      recievedCharsString = recievedChars;


      recievedCharsString.substring(2, 6).toCharArray(xsteps, 5);
      int xpos = atoi(xsteps);
      
      Serial.println("u");
      arm.attach(3);
      delay(20);
      arm.write(xpos);
      delay(1000);
      arm.detach();
      newData = false;

    }
    else if (recievedChars[0] == 'u') {

      arm.attach(3);
      delay(20);
      Serial.println("d");
      arm.write(180);
      delay(1000);
      arm.detach();
      newData = false;

    }
    else if (recievedChars[0] == 't') {

      recievedCharsString = recievedChars;


      recievedCharsString.substring(2, 6).toCharArray(xsteps, 5);
      recievedCharsString.substring(7, 11).toCharArray(ysteps, 5);

//      Serial.print("Recieved: ");
//      Serial.println(recievedCharsString);

//      Serial.print("xsteps: ");
//      Serial.println(xsteps);
//
//      Serial.print("ysteps: ");
//      Serial.println(ysteps);

      int xpos = atoi(xsteps);
      int ypos = atoi(ysteps);

//      Serial.print("xpos: ");
//      Serial.println(xpos);
//
//      Serial.print("ypos: ");
//      Serial.println(ypos);

      long positions[2];
      positions[0] = xpos;
      positions[1] = ypos;

      steppers.moveTo(positions);
      steppers.runSpeedToPosition();
      Serial.println("Ran to positions");
      BTSerial.write("hello");
      BTSerial.print("hello1");
   
      newData = false;



    }
  }
     recievedChars[0] = 'q';

}

void initMachine() {



}
