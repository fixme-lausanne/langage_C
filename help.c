//-----------------------------------------------------------------------------------//
// Nom du projet 		: Langage_C_fixme
// Nom du fichier 		: help.c
// Date de création 	: 23.09.2015
// Date de modification : 23.10.2017
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier comportant différentes fonctions d'astuces
//
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  lien pour la saisie de clavier avec getc & getchar pour ne pas
//                        avoir des erreurs d'interprétation
// 						  -> http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
// 						  lien vers différents
// 						  -> http://fr.wikipedia.org/wiki/String.h
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <string.h>

//--- librairie perso ---//
#include "display.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Help_Printf
// Entrée / Sortie      : - / - /
// Description          : on affiche quelques régles avec le printf
// Date modfification   : le 09.09.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Help_Printf(void)
{
    //--- déclaration de variable interne ---//
    char var_test = 'A';
    float var_test2 = 3452.10;
    int puissance = 5;
    int i, val;

    //--- Notion du "Printf" --> permet l'affichage dans une console ---//
    printf("-> fct ""PRINTF()"" : permet d'afficher du texte dans une console \n");
    printf("-> le \\n permet un retour a la ligne \n");
    printf("-> pour afficher un caractere on utilise %%c \n");
    printf("-> pour afficher un entier on utilise %%d \n");
    printf("-> pour afficher une valeur en hexa on utilise %%x \n");
    PRINT_SAUT_LIGNE;
    printf("=> Exemple 1A : la variable de test a comme caractere : %-3c \n", var_test);
    printf("=> Exemple 1B : la variable de test vaut en decimal :   %-3d \n", var_test);
    printf("=> Exemple 1C : la variable de test vaut en hexa :    OX%-3x \n", var_test);
    PRINT_SAUT_LIGNE;
    printf("-> pour afficher un nombre flottant on utilise %%f \n");
    printf("-> pour afficher un nombre en notation scientifique on utilise %%e \n");
    PRINT_SAUT_LIGNE;
    printf("REMARQUE : ecriture notation scientifique %%nb_total.Nb_ap_virgule => ex: %%3.1e \n");
    PRINT_SAUT_LIGNE;
    printf("=> Exemple 2A : la variable de test vaut : %f \n", var_test2);
    printf("=> Exemple 2B : la variable de test vaut en notation scientifique : %3.1e \n", var_test2);
    PRINT_SAUT_LIGNE;
    PRINT_SAUT_LIGNE;
    printf("-> Valeur de fin de fichier dit EOF : %d", EOF);
    PRINT_SAUT_LIGNE;
    printf("-> allignement de nombres entier %%nb_esapce+indicateur \n");
    printf("-> les signes  + & - devant le nb d'espace definit les sens d'alignement gauche ou droite \n");
    PRINT_SAUT_LIGNE;
    printf("=> Exemple 3 : allignement de nbs - de 1 a 10^5 \n");
    for(i = 0 ; i < puissance + 1 ; i++)
    {
        //--- calcul de la valeur à afficher ---//
        if(i == 0)
            val = 1;
        else
            val = val*10;

        //--- affichage de la valeur avec alignement de droite a gauche ---//
        printf("puissance %d -> %6d || %-6d", i, val, val);
        PRINT_SAUT_LIGNE;
    }
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Help_Loop
// Entrée / Sortie      : - / - /
// Description          : quelque exemple d'affichage avec des boucles itératives
// Date modfification   : le 23.10.2017
// Remarque             : -
//----------------------------------------------------------------------------------//
void Help_Loop(void)
{
    //--- déclaration de variable ---//
    int i, val_user;

    //--- différences nombre itération (écriture différentes) ---//
    val_user = Select_Var_Entier(LIMITE_NB_MAX, LIMITE_NB_MIN);

    //--- boucle for avec un test : x < y ---//
    PRINT_SAUT_LIGNE;
    printf("-> selection iteration user : %d", val_user);
    PRINT_SAUT_LIGNE;

    //--- boucle ---//
    printf("LOOP FOR -> iteration reel avec test (i < user)");
    PRINT_SAUT_LIGNE;
    for(i = 0; i < val_user; i++)
        printf("%d / ", i);
    PRINT_SAUT_LIGNE;

    printf("LOOP FOR -> iteration reel avec test (i <= user)");
    PRINT_SAUT_LIGNE;
    for(i = 0; i <= val_user; i++)
        printf("%d / ", i);
    PRINT_SAUT_LIGNE;

    printf("LOOP WHILE -> iteration reel avec test (i < user)");
    PRINT_SAUT_LIGNE;
    i = 0;
    while(i < val_user)
    {
        printf("%d / ", i);
        i++;
    }
    PRINT_SAUT_LIGNE;
}

