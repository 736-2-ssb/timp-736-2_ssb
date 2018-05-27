#include <stdio.h>
#include<math.h>
int main ()

{
  int n, x, sum=0,i;
  scanf("%d",&n);
  for ( i=0; i<n; i++)
  { scanf( "%d", &x);
    sum=sum+(pow((-1),(i+1))*x*x);
  }
  printf ("%d\n", sum);
  return 0;
}
