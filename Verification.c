
#include <stdio.h>

#include "Verification.h"

/**
 * COMPARER LA MATRICE A ET B
 */

void Equal(int **A, int **B, int n) {

  double largestError = 0.0000000;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {

      if (A[i][j] - B[i][j] > 0) {
        largestError = A[i][j] - B[i][j];
      }
    }
  }
  printf("\nVerifying... largest error between parallel and sequential matrix: "
         "%f\n\n",
         largestError);
}

/**
 * vérifier si le nombre de threads est un num
 */

int Even(int nb) {
  if (nb % 2 == 0)
    return 1;
  else

    return 0;
}

/**
 * vérifier si le nombre de threads est un nombre pair
 */

int IsPowerOfTwo(int nb) {
  if (nb == 0)
    return 0;
  while (nb != 1) {
    nb = nb / 2;
    if (nb % 2 != 0 && nb != 1)
      return 0;
  }
  return 1;
}
