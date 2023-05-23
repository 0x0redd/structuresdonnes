// exercice 1 
#include <stdio.h>
#include <stdlib.h>
#include "pile.c"
#include "file.c"
//afficher(P) : cette fonction affiche tous les éléments de la pile P.
void afficherp(pile P){
    while(!videp(P)){
        printf("%d",valeurp(P));
        supprimerp(&P);
    }
    printf("\n");
}
//afficher(F) : cette fonction affiche tous les éléments de la file F.
void afficherf(file F){
    while(!videf(F)){
        printf("%d",valeurf(F));
        supprimerf(&F);
    }
    printf("\n");
}
//dépilerKelt(P, k) : cette fonction dépile k éléments si la pile P contient aumoins k éléments, sinon elle dépile toute la pile.
void  depilerkelt(pile p , int k){
    while((!videp(p)) && (k>0)){
        supprimerp(&p);
        k--;
    }
}
//dépilerJusquà(P,elt) : cette fonction dépile la pile P jusqu'à l'élément elt. L'élément elt n'est pas dépilé. Si l'élément n'appartient pas à la pile, alors la fonction dépile toute la pile.
void depilerpjusqua(pile p, int elt){
    while((!videp(p)) && (valeurp(p)!=elt)){
        supprimerp(&p);
    }
}
//dépilerJusquà(P,elt) : cette fonction dépile la pile P jusqu'à l'élément elt. L'élément elt n'est pas dépilé. Si l'élément n'appartient pas à la pile, alors la fonction dépile toute la pile.
void depilerfjusqua(file f,int elt ){
    while((!videf(f)) && (valeurf(f)!=elt)){
        supprimerf(&f);
    }
}
