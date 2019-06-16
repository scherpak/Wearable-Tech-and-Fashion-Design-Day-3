/* Flicker Flare
 *  By Shannon Cherpak
 *  This sketch uses Protosnap plus board to read the raw values coming in
 *  from an analog senser and maps them to a usable range. 
 *  
 *  If the senser is exposed to a lot of light, the LED will turn off. 
 *  The darker it gets, the brighter the LED becomes. 
 */
//variables for input and output on SimpleSnap
 int sensorPin = A5;
 int ledPin1= 10;
 int ledPin2 = 11;
 //variable to store incoming val from sensor 
 int sensorValue = 0;
 
void setup() {
  //declare leds as output 
pinMode(ledPin1, OUTPUT); 
pinMode(ledPin2, OUTPUT);
//declare sensor pin as input 
pinMode(sensorPin, INPUT);
//start serial communication 
Serial.begin(9600);
}

void loop() {
//read the value from the sensor 
sensorValue = analogRead(sensorPin);
//print the raw values for easy comparison 
Serial.print("Raw sensor reading = ");
Serial.println(sensorValue);

//map sensor values based on your readings
int newSensorValue = map(sensorValue, 15, 270, 0, 255);

//constrain the values so you don't get jumpy LED behavior 
newSensorValue = constrain(newSensorValue, 0, 255);

//write the new value to the LEDS
analogWrite(ledPin1, newSensorValue);
analogWrite(ledPin2, newSensorValue);

//Print the value to the serial monitor 
Serial.print("New Sensor Value = ");
Serial.println(newSensorValue);

}
