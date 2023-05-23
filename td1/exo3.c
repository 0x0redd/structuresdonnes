#include <stdio.h>
#include <stdlib.h>
#include "pile.c"
#include "file.c"
//Ecrire un algorithme pour déplacer les entiers de P1 dans une pile P2 de façon à avoir dans P2 tous les nombres pairs en dessous des nombres impairs.

void pile_paire_impaire(pile p1,pile p2){
    pile aux; 
    creep(&aux);
    while(!videp(p1)){
        if(valeur(p1)%2) ajouter(valeurp(p1),&aux);
        else ajouterp(valeurp(p1),&p2);
        supprimerp(&p1);
    }
    while(!videop(aux)){
        ajouter(valeurp(aux),p2);
        supprimerp(&aux);
    }
}

/*Ecrire un algorithme pour copier dans P2 les nombres pairs contenus dans P1 .
Le contenu de P1 après exécution de l'algorithme doit être identique à celui avant
exécution.
Les nombres pairs dans P2 doivent être dans l'ordre où ils apparaissent dans P1 .*/

void pile_p1_p2_ordre(pile *p1,pile *p2){
    pile aux;
    creerp(&aux);
    while (!videp(*p1)) {
        ajouterp(valeurp(*p1),&aux);
        supprimerp(p1);
    }
    while (!videp(aux)) {
        if (valeurp(aux)%2 ==0) ajouterp(valeurp(aux),p2);
        ajouterp(valeur(aux),p1);
        supprimerp(&aux);
    }
}