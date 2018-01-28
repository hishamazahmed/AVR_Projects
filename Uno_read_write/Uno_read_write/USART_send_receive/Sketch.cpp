#include <Arduino.h>

String serialDataIn;
String data[3];
int counter;


int inbyte;

void setup(){
	Serial.begin(9600);
	counter = 0;
	serialDataIn = String("");
}

void loop()
{
	if(Serial.available)
	{
		inbyte = Serial.read();
		if(inbyte >= '0' & inbyte <= '9')
		serialDataIn += inbyte;
		if (inbyte == ','){  // Handle delimiter
			data[counter] = String(serialDataIn);
			serialDataIn = String("");
			counter = counter + 1;
	}
		if(inbyte ==  '\r')
			{  
			}
	}
}

// if(Serial.available())
// {
// 	byteRead =Serial.read();
// 	char arr[]="";
// 	int i=0;
// 	if(byteRead ==',' )
// 	{
// 		arr[i] =(byte)byteRead;
// 		i++;
// 	}
// 	
// 	delay(1000);
// 	Serial.write(arr[i]);
// 	Serial.println(atoi(arr[i]), BIN);
// }
