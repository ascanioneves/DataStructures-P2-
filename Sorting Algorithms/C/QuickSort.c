#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *v, int size)
{
    if (size <= 1) {
        return;
    } else {
        int pivot = v[size / 2];
        int a = 0;
        int b = size - 1;
        while (a <= b) {
            while (v[a] < pivot) a++;
            while (v[b] > pivot) b--;
            if(a <= b) {
                int aux = v[a];
                v[a] = v[b];
                v[b] = aux;
                a++;
                b--;
            }
        }
        quick_sort(v, b+1);
        quick_sort(v+a, size - a);
    }
}
int main() {
    int size;
    scanf("%d", &size);
    int v[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &v[i]);
    }
    quick_sort(v, size);
    for(int i = 0; i < size; i++) {
        printf("%d%c", v[i], (i < size - 1) ? ' ' : '\n');
    }
    return 0;
}