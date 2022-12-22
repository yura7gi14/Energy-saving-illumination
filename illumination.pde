import processing.serial.*; 
Serial myPort;              
PFont  myFont;              

int distance =   0;
int x = 200, y= 60;
int val1     = 100;
int val2     = val1/50;
int c;
//String v = "";

void serialEvent(Serial p){
  if(myPort.available()>=2){
    c = myPort.read();
    distance = myPort.read();
  }
}

void setup(){
  size(1200,200);                      
  background(0,0,0);                  
  
  println("Available serial ports:");
  printArray(Serial.list());           
  //printArray(PFont.list());          
  
  myPort = new Serial(this, Serial.list()[0], 9600); 
  myPort.clear();                                    
  myFont = createFont("Meiryo UI Bold", 80);        
  textFont(myFont);
}

void draw(){
  background(0,0,0);          
  

  fill(255);              
  rect(x, y, 800, 65);        
  
  
  fill(0);                 
  textSize(60);                 
  textAlign(RIGHT);  
  text(distance, 350, 115);      
  
  textSize(30);                  
  textAlign(LEFT);               
  text("cm", 355, 115);         
  if(distance < 15){
    textSize(60);
    textAlign(RIGHT);
    text("come humans", 1000,120);
  }else{
    text("", 1000, 120);
  }

  delay(500);
}