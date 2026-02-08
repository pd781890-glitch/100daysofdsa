// Day 008 of #100daysofdsa
#include<stdio.h>
long long power(long long a,long long b){
if(b==0)return 1;
return a*power(a,b-1);
}
int main(){
long long a,b;
scanf("%lld %lld",&a,&b);
printf("%lld",power(a,b));
return 0;
}
