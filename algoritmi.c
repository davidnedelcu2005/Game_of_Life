
#include "algoritmi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire(char*** M ,int *n, int *m, int *k,int *t, FILE *fisier)
{
   

    fscanf(fisier , "%d" , t);
    fscanf(fisier,"%d%d" , n, m);
    fscanf(fisier,"%d", k);

    
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
            fscanf(fisier,"%150s", *((*M)+i));
         
            ///fgets(*((*M)+i),150,fis);
        }
    

    
}

void salvare(char **M, int n, int m, const char *fisier)
{
    FILE *fis = fopen(fisier, "wt");
    if (fis == NULL)
    {
        puts("eroare");
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
        puts("eroare");
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
    char **M2= (char **)malloc(n* sizeof(char*));
   
    if (M2== NULL) {
        printf("eroare");
    }
    

    for ( i = 0; i < n; i++) {
        M2[i] = (char *)malloc((m+2) * sizeof(char));
        
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

Stack* generare2(char **M, int n, int m)
{
    
    int i,j;
    char **M2= (char **)malloc(n* sizeof(char*));
    Stack* s = createStack();
    if (M2== NULL) {
        printf("eroare");
    }
    

    for ( i = 0; i < n; i++) {
        M2[i] = (char *)malloc((m+2) * sizeof(char));
        
}

for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M2[i][j]=M[i][j];
        }
       
    }
   
 for(i=0;i<n;i++)
    for(j=0;j<m;j++){ char inainte = M[i][j];
 if((vecini(M,n,m,i,j) > 3 || vecini(M,n,m,i,j) < 2) && M[i][j] == 'X')
 {M2[i][j] = '+';}
 if((vecini(M,n,m,i,j) == 3 || vecini(M,n,m,i,j) == 2) && M[i][j] == 'X')
 {M2[i][j] = 'X';}
 if(vecini(M,n,m,i,j) == 3 && M[i][j] == '+')
 {M2[i][j] = 'X';}
 if(M2[i][j] != inainte){push(s,i,j);}
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
     
    return s;
   

}


Stack* createStack()
{  Stack *s=(Stack*)malloc(sizeof(Stack));
    if(!s) return NULL;
    s->top = NULL;
    return s;

}
 
void push(Stack* s,int i,int j)
{
    
    nod* nou = (nod*)malloc(sizeof(nod));
    nou->i = i;
    nou->j = j;
    nou->next = s->top;
    s->top = nou;}

void inversare(Stack *s){

    Stack *y = (Stack*)malloc(sizeof(Stack));
    y->top = NULL;
    while(s->top != NULL)
    { nod* nou2 = s->top;
     s->top = s->top->next;
     nou2->next = y->top;
     y->top = nou2;
    }

    s->top = y->top;
    free(y);
}

void elibereaza(Stack* s) {
    
    while(s->top)
    {nod* p= s->top;
    s->top = s->top->next;
free(p);}
free(s);
}

void afisarestack(const Stack *s, FILE *fis,int k)
{
    fprintf(fis, "%d",k);
   nod *p = s->top;
   while(p)
   {fprintf(fis," %d %d",p->i,p->j);
    p = p->next;
}
fprintf(fis,"\n");
}

Stack* generare3(char **M, int n, int m)
{
    
    int i,j;
    char **M2= (char **)malloc(n* sizeof(char*));
    Stack* s = createStack();
    if (M2== NULL) {
        printf("eroare");
    }
    

    for ( i = 0; i < n; i++) {
        M2[i] = (char *)malloc((m+2) * sizeof(char));
        
}

for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M2[i][j]=M[i][j];
        }
       
    }
   
 for(i=0;i<n;i++)
    for(j=0;j<m;j++){ char inainte = M[i][j];
        if(vecini(M,n,m,i,j) == 2){M2[i][j] = 'X';}
 
 if(M2[i][j] != inainte){push(s,i,j);}
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
     
    return s;
    

}

node *create_node()
{
    node *nou = (node*)malloc(sizeof(node));
    nou->modificari = NULL;
    nou->left = nou->right = NULL;
    return nou;
}

void copiaza_matrice(char **A, char **B, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
           A[i][j] = B[i][j];
}

void construire(node *root,char **matrice,int n,int m,int nr,int k)
{
   if(nr>=k)return;
   char **mat_s = malloc(n * sizeof(char*));
   for (int i = 0; i < n; i++)
      { mat_s[i] = malloc(m * sizeof(char));}
      copiaza_matrice(mat_s,matrice,n,m);
      Stack *modif_s = generare3(mat_s,n,m);
      root->left = create_node();
      root->left->modificari  = modif_s;
   
      char **mat_d = malloc(n * sizeof(char*));
   for (int i = 0; i < n; i++)
      { mat_d[i] = malloc(m * sizeof(char));}
    copiaza_matrice(mat_d,matrice,n,m);
    Stack *modif_d = generare2(mat_d,n,m);
    root->right = create_node();
    root->right->modificari = modif_d;
 
    construire(root->left, mat_s, n, m, nr + 1,k);
    construire(root->right, mat_d, n, m, nr + 1,k);

    for (int i = 0; i < n; i++) {
        free(mat_s[i]);
        free(mat_d[i]);
    }
    free(mat_s);
    free(mat_d);

}
void aplicare_modif(char **m,Stack *modif)
{
    nod *p = modif->top;
    while(p)
    {
       if (m[p->i][p->j] == 'X') {
    m[p->i][p->j] = '+';
} else {
    m[p->i][p->j] = 'X';
}


        p = p->next;

    }
}

void afisare_matrici(node *root,char **matrice,int n,int m,FILE *fis)
{
   if(!root)return;
   for(int i = 0; i < n; i++){
   {for(int j = 0; j<m;j++)
   fputc(matrice[i][j],fis);
}
fputc('\n',fis);}
fputc('\n',fis);

char **mat_s = malloc(n * sizeof(char *));
    char **mat_d = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        mat_s[i] = malloc(m * sizeof(char));
        mat_d[i] = malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            mat_s[i][j] = matrice[i][j];
            mat_d[i][j] = matrice[i][j];
        }
    }

    if(root->left){
        aplicare_modif(mat_s, root->left->modificari);
        afisare_matrici(root->left, mat_s, n, m, fis);
       
    }
    if(root->right){
        aplicare_modif(mat_d, root->right->modificari);
       afisare_matrici(root->right, mat_d, n, m, fis);
       
}
for(int i = 0; i< n;i++){free(mat_s[i]);free(mat_d[i]);}
free(mat_s);
free(mat_d);
}
void elibereaza_memorie(node *root) {
    if (!root) return;
   elibereaza_memorie(root->left);
    elibereaza_memorie(root->right);
    if (root->modificari) {
        
        elibereaza(root->modificari);  
    }
    free(root);
}

