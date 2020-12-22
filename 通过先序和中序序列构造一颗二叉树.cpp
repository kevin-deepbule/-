#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define DataType char
int leavecount = 0;
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}BiTNode,*BiTree;

int Search(char a[],char b[]){
	int len = strlen(a);
	for(int i=0;i<len;i++){
		if(a[0]==b[i]){
			return i;
		}
	}
	return -1;
}
void headReduce(char data[],int s,int l,char result[]){
		
	if(l!=0){
		for(int i=0;i<l;i++){
			result[i] = data[i+s];
		} 	
	}
	
}
void ReBiTree(BiTree *T,char preorder[],char midorder[],int i,int j,int k,int h){
//		����������[i,,,j] ��������[k...,h] ���������� 
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = preorder[i];
		int	m = k;
		while(midorder[m]!=preorder[i])
			m++;
		if(m==k)
			(*T)->lchild = NULL;
		else
			ReBiTree(&((*T)->lchild),preorder,midorder,i+1,i+m-k,k,m-1); //�롣�Һñ��� 
//			����������[i+1,...i+m-k]��������[k,...m-1] ���������� 
		if(m==h)
			(*T)->rchild = NULL;
		else
			ReBiTree(&((*T)->rchild),preorder,midorder,i+m-k+1,j,m+1,h);
//			�� ��������[i+m-k+1,...j] ��������[m+1,h] ����������
 
	
}
void InitData(DataType preorder[],DataType midorder[]){ //,int a,int b,int c,int d
		printf("��������������������˳��\n"); 
		scanf("%s",preorder);
		scanf("%s",midorder);
}
void preOrder(BiTree T){
	if (T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		
		preOrder(T->rchild);
	}
	return ;
}
//ͳ��Ҷ�ӽڵ������Ŀ
void leaveNode(BiTree T){
	if(T){
		leaveNode(T->lchild);
		leaveNode(T->rchild);
		if((T->lchild==NULL)&&(T->rchild==NULL)){
			leavecount++;
		}
	}
} 
BiTree findData(BiTree T,char a){
	if(T->data==a){
		return T;
	}
	if(T->lchild){
		BiTree t = findData(T->lchild,a); //�Եݹ��������룬˼����� 
		if(t) {
			return t;
		}	
	}
	if(T->rchild){
		BiTree t = findData(T->rchild,a);
		if(t) {
			return t;
		}	
	}
	return NULL;
	
}
int main(){
	BiTree T;
	char a[9];
	char b[9];
	InitData(a,b);
//	int i =Search(a,b);
//	printf("%d",i);
	ReBiTree(&T,a,b,0,9,0,9);
	preOrder(T);
	leaveNode(T);
	printf("%d ",leavecount);
	BiTree D = findData(T,'D');
	if(D->lchild){
		printf("%c ",D->lchild->data);
	}
	if(D->rchild)
		printf("%c ",D->rchild->data);
	return 0;
}
//�ջ񣺱��һ����ÿһ������˼·���������ܰ�������������� 
//��û��������ԭ���ǰ���ʵ�ʲ����������ģ�û�а��ճ��򻯵�˼�룬
//���Ժ��̵Ĺ�����Ҫ�����Ӳ����ÿһ������һ������äĿ��ʼ�˷�ʱ���뾫����
//һ��Ҫ����������������д�������ڽ��б�� ����������һ����ͣ������˼���ǲ���˼·���Ƿ��������� 
//����ģ���ķ���˼·һ������ѡ�� �� 
