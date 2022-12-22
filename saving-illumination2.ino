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
  duration = pulseIn( ECHO, HIGH ); // 蠕蠕ｩ縺ｫ縺九°縺｣縺滓凾髢薙′霑泌唆縺輔ｌ繧擬繝槭う繧ｯ繝ｭ遘綻

  if (duration > 0) {
    duration = duration / 2; // 蠕霍ｯ縺ｫ縺九°縺｣縺滓凾髢�
    distance = duration * speed_of_sound * 100 / 1000000;
    Serial.println((int)distance);

    if(distance > 100){
        digitalWrite(LED_PIN,HIGH);
    }else{
        digitalWrite(LED_PIN,LOW);
    }
  }

  delay(200);
}