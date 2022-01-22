#include<stdio.h>
float area(int);
void main()
{
     int x;
     printf(" 1 is square\n 2 is rectangle\n 3 is triangle \n 4 is circle\n 5 is trapezium\n");
     float A=area(x);
     printf("The area of given figure is %f\n",A);
}
float area(int x)
{
    float r,A,b,h,side,len,bdth,pside1,pside2,dist;
    printf("Enter the figure code given above:\n");
    scanf("%d",&x);
    switch(x)
    { 
         case 1 : printf("Enter the side of square\n");
                    scanf("%f",&side);
                    A = side*side ;
                    break;
         case 2 : printf("Enter the length and breadth of rectangle\n"); 
                    scanf("%f%f",&len,&bdth);
                    A = len*bdth ;
                    break;
         case 3 : printf("Enter the base and height of triangle:\n");
                    scanf("%f%f",&b,&h);
                    A = (b*h)/2 ;
                    break ;
         case 4 : printf("Enter the radius of circle:\n");
                    scanf("%f",&r);
                    A = 3.142*r*r ;
                    break;
         case 5 : printf("Enter parallel sides and distance between them:\n");
                  scanf("%f%f%f",&pside1,&pside2,&dist);
                  A = (pside1+pside2)*h/2;
                  break;
         default: printf("Invalid figure code.\n");
                        break;
    }
    return A;
}
