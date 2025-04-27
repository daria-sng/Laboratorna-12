#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void introduction(double array[], int N);
double calculation(double array[], int N, double sin(double), double cos(double));

int main(){
   system ("chcp 65001");
   int Nx, Ny, Nz, Nq, i;
   printf("Введіть кількість елементів для масивів x, y, z, q: ");
   scanf("%d%d%d%d", &Nx, &Ny, &Nz, &Nq);

   double x[Nx], y[Ny], z[Nz], q[Nq], A, B, C, D;
   introduction(x, Nx);
   introduction(y, Ny);
   introduction(z, Nz);
   introduction(q, Nq);

   A = calculation(x, Nx, sin, cos);
   printf("A= %.4lf\n", A);

   B = calculation(y, Ny, cos, sin);
   printf("B= %.4lf\n", B);

   C = calculation(z, Nz, sin, sin);
   printf("C= %.4lf\n", C);

   D = calculation(q, Nq, cos, cos);
   printf("D= %.4lf\n", D);

   return 0;
}

void introduction(double array[], int N){
   int i;
   printf("Введіть тепер значення для масива (Розмір - %d): ", N);
   for(i=0; i<N; i+=1){
      scanf("%lf", &array[i]);
   }
}

double calculation(double array[], int N, double function1(double), double function2(double)){
   int i; 
   double multiplication_sin = 0.0;
   double multiplication_cos = 0.0;
   for(i=0; i<N; i+=1){
      multiplication_sin += array[i]*function1(array[i]);
      multiplication_cos += (array[i]*array[i])*function2(array[i]);
   }
   
   double result = multiplication_sin + multiplication_cos;
   return result;
}