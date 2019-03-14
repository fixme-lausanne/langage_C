//-----------------------------------------------------------------------------------//
// Nom du projet 		: Langage_C_fixme
// Nom du fichier 		: conversion.c
// Date de création 	: 19.06.2015
// Date de modification : 29.12.2018
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier comportant différentes fonctions de conversions
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
// Entrée / Sortie      : valDecimal / - / -
// Description          : affiche la valeur binaire d'une valeur donnée entière
// modification         : le 27.12.2018
// Remarque             : -
//----------------------------------------------------------------------------------//
void ConvDeciBinaire(int valDecimal)
{
	//-- déclaration de variable --
	int iteration = 0; 
	int tbBinaire[100]; 

	//-- boucle diviser tant que le quotient n'est pas à zéro --//
	do
	{
		//-- algorithme convertion binaire --//
		tbBinaire[iteration] = valDecimal % BASE_2;		// modulo de 2 
		valDecimal /= BASE_2;							// division par 2 et remise à jour de valDecimal 
		
		//-- MAJ itération --//
		iteration++; 

	} while (valDecimal != 0);

	//-- affichage du tableau --//
	printf("la valeur binaire est de 0b "); 
	for (iteration -= 1 ; iteration >= 0; iteration--)
		printf("%d", tbBinaire[iteration]); 

	PRINT_SAUT_LIGNE; 
}

