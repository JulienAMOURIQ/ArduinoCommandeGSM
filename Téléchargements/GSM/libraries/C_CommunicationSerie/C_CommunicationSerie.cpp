
/************************************************
 * 
 *      Classe C_CommunicationSerie
 *      hérite de C_ICommStd
 * 
 **************************************************/
#include "Arduino.h"
#include "C_CommunicationSerie.h"
 

    //constructeurs
  C_CommunicationSerie::C_CommunicationSerie(){
    
  }

  //redéfinition de méthodes héritées

  void C_CommunicationSerie::ICSinitialiser(){
    Serial.begin(9600);
  }
  void C_CommunicationSerie::ICSenvoyerMessage(char *message,char *destinataire){
	Serial.print(message);
  }

  boolean C_CommunicationSerie::bICSnouveau_message_disponible(){
    if (Serial.available() > 0){
      return true ;
    }
    else{
      return false; 
    }
  }

  void C_CommunicationSerie::ICSrecevoirMessage(){
      char ctampon[ICS_TAILLEMESSAGE];
      int iboucle;
      iboucle=0;
      while(Serial.available() > 0 && iboucle <ICS_TAILLEMESSAGE-1){
		ctampon[iboucle]=Serial.read();
        iboucle++;
      }
	  if(iboucle>0){
		  //on a effectivement lut quelquchose...
		ctampon[iboucle]='\0';
		setICSmessage(ctampon);
	}
  }
