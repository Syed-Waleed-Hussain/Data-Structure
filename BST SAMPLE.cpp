#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;		
		Node* right;
		Node(int d):data(d){
		left = right = NULL;
	}		
};

void insert(Node*& root, int data){
	if(root == NULL){
		root = new Node(data);
		return;
	}
	if(data < root->data){
		insert(root->left,data);
	}else{
		insert(root->right,data);
	}
}
void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
Node* min(Node* node)
{
	Node* cur = node;
	while(cur && cur->left)
	{
		cur = cur->left;
	}
	return cur;
}
Node* deleteNode(Node* node, int val)
{
	if(!node)
	return node;
	
	if (val < node->data)
	node->left = deleteNode(node->left,val);
	else if(val > node->data)
	node->right = deleteNode(node->right,val);
	else
	{
		if(!node->left)
		{
			Node* tmp = node->right;
			delete node;
			return tmp;
		}
		else if(!node->right)
		{
			Node* tmp = node->left;
			delete node;
			return tmp;
		}
		Node* tmp = min(node->right);
		node->data = tmp->data;
		node->right = deleteNode(node->right,tmp->data);
	}
	return node;
}




int main(){
	Node* root = NULL;
	insert(root,16);
	insert(root,5);
	insert(root,3);
	insert(root,9);
	deleteNode(root,3);
	cout << root->data<<" ";
	inorder(root);
	return 0;
}