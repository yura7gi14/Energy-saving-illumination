const int SENSOR_PIN = A0;
const int LED_PIN = 11;
int sensorValue = 0;
int ledValue = 0;
const int sensorMIN = 200;
const int sensorMAX = 900;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(SENSOR_PIN);
  Serial.println(sensorValue);
  
  ledValue = (int)(sensorValue - sensorMIN)*255.0/(sensorMAX - sensorMIN);
  if (ledValue < 0) {
    ledValue = 0; //昼
  }
  if (ledValue > 255) {
    ledValue = 255; //夜
    //ここでLEDのつけるつけない判定を行う
  }  
  analogWrite(LED_PIN, ledValue);

  delay(100);
}