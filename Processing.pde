import processing.serial.*;
Serial sensor;
final String SERIAL_PORT = "COM4";
final int RESOLUTION = 1024;
String values;
float previous = 0.0;
int dataScale = 1;
int dataOffset = 0;
int differenceWindow = 5;
float canvasScaleY = 1.0;

void setup() {
  size(1024, 128);
  textSize(100);
  smooth();
  frameRate(60);
  if(Serial.list()==null)return;
  sensor = new Serial(this, SERIAL_PORT, 9600);
  sensor.clear();
  sensor.bufferUntil('\n');
}

void draw() {
  background(0);
  fill(256, 128, 0);
  text(values, 20, 100);
}

void serialEvent(Serial serial) {
  if (serial != sensor)
    return;
  if (serial == null)
    return;

  String line = serial.readStringUntil('\n');
  line = trim(line);
  if (line == null || line.length() == 0)
    return;

  String[] tokens = splitTokens(line);
  if (tokens.length < 1)
    return;
   
  if((int (tokens[0]))>1){
    values =(tokens[0]);
  }else{
    values = "come humans";
  }
}
