//exercice 1
#include <stdio.h>
#include <stdlib.h>
#include "pile.c"
#include "file.c"
#include "liste.c"
//on considere la declaration du type  cellules liste chainee ciculaire non ordonnee
typedef struct cellule {
    int val;
    struct cellule *suivant;    
}cellule;
//a) Ecrire une fonction permettant de tester si la liste est vide.
int vide(celule *p) {return(p==NULL)}
//b) Ecrire une fonction qui permet la création (allocation) d’une cellule.
cellule creer_cellulec(){
    cellule *c;
    c=(cellule) malloc(1*sizeof(cellule));
    c->suivant=NULL;
    return c;
}
//c) Ecrire une fonction permettant de remplir le champ valeur d’une cellule.
void remplirc(cellule *p){
    int x;
    printf("donner un entier:");
    scanf("%d",&x);
    (*p).val=x;
}
//d) Ecrire une fonction qui permet d’enchainer (insérer) une nouvelle cellule à la liste.
cellule *insererc(cellule *liste, cellule *c){
    if (vide(liste)){
        liste =c;
        c->suivant=liste;
        return liste 
    }
    c->suivant=liste->suivant;
    liste->suivant=c;
    return liste;
}
//e) Ecrire une fonction qui affiche une liste chainée circulaire.
void afficher_listec(cellule *liste){
    cellule *p=liste;
    if (vide(p)){
        printf("liste vide \n");
        return;
    }
    while(p->suivant!=liste){
        printf("%d",(*p).val);
        p=p->suivant;
    }
    printf("%d",(*p).val);
    printf("\n");
    getchar();
}
//f) Ecrire une fonction qui supprime une cellule de la liste chainée circulaire.
cellule *suprimerc(int x,cellule *liste ){
    cellule *pp=liste , *q ;
    cellule *p=(cellule *)NULL;
    if (liste == NULL){
        printf("liste vide; elt non trouver \n");
        return NULL;
    }
    if ((liste==liste->suivant) && ((*liste).val==x)){
        free(liste);
        return NULL;
    }
    p=liste->suivant;
    while ((p!=liste) && (*p).val != x ){
        pp=p;
        p=p->suivant;
    }
    if((*p).val==x){
        q=p;
        pp->suivant = q->suivant;
        if (p==liste)
        liste = p->suivant;
        free(q);
    }
    else    printf("elt non trouve \n");
    return liste;
}
