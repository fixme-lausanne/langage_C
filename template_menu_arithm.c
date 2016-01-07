//-----------------------------------------------------------------------------------//
// Nom du projet 		:   Langage_C_fixme
// Nom du fichier 		:   template_menu_arithm.c
// Date de création 	:   16.04.2015
// Date de modification : 	30.09.2015
//
// Auteur 				: 	Philou (Ph. Bovey)
//
// Description 			: 	Sorte de template modifiable pour afficher un menu ->
//                          ici la partie du menu arithmétique
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
#include "arithmetique.h"


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Choix_Menu_Arithmetique
// Entrée / Sortie      : - / - /
// Description          : affiche le choix du menu arithmétique
// Date modfification   : le 19.06.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Choix_Menu_Arithmetique(void)
{
    printf("[1] %s", NAME_M_OP_SIMPLE);
    PRINT_SAUT_LIGNE;
    printf("[2] %s", NAME_M_CONV);
    PRINT_SAUT_LIGNE;
    printf("[3] ... \n");
    printf("[4] ... \n");
    printf("[P] --- retour menu %s  ---", NAME_M_PRINICIPAL);
    PRINT_SAUT_LIGNE;
    printf("[E] --- fermer le programme ---");
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Choix_Menu_OP_Simple
// Entrée / Sortie      : - / - /
// Description          : affiche le choix du menu des opération arithmétique simple
// Date modfification   : le 19.06.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Choix_Menu_OP_Simple(void)
{
    printf("[1] %s", NAME_M_ADITION);
    PRINT_SAUT_LIGNE;
    printf("[2] %s", NAME_M_SOUSTRACTION);
    PRINT_SAUT_LIGNE;
    printf("[3] %s", NAME_M_MULTIPLICATION);
    PRINT_SAUT_LIGNE;
    printf("[4] %s", NAME_M_DIVISION);
    PRINT_SAUT_LIGNE;
    printf("[A] %s", NAME_M_ASTUCE_INCR);
    PRINT_SAUT_LIGNE;
    printf("[P] --- retour menu %s  ---", NAME_M_PRINICIPAL);
    PRINT_SAUT_LIGNE;
    printf("[E] --- fermer le programme ---");
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Choix_Menu_Conversion
// Entrée / Sortie      : - / - /
// Description          : affiche le choix du menu des opération arithmétique simple
// Date modfification   : le 08.07.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Choix_Menu_Conversion(void)
{
    printf("[1] %s", NAME_M_CONV_CHAR_NUM);
    PRINT_SAUT_LIGNE;
    printf("[2] %s", NAME_M_CONV_NUM_CHAR);
    PRINT_SAUT_LIGNE;
    printf("[3] %s", NAME_M_CONV_NUM_OCT_HEX);
    PRINT_SAUT_LIGNE;
    printf("[4] ... \n");
    printf("[A] %s", NAME_M_ASTUCE_CONV_CHAR_NUM);
    PRINT_SAUT_LIGNE;
    printf("[P] --- retour menu %s  ---", NAME_M_PRINICIPAL);
    PRINT_SAUT_LIGNE;
    printf("[E] --- fermer le programme ---");
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Display_Menu_Arithm
// Entrée / Sortie      : choix_menu / - /
// Description          : affiche le menu dans lequel on se situe -> ici arithmétique
// Date modfification   : le 30.09.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Display_Menu_Arithm(char choix_menu)
{
    //--- déclaration de variable interne ---//
    char i, var_retour;

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
            printf("%s", NAME_M_OP_SIMPLE);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Template_Choix_Menu_OP_Simple();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            var_retour = Selection_Menus('C');
            Template_Display_Menu_OP_Simple(var_retour);
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
        break;

        case '2':
            printf("%s", NAME_M_CONV);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Template_Choix_Menu_Conversion();
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
            var_retour = Selection_Menus('C');
            Template_Display_Menu_Conversion(var_retour);
            PRINT_SAUT_LIGNE;
            PRINT_SAUT_LIGNE;
        break;

        case 'A':
            printf("%s", NAME_M_ASTUCE_INCR);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Help_Printf();;
        break;

        default:
            printf("LA SELECTION N'EXISTE PAS !!!");
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
        break;
    }
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Display_Menu_OP_Simple
// Entrée / Sortie      : choix_menu / - /
// Description          : affiche le menu dans lequel on se situe avec les
//                        differentes options
// Date modfification   : le 30.09.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Display_Menu_OP_Simple(char choix_menu)
{
    //--- déclaration de variable interne ---//
    char i;

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
            printf("%s", NAME_M_ADITION);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Addition();
        break;

        case '2':
            printf("%s", NAME_M_SOUSTRACTION);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Soustraction();
        break;

        case '3':
            printf("%s", NAME_M_MULTIPLICATION);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Multiplication();
        break;

        case '4':
            printf("%s", NAME_M_DIVISION);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Division();
        break;

        case 'A':
            printf("%s", NAME_M_ASTUCE_INCR);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            Astuce_Calcul();
        break;

        default:
            printf("LA SELECTION N'EXISTE PAS !!!");
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
        break;
    }
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Template_Display_Menu_Conversion
// Entrée / Sortie      : choix_menu / - /
// Description          : affiche le menu dans lequel on se situe avec les
//                        differentes options -> ici menu de conversions
// Date modfification   : le 30.09.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Template_Display_Menu_Conversion(char choix_menu)
{
    //--- déclaration de variable interne ---//
    char i, choix_char;

    int choix_int;

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
        case '1':
            printf("%s", NAME_M_CONV_CHAR_NUM);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            PRINT_SELECTION_CHAR;
            choix_char = Select_Var_Cara();
            Conv_Char_Num(choix_char);
        break;

        case '2':
            printf("%s", NAME_M_CONV_NUM_CHAR);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            choix_int = Select_Var_Entier();
            Conv_Num_Char(choix_int);
        break;

        case '3':
            printf("%s", NAME_M_CONV_NUM_OCT_HEX);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            PRINT_SAUT_LIGNE;
            choix_int = Select_Var_Entier();
            Conv_Num_Oct_Hex(choix_int);
        break;

        case 'A':
            printf("%s", NAME_M_ASTUCE_CONV_CHAR_NUM);
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
            Astuce_ASCII();
        break;


        default:
            printf("LA SELECTION N'EXISTE PAS !!!");
            PRINT_SAUT_LIGNE;
            Template_Menu_Ligne();
        break;
    }

}
