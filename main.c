#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float sum(float x[], int n) {
    float s = 0;
    for (int i = 0; i < n; i+=1){
        s += x[i];
    }
    return s;
}

float product(float x[], int n) {
    float p = 1;
    for (int i = 0; i < n; i+=1){
        p *= x[i];
    }
    return p;
}

float sum_mult_func(float x[], int n, double f(double)) {
    float s = 0;
    for (int i = 0; i < n; i+=1){
        s += x[i] * f(x[i]);
    }
    return s;
}

void input_array(float x[], int n, char name) {
    for (int i = 0; i < n; i+=1) {
        printf("%c[%d] = ", name, i + 1);
        scanf("%f", &x[i]);
    }
}

int main() {
    system("chcp 65001");
    
    int n, m;
    printf("Введи розмір масиву z (n): ");
    scanf("%d", &n);
    printf("Введи розмір масиву beta (m): ");
    scanf("%d", &m);

    float z[n];
    float beta[m];

    input_array(z, n, 'z');
    input_array(beta, m, 'b');

    float sz = sum(z, n), pz = product(z, n);
    float sb = sum(beta, m), pb = product(beta, m);

    float A = (pz + sz) * sum_mult_func(z, n, exp);
    float B = pz * sum_mult_func(z, n, cos);  
    float C = sum_mult_func(z, n, sin);

    float D = (pb + sb) * sum_mult_func(beta, m, sin);
    float E = pb * sum_mult_func(beta, m, tan);  
    float F = sum_mult_func(beta, m, fabs);     

    float denom = D + E + cos(F);
    if (denom != 0){
    printf("phi = %.5f\n", (A + B * cos(D) + sin(C)) / denom);
} 
else {
    printf("Відбувається ділення на нуль!\n");
}
return 0;
}