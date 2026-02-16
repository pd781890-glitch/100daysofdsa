// Day 016 of #100daysofdsa
#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)scanf("%d",&arr[i]);
for(int i=0;i<n;i++){
int count=1,flag=0;
for(int k=0;k<i;k++)if(arr[i]==arr[k]){flag=1;break;}
if(flag)continue;
for(int j=i+1;j<n;j++)if(arr[i]==arr[j])count++;
printf("%d:%d ",arr[i],count);
}
return 0;
}
