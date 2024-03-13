#include <stdio.h>

void input(int *n, int *k, int *h, int *sum);
int calculate(int n, int k, int h, int sum);
void output(int result);
int foundation(int n, int k);
int wall(int len, int h);
int roof(int n, int k, int h);

int main(void) {
    int n = 0, k = 0, h = 0, sum = 0;
    input(&n, &k, &h, &sum);
    int result = calculate(n, k, h, sum);
    output(result);
    return 0;
}

void input(int *n, int *k, int *h, int *sum) { scanf("%d %d %d %d", n, k, h, sum); }

int calculate(int n, int k, int h, int sum) {
    int result = foundation(n, k) + 2 * wall(n, h) + 2 * wall(k, h) + roof(n, k, h);
    return sum - result;
}

int foundation(int n, int k) { return n * k * 1000; }

int wall(int len, int h) { return len * h * 500; }

int roof(int n, int k, int h) { return n * k * 700 + h * 100; }

void output(int result) { result >= 0 ? printf("YES") : printf("NO %d", result * (-1)); }