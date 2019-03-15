#include<stdio.h>
#include<ctype.h>
int main()
{
	int x,y;
	float r,per,plo;
	printf("Enter (x,y)\n");
	scanf("%d  %d", &x,&y);
	printf("Enter radius\n");
	scanf("%f", &r);
	per = 2 * 3.14 * r;
	plo = 3.14 * r * r;
	printf("Perimeter = %f\n", per);
	printf("Area = %f\n", plo);
	return 0;
}

