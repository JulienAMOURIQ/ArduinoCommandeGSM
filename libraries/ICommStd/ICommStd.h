/************************************************
 * 
 * Classe Abstraite C_ICommStd
 * 
 **************************************************/
 
#ifndef ICommStd_h
#define ICommStd_h


#include "Arduino.h"

#define ICS_TAILLEMESSAGE 50
#define ICS_TAILLEEMETTEUR 15
class C_ICommStd{//Interface de comunication standard 
private:
  char pcICSmessage[ICS_TAILLEMESSAGE];
  char pcICSemetteur[ICS_TAILLEEMETTEUR];


protected:
  void setICSmessage(char *message);

  void setICSemetteur(char *emetteur);
  
public:

  /**
  * @brief Retourne une chaine de caractère allouée dynamiquement et qui contient l'adresse/numtel/... de l'emetteur
  * d'un message reçu avec ICSrecevoirMessage()
  * @warning ATTENTION A LIBERER LA MEMOIRE: LE POINTEUR DE RETOUR EST ALLOUE DYNAMIQUEMENT !
  */
  char * get_emetteur();

  /**
  * @brief Retourne une chaine de caractère allouée dynamiquement et qui contient le corps d'un message reçu avec 
  * ICSrecevoirMessage()
  *
  * @warning ATTENTION A LIBERER LA MEMOIRE: LE POINTEUR DE RETOUR EST ALLOUE DYNAMIQUEMENT !
  */
  char * get_message();
 
   /**
   *  @brief Initialise l'utilisation du matériel de communication.
   *  Cette fonction DOIT être appelee avant les autres fonctions.
   */
  virtual void ICSinitialiser()=0;
  
  
  /**
  * @return Retourne vrai si un nouveau message est disponible, faux sinon
  */
  virtual boolean bICSnouveau_message_disponible()=0;
  
  /**
  * @brief Envoit un message au destinataire;
  */
  virtual void ICSenvoyerMessage(char *message,char *destinataire)=0;

  /**
  * @brief Lit le nouveau message disponible et enregistre le contenu dans pcICSmessage et pcICSemetteur .
  * Si plusieurs messages non-lus sont disponibles, alors 
  */
  virtual void ICSrecevoirMessage()=0;



};
#endif