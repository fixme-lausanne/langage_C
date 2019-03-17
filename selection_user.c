//-----------------------------------------------------------------------------------//
// Nom du projet 		: Langage_C_fixme
// Nom du fichier 		: selection_user.c
// Date de création 	: 16.04.2015
// Date de modification : 17.03.2019
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier comportant différentes fonctions permettant de
//                        charger des valeurs de l'utilisateur
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
#include <stdint.h>                 // type entier standardisé

//--- librairie perso ---//
#include "display.h"

//--- constante ou définition ---//
#define _CRT_NONSTDC_NO_WARNINGS



//----------------------------------------------------------------------------------//
// Nom de la fonction   : Selection_Menus
// Entrée / Sortie      : choix_selection_msg / var_retour
// Description          : affiche un message pour que l'utilisateur entre une valeur
//                        M : affichage d'un message concernant un menu
//                        C : affichage d'un message concernant un choix de sous menu
//                        V : affichage d'un message concernant une valeur
// modification         : le 23.10.2017
// Remarque             : -
//----------------------------------------------------------------------------------//
char Selection_Menus(char choix_selection_msg)
{
    //--- declaration de variable local ---//
    char var_retour;

    //--- selection du message selon la configuration ---//
    switch(choix_selection_msg)
    {
        case 'M':
            PRINT_SELECTION_MENU;
            var_retour = Select_Var_Cara();
        break;

        case 'C':
            PRINT_SELECTION_CHOIX;
            var_retour = Select_Var_Cara();
        break;

        case 'V':
            var_retour = Select_Var_Entier(LIMITE_NB_MAX, LIMITE_NB_MIN);
        break;
    }
    return var_retour;
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Select_Var_Cara
// Entrée / Sortie      : - / val_retour
// Description          : récuperation d'un caractère issu d'un utilisateur
//                        en entier
// modification         : le 04.05.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
char Select_Var_Cara(void)
{
    //--- déclaration de variable interne ---//
    char val_retour;

    //--- lire le caractère saisi ---//
    val_retour = getchar();

    //--- vide le buffer de saisie de clavier ---//
    while(getchar() != '\n');

    return val_retour;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Select_Option
// Entrée / Sortie      : - / car_retour
// Description          : demande à l'utilisateur de choisir un choix
//                        en entier
// modification         : le 19.05.2015
// Remarque             : http://fr.wikipedia.org/wiki/Lois_de_De_Morgan
//----------------------------------------------------------------------------------//
char Select_Option(void)
{
    //--- déclaration de variable interne ---//
    char car_retour;

    //--- boucle pour choisir un choix d'option
    do
    {
        //--- message afficher à l'utilisateur ---//
        PRINT_SELECTION_INT;
        PRINT_SAUT_LIGNE;
        printf("OU");
        PRINT_SAUT_LIGNE;
        PRINT_SELECTION_FLOAT;
        PRINT_SAUT_LIGNE;
        PRINT_SAUT_LIGNE;

        //--- demander à l'utilisetur de choisir une option ---//
        PRINT_SELECTION_CHOIX;

        //--- lecture du caractère en retour ---//
        car_retour = Select_Var_Cara();

    //---condition de sortie : obliger de choisir une de deux possibilités ---//
    }//while((car_retour != CHOIX_ENTIER) && (car_retour != CHOIX_FLOTTANT));    // les deux solutions sont justes
    while(!((car_retour == CHOIX_ENTIER) || (car_retour == CHOIX_FLOTTANT)));

    return car_retour;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Select_Var_Entier
// Entrée / Sortie      : limiteMax, limiteMin / val_retour
// Description          : récuperation d'une chaîne de caractère en la transformant
//                        en entier avec contrôle de limites (min et max)
// modification         : le 17.03.2019
// Remarque             :
//----------------------------------------------------------------------------------//
int Select_Var_Entier(int limiteMax, int limiteMin)
{
    //--- déclaration de variable interne ---//
	char testPositif = 0;		// 0 -> NOT OK - 1 -> OK
	int val_retour;

    //--- message de sélection ---//
    PRINT_SELECTION_NB;

	//-- boucle pour tester si valeur est correctes ou non --//
	do
	{
		//--- fonction pour la lire la saisie d'un chaîne de caractère ---//
		//-- pour VS --
		#ifdef VISUAL_STUDIO
            scanf_s("%d", &val_retour);
        #else
            scanf("%d", &val_retour);
        #endif // VISUAL_STUDIO
		//-- test si valeur est dans les limites --//
		if ((val_retour < limiteMax) && (val_retour > limiteMin))
			testPositif = 1;
		else
        {
            testPositif = 0;
            PRINT_SELECTION_NEW_NB;
        }
	} while (testPositif == 0);

    return val_retour;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : SelectValEntierSansLimite
// Entrée / Sortie      : / val_retour
// Description          : récuperation d'une chaîne de caractère en la transformant
//                        en entier sans contrôle de limites -> mode console
// modification         : le 17.03.2019
// Remarque             :
//----------------------------------------------------------------------------------//
int SelectValEntierSansLimite(void)
{
    //--- déclaration de variable interne ---//
	int valRetour;

    //--- message de sélection ---//
    PRINT_SELECTION_NB;

    //--- fonction pour la lire la saisie d'un chaîne de caractère ---//
    //-- pour VS --
	#ifdef VISUAL_STUDIO
        scanf_s("%d", &val_retour);
    #else
        scanf("%d", &valRetour);
    #endif // VISUAL_STUDIO

    return valRetour;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Select_Var_Flottant
// Entrée / Sortie      : - / val_retour
// Description          : récuperation d'une chaîne de caractère en la transformant
//                        en flottant
// modification         : le 17.03.2019
// Remarque             : -
//----------------------------------------------------------------------------------//
float Select_Var_Flottant(void)
{
    //--- déclaration de variable interne ---//
    float val_retour;

    //--- message de sélection ---//
    PRINT_SELECTION_NB;

    //--- fonction pour la lire la saisie d'un chaîne de caractère ---//
    //-- pour VS --
    #ifdef VISUAL_STUDIO
        scanf_s("%f", &val_retour);
    #else
        scanf("%f", &val_retour);
    #endif

    return val_retour;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : SelectValFlottantAvecLimite
// Entrée / Sortie      : limiteMax, limiteMin / val_retour
// Description          : récuperation d'une chaîne de caractère en la transformant
//                        en flottant avec contrôle de limite
// modification         : le 17.03.2019
// Remarque             : -
//----------------------------------------------------------------------------------//
float SelectValFlottantAvecLimite(float limitMax, float limitMin)
{
    //--- déclaration de variable interne ---//
	int8_t flagLimit = 0;		// 0 -> OK - 1 -> NOT OK
	float valRetour;

    //--- message de sélection ---//
    PRINT_SELECTION_NB;

	//-- boucle pour tester si valeur est correctes ou non --//
	do
	{
		//--- fonction pour la lire la saisie d'un chaîne de caractère ---//
		//-- pour VS --
		#ifdef VISUAL_STUDIO
            scanf_s("%d", &val_retour);
        #else
            scanf("%f", &valRetour);
        #endif // VISUAL_STUDIO

		//-- test si valeur est dans les limites --//
		if ((valRetour < limitMax) && (valRetour > limitMin))
			flagLimit = 0;
		else
        {
            flagLimit = 1;
            PRINT_SELECTION_NEW_NB;
        }
	} while (flagLimit != 0);

    return valRetour;
}
