#define N 50
typedef struct { 
	int tab_f[N];// //le tableau sera indicÃ© de 0 Ã  N-1
	int it,iq;
} file;

void creerf(file *);
int videf(file );
int valeurf(file );
int ajouterf(int,file *);
int supprimerf(file *);
int aff_file(file );
void remplir_file(file *);