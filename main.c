#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "Multiparallel2x8.h"
#include "Multiparallel4x4.h"
#include "MultiparallelA.h"
#include "MultiparallelB.h"
#include "Mutisequential.h"
#include "Verification.h"
#include "displayMatrix.h"
#include "initMatrix.h"

/* global variable declaration */
int **A;
int **B;
int **D;
int **E;
int **F;
int **G;
// Taille de la matrice
int n; 
int NbThread;
int **C;
int v;



int main(int argc, char **argv) {
  clock_t start_time, end_time, start_time_Row, end_time_Row, start_time_Column,
      end_time_Column;
  double TSequential, TParallel, TSpeedUp;
  srand(time(0));
  char *mode = argv[1];

  if (argc == 1) {
    printf("Usage: ./mmm <mode> <version> [num threads] <size> \n");
    return 1;
  }
  if (argc >= 2 && (!strcmp(mode, "S")) || (!strcmp(mode, "s"))) {

    if (argc == 2) {
      printf("Usage: ./mmm S <size>\n");
      return 1;
    }
    if (argc > 3) {
      printf("Error: too many Arguements for mode S");
      return 1;
    }
  }
  if (argc >= 2 && (!strcmp(mode, "P")) || (!strcmp(mode, "p"))) {
    if (argc == 2) {
      printf("Usage: ./mmm P <version> [num threads] <size>\n");
      return 1;
    }
    if (argc == 3) {
      printf("Error: parallel mode requires [num threads] <size>\n");
      return 1;
    }
    if (argc == 4) {
      printf("Error: parallel mode requires <size>\n");
      return 1;
    }
    if (argc > 5) {
      printf("Error: too many Arguements for mode P\n");
      return 1;
    }
  }
  if ((!strcmp(mode, "S")) || (!strcmp(mode, "s"))) {
    mode = argv[1];

    n = atoi(argv[2]);
  } else if ((!strcmp(mode, "P")) || (!strcmp(mode, "p"))) {

    mode = argv[1];

    n = atoi(argv[4]);
    v = atoi(argv[2]);
    NbThread = atoi(argv[3]);
  } else {
    printf("Usage: ./mmm <mode> [num threads] <size> \n");
    return 1;
  }

  if ((!strcmp(mode, "P")) || (!strcmp(mode, "p")))
    if (NbThread > n || NbThread < 1) {
      printf("La taille de la matrice et le nombre de threads Ce doit être un entier positif \n");
      exit(-2);
    }
  if ((!strcmp(mode, "S")) || (!strcmp(mode, "s")))
    if (n < 1) {
      printf("La taille de la matrice doit être un entier positif  \n");
      exit(-2);
    }

  int i, j;

  // Allocation Matrix

  A = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    A[i] = (int *)malloc(n * sizeof(int));
  B = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    B[i] = (int *)malloc(n * sizeof(int));
  C = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    C[i] = (int *)malloc(n * sizeof(int));
  D = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    D[i] = (int *)malloc(n * sizeof(int));
  E = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    E[i] = (int *)malloc(n * sizeof(int));
  F = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    F[i] = (int *)malloc(n * sizeof(int));
  G = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    G[i] = (int *)malloc(n * sizeof(int));

  // Générer des valeurs aléatoires dans A et B
  generateRandomMatrix(A, n, 0, 99);
  generateRandomMatrix(B, n, 0, 99);

  // Mode sequentiel
  if (((!strcmp(mode, "S")) || (!strcmp(mode, "s")))) {

    // Display Matrix
    printf("Matrix A\n");
    printMatrix(A, n);
    printf("\n\n\n");
    printf("Matrix B\n");
    printMatrix(B, n);
    printf("\n\n\n");

    printf("\n=========\n");
    printf("mode: sequentiel\n");
    printf("thread count : 1\n");
    printf("size %d", n);
    printf("\n=========\n");
    start_time = clock();
    calcul(n, A, B, C);
    end_time = clock();

    printf("Matric C\n");
    printf("\n\n\n");
    printMatrix(C, n);
    TSequential = 0;
    TSequential = (double)(end_time - start_time) / (CLOCKS_PER_SEC);

    printf("\nSequential Time: %f sec\n", TSequential);
  }
  // Mode parallele
  if ((!strcmp(mode, "P")) || (!strcmp(mode, "p"))) {

    if (v == 1) {
      // Display Matrix
      printf("Matrix A\n");
      printMatrix(A, n);
      printf("\n\n\n");
      printf("Matrix B\n");
      printMatrix(B, n);
      printf("\n\n\n");
      printf("Row wise distribution\n");
      printf("\n=========\n");
      printf("mode parallel");
      printf("\nNombre de threads = %d\n", NbThread);
      printf("size %d", n);
      printf("\n=========\n");
      start_time_Row = clock();
      launchThreadsA(NbThread);
      end_time_Row = clock();
      printf("Matric D\n");
      printMatrix(D, n);
      start_time = clock();
      calcul(n, A, B, C);
      end_time = clock();
      printf("\n\n\n");
      printf("Matric C\n");
      printMatrix(C, n);
      TSequential = 0;
      TParallel = 0;
      TSpeedUp = 0;
      TSequential = (double)(end_time - start_time) / (CLOCKS_PER_SEC);
      TParallel = (double)(end_time_Row - start_time_Row) / (CLOCKS_PER_SEC);
      TSpeedUp = TSequential / TParallel;
      printf("\nSequential Time: %f sec\n", TSequential);
      printf("\nParallel Time: %f sec\n", TParallel);
      printf("\nSpeedup Time: %f sec\n", TSpeedUp);
      Equal(C, D, n);
    }
    if (v == 2) {

      // Display Matrix
      printf("Matrix A\n");
      printMatrix(A, n);
      printf("\n\n\n");
      printf("Matrix B\n");
      printMatrix(B, n);
      printf("\n\n\n");
      printf("Column wise distribution\n");
      printf("\n=========\n");
      printf("mode parallel");
      printf("\nNombre de threads = %d\n", NbThread);
      printf("size %d", n);
      printf("\n=========\n");
      launchThreadsB(NbThread);
      printf("Matric E\n");
      printMatrix(E, n);
      start_time = clock();
      calcul(n, A, B, C);
      end_time = clock();
      printf("\n\n\n");
      printf("Matric C\n");
      printMatrix(C, n);
      TSequential = 0;
      TParallel = 0;
      TSpeedUp = 0;
      TSequential = (double)(end_time - start_time) / (CLOCKS_PER_SEC);
      TParallel =
          (double)(end_time_Column - start_time_Column) / (CLOCKS_PER_SEC);
      TSpeedUp = TSequential / TParallel;
      printf("\nSequential Time: %f sec\n", TSequential);
      printf("\nParallel Time: %f sec\n", TParallel);
      printf("\nSpeedup Time: %f sec\n", TSpeedUp);
      Equal(C, E, n);
    }
    if (v == 3) {
      if (IsPowerOfTwo(NbThread) == 1) {
        // Display Matrix
        printf("Matrix A\n");
        printMatrix(A, n);
        printf("\n\n\n");
        printf("Matrix B\n");
        printMatrix(B, n);
        printf("\n\n\n");

        printf("4 x 4 thread grid \n");
        printf("\n=========\n");
        printf("mode parallel");
        printf("\nNombre de threads = %d\n", NbThread);
        printf("size %d", n);
        printf("\n=========\n");
        launchThreadsC(NbThread);
        printf("Matric F\n");
        printMatrix(F, n);
        printf("\n\n\n");
        start_time = clock();
        calcul(n, A, B, C);
        end_time = clock();

        printf("Matric C\n");
        printf("\n\n\n");
        printMatrix(C, n);
        TSequential = 0;
        TParallel = 0;
        TSpeedUp = 0;
        TSequential = (double)(end_time - start_time) / (CLOCKS_PER_SEC);
        TParallel =
            (double)(end_time_Column - start_time_Column) / (CLOCKS_PER_SEC);
        TSpeedUp = TSequential / TParallel;
        printf("\nSequential Time: %f sec\n", TSequential);
        printf("\nParallel Time: %f sec\n", TParallel);
        printf("\nSpeedup Time: %f sec\n", TSpeedUp);
        Equal(C, F, n);
      } else {
        printf("le nombre de thread doit être une puissance de 2\n");
      }
    }
    if (v == 4) {
      if (Even(NbThread) == 1) {
        // Display Matrix
        printf("Matrix A\n");
        printMatrix(A, n);
        printf("\n\n\n");
        printf("Matrix B\n");
        printMatrix(B, n);
        printf("\n\n\n");
        printf("2 x 8 thread grid\n");
        printf("\n=========\n");
        printf("mode parallel");
        printf("\nNombre de threads = %d\n", NbThread);
        printf("size %d", n);
        printf("\n=========\n");
        launchThreadsD(NbThread);
        printf("Matric G\n");
        printMatrix(G, n);
        printf("\n\n\n");
        start_time = clock();
        calcul(n, A, B, C);
        end_time = clock();

        printf("Matric C\n");
        printf("\n\n\n");
        printMatrix(C, n);
        TSequential = 0;
        TParallel = 0;
        TSpeedUp = 0;
        TSequential = (double)(end_time - start_time) / (CLOCKS_PER_SEC);
        TParallel =
            (double)(end_time_Column - start_time_Column) / (CLOCKS_PER_SEC);
        TSpeedUp = TSequential / TParallel;
        printf("\nSequential Time: %f sec\n", TSequential);
        printf("\nParallel Time: %f sec\n", TParallel);
        printf("\nSpeedup Time: %f sec\n", TSpeedUp);
        Equal(C, G, n);

      } else {
        printf("Le nombre de thread doit être un nombre pair\n");
      }
    }
    if (v > 4) {
      printf("Usage: ./mmm P <version> [num threads] <size> \n");
    }
  }

  for (i = 0; i < n; ++i) {
    free(A[i]);
    free(B[i]);
    free(C[i]);
    free(D[i]);
    free(E[i]);
  }
  free(A);
  free(B);
  free(C);
  free(D);
  free(E);
  return 0;
}
