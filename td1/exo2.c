#include <stdio.h>
#include <stdlib.h>
#include "pile.c"
#include "file.c"

// ecrire les fonctions suivantes. on poura eventuellemrt utilise une ou deux des piles/files temporaires,

//#1 appartient(P, elt) : cette fonction retourne vrai si l'élément appartient à la pile,faux sinon

/*void appartient (pile p , int elt ){
    int i;
    while((!vide(p)) && (valeurp(p)!=elt)){
        i = 1;
        supprimerp(&p);
    }
    if(valeurp(p)==elt){
        i=0;
    }
    return i;
}*/

void appartient (pile p , int elt ){
    while(!videp(p)){
        if(valeurp==elt) return 1;
        supprimerp(&p);
    }
    return 0; 
}
//inverser(F) : cette fonction inverse les éléments de la file F.

void inverserf(file f){
    pile p;
    creerp(&p);
    while(!videf(f)){
        ajouterp(valeurf(f),&p);
        supprimerf(&p);
    }

    while(!videp(p)){
        ajouterf(valeurp(p),&f);
        supprimerp(&p);
    }
}
//inverser(P) : cette fonction inverse les éléments de la pile P. On interdit l'utilisation de files. Seules des piles temporaires peuvent être utilisées.
void iverserp(pile p){
    pile p1,p2;
    creerp(&p1);
    creerp(&p2);
    while(!videp(p)){
        ajouterp(valeurp(p),&p1);
        supprimerp(&p);
    }
    while(!videp(p1)){
        ajouterp(valeurp(p1),&p2);
        supprimerp(&p1);
    }
    while(!videp(p2)){
        ajouterp(valeurp(p2),&p);
        supprimerp(&p2);
    }
}
