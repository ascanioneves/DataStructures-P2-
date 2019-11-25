#include <stdio.h>
#include <stdlib.h>

void map(int v[], int n, int (*pointer_func)(int x)) {
	for(int i = 0; i < n; i++) {
		int ans = (*pointer_func)(v[i]);
		printf("%d ", ans);
	}
	printf("\n");
}
int square(int x) {
	return x * x;
}
int factorial(int n) {
	if(n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]); //reading
	map(arr, n, square); //map function call for each element in array(square)
	map(arr, n, factorial);//map function call for each element in array(factorial)
	return 0;
}