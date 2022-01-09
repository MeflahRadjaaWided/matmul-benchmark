/* TP APP
BINOME 1: MEFLAH RADJAA WIDED
BINOME 2: ZERRIAHEN YAMINA SOUHA
*/

Homework 1: Multiplication Matrice-Matrice Parallèle

 ***Description*** 
This HOMEWORK demonstrate the multiplication of two random square matrices  
using sequential method and parallel method. The algorithms then time how long it takes to multiply the 2 matrices together.

***To run***
To compile the program type in the terminal:
make all or make
To run the program Insert a letter according to you need. And then enter the sample size required:
Sequential method: ./mmm S <size> 
Parallel method: ./mmm P <version> [num threads] <size> 
- Row wise distribution : ./mmm P 1 [num threads] <size> 
-Column wise distributuion : ./mmm P 2 [num threads] <size> 
-4x4 thread grid : ./mmm P 3 [num threads] <size> 
-2x8 thread grid : ./mmm P 4 [num threads] <size> 

