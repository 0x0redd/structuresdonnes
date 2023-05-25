//On considère une liste doublement chaînée dont la cellule type est définie de la façon suivante:

typedef struct cellule{
    int val;
    struct cellule *suiv;
    struct cellule *pred;
}cellule;
/*a) cellule *inserer_debut(cellule *liste, cellule *c);
qui insère une nouvelle cellule c en début de liste*/

cellule *insere_debut(cellule *liste,cellule*c){
    c->suiv = liste;
    liste->pred = c;
    liste = c;
    return liste;
}

/*b) cellule *inserer_fin(cellule *liste , cellule *c);
qui insère une nouvelle cellule c en fin de liste*/

cellule *insere_fin(cellule *liste , cellule *c){
    if(vide(liste)) liste=c;
    else{
        cellule *q=liste;
        while (q->suiv != NULL) q=q->suiv;
        q->suiv =c;
        q->pred=q;
    }
    return liste;
}

/*c) cellule *recherche_elt(int x, cellule *liste);
qui retourne le pointeur de la cellule contenant l’entier x donné dans la liste s’il existe*/

cellule *recherche_elt(int x,cellule *liste){
    cellule *p=liste;
    while((p!=NULL)&&((*p).val !=x))
        p=p-suiv;
        if (p==null) return null;
        return;
}

/*d) cellule *inserer(cellule *liste , cellule *c);
qui insère la cellule c, à sa place, dans la liste triée liste*/

cellule *inserer2(cellule *liste,cellule *c){
    cellule *p=liste;
    if (vide(liste)) return c;
    while (((*c).val > (*p).val) && (p->suiv!=NULL)) p=p->suiv;
    if ((*c).val > (*p).val){
        p->suiv=c;
        c->pred=p;
    }
    else{
        if (p->pred!=NULL){
            c->suiv=p;
            c->pred=p->pred;
            p->pred->suiv=c;
            p->pred=c;
            }
        else {
        c->suiv=p;
        p->pred=c;
        liste=c;
        }
    }
    return liste;
}

/*e) cellule *supprimer(cellule *liste , int x);
qui enlève la première cellule contenant x de la liste .*/

cellule *supprimer(cellule *liste,int x){
    cellule *p=liste,*q;
    while(!vide(p) && x!=(*p).val) p=p->suiv;
    if (vide(p)){printf("non trouve\n"); return liste;}
    else{
        q=p;
        if (p->pred != NULL){
            p->pred->suiv=p->suiv;
            if (p->suiv != NULL) p->suiv->pred=p->pred;
        }
        else{
            liste=p->suiv;
            if (p->suiv != NULL) p->suiv->pred=NULL;
        }
    }
    free(q);
    return liste;
}