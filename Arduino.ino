int speakerPin = 3;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);// LED
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);// センサー
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  //センサの値をcmに変換する．
  float V_out = (float)value * 5 / 1024;
  float distance = (V_out - 0.55)/0.033;
  float distance2 = 55 - distance;

  Serial.println(distance2);
  if(distance2<1){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
      for (int i = 0; i < length; i++) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // rest
          digitalWrite(13, LOW);
          delay(500);
        } else {
            playNote(notes[i], beats[i] * tempo);
            digitalWrite(13, HIGH);
            delay(500);
        }
        // pause between notes
        delay(tempo / 2);
    }
    delay(100);
  }
}
