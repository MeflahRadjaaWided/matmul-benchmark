/*
 * init-matrix.c
 *
 *  Created on: 5 janv. 2021
 *      Author: laloukil
 */

#include <stdlib.h>
#include <time.h>

#include "initMatrix.h"

void generateRandomMatrix(int **matrix, int dim, int lowerValue,
                          int upperValue) {

  int i, j;
  for (i = 0; i < dim; ++i) {
    for (j = 0; j < dim; ++j) {
      matrix[i][j] = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    }
  }
}
