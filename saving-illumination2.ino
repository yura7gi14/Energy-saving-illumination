//Vcc: 5V
//Gnd: GND
//Trig: 3逡ｪ繝斐Φ
//Echo: 2逡ｪ繝斐Φ

int TRIG = 3;
int ECHO = 2;
int LED_PIN = 13;

double duration = 0;
double distance = 0;
double speed_of_sound = 331.5 + 0.6 * 25; // 25邃��豌玲ｸｩ縺ｮ諠ｳ螳�

void setup() {
  Serial.begin( 9600 );

  pinMode(ECHO, INPUT );
  pinMode(TRIG, OUTPUT );
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite( TRIG, HIGH );
  delayMicroseconds( 10 ); 
  digitalWrite( TRIG, LOW );
  duration = pulseIn( ECHO, HIGH ); //往復にかかった時間が返却される

  if (duration > 0) {
    duration = duration / 2; 
    distance = duration * speed_of_sound * 100 / 1000000;
    Serial.println((int)distance); //arduino上での出力
    Serial.write((int)distance); //データの出力(arduino→processing)
    if(distance >= 1200){         //距離がだいぶ離れているのなら
      digitalWrite(LED_PIN,LOW); //LEDを光らせない
    }else{
      digitalWrite(LED_PIN,HIGH); //LEDを光らせる
    }
  }

  delay(200);
}