//Programs for finding the roots of quadratic equation
#include<stdio.h>
#include<math.h>
int main()
{
   int num1,num2,num3;
   printf("Enter the value of a, b and c of a quadratic equation of the form ax^2 + bx + c:\n");
   scanf("%d%d%d",&num1,&num2,&num3);
   float d=(pow(num2,2)-4*num1*num3);
   if (d<0)
   { 
      printf("The root are imaginary\n");
   }
   else 
   {
      float root1=(-num2+sqrt(d))/2*num1 ,root2=(-num2-sqrt(d))/2*num1;
      printf("The roots of quadratic equation is %.2f and %.2f\n",root1,root2);
   }
   return 0;
}
        
   
