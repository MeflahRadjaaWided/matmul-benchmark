# hw1_MeflahRadjaaWided_ZerriahenSouhaYamina_V2


                            Homework 1: Parallel Dense Matrix-Matrix Multiplication

 ***Description***
 
This project demonstrate the multiplication of two random square matrices  using sequential method and parallel method.
 The algorithms then time how long it takes to multiply the 2 matrices together.

***Modules in the project***
 
- initMatrix: module responsible about initializing the matrix object. 
- displayMatrix: module responsible about displaying the matrix object. 
- Mutisequential: module responsible about calculating the output of two matrixes using equential method. 
- MultiParallelA: module responsible about calculation the output of two matrixes using row wise distribution method. 
-	MultiParallelB:  module responsible about calculation the output of two matrixes using column wise distribution method.
- main: our top level module combining the different modules  and	  generating	  the	  requested	  output.	 
- MultiParallel2x8:  module responsible about calculation the output of two matrixes using 2x8 thread grid method.
- MultiParallel4x4:  module responsible about calculation the output of two matrixes using 4x4 thread grid  method . 
- Verification:  an extra module responsible about verifying if the two matrixes are equal. 

***To run***

To compile the program type in the terminal:
 make all or make

To run the program Insert a letter according to you need. And then enter the sample size required:

Sequential method: ./mmm S [size] 
  
Parallel method: ./mmm P [version] [num threads] [size]
 
- Row wise distribution : ./mmm P 1 [num threads] [size] 
 
- Column wise distributuion : ./mmm P 2 [num threads] [size]
 
- 4x4 thread grid : ./mmm P 3 [num threads] [size]
 
- 2x8 thread grid : ./mmm P 4 [num threads] [size]



