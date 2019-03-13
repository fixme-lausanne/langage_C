//-----------------------------------------------------------------------------------//
// Nom du projet 		    : Langage_C_fixme
// Nom du fichier 		    : display.h
// Date de création 	    : 25.02.2015
// Date de modification     : 13.03.2019
//
// Auteur 				    : Philou (Ph. Bovey)
//
// Description              : fichier de type header file pour toutes les fonctions
//                            liées à l'afficahge
//
//
// Remarques 			    : lien pour la table ASCII :
// 						    -> http://www.asciitable.com/
// 						     lien pour la saisie de clavier avec getc & getchar pour ne pas
//                           avoir des erreurs d'interprétation
// 						    -> http://fr.openclassrooms.com/informatique/cours/utiliser-les-bonnes-fonctions-d-entree
// 						     lien vers différents
// 						    -> http://fr.wikipedia.org/wiki/String.h
//----------------------------------------------------------------------------------//
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
//--- librairie associée ---//

//-- versionning --//
#define CODE_BLOCK
//#define VISUAL_STUDIO

//--- constante ou définition ---//
//-- caractère spécifique --//
#define CHOIX_BAS               66          // représente B en caractère
#define CHOIX_DROITE            68          // représente D en caractère
#define CHOIX_ENTIER            73          // représente I en caractère
#define CHOIX_EXIT              69          // représente E en caractère
#define CHOIX_FLOTTANT          70          // représente F en caractère
#define CHOIX_GAUCHE            71          // représente G en caractère
#define CHOIX_HAUT              72          // représente H en caractère
#define CHOIX_MENU              77          // représente M en caractère
#define CHOIX_MENU_PRINCIPAL    80          // représente P en caractère
#define CHOIX_PLEINS            80          // représente P en caractère
#define CHOIX_VIDE              86          // représente V en caractère
#define MAX_CARA                80          // largeur d'une fenêtre DOS

//-- gestion de message user --//
#define DELETE_SCREEN           system("cls")
#define PRINT_SAUT_LIGNE        printf("\n")
#define PRINT_ESPACE            printf(" ")
#define PRINT_ETOILE            printf("*");
#define PRINT_M_MENU            printf("MENU : ")
#define PRINT_SELECTION_MENU    printf("Veuillez Selectionner votre Menu : ")
#define PRINT_SELECTION_CHAR    printf("Veuillez taper un caractere :")
#define PRINT_SELECTION_CHOIX   printf("Veuillez Selectionner votre choix : ")
#define PRINT_SELECTION_GD      printf("Veuillez choisir entre Gauche[G] et Droite[D] : ")
#define PRINT_SELECTION_HB      printf("Veuillez choisir entre Haut[H] et Bas[B] : ")
#define PRINT_SELECTION_NB      printf("Indiquer un nombre : ")
#define PRINT_SELECTION_PV      printf("Veuillez choisir entre Plein [P] et Vide [V] : ")
#define PRINT_SELECTION_INT     printf("Voulez-vous travailler en entier   - taper 'I' ")
#define PRINT_SELECTION_FLOAT   printf("Voulez-vous travailler en flottant - taper 'F' ")

#define NAME_M_ADITION                  "ADITION"
#define NAME_M_AFFICHAGE                "AFFICHAGE"
#define NAME_M_ARITHEMTIQUE             "ARITHMETIQUE"
#define NAME_M_ASTUCE_PRINTF            "ASTUCE PRINTF"
#define NAME_M_ASTUCE_INCR              "ASTUCE INCREMENTATION & DECREMENTATION"
#define NAME_M_ASTUCE_CONV_CHAR_NUM     "ASTUCE CONVERSION CARACTERE NUMERIQUE - TABLE"
#define NAME_M_ASTUCE_LOOP              "ASTUCE BOUCLE"
#define NAME_M_CONV                     "CONVERSIONS"
#define NAME_M_CONV_CHAR_NUM            "CONVERSION CARACTERE EN NUM (DEC - HEXA)"
#define NAME_M_CONV_NUM_CHAR            "CONVERSION NUMERIQUE EN CARACTERE"
#define NAME_M_CONV_NUM_OCT_HEX         "CONVERSION NUMERIQUE EN OCTAL - HEXA"
#define NAME_M_DIVISION                 "DIVISION"
#define NAME_M_DISP_CARRE               "AFFICHAGE DE CARRE"
#define NAME_M_DISP_LOSANGE             "AFFICHAGE DE LOSANGE"
#define NAME_M_DISP_PARALLELOGRAMME     "AFFICHAGE DE PARALLELOGRAMME"
#define NAME_M_DISP_TRIANGLE            "AFFICHAGE DE TRIANGLE"
#define NAME_M_MULTIPLICATION           "MULTIPLICATION"
#define NAME_M_OP_SIMPLE                "OPERATION SIMPLE"
#define NAME_M_PRINICIPAL               "PRINCIPAL"
#define NAME_M_SOUSTRACTION             "SOUSTRACTION"

