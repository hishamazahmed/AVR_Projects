
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 

// Setup a oneWire instance to communicate with any OneWire devices  (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int val, val_digital;
int tempPin = A0;

void setup()
{
  Serial.begin(57600);
  Serial.println("Dallas Temperature IC Control Library Demo");  
  sensors.begin(); 
}
void loop()
{
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  Serial.println();
  Serial.println();
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);

  Serial.print(" Requesting temperatures..."); 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Serial.println("DONE"); 

  Serial.print("Temperature is: "); 
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000); 
}


