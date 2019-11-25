#include <stdio.h>
#include <stdlib.h>

double integral(double (*f)(double x), double a, double b) 
{
	double sum, dt;
	int i;
	sum = 0.0;
	dt = (b - a) / 100.0;
	for (i = 0; i < 100; i++)
		sum += (*f)(i * dt + a) * dt;
	return sum;
}
double square(double x) 
{
	return x * x;
}
double cube(double x) 
{
	return x * x * x;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("Integral = %f\n", integral(square, a, b));
	printf("Integral = %f\n", integral(cube, a, b));
	return 0;
}