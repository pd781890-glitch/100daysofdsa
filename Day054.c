#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* left,*right;
};
struct Node* newNode(int val){
if(val==-1)return NULL;
struct Node* node=(struct Node*)malloc(sizeof(struct Node));
node->data=val;
node->left=node->right=NULL;
return node;
}
void printZigZag(struct Node* root,int n){
if(!root)return;
struct Node** s1=(struct Node**)malloc(n*sizeof(struct Node*));
struct Node** s2=(struct Node**)malloc(n*sizeof(struct Node*));
int t1=-1,t2=-1;
s1[++t1]=root;
while(t1!=-1||t2!=-1){
while(t1!=-1){
struct Node* curr=s1[t1--];
printf("%d ",curr->data);
if(curr->left)s2[++t2]=curr->left;
if(curr->right)s2[++t2]=curr->right;
}
while(t2!=-1){
struct Node* curr=s2[t2--];
printf("%d ",curr->data);
if(curr->right)s1[++t1]=curr->right;
if(curr->left)s1[++t1]=curr->left;
}
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
while(i<n&&head<tail){
struct Node* curr=q[head++];
if(i<n) {
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
printZigZag(root,n);
return 0;
}