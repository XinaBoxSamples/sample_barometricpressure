#include <xCore.h>  //add core library
#include <xSW01.h>  //add weather sensor library
#include <xOD01.h>

#if defined(ESP8266)
#define RED   RED
#define GREEN GREEN
#define BLUE  BLUE
#include <ESP8266WiFi.h>
#define Serial Serial

#elif defined(ARDUINO_SAMD_ZERO)
#define RED   CC03_RED
#define GREEN CC03_GREEN
#define BLUE  CC03_BLUE
#define Serial SerialUSB

#elif defined(ARDUINO_AVR_PRO)
#define RED   CC01_RED
#define GREEN CC01_GREEN
#define BLUE  CC01_BLUE
#define Serial Serial

#elif defined(ESP32)
#define RED   CW02_RED
#define GREEN CW02_GREEN
#define BLUE  CW02_BLUE
#define Serial Serial
#endif


xSW01 SW01;

const int DelayTime = 500; //Defining set delay time that could be used elsewhere in the code

//Create a variable to store the data read from SW01
float pressure;

void setup(){

  #if defined(ESP8266)
  WiFi.forceSleepBegin();
  Wire.begin(2, 14);
  Wire.setClockStretchLimit(15000);

#elif defined(ARDUINO_SAMD_ZERO)
  Wire.begin();

#elif defined(ARDUINO_AVR_PRO)
  Wire.begin();

#elif defined(ESP32)
  Wire.begin();

#endif
  

  //Initialise variable to zero
  pressure = 0;
  
  //Start Serial Monitor
  Serial.begin(115200);

  //Start SW01 Sensor
  SW01.begin();
  OLED.begin();
  
  //String intro for project
  OD01.println("Barometric Pressure Experiment");
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

