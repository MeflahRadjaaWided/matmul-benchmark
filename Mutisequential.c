#include "Mutisequential.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>



void calcul(int n, int **A, int **B, int **C) {
  // row in A
  for (int i = 0; i < n; i++) {
    // column B
    for (int j = 0; j < n; j++) {
      C[i][j] = 0;
      // multiply row A and column B
      for (int k = 0; k < n; k++) {
        // store in output
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
