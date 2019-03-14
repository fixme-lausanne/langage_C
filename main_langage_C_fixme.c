//-----------------------------------------------------------------------------------//
// Nom du projet 		:   Langage_C_fixme
// Nom du fichier 		:   main_langage_C_fixme.c
// Date de création 	:   25.02.2015
// Date de modification : 	13.03.2019
//
// Auteur 				: 	Philou (Ph. Bovey)
//
// Description 			: 	Selon le livre "le Langage C" - Auteur : Tony Zhang
//                          Reprise des Exercies du livres et adapter ceux-ci
//                          pour faire un programme complet et aisni voirdifférents
//                          aspects du C
//
// Remarques			:   lien pour la table ASCII :
//                          http://www.asciitable.com/
//                          lien pour la saisie de clavier avec getc & getchar pour ne pas
//                          avoir des erreurs d'interprétation
//                          http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
//                          lien vers différents
//                          http://fr.wikipedia.org/wiki/String.h
//----------------------------------------------------------------------------------//

//--- Librairie utilisées ---//
//--- Standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <string.h>

//--- Perso ---//
#include "display.h"

//--- définition ---//
#define VERSION_PROG  1


//--- Programme personalisé ---//
int main()
{
    //--- déclaration de variables interne à la function main ---//
    char var_retour = CHOIX_MENU_PRINCIPAL;         // initialise la variable de retour

    //--- Message de bienvenue ---//
    printf("--- Fixme - Projet en C - Version %d ---", VERSION_PROG);
    PRINT_SAUT_LIGNE;

    //--- tant que l'utilisateur n'est pas sorti en tapant sur 'E' on reste dans la boucle ---//
    do{
        //--- structure du menu ---//
        Template_Menu_Ligne();
        Template_Display_Menu(var_retour);
        PRINT_SAUT_LIGNE;
        PRINT_SAUT_LIGNE;
        var_retour = Selection_Menus(CHOIX_MENU);
        PRINT_SAUT_LIGNE;
        DELETE_SCREEN;

    }while(var_retour != CHOIX_EXIT);

    return 0;
}