const int SENSOR_PIN = A0;
const int LED_PIN = 13;
int sensorValue = 0;
int ledValue = 0;
const int sensorMIN = 200;
const int sensorMAX = 900;

double Duration = 0;
double Distance = 0;
double speed_of_sound = 331.5+0.6*25;

const int TrigPin=3;
const int EchoPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(SENSOR_PIN);
  Serial.println(sensorValue);

  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);

  //超音波を出力するためのトリガ信号生成
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  Duration = pulseIn( EchoPin, HIGH ); //11番ピンに入力されるEchoピンのHigh期間を測定
  
  ledValue = (int)(sensorValue - sensorMIN)*255.0/(sensorMAX - sensorMIN);
  if (ledValue < 0) {
    ledValue = 0; //昼
  }
  if (ledValue > 255) {
    ledValue = 255; //夜
    //ここでLEDのつけるつけない判定を行う
    if(Duration > 0){
     Duration = Duration / 2;
     Distance = Duration * speed_of_sound * 100 / 1000000;
     if(Distance > 100){
      digitalWrite(LED_PIN,HIGH);
     }else{
      digitalWrite(LED_PIN,LOW);
     }
    }
  }  
  analogWrite(LED_PIN, ledValue);

  delay(100);
}