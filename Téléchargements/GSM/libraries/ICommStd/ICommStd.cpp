/************************************************
* 
*      Classe Abstraite C_ICommStd
* 
**************************************************/

#include "Arduino.h"
#include "ICommStd.h"




void C_ICommStd::setICSmessage(char *message){
	strncpy(pcICSmessage,message,ICS_TAILLEMESSAGE);

}

void C_ICommStd::setICSemetteur(char *emetteur){
	strncpy(pcICSemetteur,emetteur,ICS_TAILLEEMETTEUR);
	 Serial.print("emetteur:");
        Serial.println(emetteur);
}


/*
Retourne une chaine de caractère allouée dynamiquement et qui contient l'adresse/numtel/... de l'emetteur
ATTENTION A LIBERER LA MEMOIRE: LE POINTEUR DE RETOUR EST ALLOUE DYNAMIQUEMENT !
*/
char * C_ICommStd::get_emetteur(){
	char *pcreponse=(char*)malloc(ICS_TAILLEEMETTEUR);
	strcpy(pcreponse,pcICSemetteur);
	return pcreponse;    
}

/*
Retourne une chaine de caractère allouée dynamiquement et qui contient l'adresse/numtel/... de l'emetteur
ATTENTION A LIBERER LA MEMOIRE: LE POINTEUR DE RETOUR EST ALLOUE DYNAMIQUEMENT !
*/
char * C_ICommStd::get_message(){
	char *pcreponse;	
	pcreponse=strdup(pcICSmessage);
	return pcreponse;
}

