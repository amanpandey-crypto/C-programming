#include <stdio.h>
int greatest(int,int,int,int);
int main() 
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = greatest(a, b, c, d);
    printf("\n%d", ans);
    
    return 0;
}
int greatest(int a,int b,int c,int d)
{
   if(a>b)
    {
        if(a>c)
        {
            if(a>d)
            {  
                return a;
            }
            else
            {
                return d;
            }
        }
    }
    else if(b>c)
    {
        if(b>d)
        {
            return b;
        }
        else
        {
            return d;
        }
    }
    else if(c>d)
    {
        return c;
    }
    else
    {
        return d;
    } 
}