void dfs(char **matrice, int n, int m, int i, int j, int **vizitat, int drum[][2], int pas,
         int *max_len, int max_drum[][2]) {
    vizitat[i][j] = 1;
    drum[pas][0] = i;
    drum[pas][1] = j;

    int ext = 0;

    
    if (i > 0 && j > 0 && matrice[i-1][j-1] == 'X' && !vizitat[i-1][j-1]) {
        ext = 1;
        dfs(matrice, n, m, i-1, j-1, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (i > 0 && matrice[i-1][j] == 'X' && !vizitat[i-1][j]) {
        ext = 1;
        dfs(matrice, n, m, i-1, j, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (i > 0 && j < m - 1 && matrice[i-1][j+1] == 'X' && !vizitat[i-1][j+1]) {
        ext = 1;
        dfs(matrice, n, m, i-1, j+1, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (j > 0 && matrice[i][j-1] == 'X' && !vizitat[i][j-1]) {
        ext = 1;
        dfs(matrice, n, m, i, j-1, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (j < m - 1 && matrice[i][j+1] == 'X' && !vizitat[i][j+1]) {
        ext = 1;
        dfs(matrice, n, m, i, j+1, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (i < n - 1 && j > 0 && matrice[i+1][j-1] == 'X' && !vizitat[i+1][j-1]) {
        ext = 1;
        dfs(matrice, n, m, i+1, j-1, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (i < n - 1 && matrice[i+1][j] == 'X' && !vizitat[i+1][j]) {
        ext = 1;
        dfs(matrice, n, m, i+1, j, vizitat, drum, pas + 1, max_len, max_drum);
    }

    if (i < n - 1 && j < m - 1 && matrice[i+1][j+1] == 'X' && !vizitat[i+1][j+1]) {
        ext = 1;
        dfs(matrice, n, m, i+1, j+1, vizitat, drum, pas + 1, max_len, max_drum);
    }

   
    if (!ext) {
        if (pas > *max_len) {
            *max_len = pas;
            for (int x = 0; x <= pas; x++) {
                max_drum[x][0] = drum[x][0];
                max_drum[x][1] = drum[x][1];
            }
        } else if (pas == *max_len) {
            for (int x = 0; x <= pas; x++) {
                if (drum[x][0] != max_drum[x][0]) {
                    if (drum[x][0] < max_drum[x][0]) {
                        for (int y = 0; y <= pas; y++) {
                            max_drum[y][0] = drum[y][0];
                            max_drum[y][1] = drum[y][1];
                        }
                    }
                    break;
                } else if (drum[x][1] != max_drum[x][1]) {
                    if (drum[x][1] < max_drum[x][1]) {
                        for (int y = 0; y <= pas; y++) {
                            max_drum[y][0] = drum[y][0];
                            max_drum[y][1] = drum[y][1];
                        }
                    }
                    break;
                }
            }
        }
    }

   
    vizitat[i][j] = 0;
}
void lant_max(char **mat,int n ,int m,int *lungime_max,int max_drum[][2])
{
   int **viz = malloc(n * sizeof(int*));
   for(int i = 0 ; i<n;i++)
   {viz[i] = calloc(m,sizeof(int));}
 int **drum = malloc(n * m * sizeof(int *));
for (int i = 0; i < n * m; i++)
    drum[i] = malloc(2 * sizeof(int));  

  *lungime_max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'X') {
                dfs(mat, n, m, i, j, viz, (int (*)[2])drum, 0, lungime_max, max_drum);
            }
        }
    }

 for (int i = 0; i < n; i++) {
    free(viz[i]); 
}

free(viz);
for (int i = 0; i < n * m; i++) {
    free(drum[i]); 
}

free(drum);

}

 void afisare_lant(node *root,char **mat,int n,int m,FILE *fis)
 {
    if(!root) return;
    int max_drum[n*m][2];
    int lungime;
    lant_max(mat,n,m,&lungime,max_drum);
    fprintf(fis,"%d",lungime);
    fprintf(fis,"\n");
    if(lungime != -1)
    {  for(int i = 0; i<=lungime;i++)
        fprintf(fis,"(%d,%d) ",max_drum[i][0]  ,max_drum[i][1] );
        fprintf(fis, "\n");
    }

    char **mat_s = malloc(n * sizeof(char *));
    char **mat_d = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        mat_s[i] = malloc(m * sizeof(char));
        mat_d[i] = malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            mat_s[i][j] = mat[i][j];
            mat_d[i][j] = mat[i][j];
        }
    }

    /* if (root->left) {
        aplicare_modif(mat_s, root->left->modificari);
       afisare_lant(root->left, mat_s, n, m, fis);
    }

    if (root->right) {
        aplicare_modif(mat_d, root->right->modificari);
        afisare_lant(root->right, mat_d, n, m, fis);
    }
*/
    for (int i = 0; i < n; i++) {
        free(mat_s[i]);
        free(mat_d[i]);
    }
    free(mat_s);
    free(mat_d);
}

