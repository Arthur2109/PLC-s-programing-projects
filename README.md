# PLC-s-programing-projects
PLC's programing projects coded in Ladder, Grafcet or FBD (function block diagram).

1) Projet préhenseur d'oeuf (codé en FDB, non abouti): projet de plusieurs mois qui consiste a placer des oeufs dans une boite d'oeufs de maniere automatique.
Les oeufs sont a l'origine placés dans une bouteilles (cf photos et vidéos). Un tourniquet s'actionne pour laisser tomber un oeuf dans la boite. A chaque fois qu'un oeuf tombe pour occuper un espace de la boite, les pistons X et Y de déplacent d'un cran (asservissement de la position a l'aide de capteur ultrasons placés le long des axes X et Y, + structure en glissiere qui permet le mouvement independant X Y de la boite). Le parcours de tous les emplacements de la boite est ainsi fait qu'il permet de ne faire aucun aller retour pour ne pas perdre de temps (zig-zag).

Conception des pieces sous Inventor (AutoCAD).

Problemes de ce projet :
- Le capteur ultrason est adapté a un microcontroleur mais pas a un PLC (cf explication fichier arduino).
- La structure des glissieres crée un arc-boutement important et bloque le glissement (cf videos).
- Manque de temps significatif.

2) Grafcet : Petit programme de simulation de deux pistons et d'un moteur codé en Grafcet. Asservissement de la vitesse du moteur. A executer sous Automation Studio.

3) Ladder : Petit programme de simulation de deux pistons, codé en Ladder. le bouton ON actionne les pistons suivant la séquence X+,attente,X-,Y+,attente,Y-. A executer aussi sous Automation Studio.


