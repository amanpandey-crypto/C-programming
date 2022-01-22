#include<stdio.h>
int n1 =100;
int n;
void Heapify(int arr[], int n, int i) 
{ 
    int maximum = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  

    if (l < n && arr[l] > arr[maximum]) 
        maximum = l; 
  

    if (r < n && arr[r] > arr[maximum]) 
        maximum = r; 

    if (maximum != i) { 
        int temp=0;
        temp=arr[i];
        arr[i]=arr[maximum];
        arr[maximum]=temp;
        
        Heapify(arr, n, maximum); 
    } 
}
void DeleteRootNode(int arr[], int n) 
{ 
     
    int lstElmnt = arr[n - 1]; 
  
     
    arr[0] = lstElmnt; 
  

    n = n - 1; 
  

    Heapify(arr, n, 0); 
} 
void insertNewNode(int arr[], int n, int Key) 
{ 
   
  //  n = n + 1; 
  
    printf("%d ",n);
    printf("manish the cider ");
    arr[n - 1] = Key; 

    Heapify(arr, n, n - 1); 
} 



void buildHeap(int arr[], int n){
    int strtIdx= (n/2)-1;
    for (int i = strtIdx; i >= 0; i--) { 
        Heapify(arr, n, i); 
    }

}

void display(int arr[]){
    
    printf("%d ",n);
    printf(" shbham kumar ");
    for(int i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void menu(int arr[], int n){
    int choice;
    do{
        printf("menu\n\n");
      printf("enter 1 to insert any number in the heap\n");
      
      printf("enter 2 to perform delete operation\n");
      printf("enter 3 to display the heap\n");
      printf("enter 4 to end the program \n");
      scanf("%d", &choice);
       
      switch(choice){
          case 1: printf("enter new node you wnat to enter\n");
             int newNoDe; scanf("%d", &newNoDe);
             n=n+1;
             insertNewNode(arr, n, newNoDe);
             
             break;
          case 2: 
             DeleteRootNode(arr,n);
          break;
          case 3: display(arr);
          break;
          
          default: printf("wrong choice: enter again");
          break;
      }

    }while(choice!=4);
}

void solve(){
    printf("enter max size of the heap you want ");
    printf("\n");
    

   
    scanf("%d",&n);
    int arr[n1];
    printf("enter n elements");
    printf("\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr,n);
    menu(arr, n);
}

int main(){
    solve();
}