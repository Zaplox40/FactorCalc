#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {

    int numOfAttr;
    int numOfExamples;
    int numOfTest;
     
     if(argc < 2) {
        printf("Need to pass an argument\n");
        return -1;
    }

   char *filename = argv[1];
      
   FILE *learning=fopen(filename, "r");
    
    if(learning == NULL ) {
        return -1;
    }

    fscanf(learning,"%d\n",&numOfAttr);
    fscanf(learning,"%d\n",&numOfExamples);
 
    char *filename2 = argv[2];

    FILE *test=fopen(filename2, "r");

    if(test == NULL ) {
        return -1;
    }

    fscanf(test,"%d\n",&numOfTest); 

    int numRows = numOfExamples;
    int numCols = numOfAttr;

    double** LearningMatrix = (double **)malloc(sizeof(double*)*numOfExamples);

    double *Ymatrix = (double*)malloc(sizeof(double)*numOfExamples);

    double** TestingMatrix = (double **)malloc(sizeof(double*)*numOfTest);

    double** ans = (double **)malloc(sizeof(double*)*numOfTest);
     
    double** Calc = (double **)malloc(sizeof(double*)*(numOfAttr+1));

    for(int i=0;i<numOfExamples;i++) {
	LearningMatrix[i]=(double*)malloc(sizeof(double)*(numOfAttr+1));
	}
    
    for(int i=0;i<numOfTest;i++) {
	TestingMatrix[i]=(double*)malloc(sizeof(double)*(numOfAttr));
	}

    for(int i=0;i<+numOfAttr;i++) {
	Calc[i]=(double*)malloc(sizeof(double)*(1));
	}

    for(int i=0;i<numOfTest;i++) {
	ans[i]=(double*)malloc(sizeof(double)*1);
	}
     
    for(int i=0;i<numOfExamples;i++) {
	for(int j=0;j<numOfAttr+1;j++) {
		fscanf(learning,"%lf%*[,]",&LearningMatrix[i][j]);
		}
	}

     for(int i=0;i<numOfExamples;i++) {
	  Ymatrix[i] = LearningMatrix[i][0];	
	}

     for(int i=0;i<numOfExamples;i++) {
	LearningMatrix[i][0] =1;
	}
	
	
     for(int i=0;i<numOfTest;i++) {
	for(int j=0;j<numOfAttr;j++) {
		fscanf(test,"%lf%*[,]",&TestingMatrix[i][j]);
	}
}

double ** TransposeMatrix(double **X,int numRows,int numCols) {

	double** Transpose = (double **)malloc(sizeof(double*)*numCols+1);
	
	for(int i=0;i<numCols+1;i++) {
		Transpose[i] = (double*)malloc(sizeof(double)*(numRows));
	}
	
	for(int i=0;i<numCols+1;i++) {
		for(int j=0;i<numRows;j++) {
		Transpose[i][j]=X[j][i];
		}
	}
	
	return Transpose;
}


double ** MultiplyMatrix(double **X,int numRows,int numCols,double **Z, int numRows2, int numCols2) {

	double** Result = (double **)malloc(sizeof(double*)*numRows);

	for(int i=0; i<numRows;++i) {
		for(int j=0;j < numCols2; ++j) {
			for(int k=0; k<numCols;++k) {
				Result[i][j] += X[i][k] * Z[k][j];
			}
		}
	}
	return Result;
}

double ** findInverse(double** X,int numRows,int numCols) {
	
	double* Inverse = (double *)malloc(sizeof(double*)*numRows);

	int c=0;

	for(int i=1; i<=numRows; i++) {
	    
           for(int j=1; j<=numRows; i++) {

 		if(j!=i) {
		c=X[j][i]/X[j][i];

		for(int k=1; k<=numRows+1;k++) {
		   X[j][c]=X[j][k]-c*X[j][k];
		}
	     }
          }
      }
	printf("The solution is: \n");
	for(int i=1;i<=numRows; i++) {
	Inverse[i]=X[i][numRows+1]/X[i][i];
	printf("\n x%d=%f\n",i,Inverse[i]);
	}
}
	double **XTranspose;
	double **Result;
	
	XTranspose = TransposeMatrix(LearningMatrix,numRows,numCols);	
			
	
	return 0;
}




		





