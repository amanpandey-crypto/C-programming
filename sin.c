#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float sine(float);
void main()
{
    int n;
    float x,sin_val,x1;
    printf("Enter the value of x (in degrees) \n");
    scanf("%f", &x);
    x1 = x;
    x = x * (3.14 / 180.0);
    sin_val = sine(x);
    printf("sine(%f) = %f\n", x1, sin_val);
}
float sine(float x)
{
    int n;
    float acc, term, deno,sinx, sin_val;
    printf("Enter the accuracy for the result \n");
    scanf("%f", &acc);
    term = x;
    sinx = term;
    n = 1;
    while (acc>=n)
    {
        deno = 2 * n * (2 * n + 1);
        term = -term * x * x / deno;
        sinx = sinx + term;
        n++;
    }
    return sinx;
}
  
     
    
   
