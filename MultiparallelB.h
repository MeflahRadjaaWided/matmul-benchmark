/*
 * MultiparallelB.h
 *
 *  Created on: 11 Nov. 2021
 *      Author: MEFLAH
 */
#ifndef MutiparallelB_H_
#define MutiparallelB_H_

extern int NbThread;
extern int **E;
extern int n;

void launchThreadsB(int NbTB);
void *calculC(void *arg);

#endif /* MULTIPARALLELB_H_ */
