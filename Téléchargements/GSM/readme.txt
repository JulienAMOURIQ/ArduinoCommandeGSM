[Arduino] Commande de chauffage via GSM avec un relais------------------------------------------------------
Url     : http://codes-sources.commentcamarche.net/source/100510-arduino-commande-de-chauffage-via-gsm-avec-un-relaisAuteur  : juliusIIDate    : 30/08/2015
Licence :
=========

Ce document intitul� � [Arduino] Commande de chauffage via GSM avec un relais � issu de CommentCaMarche
(codes-sources.commentcamarche.net) est mis � disposition sous les termes de
la licence Creative Commons. Vous pouvez copier, modifier des copies de cette
source, dans les conditions fix�es par la licence, tant que cette note
appara�t clairement.

Description :
=============

Le principe est le suivant: vous envoyez via un vecteur de communication un ordr
e � la carte Arduino, qui va agir sur un relais (interrupteur command� �lectroni
quement et � acheter s�paremment) . Le relais permettra d'allumer ou d'�teindre 
le chauffage � volont�. La carte Arduino est capable de donner l'�tat actuel de 
fonctionnement du chauffage et la temp�rature de la pi�ce. Id�al quand on part d
e chez soit pour faire chauffer une pi�ce afin de ne pas avoir la maison enti�re
ment froide en rentrant. Le coe source fourni est capable sans adaptation de com
muniquer via n'importe quel moyen de communication. 
<br />
<br />J'utilise po
ur cela le patron de conception &quot;strat�gie&quot;: la <b>classe ICommStd</b>
 ,une classe abstraite, fourni une interface de communication standard, si bien 
que vous pouvez facilement modifier le vecteur de communication (serie, ethernet
, etc...)simplement en h�ritant de cette classe. 
<br />
<br />La classe <b>C_
CommunicationGSM</b> impl�mente l'interface ICommStd et h�rite de celle-ci.
<br
 />Ci-dessous le diagramme de classe UML, inclus dans le fichier zip.
<br /><a 
href='http://www.hostingpics.net/viewer.php?id=828050umlcommunication.jpg' rel='
nofollow' target='_blank'>http://www.hostingpics.net/viewer.php?id=828050umlcomm
unication.jpg</a>
<br /><b>N'h�sitez pas � me contacter si quelquechose n'est p
as clair ou si j'ai fait une erreur</b>, j'en profiterais pour am�liorer la desc
ription =) .
<br />
<br /><i>Ce code source est mis � votre disposition sous l
es termes de la licence <a href='http://creativecommons.org/licenses/by/4.0/deed
.fr' rel='nofollow' target='_blank'>http://creativecommons.org/licenses/by/4.0/d
eed.fr</a> .</i>
<br />
<br /><b>MAJ 01/2015 :</b> Les sources ne semblent pas
 compiler sous l'IDE Arduino 1.0.6. En revanche il fonctionne bien avec l'IDE 1.
0.5-r2 . Il semblerait que cela soit d� � un bug dans les librairies de l'IDE en
 version 1.0.6.
<br /><b>MAJ 01/2015 :</b> correction de la classe C_Communicat
ion s�rie
<br /><b>MAJ 08/2015 :</b> correction de la classe C_Communication GS
M (projet � 100% fonctionnel)