//--- déclaration de variable global ---//
extern char var_retour;

//--- déclaration de prototype ---//
//--- liée au fichier template_menu.c ---//
void Template_Menu_Ligne(void);                         //-> affiche un trait d'*
void Template_Display_Menu(char choix_menu);            //-> affiche le titre dans lequel se trouve le user et sélectionne le menu choisi
void Template_Choix_Menu_Principal(void);               //-> affiche le menu principal pour le user

//--- liée au fichier template_menu_arithm.c ---//
void Template_Display_Menu_Arithm(char choix_menu);     //-> affiche le titre dans lequel se trouve le user et sélectionne le menu choisi
void Template_Choix_Menu_Arithmetique(void);            //-> affiche le menu arithmetique
void Template_Choix_Menu_OP_Simple(void);               //-> affiche le menu opération simple
void Template_Choix_Menu_Conversion(void);              //-> affiche le menu Conversion
void Template_Display_Menu_OP_Simple(char choix_menu);  //-> affiche le menu concernant les oérations simples
void Template_Display_Menu_Conversion(char choix_menu); //-> affiche le menu concernant différentes conversions

//--- liée au fichier template_menu_display.c ---//
void Template_Choix_Menu_Display(void);                 //-> affichage de différents theme du menu display
void Template_Display_Menu_Display(char choix_menu);    //-> affiche le titre dans lequel se trouve le user et sélectionne le menu choisi

//--- liée au fichier selection_user.c ---//
char Selection_Menus(char choix_selection_msg);         //-> permet de récuprer une valeur entrer par l'utilisateur
char Select_Var_Cara(void);                             //-> récupère un caractère fournis par un utilisateur
char Select_Option(void);                               //-> permet à l'utilisteur de choisir entre deux options
float Select_Var_Flottant(void);                        //-> récupère une chaine de caractère et la transforme en floattant
int Select_Var_Entier(void);                            //-> récupère une châine de chaîne de caractère et le transforme en entier

//--- lié au fichier help.c ---//
void Help_Printf(void);                                 //-> affiche une aide sur le printf
void Help_Loop(void);                                   //-> effect visuel avec des boucles itératives

//--- liée au fichier affichage.c ---//
void Triangle_Etoile_AGB(int nb_etoile);                            // permet d'afficher un triangle selon les datas du user
void Triangle_Etoile_AGH(int nb_etoile);
void Triangle_Etoile_ADB(int nb_etoile);
void Triangle_Etoile_ADH(int nb_etoile);
void Carre(int val_user);                                           // afficher un carré plein d'étoiles
void Parallelogramme_AG(int val_user);                              // affiche un parallelogramme avec l'angle a gauche
void Parallelogramme_AD(int val_user);                              // affiche un parallelogramme avec l'angle a droite
void Choix_Emplacement_Triangle(char choix_HB, char choix_GD);      // definit quel dessin de traingle afficher selon le user
void Losange_Vide(void);                                            // affiche un losange entouré d'étoile
void Losange_Plein(void);                                           // affiche un losange remplit d'étoile
void Selection_Losange (char choix_user);                           // selectionne un losange vide ou plein
void Selection_Sens_Paralelogramme(char choix_user);                // choix pour l'affichage d'un parallelogramme (angle droite ou gauche)

#endif // DISPLAY_H_INCLUDED
