// Day 019 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cmp(const void*a,const void*b){return(*(int*)a-*(int*)b);}
int main(){
    int n;
    if(scanf("%d",&n)!=1)return 0;
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int l=0,r=n-1,ml=0,mr=n-1,ms=INT_MAX;
    while(l<r){
        int s=a[l]+a[r];
        if(abs(s)<abs(ms)){
            ms=s;ml=l;mr=r;
        }
        if(s<0)l++;
        else if(s>0)r--;
        else break;
    }
    printf("%d %d\n",a[ml],a[mr]);
    return 0;
}