#include <Servo.h>

Servo servoBase;   // Servo da base
Servo servoArm1;   // Servo do braço 1
Servo servoArm2;   // Servo do braço 2
Servo servoClaw;   // Servo da garra

void setup() {
  // Inicializar servos
  servoBase.attach(9);
  servoArm1.attach(10);
  servoArm2.attach(11);
  servoClaw.attach(12);

  // Inicializar comunicação serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    if (command.startsWith("BASE:")) {
      int pos = command.substring(5).toInt();
      servoBase.write(pos);
    } else if (command.startsWith("ARM1:")) {
      int pos = command.substring(5).toInt();
      servoArm1.write(pos);
    } else if (command.startsWith("ARM2:")) {
      int pos = command.substring(5).toInt();
      servoArm2.write(pos);
    } else if (command.startsWith("CLAW:")) {
      int pos = command.substring(5).toInt();
      servoClaw.write(pos);
    }
  }
}

