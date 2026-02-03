#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <sys/stat.h>  // pour stat
#include "table.h"

// -----------------------------------------------------------------------------
// Programme : inserer_table
// Objectif  : Ajouter une nouvelle ligne dans le fichier "data" d'une table.
// Utilisation : ./inserer_table <nom_table>
// -----------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    // Vérifie qu'on a bien donné un argument (le nom de la table)
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS){
        return EXIT_FAILURE;
}

    // Vérifie que le dossier existe
    if (!verifier_existence_dossier(nom_table))
        return EXIT_FAILURE;

    // Ouvre le fichier meta
    char chemin_meta[256];
    snprintf(chemin_meta, sizeof(chemin_meta), "%s/meta", nom_table);
    FILE *fmeta = fopen(chemin_meta, "r");
    if (!fmeta) {
        printf("Erreur : impossible d'ouvrir '%s'.\n", chemin_meta);
        return EXIT_FAILURE;
    }

    // Lecture des colonnes
    char noms[50][50];
    int types[50];
    int nb_colonnes = 0;
    while (fscanf(fmeta, "%49s %d", noms[nb_colonnes], &types[nb_colonnes]) == 2) {
        nb_colonnes++;
    }
    fclose(fmeta);


    // Ouvre le fichier data en mode "append" (ajout)
    char chemin_data[256];
    construire_chemin(chemin_data, nom_table, "data");
    FILE *fdata = fopen(chemin_data, "a");
    if (!fdata) {
        printf("Erreur : impossible d'ouvrir ou créer '%s'.\n", chemin_data);
        return EXIT_FAILURE;
    }

    printf("\n=== Insertion d'une nouvelle ligne dans '%s' ===\n", nom_table);

    // Pour chaque colonne, demande une valeur à l'utilisateur
    for (int i = 0; i < nb_colonnes; i++) {
        char valeur[100];

        printf("Valeur pour '%s' (type %d) : ", noms[i], types[i]);
        scanf(" %99[^\n]", valeur);  // lit toute la ligne jusqu'au retour chariot
        getchar(); // consomme le \n restant dans le buffer

        fprintf(fdata, "%s", valeur);  // écrit la valeur dans data
        if (i < nb_colonnes - 1)
            fprintf(fdata, " ");       // espace entre chaque valeur
    }
    fprintf(fdata, "\n");  // fin de ligne = fin de l'enregistrement
    fclose(fdata);

    printf("→ Enregistrement ajouté dans '%s/data'.\n", nom_table);
    return EXIT_SUCCESS;
}