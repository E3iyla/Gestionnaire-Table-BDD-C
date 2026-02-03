#include <stdio.h>     // pour printf, fopen, fgets
#include <stdlib.h>    
#include <string.h>    
#include <sys/stat.h>  
#include "table.h"

// -----------------------------------------------------------------------------
// Programme : lister_table
// Objectif  : Afficher le contenu d'une table à partir de "meta" et "data".
// Utilisation : ./lister_table <nom_table>
// -----------------------------------------------------------------------------

int main(int argc, char *argv[]) {

    // Vérifie qu'on a bien un argument
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS) {
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

    if (nb_colonnes == 0) {
        printf("Erreur : aucune colonne trouvée dans meta.\n");
        return EXIT_FAILURE;
    }


    // Ouvre le fichier data
    char chemin_data[256];
    construire_chemin(chemin_data, nom_table, "data");
    FILE *fdata = fopen(chemin_data, "r");
    if (!fdata) {
        printf("Aucune donnée trouvée dans '%s'.\n", chemin_data);
        return EXIT_SUCCESS;
    }

    printf("\n=== Contenu de la table '%s' ===\n\n", nom_table);

    // Affiche les noms de colonnes
    for (int i = 0; i < nb_colonnes; i++)
        printf("%-15s", noms[i]);
    printf("\n");

    for (int i = 0; i < nb_colonnes; i++)
        printf("---------------");
    printf("\n");

    // Affiche les données ligne par ligne
    char ligne[512];
    while (fgets(ligne, sizeof(ligne), fdata)) {
        char *valeur = strtok(ligne, " \n");
        while (valeur) {
            printf("%-15s", valeur);
            valeur = strtok(NULL, " \n");
        }
        printf("\n");
    }

    fclose(fdata);
    printf("\n(fin de la table)\n");
    return EXIT_SUCCESS;
}