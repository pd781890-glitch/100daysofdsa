// Day 020 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){return(*(long long*)a-*(long long*)b);}

int main(){
    int n;
    if(scanf("%d",&n)!=1)return 0;
    long long p[n+1],s=0,c=0;
    p[0]=0;
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        s+=x;p[i+1]=s;
    }
    qsort(p,n+1,sizeof(long long),cmp);
    long long count=1;
    for(int i=1;i<=n;i++){
        if(p[i]==p[i-1])count++;
        else{
            c+=(count*(count-1))/2;
            count=1;
        }
    }
    c+=(count*(count-1))/2;
    printf("%lld\n",c);
    return 0;
}