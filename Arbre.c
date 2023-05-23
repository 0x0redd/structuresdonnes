#include<stdio.h>

#define N 20 
typedef int sommet [N];
typedef char *valeur[N];
main(){
    int racine;
    valeur val={"","s0","s1","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","s12"};
    sommet fils={-1,2,3,-1,6,8,-1,10,-1,12,-1,-1,-1,-1};
    sommet frere={-1,-1,4,5,-1,-1,7,-1,9,-1,11,-1,13,-1};
    sommet pere={-1,-1,1,2,1,2,4,4,5,5,7,7,9,9};
}

int nbr_feuilles(sommet n,valeur val){
    int i,nbf=0;
    for (i=1;i<N;i++)
        if (n[i]==-1) {nbf++; printf("%s\n",val[i]);}
        t=fils[sommet];
        while(t!=-1){

            printf("%s",val[t]);
            t=frere[t];
        }
    
}

char *ind_pere(char *s , sommet fils , sommetfrere ,valeur val){
    int i,t;
    for(i=1;i<N;i++) if(!strcmp(s,val[i])){t=i break; }
    int pere = -1 ;
    if (t == 1 ) {printf("pas de pere \n"); getchar();exit(0);}
    while (pere == -1 )
    {
        for(i=1;i<N;i++) if (t==fils[i]) pere=i;
        for(i=1;i<N;i++) if (t==frere[i]) t=i;
    }
    return val [pere];
    
}