#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b){
return(*(int*)a-*(int*)b);
}
int check(int d,int n,int k,int*stalls){
int count=1,last=stalls[0];
for(int i=1;i<n;i++){
if(stalls[i]-last>=d){
count++;
last=stalls[i];
}
}
return count>=k;
}
int main(){
int n,k;
if(scanf("%d %d",&n,&k)!=2)return 0;
int*stalls=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++)scanf("%d",&stalls[i]);
qsort(stalls,n,sizeof(int),compare);
int low=1,high=stalls[n-1]-stalls[0],ans=0;
while(low<=high){
int mid=low+(high-low)/2;
if(check(mid,n,k,stalls)){
ans=mid;
low=mid+1;
}else{
high=mid-1;
}
}
printf("%d\n",ans);
free(stalls);
return 0;
}