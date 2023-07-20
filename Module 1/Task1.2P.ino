#include <HCSR04.h>

const uint8_t trig_pin = 8;
const uint8_t echo_pin = 9;
const uint8_t led_pin = 13;
const uint8_t button_pin = 2;

int dist;
bool measurement = false;

HCSR04 hc(trig_pin, echo_pin);

void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(button_pin), test, FALLING);
}

void loop()
{
  if (measurement)
  {
    dist = hc.dist();
    Serial.println("Distance is: " + String(dist) + " cm");

    if (dist < 20)
    {
      digitalWrite(led_pin, HIGH);
      Serial.println("Distance is below 20cm, turning on LED");
    }
    else
    {
      digitalWrite(led_pin, LOW);
      Serial.println("Distance is above 20cm, turning off LED");
    }
  }
  delay(1000);
}

void test()
{
  measurement = !measurement;
  Serial.println(measurement);

  if (measurement)
  {
    Serial.println("Measurement started!!");
  }
  else 
  {
    Serial.println("Measurement stopped!!");
  }
  delay(50);
}
