# get_next_line

> L'art de retourner une ligne à la fois
> 

### **Objectif du projet**

Écrire une fonction qui sera employée pour retourner, une ligne à la fois, du texte depuis un descripteur de fichier lui étant précisé. Apprendre les notions de descripteur de fichier, d'allocation dynamique et de la disposition de la mémoire en langage C.

### **Les nouvelles notions abordé durant le projet**

***Les variables statique***

Les variables déclarées statiques ont la particularitées de garder en mémoire leurs valeurs au delà du scope de la fonction ou elle sont déclarées. Donc, si nous rappelons une seconde fois cette même fonction, les valeures des variables statiques n'aurons pas changées ou ne seront pas perdu.

***Le file descriptor (descripteur de fichier)***

Le descripteur de fichier, dans un environnement POSIX, est une clé abstraite (un entier de type integrer (int) en langage C) qui permet d'accéder à un fichier.

Plusieurs fonction travail avec les descripteur de fichier t'elle que `open()`, `close()`, `read()` ou `write()`.

La fonction `open()` renvoit un integrer, le numéro du descripteur de fichier.

Il existe des descripteur standard tel que:

- 0 = std input
- 1 = std output
- 2 = std error

La fonction `read()` renvoit un integrer (int), soit le nombre de caractère lu. Elle prend en paramètre numéro du descripteur de fichier (fd), une chaine de caractère qui contiendra les éléments lue et le nombre de caractère que l'on à lu. Elle revoie 0 quand elle atteint la fin du fichier (EOF) end of file et -1 quand il y a une erreur de lecture.

La bibliothèque limite.h permet d'utiliser en autre la variabe définie OPEN_MAX qui est une variable représentant le nombre maximal de fichier qu'un processus peut avoir d'ouvert en même temps sur le système actuel. Il pourra être utilisé pour empêcher la fonction de parcourir des numéro fd trop grand.

### **Les difficultées rencontré durant la réalisation du projet**

***Les leaks mémoire*** 

Si de la mémoire est alloué dynamiquement, celle-ci doit être libéré une fois qu'elle n'est plus utilisé par le programme pour être à nouveau disponible pour autre chose. Une fuite mémoire ce produit quand des emplacements en mémoire ont été alloué dynamiquement et qu'elle n'ont pas été libéré par le programme. 

La mémoire octroyé dynamiquement ce retrouve dans une zone de la mémoire appelé la Heap. Cette zone permet d'allouer de grand bloc de mémoire. C'est principalement l'emplacement ou est stocké la mémoire alloué dynamiquement.

### man get_next_line (Si il s'agit d'un fonction)

**NOM**

  get_next_line

**SYNOPSIS**

  **#include "get_next_line.h"**

    **char *get_next_line(int fd);**

**DESCRIPTION**

  La fonction get_next_line li depuis un descripteur de fichier passé en paramètre, ligne par ligne. 

**VALEUR RETOURNÉ**

  get_next_line renvoie une chaîne de caractère, soit une ligne lue depuis un descripteur de fichier. Si le     fichier ne contient aucune donnée elle renvoie NULL. Si un problème survient lors de la lecture du descripteur  de fichier, la fonction renvoie NULL également.

### Mon approche:

La fonction `get_next_line()` li depuis un descripteur de fichier passé en paramètre, ligne par ligne.

Pour ce faire, la fonction fera appel à 3 autres fonctions qui s'occuperons de retourner un seul ligne et préparer la suivante. C'est dans a fonction `get_next_line()` qu'elle seront appelées. Puis dans cette même fonction, une variable static nommé remaining qui est une chaine de caractère, stockera le ou les lectures du fd et gardera également les valeurs de la prochaine ligne, si il y a. Ensuite, j'appel la fonction `read()` dans une première fonction nommé `get_line()`. Mise dans une boucle while (tant que le buffer ne contient pas de retour de ligne \n ou que la valeur retourné par read() n'égale pas '\0'), `read()` lira le descripteur de fichier et stockera dans la variable buffer les valeurs retournées. Il joindra aussi le buffer à la variable static remaining destinée a recueillir une ligne complète. Puis, de retour dans la fonction `get_next_line()` la chaine de caractère remaining passera par la fonction `crop_front()` qui s'occupera de créer un nouvelle chaine de caractère et y copier les éléments constituant la ligne qui sera finalement retourner dans la fonction `get_next_line()`. Pour finir, la chaine de caractère remaining sera passé à la fonction `crop_end()` pour retirer les éléments précédent le retour de ligne, pour ne garder que les potentiels autres lignes lu dans le descripteur de fichier.

Pour la partie bonus du projet, nous avions a prendre en charge la lecture de plusieurs fd de facon à pouvoir alterner entre eux la lecture et l'affichage des lignes. Un simple tableau de pointeur a été nécéssaire pour cela. Donc, la variable static est devenue le tableau de pointeur ou chaques descripteur de fichier ouvert nécéssitait une case de ce tableau pour stocker les données lue. Puis, était demandé l'utilisation d'une seul static, ce qui était déja mon cas.
