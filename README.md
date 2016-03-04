# ArduinoCommandeGSM
Description :
=============

Le principe est le suivant: vous envoyez via un vecteur de communication un ordr
e à la carte Arduino, qui va agir sur un relais (interrupteur commandé électroni
quement et à acheter séparemment) . Le relais permettra d'allumer ou d'éteindre 
le chauffage à volonté. La carte Arduino est capable de donner l'état actuel de 
fonctionnement du chauffage et la température de la pièce. Idéal quand on part d
e chez soit pour faire chauffer une pièce afin de ne pas avoir la maison entière
ment froide en rentrant. Le coe source fourni est capable sans adaptation de com
muniquer via n'importe quel moyen de communication. 
<br />
<br />J'utilise po
ur cela le patron de conception &quot;stratégie&quot;: la <b>classe ICommStd</b>
 ,une classe abstraite, fourni une interface de communication standard, si bien 
que vous pouvez facilement modifier le vecteur de communication (serie, ethernet
, etc...)simplement en héritant de cette classe. 
<br />
<br />La classe <b>C_
CommunicationGSM</b> implémente l'interface ICommStd et hérite de celle-ci.
<br
 />Ci-dessous le diagramme de classe UML, inclus dans le fichier zip.
<br /><a 
href='http://www.hostingpics.net/viewer.php?id=828050umlcommunication.jpg' rel='
nofollow' target='_blank'>http://www.hostingpics.net/viewer.php?id=828050umlcomm
unication.jpg</a>
<br /><b>N'hésitez pas à me contacter si quelquechose n'est p
as clair ou si j'ai fait une erreur</b>, j'en profiterais pour améliorer la desc
ription =) .
<br />
<br /><i>Ce code source est mis à votre disposition sous l
es termes de la licence <a href='http://creativecommons.org/licenses/by/4.0/deed
.fr' rel='nofollow' target='_blank'>http://creativecommons.org/licenses/by/4.0/d
eed.fr</a> .</i>
<br />
<br /><b>MAJ 01/2015 :</b> Les sources ne semblent pas
 compiler sous l'IDE Arduino 1.0.6. En revanche il fonctionne bien avec l'IDE 1.
0.5-r2 . Il semblerait que cela soit dû à un bug dans les librairies de l'IDE en
 version 1.0.6.
<br /><b>MAJ 01/2015 :</b> correction de la classe C_Communicat
ion série
<br /><b>MAJ 08/2015 :</b> correction de la classe C_Communication GS
M (projet à 100% fonctionnel)
