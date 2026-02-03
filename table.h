// déclarer les structure et fonctions

#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h> // pour EXIT_SUCCESS / EXIT_FAILURE

int verifier_arguments(int argc, char *argv[], char **nom_table);

int verifier_existence_dossier(const char *nom_table);

void construire_chemin(char *destination, const char *nom_table, const char *nom_fichier);



#endif






