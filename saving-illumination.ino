const int SENSOR_PIN = A0;
const int LED_PIN = 11;
int sensorValue = 0;
int ledValue = 0;
const int sensorMIN = 200;
const int sensorMAX = 900;

float ProDelay = 0;
float Distance = 0;

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

  degitalWrite(TrigPin,LOW);
  delayMicroseconds(10);

  //超音波を出力するためのトリガ信号生成
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  ProDelay = pulseIn( EchoPin, HIGH ); //11番ピンに入力されるEchoピンのHigh期間を測定
  
  ledValue = (int)(sensorValue - sensorMIN)*255.0/(sensorMAX - sensorMIN);
  if (ledValue < 0) {
    ledValue = 0; //昼
  }
  if (ledValue > 255) {
    ledValue = 255; //夜
    //ここでLEDのつけるつけない判定を行う
    if(ProDelay > 0){
      Distance = 340*ProDelay/2/10000; // 音速340m/sとして距離の計算とcmへの換算
    }
  }  
  analogWrite(LED_PIN, ledValue);

  delay(100);
}