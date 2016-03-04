
/************************************************
 * 
 *      Classe C_CommunicationGSM
 *      hérite de C_ICommStd
 * 
 **************************************************/
#ifndef C_CommunicationGSM_h
#define C_CommunicationGSM_h

#include "Arduino.h"
#include "ICommStd.h"

#include <GSM.h>
#include <GSM3CircularBuffer.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3SMSService.h>
#include <GSM3SoftSerial.h>

#define COG_TAILLEPINSIM 5  //4 + le caractère \0
class C_CommunicationGSM : public C_ICommStd{
private:
  GSM COGgsmAccess;
  GSM_SMS COGsms;
  char pcCOGcodepinsim[COG_TAILLEPINSIM];

  /*
  * @Brief initialise la connection avec la carte SIM.
   */
  void COGconnecter_GSM();


public:
  //constructeurs
  C_CommunicationGSM();

  C_CommunicationGSM(char *ccodepinsim);

  //redéfinition de méthodes héritées

  void ICSinitialiser();
  void ICSenvoyerMessage(char *message,char *destinataire);

  boolean bICSnouveau_message_disponible();

  void ICSrecevoirMessage();

};
#endif