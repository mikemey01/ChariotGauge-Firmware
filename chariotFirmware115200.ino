String one = "1";
String mapSensor;
String tempSensor;
String widebandSensor;
String oilSensor;
String volts;
String sendData;

int aInput0=0; //Analog input pin 0
int aInput1=1; //Analog input pin 1
int aInput2=2; //Analog input pin 2
int aInput3=3; //Analog input pin 3
int aInput4=4; //Analog input pin 4

int initTemp=0;
int reading[5];

void setup(void) {
  
  pinMode(aInput1, INPUT); //Set the analog pin 1 to input
  pinMode(aInput2, INPUT); //Set the analog pin 2 to input
  pinMode(aInput4, INPUT); //Set the analog pin 4 to input
  
  // We'll send debugging information via the Serial monitor 
  Serial.begin(115200);
  delay(800);
}

void loop(void) {
  
  if(initTemp == 9){
    pinMode(aInput3, INPUT); //Set the analog pin 2 to input
    pinMode(aInput0, INPUT); //set the voltage input pin.
  }
  
  if(initTemp < 10){

    volts = one;//(String)readPin(0);
      delay(5);
    mapSensor = (String)readPin(aInput1);
      delay(5);
    widebandSensor = (String)readPin(aInput2);
      delay(5);
    tempSensor = one;
      delay(5);
    oilSensor = (String)readPin(aInput4);
      delay(5);

    sendData =  volts + "," + 
                mapSensor + "," + 
                initTemp + "," +
                initTemp + "," +
                initTemp;
    initTemp = initTemp + 1;
    delay(5);
  }else{
    volts = (String)readPin(aInput0);
    tempSensor = (String)readPin(aInput3);
    mapSensor = (String)readPin(aInput1);
    oilSensor = (String)readPin(aInput4);
    widebandSensor = (String)readPin(aInput2);

    sendData =  volts + "," + 
                mapSensor + "," + 
                widebandSensor + "," +
                tempSensor + "," +
                oilSensor;
    delay(60);
  }

  Serial.println(sendData);
  
}

int readPin(int aInputNum){
  int sval = 0;
  int temp = 0;
  int w = 0;

  for (int k = 0; k < 5; k++){ //Loop through the sensor four times
    reading[k] = analogRead(aInputNum);
  }
  
  //Sort
  for (int i=0; i< 4; i++){
    for (int j=i+1; j< 5; j++){
      if (reading[i] > reading[j]){
      
        w = reading[i];
        reading[i] = reading[j];
        reading[j] =w;
      }
    }
  }
  
  sval = (reading[0]+reading[1]+reading[2]) / 3;    // average
  return sval;  //return
}



