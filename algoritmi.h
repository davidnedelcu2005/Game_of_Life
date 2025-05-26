
#ifndef ALGORITMI_H
#define ALGORITMI_H
#include <limits.h>
#include <stdio.h>


 typedef struct lista{
    int i,j;
    struct lista* next;
 }nod; 

struct Stack
{ 
nod* top;
};
struct arbore{
   struct Stack *modificari;
   struct arbore  *left , *right;
   
};
typedef struct arbore node;
typedef struct Stack Stack;
Stack* generare2(char **M, int n, int m);
Stack* createStack();
void inversare(Stack *s);
void push(Stack*s, int i,int j);
void deleteStack(Stack**s);
void printStack(Stack *s);
void elibereaza(Stack* s);
void afisarestack(const Stack *s, FILE *fis,int k);
void citire(char*** M ,int *n, int *m, int *k,int *t, FILE *fisier);
void salvare(char **M, int n, int m, const char *fisier);
void salvare2(char **M, int n, int m, const char *fisier);
int vecini(char **M, int n, int m, int i, int j); 
void generare(char **M, int n, int m);
Stack* generare3(char **M, int n, int m);
void construire(node *root,char **matrice,int n,int m,int nr,int k);
void aplicare_modif(char **m,Stack *modif);
void afisare_matrici(node *root,char **matrice,int n,int m,FILE *fis);
node *create_node();
void copiaza_matrice(char **A, char **B, int n, int m);
void elibereaza_memorie(node *root);
void dfs(char **matrice, int n, int m, int i, int j, int **vizitat, int drum[][2], int pas,  int *max_len, int max_drum[][2]);
void lant_max(char **mat,int n ,int m,int *lungime_max,int max_drum[][2]);
 void afisare_lant(node *root,char **mat,int n,int m,FILE *fis);
void elibereaza_matrice(char **mat, int n);
#endif