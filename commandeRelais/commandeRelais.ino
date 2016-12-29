


/************************************************************************
 * 
 * CLASSES ANNEXES
 * 
 * 
 ************************************************************************/

#define VIAGSM


#include <ICommStd.h>

#include <GSM.h>  //il faut l'inclure pour que l'inclusion dans C_CommunicationGSM.h compte . Je ne sais pas pourquoi.
#include <C_CommunicationGSM.h>

//#include <C_CommunicationSerie.h>


#include <C_Temperature.h>











class C_Pin{
private:
  boolean bEtatPin;
  int iPin;

public:
  boolean get_bEtatPin(){
    return bEtatPin;
  }

  C_Pin(){
    C_Pin(12);
  }

  C_Pin(int inumpin){
    iPin=inumpin;
    bEtatPin=false;
    pinMode(iPin, OUTPUT);
    digitalWrite(iPin, LOW);
  }

  void setEtatPin(boolean bnouvel_etat){
    bEtatPin=bnouvel_etat;
    if(bEtatPin){
      digitalWrite(iPin, HIGH);
    }
    else{
      digitalWrite(iPin, LOW);
    }
  }

  boolean getEtatPin(){
    return bEtatPin;
  }

};








/**************************************************
 * 
 * Classe C_Instruction
 * 
 **************************************************/

#define TAILLE_EMMETTEUR 15
#define INS_ALLUMER 10
#define INS_AIDE 1
#define INS_ETEINDRE 20
#define INS_ENVOYER_ETAT 30
class C_Instruction{
private:
  char pcINSemmetteur[TAILLE_EMMETTEUR];
  int iINSinstruction;
  C_Pin INSpinrelais;

public:
  C_Instruction(){
    iINSinstruction=0;//ne rien faire
  }
  C_Instruction(C_Pin & brocheautiliser){
    INSpinrelais=brocheautiliser;
    C_Instruction();
  }

  void setEmmetteur(C_ICommStd &interface){
    char * monemetteur=interface.get_emetteur();
    strncpy(pcINSemmetteur,monemetteur,TAILLE_EMMETTEUR); //strcpy(destination,source)
    free(monemetteur);
  }

  void setInstruction(C_ICommStd &interface){

    char *pcTexteduMessage;
    interface.ICSrecevoirMessage();
    pcTexteduMessage=interface.get_message();
    iINSinstruction=0;
        if(strcmp (pcTexteduMessage, "aide")==0){
      iINSinstruction=INS_AIDE;
    }
    if(strcmp (pcTexteduMessage, "allumer")==0){
      iINSinstruction=INS_ALLUMER;
    }
    if(strcmp (pcTexteduMessage, "eteindre")==0){
      iINSinstruction=INS_ETEINDRE;
    }
    if(strcmp (pcTexteduMessage, "etat?")==0){
      iINSinstruction=INS_ENVOYER_ETAT;
    }
    Serial.print(pcTexteduMessage);
    
    // libération de la mémoire
    free(pcTexteduMessage); 
  }


  void INSexecuter(C_ICommStd &interface,C_Temperature &lethermometre){
    if(iINSinstruction==INS_ALLUMER){
      INSpinrelais.setEtatPin(1);
    }
    if(iINSinstruction==INS_ETEINDRE){
      INSpinrelais.setEtatPin(0);
    }
    if(iINSinstruction==INS_AIDE){

      interface.ICSenvoyerMessage("aide: renvoie l'aide\neteindre:éteint l'appareil electro-menager\nallumer:le contraire d'eteindre\netat?:renvoie un sms de diagnostique\nFIN DE L'AIDE",pcINSemmetteur);
    }
    if(iINSinstruction==INS_ENVOYER_ETAT){
      char texteMessage[50]="Temperature actuelle:"; //21 caractères + car nul
      char temperature[6];
      sprintf(texteMessage,"Temperature actuelle: %d", (int)(lethermometre.get_temperature())); 
      //strcat(texteMessage,temperature); //26 caractères + caractère nul
      
      if(INSpinrelais.get_bEtatPin()){
        strcat(texteMessage,".Chauffage :ON\n"); //26+17 caractères + caractère nul = 44caractères
      }else{
        strcat(texteMessage,".Chauffage :OFF\n");
      }
      interface.ICSenvoyerMessage(texteMessage,pcINSemmetteur);
    }
  }

};










/************************************************************************
 * 
 * PROGRAMME PRINCIAL
 * 
 * 
 ************************************************************************/
#define CODEPINSMS "1527"


C_Instruction uneInstruction;

#ifdef VIAGSM
  C_CommunicationGSM vecteurcomm(CODEPINSMS); //PIN à 0
#endif
#ifdef VIASERIE
  C_CommunicationSerie vecteurcomm;
#endif

C_Temperature monthermometre(A0);

void setup(){
  C_Pin pinduRelais=C_Pin(A1);
  #ifdef VIAGSM
    // initialize serial communications
    Serial.begin(9600); 
  #endif

  vecteurcomm.ICSinitialiser();
  uneInstruction=C_Instruction(pinduRelais);
  monthermometre.PrendreUneMesure();
}
void loop(){

  // si il y a des messages disponibles 
  if (vecteurcomm.bICSnouveau_message_disponible()){
    Serial.println("message dispo");
    //test
    vecteurcomm.ICSrecevoirMessage();
     Serial.println("message recu");
    uneInstruction.setEmmetteur(vecteurcomm);

    // lit le message et le décode comme instruction
    uneInstruction.setInstruction(vecteurcomm);
    uneInstruction.INSexecuter(vecteurcomm,monthermometre);
  }
  monthermometre.PrendreUneMesure();
  delay(1000);
}


