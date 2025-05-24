
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmi.h"


int main(int argc, char** argv)
{
    int n,m,i,k,t;
    char** M;
    
citire(&M,&n,&m,&k,&t,argv[1]);

if(t == 1){
  salvare(M,n,m,argv[2]);
  for( i=0;i<k;i++)
    { 
        generare(M,n,m);
          salvare2(M,n,m,argv[2]);
        
    }}


    if(t == 2)
    {
       FILE *fis = fopen(argv[2],"wt");
       if(fis == NULL)
       {puts("eroare");
      exit(1);}

      for(i = 1;i <= k;i++)
        {Stack *s = generare2(M,n,m);
          inversare(s);
        afisarestack(s,fis,i);
      elibereaza(s);}
      fclose(fis);
    }

  

  if(t == 3){

    char **matrice = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        matrice[i] = malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            matrice[i][j] = M[i][j];
        }
    }

    
    node *root = create_node();  
    construire(root, matrice, n, m, 0, k);

   
    FILE *fis = fopen(argv[2], "w");
    if (fis == NULL) {
        puts("eroare");
        exit(1);
    }
    afisare_matrici(root, matrice, n, m, fis);
    fclose(fis);
   elibereaza_memorie(root);
    for (i = 0; i < n; i++) {
        free(matrice[i]);
    }
    free(matrice);
 }

  if (t == 4){
    char **Matrice = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        Matrice[i] = malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            Matrice[i][j] = M[i][j];
        }
    }

    node *root = create_node();
    construire(root, Matrice, n, m, 0, k);

    FILE *fis = fopen(argv[2], "w");
    if (fis == NULL) {
        puts("Eroare");
        exit(1);
    }

   afisare_lant(root, Matrice, n, m, fis);
    fclose(fis);

    elibereaza_memorie(root);
    for (int i = 0; i < n; i++) {free(Matrice[i]);}
    free(Matrice);
}
  for (i = 0; i < n; i++) {
    free(M[i]);
}
free(M);

    return 0;
}
