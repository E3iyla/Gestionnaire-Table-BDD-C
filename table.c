

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // pour stat
#include "table.h"


typedef struct {
    char nom[50];  // nom de la colonne
    int type;      // 0 = int 2 = texte 3 = date (peut etre float)
} Colonne;


typedef struct {
    char nom[100];          // nom de la table 
    int nb_colonnes;        // nombre total de colonnes
    Colonne colonnes[50];   // tableau des colonnes
} Table;


//le cas ou l'utilisateur n'a pas fournit le bon nombre d'arguments
int verifier_arguments(int argc, char *argv[], char **nom_table) {
    if (argc != 2) {
        fprintf(stderr, "Erreur : vous devez indiquer le nom de la table à créer.\n");
        fprintf(stderr, "Exemple : %s Personnages\n", argv[0]);
        return EXIT_FAILURE;
    }

    *nom_table = argv[1];  // on passe le nom de la table à l'appelant, on recup ici le nom de la table
    return EXIT_SUCCESS;
}




// verifier que l existance de la table
int verifier_existence_dossier(const char *nom_table) {
    struct stat st;
    if (stat(nom_table, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Erreur : le dossier '%s' n'existe pas.\n", nom_table);
        return 0; // on peut aussi faire un exitfaillure 
    }
    return 1; 
}


// construire le chemin complet vers un fichier dans la table
void construire_chemin(char *destination, const char *nom_table, const char *nom_fichier) {
    strcpy(destination, nom_table);  // copie "nom_table" dans destination
    strcat(destination, "/");        // ajoute le slash
    strcat(destination, nom_fichier); // ajoute le nom du fichier
}


















