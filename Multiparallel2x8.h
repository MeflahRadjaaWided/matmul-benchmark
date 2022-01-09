/*
 * MultiparallelB.h
 *
 *  Created on: 11 Nov. 2021
 *      Author: MEFLAH
 */
#ifndef MutiparallelB_H_
#define MutiparallelB_H_

extern int NbThread;
extern int **G;
extern int n;

void launchThreadsD(int NbTD);
void *calcul2x8(void *arg);

#endif /* MULTIPARALLELB_H_ */
