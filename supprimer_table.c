#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>    
#include <dirent.h>     // pour parcourir le contenu d'un dossier (opendir, readdir)
#include <unistd.h>     // pour rmdir, unlink
#include <sys/types.h>  // types utilisés par dirent
#include "table.h"

// -----------------------------------------------------------------------------
// Fonction : supprimer_contenu_dossier
// Supprime tous les fichiers contenus dans un dossier donné.
// Entrée : nom du dossier (ex : "Personnages")
// Retour : 0 si tout va bien, -1 si erreur
// -----------------------------------------------------------------------------

int supprimer_contenu_dossier(const char *nom_dossier) {
    DIR *dossier;                // pointeur vers le dossier ouvert
    struct dirent *entree;       // structure contenant le nom d'un fichier lu
    char chemin[512];            // pour stocker le chemin complet d'un fichier

    dossier = opendir(nom_dossier);  // ouverture du dossier
    if (dossier == NULL) {           // si l'ouverture échoue
        perror("Erreur lors de l'ouverture du dossier");
        return -1;
    }

    // On lit chaque élément du dossier un par un
    while ((entree = readdir(dossier)) != NULL) {
        // On ignore les deux entrées spéciales "." et ".."
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
            continue;

        // Construction du chemin complet vers le fichier à supprimer
        // Exemple : "Personnages/meta"
        snprintf(chemin, sizeof(chemin), "%s/%s", nom_dossier, entree->d_name);

        // On supprime le fichier (remove fonctionne pour fichiers simples)
        if (remove(chemin) != 0) {
            perror("Erreur lors de la suppression d'un fichier");
            closedir(dossier);
            return -1;
        }
    }

    closedir(dossier);  // on ferme le dossier proprement
    return 0;            // succès
}

// -----------------------------------------------------------------------------
// Fonction principale (main)
// Gère la suppression complète d'une table (dossier + contenu).
// Utilisation : ./supprimer_table.exe <nom_table>
// -----------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    // On vérifie qu'un argument a bien été donné (le nom de la table)
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
}

    // Étape 1 : supprimer le contenu du dossier
    if (supprimer_contenu_dossier(nom_table) != 0) {
        return 1;  // erreur déjà affichée
    }

    // Étape 2 : supprimer le dossier vide
    if (rmdir(nom_table) != 0) {
        perror("Erreur lors de la suppression du dossier");
        return 1;
    }

    // Tout s'est bien passé
    printf("Table '%s' supprimée avec succès.\n", nom_table);
    return 0;
}