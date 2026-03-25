#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *left,*right;
};
struct QueueNode{
struct Node* node;
int hd;
};
struct Node* newNode(int val){
if(val==-1)return NULL;
struct Node* node=(struct Node*)malloc(sizeof(struct Node));
node->data=val;
node->left=node->right=NULL;
return node;
}
void printVerticalOrder(struct Node* root,int n){
if(!root)return;
struct QueueNode* q=(struct QueueNode*)malloc(n*sizeof(struct QueueNode));
int head=0,tail=0;
int minHD=0,maxHD=0;
q[tail++]=(struct QueueNode){root,0};
int* hds=(int*)malloc(n*sizeof(int));
int* vals=(int*)malloc(n*sizeof(int));
int count=0;
while(head<tail){
struct QueueNode curr=q[head++];
hds[count]=curr.hd;
vals[count++]=curr.node->data;
if(curr.hd<minHD)minHD=curr.hd;
if(curr.hd>maxHD)maxHD=curr.hd;
if(curr.node->left)q[tail++]=(struct QueueNode){curr.node->left,curr.hd-1};
if(curr.node->right)q[tail++]=(struct QueueNode){curr.node->right,curr.hd+1};
}
for(int d=minHD;d<=maxHD;d++){
for(int i=0;i<count;i++){
if(hds[i]==d)printf("%d ",vals[i]);
}
printf("\n");
}
}
struct Node* buildTree(int n){
if(n==0)return NULL;
int* arr=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++)scanf("%d",&arr[i]);
struct Node* root=newNode(arr[0]);
struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
int head=0,tail=0;
q[tail++]=root;
int i=1;
while(i<n){
struct Node* curr=q[head++];
if(i<n){
curr->left=newNode(arr[i++]);
if(curr->left)q[tail++]=curr->left;
}
if(i<n){
curr->right=newNode(arr[i++]);
if(curr->right)q[tail++]=curr->right;
}
}
return root;
}
int main(){
int n;
if(scanf("%d",&n)!=1)return 0;
struct Node* root=buildTree(n);
printVerticalOrder(root,n);
return 0;
}