#include <HCSR04.h>

HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  double dist = hc.dist();
  if(dist < 20)
  {
    Serial.println("distance is: " + String(dist));
    digitalWrite(2, HIGH);
    Serial.println("Distance is below 20cm, turning on LED");
  }
  else
  {
    Serial.println("distance is: " + String(dist));
    Serial.println("Distance is above 20cm, turning off LED");
    digitalWrite(2, LOW);
  }
  
  delay(1000);

}