all:	mmm

mmm:	main.o initMatrix.o displayMatrix.o Mutisequential.o MultiparallelA.o MultiparallelB.o Multiparallel4x4.o Multiparallel2x8.o Verification.o
	gcc -Wall main.o initMatrix.o displayMatrix.o Mutisequential.o MultiparallelA.o MultiparallelB.o Multiparallel4x4.o Multiparallel2x8.o Verification.o -lpthread -o mmm -lm

main.o:	main.c
	gcc -c main.c -o main.o

initMatrix.o:	initMatrix.c
	gcc -c initMatrix.c -o initMatrix.o
	
displayMatrix.o:	displayMatrix.c
	gcc -c displayMatrix.c -o displayMatrix.o


Mutisequential.o:	Mutisequential.c
	gcc -c Mutisequential.c -o Mutisequential.o
	
MultiparallelA.o:      MultiparallelA.c	
		gcc -c MultiparallelA.c -o MultiparallelA.o
		
MultiparallelB.o:       MultiparallelB.o	
		gcc -c MultiparallelB.c -o MultiparallelB.o	

Multiparallel4x4.o:       Multiparallel4x4.o	
		gcc -c Multiparallel4x4.c -o Multiparallel4x4.o			

Multiparallel2x8.o:       Multiparallel2x8.o	
		gcc -c Multiparallel2x8.c -o Multiparallel2x8.o	
				
Verification.o:       Verification.o	
		gcc -c Verification.c -o Verification.o				

clean:
	rm -fr mmm *.o
