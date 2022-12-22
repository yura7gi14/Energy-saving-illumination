//照度センサーだけのプログラム


const int SENSOR = A0;

  Serial.begin(9600);
}


  int sensor = analogRead(SENSOR);
  Serial.println(sensor);
}