// creer le dossier/une table (avec surement mkdir)
// sans ça on peut rien stocker   


#include <stdio.h>
#include <stdlib.h>
#include <errno.h> // pour errno
#include <sys/stat.h> // pour mkdir
#include "table.h"


int main(int argc, char *argv[]) {
// dans le cas ou l'utilisateur n'a pas fournit le bon nombre d'arguments
    char *nom_table;
    if (verifier_arguments(argc, argv, &nom_table) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
}

// cas ou il y a une erreur de création, si mkdir échoue
    if (mkdir(nom_table, 0755) != 0) {
    perror("Erreur lors de l'initialisation de la table");
    return EXIT_FAILURE;
}
    printf("Le dossier '%s' a été créé avec succès.\n", nom_table);
    return EXIT_SUCCESS;
}

