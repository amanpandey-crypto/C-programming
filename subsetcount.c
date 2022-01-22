#include<stdio.h>
#include<stdlib.h>
int main(){
// Get input sequence
int n;    // Size of input set
int m;    // Target value
int *S;   // Input set
int *C;   // Cost table
int i,j,potentialSum,leftover;
 
 
scanf("%d",&n);
scanf("%d",&m);
 
 
S=(int*) malloc((n+1)*sizeof(int));
C=(int*) malloc((m+1)*sizeof(int));
if (!S || !C)
{
  printf("malloc failed %d\n",__LINE__);
  exit(0);
}
 
 
S[0]=0;                // Sentinel zero
for (i=1;i<=n;i++)
  scanf("%d",S+i);
 
 
// Initialize table for DP
C[0]=0;  // DP base case
// For each potential sum, determine the smallest index such
// that its input value is in a subset to achieve that sum.
for (potentialSum=1; potentialSum<=m; potentialSum ++)
{
  for (j=1;j<=n;j++)
  {
    leftover=potentialSum-S[j];      // To be achieved with other values
    if (leftover<0)                  // Too much thrown away
      continue;
    if (C[leftover]==(-1))           // No way to achieve leftover
      continue;
    if (C[leftover]<j)               // Indices are included in
      break;                         // ascending order.
  }
   
  if (j<=n)
     C[potentialSum]=j;
  else
      C[potentialSum]=-1;
 
 
}
 
 
/**/
// Output the input set
printf("  i   S\n");
printf("-------\n");
for (i=0;i<=n;i++)
  printf("%3d %3d\n",i,S[i]);
 
 
// Output the DP table
printf("  i   C\n");
printf("-------\n");
for (i=0;i<=m;i++)
  printf("%3d %3d\n",i,C[i]);
/**/
 
 
if (C[m]==(-1))
  printf("No solution\n");
else
{
  printf("Solution\n");
  printf("  i   S\n");
  printf("-------\n");
  for (i=m;i>0;i-=S[C[i]])
    printf("%3d %3d\n",C[i],S[C[i]]);
}
}
