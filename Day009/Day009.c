// Day 009 of #100daysofdsa
#include<stdio.h>
#include<string.h>
int main(){
char s[1000];
scanf("%s",s);
int l=0,r=strlen(s)-1;
while(l<r){
char t=s[l];
s[l]=s[r];
s[r]=t;
l++;
r--;
}
printf("%s",s);
return 0;
}
