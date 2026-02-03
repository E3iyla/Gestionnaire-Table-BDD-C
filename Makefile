# Makefille!!

opt = -Wall -Wextra -std=c99 -c

#Compilation de tous les programmes avec tout 
all : creer_table inserer_table lister_table preparer_table reinitialiser_table supprimer_table


creer_table : creer_table.o table.o
	gcc -o creer_table creer_table.o table.o

creer_table.o : creer_table.c
	gcc ${opt} creer_table.c


inserer_table : inserer_table.o table.o
	gcc -o inserer_table inserer_table.o table.o

inserer_table.o : inserer_table.c
	gcc ${opt} inserer_table.c



lister_table : lister_table.o table.o
	gcc -o lister_table lister_table.o table.o

lister_table.o : lister_table.c
	gcc ${opt} lister_table.c



preparer_table : preparer_table.o table.o
	gcc -o preparer_table preparer_table.o table.o

preparer_table.o : preparer_table.c
	gcc ${opt} preparer_table.c


reinitialiser_table : reinitialiser_table.o table.o
	gcc -o reinitialiser_table reinitialiser_table.o table.o

reinitialiser_table.o : reinitialiser_table.c
	gcc ${opt} reinitialiser_table.c



supprimer_table : supprimer_table.o table.o
	gcc -o supprimer_table supprimer_table.o table.o

supprimer_table.o : supprimer_table.c
	gcc ${opt} supprimer_table.c


table.o : table.c
	gcc ${opt} table.c


clean :
	rm -f *.o
	rm -f creer_table inserer_table lister_table preparer_table reinitialiser_table supprimer_table
