#include "Multiparallel4x4.h"
#include "MultiparallelA.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaration de variable globale */
extern int NbThread;
extern int **F;
extern int n;
void *calcul4x4(void *arg);

void launchThreadsC(int NbTC) {
  pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * NbTC);

  long i;

  for (i = 0; i < NbTC; i++)
    pthread_create(&threads[i], NULL, calcul4x4, (void *)i);

  for (i = 0; i < NbTC; i++)
    pthread_join(threads[i], NULL);
}

void *calcul4x4(void *arg) {

  int i, j, k;
  int istart, iend, jstart, jend;
 
  int threadID = (long)arg;
  // calculer un bloc de taille n/sqrt(p) par thread
  int b = n / (int)sqrt(NbThread);

  istart = (threadID / (int)sqrt(NbThread)) * b;
  if (threadID >= ((int)sqrt(NbThread)) * ((int)sqrt(NbThread) - 1)) {
    iend = n - 1;
  } else {
    iend = istart + b - 1;
  }

  jstart = (threadID % ((int)sqrt(NbThread))) * b;
  if ((threadID + 1) % (int)(sqrt(NbThread)) == 0) {
    jend = n - 1;
  } else {
    jend = jstart + b - 1;
  }

  for (i = istart; i <= iend; i++) {
    for (j = jstart; j <= jend; j++) {
      for (k = 0; k < n; k++) {
        F[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  pthread_exit(NULL); 
}
