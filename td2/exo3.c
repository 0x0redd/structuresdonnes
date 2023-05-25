//Exercice 3 
//Ecrire une fonction qui fusionne deux listes chaînées triées
#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int val;
    cellule *lien;
}cellule;

cellule *fusionner(cellule *l1 , cellule *l2){
    cellule *p=l1, *q=l2, *f,*pf;
    if (vide(l1)) return l2;
    if (vide(l2)) return l1;
    if ((*p).val < (*q).val){
        f=p;
        q=q->lien;
        pf=f;
    }
        else if ((*p).val > (*q).val ){
            f=q;
            q=q->lien;
            pf=f;
        }
            else{
                f=q;
                q=q->lien;
                f->lien=p;
                p=p->lien;
                pf=f->lien;
            }

    while((p!=NULL)&&(q!=NULL)){
        if ((*p).val < (*q).val){
            pf->lien=p;
            p=p->lien;
        }
            else if((*p).val > (*q).val){
                pf->lien=q;
                q=q->lien;
            }
                else{
                    pf->lien=p;
                    p=p->lien;
                    pf=pf->lien;
                    pf->lien=q;
                    q=q->lien;
                }
        pf=pf->lien;
    }
    if (p==NULL)
        while (q!=NULL) {
            pf->lien=q ; 
            q=q->lien;
            pf=pf->lien;
        }
    else 
        while (p!=NULL) {
            pf->lien=p ; 
            p=p->lien;
            pf=pf->lien;
        }
    return f;
}