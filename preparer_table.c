// demande les colonnes et creer le fichier meta
// description de la table les noms et types des colonnes
// meta -> la description de la table (les colonnes)

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS et EXIT_FAILURE
#include <string.h> // Pour strcspn, snprintf
#include "table.h"


int main(int argc, char *argv[]) {
// dans le cas ou l'utilisateur n'a pas fournit le bon nombre d'arguments
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
}

 // creation du fichier meta contruction du chemain meta 
    char chemin_meta[256];
    construire_chemin(chemin_meta, nom_table, "meta");

// ouverture du fichier meta en ecriture
    FILE *fichier_meta = fopen(chemin_meta, "w"); // w = write
    if (fichier_meta == NULL) { // si l'ouverture a echoue -> code d'erreur + fin du programme
        printf("Erreur : impossible de créer le fichier meta dans le dossier '%s'.\n", nom_table);
        printf("Vérifiez que le dossier existe (créez-le avec ./creer_table <nom_table>).\n");
        return EXIT_FAILURE;
    }

// Demander le nombre de colonnes a l'utilisateur
    int nb_colonnes;
    printf("Combien de colonnes voulez-vous ? ");
    scanf("%d", &nb_colonnes);

   
    getchar(); // Nettoie le buffer avant la prochaine lecture '\n'


// Boucle répétée pour chaque colonne : on demande son nom et son type
    for (int i = 0; i < nb_colonnes; i++) {
        char nom_colonne[50];
        int type_colonne;

        printf("Nom de la colonne %d : ", i + 1);
        fgets(nom_colonne, sizeof(nom_colonne), stdin);

// Supprimer le \n de fin de ligne
        nom_colonne[strcspn(nom_colonne, "\n")] = '\0';

        printf("Type de la colonne %d (0 = int, 2 = texte, 3 = date) : ", i + 1); // demander le type
        scanf("%d", &type_colonne);
        getchar();  // Vider le buffer car 

// Écrire les infos dans le fichier meta
        fprintf(fichier_meta, "%s %d\n", nom_colonne, type_colonne);
    }


    fclose(fichier_meta); // fermer le fichier meta apres ecriture
    printf("\nFichier meta créé avec succès dans '%s/meta'.\n", nom_table);
    return EXIT_SUCCESS; // fin du programme avec code de succes
}

