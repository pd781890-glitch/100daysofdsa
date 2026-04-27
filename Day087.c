#include <stdio.h>
void bubbleSort(int arr[],int n){
for(int i=0;i<n-1;i++)
for(int j=0;j<n-i-1;j++)
if(arr[j]>arr[j+1]){
int t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;
}
}
int binarySearch(int arr[],int n,int target){
int low=0,high=n-1;
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]==target)return mid;
if(arr[mid]<target)low=mid+1;
else high=mid-1;
}
return -1;
}
int main(){
int n,target;
if(scanf("%d",&n)!=1)return 0;
int arr[n];
for(int i=0;i<n;i++)scanf("%d",&arr[i]);
bubbleSort(arr,n);
for(int i=0;i<n;i++)printf("%d ",arr[i]);
return 0;
}