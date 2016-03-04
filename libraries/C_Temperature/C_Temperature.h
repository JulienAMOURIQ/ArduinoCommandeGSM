
/**************************************************
 * 
 * Classe C_Temperature
 * 
 **************************************************/
  
#ifndef C_Temperature_h
#define C_Temperature_h

#include "Arduino.h"

#define TEM_NBAMORTI 15
class C_Temperature{
 public:
  C_Temperature();
  C_Temperature(int numerodebrochecapteur);
  void PrendreUneMesure();
  
  //float get_temperature();
  int get_temperature();
  
 private:
  short int siTEMnumMesure;
  int iTEMnumerobrochecapteur;
  float pfTEMammortissement[TEM_NBAMORTI];
  float fTEMtemperature;
  boolean bTEMtemperatureAjour;
  
  
  void calculerTemperatureMoyenne();
  
   /*
   * getVoltage() - returns the voltage on the analog input defined by
   * pin
   */
  float getVoltage(int pin);

};
#endif