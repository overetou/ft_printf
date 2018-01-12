# ft_printf
1.Faire marcher les ellipses pour gerer un nombre non defini d'arguments.V
A gerer : flags (#0-+ et space; hh h 1 11 j z), precison, taille minimale

Plan de guerre :

sans flags, tout va bien !
flag : lancer lecteur d'options qui fait ruisseler les specifications facultatives et fait tout tout beau tout propre.
appliquer la conversion en tenant compte des parametres recueuillis precedement. Atention, les specifications doivent analyser le type pour etre correctement appliquees.

# : mettre 0x devant hexa, 0 devant oct, ect...
0 : paddig avec des 0 plutot que des espaces. Se fait overrider par -
- : fait passer le padding de l'autre cote du champ. (a droite)
+ : rajoute le signe de toutes les conversions signees.

field width : taille MINIMALE mais pas maximale du champs. Compte le nombre de caracteres, pas la valeur. Si le nombre de caracteres senses sortir est inferieur a la taille precisee, le restant est remplis par des blancks ou des 0 si flags.

precision : indique pour toute valeur numerique le nombre minimum de chiffre qui doivent apparaitre et remplie de 0 si c'est superieur. Pour s et S, elle indique le nombre MAXIMAL de caracteres qui seront imprimes, et tronque le reste de la chaine une fois que la precision est atteinte. la precision est precedee d'un point.

specification de longueur : precise la longueur de ce que l'on souhaite convertir pour que tout se passe sans fracas. Par exemple si l'on souhaite afficher un caractere en sa valeur decimale.

architecture :
fonction chargee de calculer l'espace : fonction : is there