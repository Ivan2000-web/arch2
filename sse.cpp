#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <xmmintrin.h>

#define N 100000000
int main(){
	long int i;
	float *x = (float*) malloc(N * sizeof(float));
	float *y = (float*) malloc(N * sizeof(float));
	float *z = (float*) malloc(N * sizeof(float));
	float *f = (float*) malloc(N * sizeof(float));
	float num1[1] = {1.0}, num2[1]={1.0},num3[1]={1.0},num4[1] = {0.3};
	srand(time(NULL));
	for(i=0; i<N; i++)
		{
			x[i]=rand()%-100-100;
			y[i]=rand()%-100-100;
			z[i]=rand()%-100-100;
		__asm(
			"movups (%[x]), %%xmm0 \n\t"
			"movups (%[num1]), %%xmm1 \n\t"
			"mulps %%xmm1, %%xmm0 \n\t"
			"movups (%[z]), %%xmm0 \n\t"
			"mulps %%xmm1, %%xmm0 \n\t"
			"movups (%[num2]), %%xmm0 \n\t"
			"addps %%xmm1, %%xmm0 \n\t"
			"movups (%[num3]), %%xmm0 \n\t"
			"movups (%[z]), %%xmm2 \n\t"
			"divps %%xmm0, %%xmm2 \n\t"
			"movups (%[y]), %%xmm2 \n\t"
			"mulps %%xmm0, %%xmm2 \n\t"
			"addps %%xmm1, %%xmm0 \n\t"
			"movups (%[num4]), %%xmm0 \n\t"
			"movups (%[y]), %%xmm2 \n\t"
			"mulps %%xmm0, %%xmm2 \n\t"
			"movups (%[z]), %%xmm2 \n\t"
			"mulps %%xmm0, %%xmm2 \n\t"
			"subps %%xmm1, %%xmm0 \n\t"			
			"movups %%xmm1, %[f] \n\t"
			:[f] "=m" (*f)
			:[x]"r"(x),[y]"r"(y),[z]"r"(z),[num1]"r"(num1),[num2]"r"(num2),[num3]"r"(num3),[num4]"r"(num4)
			:"%xmm0", "%xmm1","%xmm2"
			);
}
		printf("%f\n" , f[N-1]);
		free(x);
		free(y);
		free(z);
		free(f);
		return 0;
}
