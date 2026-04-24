#include <stdio.h>
void swap(int *a,int *b){
int t=*a;
*a=*b;
*b=t;
}
void selectionSort(int arr[],int n){
for(int i=0;i<n-1;i++){
int minIdx=i;
for(int j=i+1;j<n;j++){
if(arr[j]<arr[minIdx])
minIdx=j;
}
if(minIdx!=i)
swap(&arr[minIdx],&arr[i]);
}
}
int main(){
int n;
if(scanf("%d",&n)!=1)return 0;
int arr[n];
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);
selectionSort(arr,n);
for(int i=0;i<n;i++)
printf("%d ",arr[i]);
printf("\n");
return 0;
}