#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  int main()
 {
  float a,b,c;
   printf("Введите числа a и b (a^b):\n");
   scanf("%f %f", &a,&b);
   c=powf(a,b);
   printf("a в степени b =%.f\n",c);
   return 0;
}

