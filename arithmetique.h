//-----------------------------------------------------------------------------------//
// Nom du projet 		: Langage_C_fixme
// Nom du fichier 		: arithmetique.h
// Date de création 	: 09.04.2015
// Date de modification : 17.03.2019
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier de type header file pour toutes les fonctions
//                        liées aux calculs
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  lien pour la saisie de clavier avec getc & getchar pour ne pas
//                        avoir des erreurs d'interprétation
// 						  -> http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
// 						  lien vers différents
// 						  -> http://fr.wikipedia.org/wiki/String.h
//----------------------------------------------------------------------------------//
#ifndef ARITHMETIQUE_H_INCLUDED
#define ARITHMETIQUE_H_INCLUDED

#define _CRT_NONSTDC_NO_WARNINGS

//--- constante ou définition ---//
#define BASE_2					2
#define CHAR_RETOUR_CHARIOT     '\n'      // caractère spécial représentant un retour de ligne
#define DEBUT_CHAR              65        // correspond a la lettre 'A'
#define DEBUT_NUM               48        // correspond au caractère '0'
#define LIMITE_AXE_X_MAX		100		  // abscisse max
#define LIMITE_AXE_X_MIN		-100	  // abscisse min
#define LIMITE_AXE_Y_MAX		50		  // ordonnee max
#define LIMITE_AXE_Y_MIN		-50		  // ordonnee min
#define NB_ALPHABETE            24        // nombre de caractère dans l'alphabet
#define SAUT_MAJ_MIN            32        // différence entre les caractères majuscule et minuscule -><-

//--- déclaration de prototype ---//
//--- fonctions liées au fichier : calcul_entier.c ---//
void Addition(void);                        //-> affiche une addition pour le user (entier ou flottant)
void Astuce_Calcul(void);                   //-> affiche des exemples d'incrémentation
void Division(void);                        //-> affiche la division de deux nombre choisi par l'utilisateur
void Multiplication(void);                  //-> affiche la multiplication de deux nombre choisi par l'utilisateur
void Soustraction(void);                    //-> affiche la soustraction de deux nombre choisi par l'utilisateur
void Calculs_Segment(void);                     //-> affiche la longueur d'un segment, son milieu ainsi que la pente selon le choix de l'utilisateur

int pemier_calcul(int val_x);               //-> plus implémentée

//--- fonctions liées au fichier : conversions.c ---//
void Conv_Char_Num(char var_char);          //-> converti un caractère en valeur numérique
void ConvDeciBinaire(int valDecimal);		//-> converti un nombre décimal en binaire
void Conv_Num_Char(int var_int);            //-> converti un nombre en caractère
void Conv_Num_Oct_Hex(int var_int);         //-> converti un nombre en octal et en hexa
void Astuce_ASCII(void);                    //-> montre toutes les valeurs des caractères



#endif // ARITHMETIQUE_H_INCLUDED
