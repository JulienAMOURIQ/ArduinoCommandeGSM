
/************************************************
 * 
 *      Classe C_CommunicationGSM
 *      hérite de C_ICommStd
 * 
 **************************************************/
#include "Arduino.h"
#include "C_CommunicationGSM.h"
 

  /*
  * @Brief initialise la connection avec la carte SIM.
   */
  void C_CommunicationGSM::COGconnecter_GSM(){
    Serial.println("SMS Messages Receiver");

    // connection state
    boolean notConnected = true;

    // Start GSM shield
	int i=0;
    while(notConnected){
		Serial.println("essai connection");;
		i++;
		if (i<3){
			if(COGgsmAccess.begin(pcCOGcodepinsim)==GSM_READY){
				
				notConnected = false;
			}else{
				Serial.print("Not connected. pin :" );
				Serial.println(pcCOGcodepinsim);
				delay(1000);
			}
		}else{
			Serial.println("Non connecte. sécurite anti pinbreak enclenchee" );
			delay(2000);
		}
    }
    Serial.println("GSM initialisé");
  }

    //constructeurs
  C_CommunicationGSM::C_CommunicationGSM(){
    C_CommunicationGSM("0000");
  }

  C_CommunicationGSM::C_CommunicationGSM(char *ccodepinsim){
	 // COGgsmAccess= GSM(true);
    strncpy(pcCOGcodepinsim,ccodepinsim,COG_TAILLEPINSIM);
  }

  //redéfinition de méthodes héritées

  void C_CommunicationGSM::ICSinitialiser(){
    COGconnecter_GSM();
  }
  void C_CommunicationGSM::ICSenvoyerMessage(char *message,char *destinataire){
    COGsms.beginSMS(destinataire);
    COGsms.print(message);
    COGsms.endSMS();
  }

  boolean C_CommunicationGSM::bICSnouveau_message_disponible(){
    if(COGsms.available()){
      return true ;
    }
    else{
      return false; 
    }
  }

  void C_CommunicationGSM::ICSrecevoirMessage(){
    {
      char ctampon[ICS_TAILLEMESSAGE];
      int iboucle;
      iboucle=0;   
	  COGsms.remoteNumber(ctampon, 10);
      setICSemetteur(ctampon);
      while(ctampon[iboucle]=COGsms.read()){
        if(iboucle<ICS_TAILLEMESSAGE-1){
          iboucle++;
        }
      }
	  if(iboucle>0){
		  ctampon[ICS_TAILLEMESSAGE-1]='\0';
		  setICSmessage(ctampon);
	  }
    }
    char ctampon[ICS_TAILLEEMETTEUR];
 
    COGsms.flush();
  }
/*
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
  */