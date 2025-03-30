#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citire(char*** M ,int *n, int *m, int *k,int *t, const char *fisier)
{
    FILE *fis = fopen(fisier, "rt");
    if (fis == NULL)
    {
        puts("eroare la deschiderea fisierului");
        exit(1);
    }

    fscanf(fis , "%d" , t);
    fscanf(fis,"%d %d" , n, m);
    fscanf(fis,"%d", k);

    
     (*M) = (char**)malloc((*n) * sizeof(char*));
    if ((*M) == NULL)
    {
        puts("alocare esuata");
        exit(1);
    }

    for (int i = 0; i < *n; i++)
    {
        (*M)[i] = (char*)malloc((*m + 1) * sizeof(char)); 
        if ((*M)[i] == NULL)
        {
            puts("eroare alocare");
            exit(1);
        }}
        for(int i=0;i<(*n);i++)
        {
            fscanf(fis,"%99s", *((*M)+i));
        }
    

    fclose(fis); 
}

void salvare(char **M, int n, int m, const char *fisier)
{
    FILE *fis = fopen(fisier, "wt");
    if (fis == NULL)
    {
        puts("eroare la deschiderea fisierului");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fis, "%s\n", M[i]); 
    }
 
fprintf(fis,"\n");
    fclose(fis);
}

void salvare2(char **M, int n, int m, const char *fisier)
{
    FILE *fis = fopen(fisier, "a");
    if (fis == NULL)
    {
        puts("eroare la deschiderea fisierului");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fis, "%s\n", M[i]); 
    }
 
fprintf(fis,"\n");
    fclose(fis);
}

 int vecini(char **M, int n, int m, int i, int j) {
    int k = 0;

    if (i == 0 && j == 0) {
      
        if(M[i+1][j] == 'X') k++;
        if(M[i+1][j+1] == 'X') k++;
        if(M[i][j+1] == 'X') k++;
    }
    else if (i == 0 && j == m - 1) {
      
        if(M[i+1][j] == 'X') k++;
        if(M[i+1][j-1] == 'X') k++;
        if(M[i][j-1] == 'X') k++;
    }
    else if (i == n - 1 && j == 0) {
       
        if(M[i][j+1] == 'X') k++;
        if(M[i-1][j] == 'X') k++;
        if(M[i-1][j+1] == 'X') k++;
    }
    else if (i == n - 1 && j == m - 1) {
      
        if(M[i][j-1] == 'X') k++;
        if(M[i-1][j] == 'X') k++;
        if(M[i-1][j-1] == 'X') k++;
    }
    else if (i == 0) {
       
        if(M[i][j-1] == 'X') k++;
        if(M[i][j+1] == 'X') k++;
        if(M[i+1][j-1] == 'X') k++;
        if(M[i+1][j] == 'X') k++;
        if(M[i+1][j+1] == 'X') k++;
    }
    else if (i == n - 1) {
     
        if(M[i][j-1] == 'X') k++;
        if(M[i][j+1] == 'X') k++;
        if(M[i-1][j-1] == 'X') k++;
        if(M[i-1][j] == 'X') k++;
        if(M[i-1][j+1] == 'X') k++;
    }
    else if (j == 0) {
      
        if(M[i-1][j] == 'X') k++;
        if(M[i+1][j] == 'X') k++;
        if(M[i-1][j+1] == 'X') k++;
        if(M[i][j+1] == 'X') k++;
        if(M[i+1][j+1] == 'X') k++;
    }
    else if (j == m - 1) {
        
        if(M[i-1][j] == 'X') k++;
        if(M[i+1][j] == 'X') k++;
        if(M[i-1][j-1] == 'X') k++;
        if(M[i][j-1] == 'X') k++;
        if(M[i+1][j-1] == 'X') k++;
    }
    else {
        
        if(M[i-1][j-1] == 'X') k++;
        if(M[i-1][j] == 'X') k++;
        if(M[i-1][j+1] == 'X') k++;
        if(M[i][j-1] == 'X') k++;
        if(M[i][j+1] == 'X') k++;
        if(M[i+1][j-1] == 'X') k++;
        if(M[i+1][j] == 'X') k++;
        if(M[i+1][j+1] == 'X') k++;
    }

    return k;
}

 
void generare(char **M, int n, int m)
{
    
    int i,j;
    char **M2= (char **)malloc(n * sizeof(char*));
    if (M2== NULL) {
        printf("Eroare la alocarea memoriei\n");
    }
    

    for ( i = 0; i < n; i++) {
        M2[i] = (char *)malloc((m+1) * sizeof(char));
        
}

for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M2[i][j]=M[i][j];
        }
    }
   
 for(i=0;i<n;i++)
    for(j=0;j<m;j++){
 if((vecini(M,n,m,i,j) > 3 || vecini(M,n,m,i,j) < 2) && M[i][j] == 'X')
 {M2[i][j] = '+';}
 if((vecini(M,n,m,i,j) == 3 || vecini(M,n,m,i,j) == 2) && M[i][j] == 'X')
 {M2[i][j] = 'X';}
 if(vecini(M,n,m,i,j) == 3 && M[i][j] == '+')
 {M2[i][j] = 'X';}
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M[i][j]=M2[i][j];
        }
    }
    for( i=0;i<n;i++)
    free(M2[i]);
    free(M2);
}

int main(int argc, char** argv)
{
    int n,m,i,k,t;
    char** M;
    
citire(&M,&n,&m,&k,&t,argv[1]);
salvare(M,n,m,argv[2]);
  for( i=0;i<k;i++)
    {
        generare(M,n,m);
          salvare2(M,n,m,argv[2]);
    }

for ( i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
    return 0;
}