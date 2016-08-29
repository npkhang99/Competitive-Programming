#include <stdio.h>
using namespace std;

const int N=100009;

class BST{
  private:
	struct binaryTree{
		binaryTree* left;
		binaryTree* right;
		int val;
	};
	binaryTree* root;
  public:
	int insert(int);
	BST(int u) { insert(u); }
	BST() { root = NULL; }
};

int BST::insert(int u){
	binaryTree* t = new binaryTree;
	binaryTree* parent;
	int r=-1;
	t->left = t->right = NULL;
	t->val = u;
	if(root==NULL) root = t;
	else{
		binaryTree* curr;
		curr = root;
		while(curr){
			parent = curr;
			if(u > curr->val) curr = curr->right;
			else curr = curr->left;
		}
		if(u > parent->val) parent->right = t;
		else parent->left = t;
		r = parent->val;
	}
	return r;
}

int n, x;
BST tree;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		int t=tree.insert(x);
		if(i>0) printf("%d ",t);
	}
	return 0;
}
