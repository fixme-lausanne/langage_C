//-----------------------------------------------------------------------------------//
// Nom du projet 		:   Langage_C_fixme
// Nom du fichier 		:   template_menu_display.c
// Date de création 	:   06.11.2015
// Date de modification : 	07.01.2016
//
// Auteur 				: 	Philou (Ph. Bovey)
//
// Description 			: 	Sorte de template modifiable pour afficher un menu ->
//                          ici la partie du menu display pour afficher des formes
//
// Remarques			:   lien pour la table ASCII :
//                          http://www.asciitable.com/
//                          lien pour la saisie de clavier avec getc & getchar pour ne pas
//                          avoir des erreurs d'interprétation
//                          http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
//                          lien vers différents
//                          http://fr.wikipedia.org/wiki/String.h
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <string.h>

//--- librairie perso ---//
#include "display.h"
//#include "arithmetique.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Choix_Menu_Display
// Entrée / Sortie      : - / - /
// Description          : affiche le choix du menu "Display"
// Date modfification   : le 06.11.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Choix_Menu_Display(void)
{
    printf("[1] %s", NAME_M_DISP_CARRE);
    PRINT_SAUT_LIGNE;
    printf("[2] %s", NAME_M_DISP_TRIANGLE);
    PRINT_SAUT_LIGNE;
    printf("[3] %s", NAME_M_DISP_LOSANGE);
    PRINT_SAUT_LIGNE;
    printf("[4] %s", NAME_M_DISP_PARALLELOGRAMME);
    PRINT_SAUT_LIGNE;
    printf("[P] --- retour menu %s  ---", NAME_M_PRINICIPAL);
    PRINT_SAUT_LIGNE;
    printf("[E] --- fermer le programme ---");
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Display_Menu_Display
// Entrée / Sortie      : choix_menu / - /
// Description          : affiche le menu dans lequel on se situe -> ici display
// Date modfification   : le 07.01.2016
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Display_Menu_Display(char choix_menu)
{
    //--- déclaration de variable interne ---//
    char i, choix_HB, choix_GD, choix_PV;
    int choix_val;

    //--- affiche une ligne entière d'étoile ---//
    PRINT_SAUT_LIGNE;
    Template_Menu_Ligne();

    //--- boucle pour afficher x caractère sur une ligne ---//
    for(i = 0; i < 3; i++)
        printf("*");

    //--- pour l'esthétique afficher un espace avant le mots "menu" ---/
    PRINT_ESPACE;
    PRINT_M_MENU;

    switch(choix_menu)
    {
        case 'P':
            printf("%s", NAME_M_PRINICIPAL);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Template_Choix_Menu_Principal();
        break;

        case '1':
            printf("%s", NAME_M_DISP_CARRE);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            choix_val = Select_Var_Entier();
            Carre(choix_val);
        break;

        case '2':
            printf("%s", NAME_M_DISP_TRIANGLE);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            PRINT_SELECTION_GD;
            choix_GD = Select_Var_Cara();
            PRINT_SELECTION_HB;
            choix_HB = Select_Var_Cara();
            Choix_Emplacement_Triangle(choix_HB, choix_GD);
        break;

        case '3':
            printf("%s", NAME_M_DISP_LOSANGE);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            PRINT_SELECTION_PV;
            choix_PV = Select_Var_Cara();
            Selection_Losange(choix_PV);
        break;

        case '4':
            printf("%s", NAME_M_DISP_PARALLELOGRAMME);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            PRINT_SELECTION_GD;
            choix_GD = Select_Var_Cara();
            Selection_Sens_Paralelogramme(choix_GD);
        break;

        default:
            printf("LA SELECTION N'EXISTE PAS !!!");
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
        break;
    }
}
