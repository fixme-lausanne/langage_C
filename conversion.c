//-----------------------------------------------------------------------------------//
// Nom du projet 		: Langage_C_fixme
// Nom du fichier 		: conversion.c
// Date de création 	: 19.06.2015
// Date de modification : 27.11.2020
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier comportant différentes fonctions de conversions
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
#include <stdint.h>					// entier normalisé

//--- librairie perso ---//
#include "arithmetique.h"
#include "display.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Conv_Char_Num
// Entrée / Sortie      : var_char / - / -
// Description          : avec le choix de l'utilisateur sélectionnant un caractètre
//                        la fonction affiche sa valeur decimale et hexa
// modification         : le 29.07.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Conv_Char_Num(char var_char)
{
    if(var_char < DEBUT_NUM)
        printf("le caractere selectionne est sepacial");
    else
        printf("le caractere selectionne est '%c'", var_char);

    PRINT_SAUT_LIGNE;
    printf("conv en hexa : 0X%x", var_char);
    PRINT_SAUT_LIGNE;
    printf("conv en decimal :  %d", var_char);
    PRINT_SAUT_LIGNE;
}


//----------------------------------------------------------------------------------//
// Nom de la fonction   : Conv_Num_Char
// Entrée / Sortie      : var_int / - / -
// Description          : avec le choix de l'utilisateur sélectionnant un nombre
//                        la fonction affiche la valeur en caractère
// modification         : le 23.06.2014
// Remarque             : -
//----------------------------------------------------------------------------------//
void Conv_Num_Char(int var_int)
{
    printf("la valeur selectionnee est '%d'", var_int);
    PRINT_SAUT_LIGNE;
    printf("conv en caractere : %c", var_int);
    PRINT_SAUT_LIGNE;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Conv_Num_Oct_Hex
// Entrée / Sortie      : var_int / - / -
// Description          : avec le choix de l'utilisateur sélectionnant un nombre
//                        la fonction affiche la valeur en octal et en hexa
// modification         : le 19.08.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Conv_Num_Oct_Hex(int var_int)
{
    printf("la valeur selectionnee est '%d'", var_int);
    PRINT_SAUT_LIGNE;
    printf("conv en octal: %o || conv en hexa : %x", var_int, var_int);
    PRINT_SAUT_LIGNE;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : Astuce_ASCII
// Entrée / Sortie      : - / - / -
// Description          : affiche la correspondance entre un caractère et sa valeur
//                        en numérique (dec + hexa)
// modification         : le 08.07.2015
// Remarque             : -
//----------------------------------------------------------------------------------//
void Astuce_ASCII(void)
{
    //--- déclaration de variable ---//
    char i;                         // utiliser pour l'incrémentation
    char fin_num = 57;              // correspond au caractère '9'

    //--- affiche les valeurs correspondant aux chiffres 0 à 9 ---//
    for(i = DEBUT_NUM; i < fin_num + 1; i++)
    {
        Conv_Char_Num(i);
        PRINT_SAUT_LIGNE;
    }

    //--- affichage des valeurs correspondants au caractère de l'alpahabet en majuscule et minuscule ---//
    for(i = DEBUT_CHAR; i < DEBUT_CHAR + NB_ALPHABETE; i++)
    {
        //--- Partie Majuscule ---//
        Conv_Char_Num(i);
        PRINT_SAUT_LIGNE;

        //--- Partie Minsucle ---//
        Conv_Char_Num(i + SAUT_MAJ_MIN);
        PRINT_SAUT_LIGNE;
    }

    //--- affichage de valeur de certains caractère spéciaux ---//
    Conv_Char_Num(CHAR_RETOUR_CHARIOT);     // retiour chariot
    PRINT_SAUT_LIGNE;
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : ConvDeciBinaire
// Entrée / Sortie      : valNum / - / -
// Description          : affiche la valeur binaire d'une valeur donnée ou flottante
// modification         : le 27.11.2020
// Remarque             : https://fr.wikiversity.org/wiki/Introduction_au_langage_C/Types
//----------------------------------------------------------------------------------//
void ConvDeciBinaire(float valNum)
{
	//-- déclaration de variable --//
	float partieFractionnee; 

	int	partieEntiere; 
	int8_t iteration, iterationEntier = 0, iterationFractionnee = 0, depassement = 0; 
	int8_t tbBinaire[TAILLE_TB_BINAIRE];

	//-- séparartion de la partie entière à la partie fractionnée --//
	partieEntiere = valNum;							//cast implicite 
	partieFractionnee = valNum - partieEntiere;		

	//-- partie entière --//
	//-- boucle diviser tant que le quotient n'est pas à zéro --//
	do
	{
		//-- séparation 
		//-- algorithme convertion binaire --//
		tbBinaire[iterationEntier] = partieEntiere % BASE_2;		// modulo de 2 
		partieEntiere /= BASE_2;							// division par 2 et remise à jour de valDecimal 
		
		//-- MAJ itération --//
		iterationEntier++; 

	} while (partieEntiere != 0);

	//-- récupération de l'emplacement du tableau
	iterationFractionnee = iteration = iterationEntier; 

	//-- partie fractionnee --//
	//-- boucle multipliant par 2 la fraction jusqu'à obtenir une valeur égale à 0 --// 
	do 
	{
		//-- MAJ de la partie fractionnée => recherche du 0 et du 1 binaire fractionner (x 2) --//
		partieFractionnee *= VAL_NUM_2_0;

		//-- calcul pour la conversion en binaire --// 
		tbBinaire[iterationFractionnee] = partieFractionnee;	// cast implicte en entier pour l'enregistrement dans le tableau 
		
		//-- traitement si valeur fractionnée > que 1.0 --//
		if (partieFractionnee >= 1.0)
			partieFractionnee -= 1.0; 

		//-- MAJ itération --//
		iterationFractionnee++; 

		//-- test si la divsion binaire dure plus 5 itérations --//
		if ((iterationFractionnee - iterationEntier) > 5)
			depassement = 1; 

	} while (/*(partieFractionnee < 1.0) ||*/ (partieFractionnee != 0.0) && (depassement != 1)); // || (partieFractionnee != 0.0)));

	//-- affichage du tableau pour la partie entière--//
	printf("la valeur binaire est de 0b "); 

	for (iterationEntier -= 1 ; iterationEntier >= 0; iterationEntier--)
		printf("%d", tbBinaire[iterationEntier]); 
	
	//-- affichage du point de séparation --// 
	printf("."); 

	//-- affichage de la partie fractionnée --// 
	for(; iteration < iterationFractionnee ; iteration++)
		printf("%d", tbBinaire[iteration]);

	PRINT_SAUT_LIGNE; 
}

