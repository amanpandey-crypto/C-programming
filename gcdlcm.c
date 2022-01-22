//Program to find the gcd and lcm of two integer using recursions
#include <stdio.h>
 
int gcd(int, int);
 
int main() {
  int x, y, hcf, lcm;
 
  printf("Enter two integers\n");
  scanf("%d%d", &x, &y);
 
  hcf = gcd(x, y);
  lcm = (x*y)/hcf;
 
  printf("Highest Common Factor of %d and %d = %d\n", x, y, hcf);
  printf("Least Common Multiple of %d and %d = %d\n", x, y, lcm);
 
  return 0;
}
 
int gcd(int a, int b)
{
    if (b == 0) 
    {
       return a;
    }
    else 
    {
       return gcd(b, a % b);
    }
}