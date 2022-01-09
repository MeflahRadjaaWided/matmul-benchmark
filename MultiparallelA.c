#include "MultiparallelA.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* declaration variable globales */
extern int NbThread;
extern int **A;
extern int **B;
extern int **D;
extern int n;
void *calculR(void *arg);


void launchThreadsA(int NbTA) {

  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * NbTA);

  long i;

  for (i = 0; i < NbTA; i++)
    pthread_create(&threads[i], NULL, calculR, (void *)i);

  for (i = 0; i < NbTA; i++)
    pthread_join(threads[i], NULL);
}

void *calculR(void *arg) {
  int row_start, row_end;
  int i, j, k;
  int threadID = (long)arg;
  // calculer un bloc de n/p lignes par thread
  int b = n / NbThread;
  row_start = threadID * b;
  row_end = row_start + b - 1;
  // calculer les dernières lignes pour le dernier thread
  if (threadID == (NbThread - 1)) {

    row_end = n - 1;
  }

  for (i = row_start; i <= row_end; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        D[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  pthread_exit(NULL); 
}
