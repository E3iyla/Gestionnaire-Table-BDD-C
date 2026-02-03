#include <stdio.h>   
#include <stdlib.h>  // pour exit
#include <string.h>  // pour snprintf
#include "table.h"

// -----------------------------------------------------------------------------
// Fonction : supprimer_fichiers_table
// Supprime uniquement les fichiers meta et data dans un dossier de table.
// Entrée : nom du dossier (ex : "Personnages")
// Retour : 0 si tout va bien, -1 s'il y a eu une erreur
// -----------------------------------------------------------------------------

int supprimer_fichiers_table(const char *nom_table){
    char chemin[256];   // pour stocker le chemin complet vers un fichier
    int erreurs = 0;    // compteur d'erreurs

    // Suppression du fichier meta
    construire_chemin(chemin, nom_table, "meta");
    if (remove(chemin) != 0) {   // remove supprime le fichier si possible
        perror("Impossible de supprimer le fichier meta");
        erreurs++;  // on note une erreur mais on continue
    }

    // Suppression du fichier data
    construire_chemin(chemin, nom_table, "data");
    if (remove(chemin) != 0) {
        perror("Impossible de supprimer le fichier data");
        erreurs++;
    }

    // Si aucune erreur, tout s’est bien passé
    return erreurs == 0 ? 0 : -1;
}

// -----------------------------------------------------------------------------
// Fonction principale (main)
// Réinitialise une table sans supprimer son dossier.
// Utilisation : ./reinitialiser_table.exe <nom_table>
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    // Vérifie que le programme reçoit bien un argument (nom du dossier)
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
}

    // Appel de la fonction de suppression
    if (supprimer_fichiers_table(nom_table) == 0) {
        printf("Table '%s' réinitialisée (meta et data supprimés).\n", nom_table);
    }else{
        printf("La table '%s' n'a pas pu être complètement réinitialisée.\n", nom_table);
        }
    return 0;
}