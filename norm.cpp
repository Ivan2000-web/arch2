#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

int main()
{
	long int i, j;
	float *x = (float*) malloc(N * sizeof(float));
	float *y = (float*) malloc(N * sizeof(float));
	float *z = (float*) malloc(N * sizeof(float));
	float * f= (float*) malloc(N * sizeof(float));
	srand(time(NULL));

	
	for(i=0; i<N; i++)
	{
		x[i]=rand()%-100-100;
		y[i]=rand()%-100-100;
		z[i]=rand()%-100-100;
		f[i]=(x[i]+y[i])/(z[i]-y[i])+0.3*pow(z[i], 2);
	}
	free(x);
	free(y);
	free(z);
	free(f);
	

	return 0;
}
