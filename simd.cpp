#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <xmmintrin.h>

#define N 100000000
int main()
{
	long int i, j;
	long int nSize = N/4;
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
        }
	
	__m128 m1,m2,m3;
	__m128 *xx=(__m128*)x;
	__m128 *yy=(__m128*)y;
	__m128 *zz=(__m128*)z;
	__m128 *ff=(__m128*)f;

	__m128 m7_25=_mm_set_ps1(7.25f);
	__m128 m0_7=_mm_set_ps1(0.7f);
	__m128 m5_0=_mm_set_ps1(5.0f);
	__m128 m8_7=_mm_set_ps1(8.7f);

	
	
	for(i=0; i<nSize; i++)
	{
		m1=_mm_mul_ps(m7_25,*zz);
		m2=_mm_mul_ps(m1,*xx);
		m1=_mm_add_ps(m2,m0_7);
		m2=_mm_div_ps(m5_0,*zz);
		m3=_mm_mul_ps(m2,*yy);
		m2=_mm_add_ps(m3,m1);
		m1=_mm_mul_ps(m8_7,*yy);
		m3=_mm_mul_ps(m1,*zz);
		*ff=_mm_sub_ps(m2,m3);
		xx++;
		yy++;
		zz++;
		ff++;		
	}
	printf("%f\n" , f[N-1]);
	free(x);
	free(y);
	free(z);
	free(f);
	

	return 0;
}
