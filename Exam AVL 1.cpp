#include<iostream>
using namespace std;

class AVLtree{
    public:
    int price;
    int height;
    AVLtree*left;
    AVLtree* right;
    AVLtree(int p):price(p),height(1),left(NULL),right(NULL){}
};
AVLtree* rightrotation(AVLtree* y){
    AVLtree* x = y->left;
    AVLtree* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
AVLtree* leftrotation(AVLtree* x){
    AVLtree* y = x->right;
    AVLtree* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}
int max(int a,int b){
    int mx=0;
    if(a>b)
    mx=a;
    else
    mx=b;

    return mx;
}
int height(AVLtree* root){
    if(!root)
    return -1;

    return root->height;
}
int balancefactor(AVLtree* root){
    return height(root->left) - height(root->right);
}
AVLtree* insertion(AVLtree* root, int price){
    if(!root){
       return new AVLtree(price);
    }
    if(price < root->price){
        root->left = insertion(root->left,price);
    }else if(price > root->price){
        root->right = insertion(root->right,price);
    }else{
        cout<<" No Duplication is Allowed."<<endl;
    }

    root->height = 1 + max(height(root->left),height(root->right));
    int BF = balancefactor(root);

    if(BF > 1 && price < root->left->price){
        return rightrotation(root);
    }else if(BF > 1 && price > root->left->price){
        root->left = leftrotation(root);
        return rightrotation(root);
    }else if( BF < 1 && price < root->right->price){
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }else if( BF < 1 && price > root->right->price){
        return leftrotation(root);
    }
    return root;
}
AVLtree* searchNearestPrice(AVLtree* root, int budget) {
    if (!root) {
        return NULL;
    }

    if (root->price == budget) {
        return root;
    }

    if (budget < root->price) {
        AVLtree* left = searchNearestPrice(root->left, budget);
        if (left != NULL) {
            return left;
        } else {
            return root;
        }
    } else {
        AVLtree* right = searchNearestPrice(root->right, budget);
        if (right != NULL) {
            return right;
        } else {
            return root;
        }
    }

}
AVLtree* minimum(AVLtree * node){
    AVLtree* current = node;
    while(!current && current->left ==NULL ){
        current = current->left;
    }
    return current;
}
AVLtree* deletenode(AVLtree* root,int key){
    if(root == NULL)
    return root;
    if(key < root->price){
        root->left = deletenode(root->left,key);
    }else if(key > root->price){
        root->right = deletenode(root->right,key);
    }else{
        if(root->left == NULL || root->right == NULL){
            AVLtree* temp;
            if(root->left != NULL){
                temp = root->left;
            }else{
                temp = root->right;
            }
            if(temp ==NULL){
                temp = root;
                root =NULL;
            }else{
                root =temp;
            }
        }else{
            AVLtree* temp =minimum(root->right);
            root->price = temp->price;
            root->right = deletenode(root->right,temp->price);
        }

    }
    if(root == NULL){
        return root;
    }
    
    root->height = 1 + max(height(root->left),height(root->right));
    int BF = balancefactor(root);

    if(BF > 1 && key < root->left->price){
        return rightrotation(root);
    }else if(BF > 1 && key > root->left->price){
        root->left = leftrotation(root);
        return rightrotation(root);
    }else if( BF < 1 && key < root->right->price){
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }else if( BF < 1 && key > root->right->price){
        return leftrotation(root);
    }
    return root;
}
int main(){
 AVLtree* product_price = NULL;
    product_price = insertion(product_price, 321);
    product_price = insertion(product_price, 400);
    product_price = insertion(product_price, 550);
    product_price = insertion(product_price, 620);
    product_price = insertion(product_price, 870);

    cout << "Enter Your Budget: " << endl;
    int budget = 0;
    cin >> budget;

    AVLtree* nearestProduct = searchNearestPrice(product_price, budget);

    if (nearestProduct != NULL) {
        cout << "Suggested Product Price: " << nearestProduct->price << endl;
    } else {
        cout << "No product found within the budget." << endl;
    }

    return 0;
}