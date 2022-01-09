/*
 * MultiparallelA.h
 *
 *  Created on: 11 Nov. 2021
 *      Author: MEFLAH
 */
#ifndef MutiparallelA_H_
#define MutiparallelA_H_

extern int NbThread;

extern int **A;
extern int **B;
extern int **D;
extern int n;

void launchThreadsA(int NbTA);
void *calculR(void *arg);

#endif /* MULTIPARALLELA_H_ */
