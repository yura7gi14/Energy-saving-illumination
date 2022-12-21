import processing.serial.*; //Arduinoと通信するためのライブラリの読み込み
Serial myPort;              //シリアル通信を行うための変数を定義
PFont  myFont;              //画面に表示するフォントの指定

int distance =   0;
int x = 200, y= 60;
int val1     = 100;
int val2     = val1/50;

void serialEvent(Serial p){
  distance = myPort.read();
}

void setup(){
  size(1200,200);                      //ウィンドウサイズ
  background(0,0,0);                   //背景の色
  
  println("Available serial ports:");
  printArray(Serial.list());           //使用できるCOMポートの取得
  //printArray(PFont.list());          //使用できるFontの表示、わからないときに使用
  
  myPort = new Serial(this, Serial.list()[0], 9600); //通信するポートと速度の設定、Arduinoと合わせる必要あり
  myPort.clear();                                    //受信データをクリア
  myFont = createFont("Meiryo UI Bold", 80);         //Font指定、サイズ80pt
  textFont(myFont);
}

void draw(){
  background(0,0,0);          //画面の再描画
  
  //ゲージの下地描画
  fill(255);              //色指定
  rect(x, y, 800, 65);        //ゲージの下地描画
  
  
  fill(0);                 //色指定
  //距離表示
  textSize(60);                  //テキストサイズ
  textAlign(RIGHT);              //右揃え
  text(distance, 350, 115);      //距離の表示
  
  //cm表示
  textSize(30);                  //テキストサイズ
  textAlign(LEFT);               //左揃え
  text("cm", 355, 115);          //cm表示


  
  delay(100);
}