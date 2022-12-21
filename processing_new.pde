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
  fill(100,0,0);              //色指定
  rect(x, y, 800, 65);        //ゲージの下地描画
  
  fill(255,255,0);            //色指定
  //横軸表示
  textSize(20);               //テキストサイズ
  textAlign(CENTER);          //中央揃え
  text(  0, x,        150);   //0
  text( 50, x+val1,   150);   //50
  text(100, x+val1*2, 150);   //100
  text(150, x+val1*3, 150);   //150
  text(200, x+val1*4, 150);   //200
  text(250, x+val1*5, 150);   //250
  text(300, x+val1*6, 150);   //300
  text(350, x+val1*7, 150);   //350
  text(400, x+val1*8, 150);   //400
  text("cm", x+val1*8+40, 150); //cm
  
  //距離ゲージ表示
  fill(255,255,0);               //色指定
  rect(x, y, distance*val2, 65); //横棒描画
  
  fill(255,0,0);                 //色指定
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