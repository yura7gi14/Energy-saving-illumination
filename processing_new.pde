//Original :04 シリアル通信でProcessingと連携(Processing)

import processing.serial.*;

Serial port; 
int inByte;

void setup(){
  println(Serial.list());
  String arduinoPort = Serial.list()[4];              // printlnで表示された番号を4の代わりに入れる
  port = new Serial(this, arduinoPort, 9600);  // Arduino
}

void draw(){
  delay(100);
  background(0);  // 背景を黒に。
  text(inByte,50,50); //テキスト（変数inByteの値）を50,50の位置に表示
  
}

void serialEvent(Serial p){
  delay(10);
  inByte=port.read();
}