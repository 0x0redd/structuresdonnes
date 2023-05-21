#define N 50
typedef struct { int tab_p[N];//le tableau sera indicÃ© de 0 Ã  N-1
int ip;
} pile;
void creerp(pile *);
int videp (pile );
int valeurp(pile );
int ajouterp(int,pile *);
int supprimerp(pile *);
void aff_pile(pile ); // affichage du contenu dâ€™une pile
void remplir_pile(pile *);