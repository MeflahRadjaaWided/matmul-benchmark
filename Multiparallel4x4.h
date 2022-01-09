/*
 * MultiparallelB.h
 *
 *  Created on: 11 Nov. 2021
 *      Author: MEFLAH
 */
#ifndef Mutiparallel4x4_H_
#define Mutiparallel4x4_H_

extern int NbThread;
extern int **F;
extern int n;

void launchThreadsC(int NbTC);
void *calcul4x4(void *arg);

#endif /* MULTIPARALLEL4x4_H_ */
