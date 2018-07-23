#include <xCore.h>  //add core library
#include <xSW01.h>  //add weather sensor library
#include <xOD01.h>

xSW01 SW01;

const int DelayTime = 500; //Defining set delay time that could be used elsewhere in the code

//Create a variable to store the data read from SW01
float pressure;

void setup(){

  //Initialise variable to zero
  pressure = 0;
  
  //Start Serial Monitor
  Serial.begin(115200);

  //Start I2C communication
  Wire.begin(2, 14);

  //Start SW01 Sensor
  SW01.begin();
  OLED.begin();
  
  //String intro for project
  OD01.println("Pressure Experiment");
  OD01.println("______________________________________");

  //Delay for sensor to normalise
  delay(3000);
  
}

void loop(){
  
  //Read and calculate data from SW01
  SW01.poll();

  //Request to get humidity, temperature and dew point data then store in the variables
  pressure = SW01.getPressure();


  //Display recorded data over the Serial Monitor

  OD01.print("Pressure:");
  OD01.print(pressure);
  OD01.println("Pa ");

  delay(5000);

}

