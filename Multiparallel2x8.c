#include "Multiparallel2x8.h"
#include "MultiparallelA.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* global variable declaration */
extern int NbThread;
extern int **G;
extern int n;
void *calcul2x8(void *arg);

/*
 * multiplication matricielle avec des threads
 * NbThread nombre de thread
 * n taille de matrice
 */

void launchThreadsD(int NbTD) {
  // allouer de l'espace pour stocker N threads
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * NbTD);

  // générer N threads, chaque thread appelle threadFunction(i)
  long i;

  for (i = 0; i < NbTD; i++)
    pthread_create(&threads[i], NULL, calcul2x8, (void *)i);

  // attendre que tous les threads se termine
  for (i = 0; i < NbTD; i++)
    pthread_join(threads[i], NULL);
}

void *calcul2x8(void *arg) {

  int start, end;
  int i, j, k;
  int istart, iend, jstart, jend; 
  int threadID = (long)arg;

  // calculer un bloc de taille n/(p/2) par thread
  int b = (n / (NbThread / 2));

  if (threadID < NbThread / 2) {
    istart = 0;
    iend = (n / 2) - 1;
  } else {
    istart = n / 2;
    iend = n - 1;
  }
  jstart =(threadID%(NbThread/2))*b ;
  
  if ((threadID + 1) % (NbThread / 2) == 0) {
    jend = n - 1;
  } else {
    jend = jstart + b - 1;
  }

  for (i = istart; i <= iend; i++) {
    for (j = jstart; j <= jend; j++) {
      for (k = 0; k < n; k++) {

        G[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  pthread_exit(NULL); 
}
