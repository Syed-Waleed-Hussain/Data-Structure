#include<iostream>
using namespace std;

class Treenode{
	public:
		int id;
		int rollnumber;
		Treenode* left;
		Treenode* right;
		int height;
		Treenode(int ID,int rollno){
			id = ID;
			rollnumber = rollno;
			left = NULL;
			right = NULL;
			height = 1;
		}
	
};

Treenode* rightrotate(Treenode* y){
	Treenode* x = y->left;
	Treenode* T2 = x->right;
	
	x->right = y;
	y->left = T2;
	return x;
}
Treenode* leftrotate(Treenode* x){
	Treenode* y = x->right;
	Treenode* T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	return y;
}

int height(Treenode* r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->height;
	}
}
int max(int a, int b) {
	
    return (a > b) ? a : b;
}
int balancefactor(Treenode* r){
	if(r == NULL){
		return -1;
	}else{
		return (height(r->left) - height(r->right));
	}
}
Treenode * insertion(Treenode* r,Treenode* newnode){
	if (r == NULL){
		r = newnode;
		return newnode;
	}
	if(newnode->id < r->id){
		r->left = insertion(r->left,newnode);
	}else if(newnode->id > r->id){
		r->right = insertion(r->right,newnode);
	}else {
		cout<<"No Duplicate Values Allowed ..!"<<endl;
	}
	r->height = 1 + max(height(r->left), height(r->right));
	
	int BF = balancefactor(r);
	if(BF > 1 && newnode->id < r->left->id){
		return rightrotate(r);
	}else if(BF > 1 && newnode->id > r->left->id){
		r->left = leftrotate(r);
		return rightrotate(r);
	}else if(BF < -1 && newnode->id > r->right->id){
		return leftrotate(r);
	}else if(BF < -1 && newnode->id < r->right->id){
		r->right = rightrotate(r->right);
		return leftrotate(r);
	}
	return r;
}

void search(Treenode* root, int roll) {
    if (root == NULL) {
        cout << "Roll number : " << roll << " not found." << endl;
        return;
    }
    if (root->rollnumber == roll) {
        cout << "Roll number : " << root->rollnumber << " with ID : " << root->id << " Found" << endl;
    } else if (roll < root->rollnumber) {
        search(root->left, roll);
    } else {
        search(root->right, roll);
    }
}


Treenode* minValueNode(Treenode* node) { 
    Treenode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Treenode* deleteNode(Treenode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->rollnumber) 
        root->left = deleteNode(root->left, key);
    else if (key > root->rollnumber)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Treenode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                root = temp;

            delete temp;
        } else {
            Treenode* temp = minValueNode(root->right);
            root->rollnumber = temp->rollnumber;
            root->right = deleteNode(root->right, temp->rollnumber);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right)); 

    int BF = balancefactor(root);
    if (BF > 1 && balancefactor(root->left) >= 0)
        return rightrotate(root);
    if (BF > 1 && balancefactor(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (BF < -1 && balancefactor(root->right) <= 0)
        return leftrotate(root);
    if (BF < -1 && balancefactor(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void inorder(Treenode* root) {
        if (root != NULL) {
        inorder(root->left);
        cout << root->rollnumber << " "; 
        inorder(root->right);
    }
    }
int main(){
	
    Treenode* student = NULL;
    student = insertion(student, new Treenode(1, 10)); 
    student = insertion(student, new Treenode(2, 20));
    student = insertion(student, new Treenode(3, 30));
    student = insertion(student, new Treenode(4, 40));
    student = insertion(student, new Treenode(5, 50));
    student = insertion(student, new Treenode(6, 15));

    cout << "Initial AVL Tree: ";
    inorder(student);
    cout << endl;

    cout << "Height of the tree: " << height(student) << endl;

    search(student, 25);

    student = deleteNode(student, 20); 

    cout << "AVL Tree after deleting 20: ";
    inorder(student);
    cout << endl;

    return 0;
}
