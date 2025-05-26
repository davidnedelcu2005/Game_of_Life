# Game of Life
[Game of Life](https://site-pa.netlify.app/proiecte/game_of_life/) implementation in C. 
# FEATURES
Task 1: Basic Game of Life Implementation
Goal: Simulate Conway's Game of Life for K generations.
Input:
A matrix (from a file) representing the initial generation ('X' for alive, '+' for dead).
Dimensions N x M and number of generations K.
Output:
Write each of the K subsequent generations to a file (matrices separated by empty lines).

Task 2: Efficient Change Tracking with Stacks
Goal: Store only the changes between generations (not full matrices).
Input: Same as Task 1 (initial matrix + K generations).
Output:
A stack where each generation k (1 to K) contains a list of changed cell coordinates (i, j).
Changes are ordered by row then column.
Bonus: Reverse the process—reconstruct the initial generation (0) from the stack and generation 


Task 3: Alternative Rules with Binary Tree
Goal: Explore an alternative rule (B: "a dead cell with exactly 2 live neighbors becomes alive") alongside classic rules.
Input: Same as Task 1.
Output:
A binary tree where:
Left child of a node = next generation using only rule B.
Right child = next generation using classic rules.
Each node stores changes (like Task 2).
Preorder traversal output: matrices for all nodes (root = generation 0, then left/right children).

Task 4: Hamiltonian Paths in Generations
Goal: Find the longest Hamiltonian path (visiting each live cell exactly once) for each node in the tree from Task 3.
Input: Same as Task 1.
Output: For each tree node:
Length of the longest Hamiltonian path.
Coordinates of the path (prioritize paths starting from the smallest (i,j)).
If no path exists, return -1.
## How to run it
I uploaded the Makefile which contains exactly which files are compiled and how the checker runs.
To see the result in the console, type make build (to compile) and make run (to run).
# FUNCTIONS
TASK 1: I created a function that reads the data from the input file, a function that calculates how many live neighbors each cell has, and a function that generates the matrices according to the rules of the game.
## EXAMPLE
```bash
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
```
TASK 2:In task 2, I used the generation function from task 1, but for each cell change, I stored its row and column in a stack. I created a function to reverse the stack, and I displayed it for each generation.

TASK 3: In task 3, we had to change the rules of the Game of Life. I created a tree where the left child was a node that stored the changes according to the new rule, and the right child followed the standard rules. I created a function that transforms the matrix based on the changes stored in the stack, and for each node, I displayed the corresponding matrix.
```bash
 typedef struct lista{
    int i,j;               //I store the row and column.
    struct lista* next;    
 }nod;
struct Stack
{ 
nod* top;
};
struct arbore{                   //The structure of the tree
   struct Stack *modificari;    // The stack that contains the changes for each node.
   struct arbore  *left , *right;
   
};
typedef struct arbore node;
typedef struct Stack Stack;
void aplicare_modif(char **m,Stack *modif) //The function that modifies the matrix based on the stack.
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
```
TASK 4: In Task 4, I implemented an algorithm that searches for the longest path starting from the 'X' cell, called dfs, and a function lant_max that calls dfs for every 'X' cell. 
```bash
void dfs(char **matrice, int n, int m, int i, int j, int **vizitat, int drum[][2], int pas,
         int *max_len, int max_drum[][2]) {
    vizitat[i][j] = 1; ///We mark the cell as visited.
    drum[pas][0] = i;  ///We save the row in the current path.
    drum[pas][1] = j; // We save the column.

    int ext = 0; // "extension": if we find unvisited neighbors

    //The same pattern repeats for the other 7 directions: up, down, left, right, and the diagonals.
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
```
## PROBLEM
The problem appears in task 4 because the function that prints the longest Hamiltonian path goes into deep recursion and the checker gets stuck.
