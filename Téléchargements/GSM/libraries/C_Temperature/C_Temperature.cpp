#include "Arduino.h"
#include "C_Temperature.h"

//public


C_Temperature::C_Temperature(){
  C_Temperature(1);
}

C_Temperature::C_Temperature(int numerodebrochecapteur){
	iTEMnumerobrochecapteur=numerodebrochecapteur;
}

void C_Temperature::PrendreUneMesure(){
	if(siTEMnumMesure>=TEM_NBAMORTI){
	  siTEMnumMesure=0;
	}
	float temperature = getVoltage(iTEMnumerobrochecapteur);  //getting the voltage reading from the temperature sensor
	pfTEMammortissement[siTEMnumMesure] = (temperature - .5) * 100;          //converting from 10 mv per degree wit 500 mV offset
	siTEMnumMesure=siTEMnumMesure+1;      //to degrees ((volatge - 500mV) times 100)
	bTEMtemperatureAjour=false;
}
/*
float C_Temperature::get_temperature(){
	if(!bTEMtemperatureAjour){
	  calculerTemperatureMoyenne();
	}
	return fTEMtemperature;
}
*/

int C_Temperature::get_temperature(){
	if(!bTEMtemperatureAjour){
	  calculerTemperatureMoyenne();
	}
	return (int)fTEMtemperature;
}


//private

void C_Temperature::calculerTemperatureMoyenne(){
	float totaltemperature=pfTEMammortissement[0];
	for(int j=1;j<TEM_NBAMORTI;j++){
	  totaltemperature=pfTEMammortissement[j]+totaltemperature;
	}
	fTEMtemperature=(totaltemperature/TEM_NBAMORTI);
	bTEMtemperatureAjour=true;
}


/*
* getVoltage() - returns the voltage on the analog input defined by
* pin
*/
float C_Temperature::getVoltage(int pin){
	return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
										  // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}
