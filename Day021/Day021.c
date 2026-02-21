// Day 021 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>
struct N{int d;struct N*n;};
int main(){
    int i,c,v;
    if(scanf("%d",&c)!=1)return 0;
    struct N *h=NULL,*t=NULL;
    for(i=0;i<c;i++){
        scanf("%d",&v);
        struct N*m=(struct N*)malloc(sizeof(struct N));
        m->d=v;m->n=NULL;
        if(!h)h=t=m;
        else{t->n=m;t=m;}
    }
    struct N*p=h;
    while(p){
        printf("%d%s",p->d,p->n?" ":"");
        p=p->n;
    }
    return 0;
}