#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int val;
    cellule *lien;
}cellule;

cellule  *inverser(cellule *l){
    cellule *p,*li;
    if (l!=NULL){
        li =l;
        l=l->lien;
        li->lien=NULL;
        while(l!=NULL){
            p=l;
            l=l->lien;
            p->lien=li;
            li=p;
        }
        l=li;
    }
    return l; 
}
