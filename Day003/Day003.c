// Day 003 of #100daysofdsa
#include<stdio.h>
int main(){
int n,k;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)scanf("%d",&arr[i]);
scanf("%d",&k);
int c=0,f=0;
for(int i=0;i<n;i++){
c++;
if(arr[i]==k){
printf("Found at index %d\n",i);
f=1;
break;
}
}
if(!f)printf("Not Found\n");
printf("Comparisons = %d\n",c);
return 0;
}
