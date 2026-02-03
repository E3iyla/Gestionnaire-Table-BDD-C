

# → Gestionnaire de tables en C

Ce projet permet d’implémenter un petit gestionnaire de tables de base de données en langage C. 
Chaque table est représentée par un dossier qui contient un fichier **meta:** permet de décrire la structure de la table (nom et types des colonnes) et un fichier **data:** contient le contenu de la table (les enregistrements).

Grâce à ce gestionnaire de tables en C, on va pouvoir créer, préparer, remplir, lister, réinitialiser et supprimer une table.

 ⇒ Avant de compiler, assurez-vous d’avoir les fichiers ci-dessous dans le dossier du projet :
        - creer_table.c
        - inserer_table.c
        - lister_table.c
        - preparer_table.c
        - reinitialiser_table.c
        - supprimer_table.c
        - table.c
        - table.h
        - utile.c
        - makefile
        - README.md

## Compilation 

Depuis le terminal (Bash, VSCode, etc…)
    1. Placez-vous dans le dossier du projet : cd nom_dossier
    2. Compilez les fichiers sources avec : Make


⇒ Exécution du programme

1. **Créer une table** : `./creer_table <nom_table>`
   - Crée un dossier portant le nom de la table.

2. **Préparation de la table** : `./preparer_table <nom_table>`
   - Si la table existe, le programme vous demandera :
     - le nombre de colonnes souhaité
     - leurs noms
     - et leurs types.
   - Le fichier **meta** sera ensuite créé dans le dossier de la table.

3. **Insérer un enregistrement** : `./inserer_table <nom_table>`
   - Demande à l’utilisateur de saisir les valeurs de chaque colonne, puis les enregistre dans le fichier **data**.
   - Vous pouvez relancer cette commande plusieurs fois pour ajouter plus de données.

4. **Lire le contenu de la table** : `./lister_table <nom_table>`
   - Affiche toutes les données enregistrées dans la table de façon formatée.

5. **Réinitialiser la table** : `./reinitialiser_table <nom_table>`
   - Permet de vider le contenu des fichiers **meta** et **data**, sans effacer le dossier.

6. **Supprimer complètement la table** : `./supprimer_table <nom_table>`
   - Supprime entièrement le dossier et tous ses fichiers associés.
  
     
