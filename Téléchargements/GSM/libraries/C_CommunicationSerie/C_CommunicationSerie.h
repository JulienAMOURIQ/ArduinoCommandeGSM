
/************************************************
 * 
 *      Classe C_CommunicationSerie
 *      hérite de C_ICommStd
 * 
 **************************************************/
#ifndef C_CommunicationSerie_h
#define C_CommunicationSerie_h

#include "Arduino.h"
#include "ICommStd.h"

class C_CommunicationSerie : public C_ICommStd{
private:



public:
  //constructeurs
  C_CommunicationSerie();

  //redéfinition de méthodes héritées

  void ICSinitialiser();
  void ICSenvoyerMessage(char *message,char *destinataire);

  boolean bICSnouveau_message_disponible();

  void ICSrecevoirMessage();

};
#endif