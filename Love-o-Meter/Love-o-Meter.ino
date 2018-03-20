const int sensorPin = A0;
const float baselineTemp = 30.0;

int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Open a serial port
  for(int pinNumber = 2; pinNumber < 5;pinNumber++ ) {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  // convert the ADC reading to voltage
  float voltage = (sensorValue/1024.0)*5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C : ");
  // convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp + 3 && temperature < baselineTemp + 6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp + 6 && temperature < baselineTemp + 8) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  } else if(temperature >=  baselineTemp + 8) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  delay(1);
}

