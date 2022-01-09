#include "MultiparallelB.h"
#include "MultiparallelA.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* global variable declaration */
extern int NbThread;
extern int **E;
extern int n;
void *calculC(void *arg);



void launchThreadsB(int NbTB) {

  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * NbTB);

  
  long i;

  for (i = 0; i < NbTB; i++)
    pthread_create(&threads[i], NULL, calculC, (void *)i);

  
  for (i = 0; i < NbTB; i++)
    pthread_join(threads[i], NULL);
}

void *calculC(void *arg) {

  int col_start, col_end;
  int i, j, k;
  
  int threadID = (long)arg;
  // calculer un bloc de n/p colonnes par thread
  int b = n / NbThread;
  col_start = threadID * b;
  col_end = col_start + b - 1;
  // calculer les dernières colonnes pour le dernier thread
  if (threadID == (NbThread - 1)) {
    col_end = n - 1;
  }

  for (i = col_start; i <= col_end; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {

        E[j][i] += A[j][k] * B[k][i];
      }
    }
  }

  pthread_exit(NULL); 
}
