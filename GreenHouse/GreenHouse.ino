#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>
 

OneWire oneWire(9);
int ZrWindOpn = 8, ZrWindCls = 7, FrstWindOpn = 6, FrstWindCls = 5;
int ZrWindSrvPin = 12, FrstWindSrvPin = 11;
Servo ZrWindSrv, FrstWindSrv;
float ZrSensTemp, TmpPrvsZr = 25, ResTmpZr; 

 
DallasTemperature sensor(&oneWire);
 
void setup(){
  Serial.begin(9600);
  sensor.begin();
  sensor.setResolution(12);
  ZrWindSrv.attach(ZrWindSrvPin);
  FrstWindSrv.attach(FrstWindSrvPin);
  pinMode(ZrWindOpn, INPUT);
  pinMode(ZrWindCls, INPUT);
  pinMode(FrstWindOpn, INPUT);
  pinMode(FrstWindCls, INPUT);
}
 
void loop(){
  sensor.requestTemperatures();
  ZrSensTemp = sensor.getTempCByIndex(0);  
  ResTmpZr = (ZrSensTemp + TmpPrvsZr)/2;
  TmpPrvsZr = ZrSensTemp;
  Serial.print("Temp Cish: ");
  Serial.println(ZrSensTemp);
  /*Serial.print("Temp Cres: ");
  Serial.println(ResTmpZr);
  if(ResTmpZr > 25){    
    while(digitalRead(ZrWindOpn) == HIGH){
      ZrWindSrv.write(180);      
    }
    ZrWindSrv.write(76);
  } 
  else{    
    while(digitalRead(ZrWindCls) == HIGH){      
      ZrWindSrv.write(0);
    }
    ZrWindSrv.write(76);
  }*/
  delay(2000);
}
