#include <Servo.h>

Servo myservo6,myservo9,myservo10,myservo11;  

int pot6 = 0; //pinza
int pot9 = 1; //primer eslabon
int pot10 = 2; //giro pinza
int pot11 = 3;   //base
int val6,val9,val10,val11;   

void setup() {
  myservo6.attach(6); //pinza
  myservo9.attach(9); //primer eslabon
  myservo10.attach(10); //giro pinza
  myservo11.attach(11); //base
  myservo6.write(50); //pinza
  myservo9.write(100); //primer eslabon
  myservo10.write(0); //giro pinza
  myservo11.write(0); //base
}

void loop() {
  val9 = analogRead(pot9);
  val6 = analogRead(pot6);
  val10 = analogRead(pot10);
  val11 = analogRead(pot11);          
  val6 = map(val6, 0, 1023, 0, 180); //giro pinza----
  val9 = map(val9, 0, 1023, 50, 150); //primer eslabon
  val10 = map(val10, 0, 1023, 8, 180); //pinza
  val11 = map(val11, 0, 1023, 0, 180);   //base ------
  myservo10.write(val10);    //giro pinza           
  delay(15); 
  myservo9.write(val9);     //primer eslabon           
  delay(15);
  myservo6.write(val6);      //pinza          
  delay(15);
  myservo11.write(val11);     //base           
  delay(15);              
}

