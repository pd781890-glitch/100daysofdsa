#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 100
int findMin(int dist[],bool visited[],int n){
int min=INT_MAX,minIndex;
for(int v=1;v<=n;v++)
if(visited[v]==false&&dist[v]<=min)
min=dist[v],minIndex=v;
return minIndex;
}
void dijkstra(int graph[V][V],int n,int src){
int dist[V];
bool visited[V];
for(int i=1;i<=n;i++)
dist[i]=INT_MAX,visited[i]=false;
dist[src]=0;
for(int count=1;count<=n-1;count++){
int u=findMin(dist,visited,n);
visited[u]=true;
for(int v=1;v<=n;v++)
if(!visited[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
dist[v]=dist[u]+graph[u][v];
}
for(int i=1;i<=n;i++)
printf("%d ",dist[i]);
printf("\n");
}
int main(){
int n,m,u,v,w,src,graph[V][V]={0};
if(scanf("%d %d",&n,&m)!=2)return 0;
for(int i=0;i<m;i++){
scanf("%d %d %d",&u,&v,&w);
graph[u][v]=w;
graph[v][u]=w;
}
scanf("%d",&src);
dijkstra(graph,n,src);
return 0;
}