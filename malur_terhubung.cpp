#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct BST {
	node *root;
	unsigned size;
	
	void init() {
		root = NULL;
		size = 0u;
	}
	
	bool isEmpty() {
		return root == NULL;
	}
	
    bool find(int value) {
        node *temp = search(root, value);
		if(temp == NULL)
            return false;

		if (temp->key == value)
			return true;
        else
            return false;
    }
       	
	void insert(int value) {
    	if (!find(value)) {
	        root = in(value, root);
	        size++;
		}
    }
    
    void remove(int value) {
        root = removeT(value, root);
        size--;
    }
	
	void inorder() {
		inorderT(root);	
	}
	
	void preorder() {
		preorderT(root);	
	}
	
	void postorder() {
		postorderT(root);	
	}
	
	void levelorder() {
		printLevelOrder(root);
	}
	
	int sumConnectingSubtree(int l, int r) {
		int sum = 0;
//		cout << "subtreein ok" << endl;
		scs(root, l, r, &sum);
//		cout << "subtreeout ok" << endl;
		return sum;
	}

private:
	
	void scs_recur(node *t, int* sum) {
//		cout << "recurin ok" << endl;
		if (t != NULL) {
			*sum += t->key;
//		    cout << t->key << endl;
			scs_recur(t->left, sum);
			scs_recur(t->right, sum);
		}
	}

	
	void scs(node* t, int l, int r, int* sum) {
//		cout << "scsin ok at " << t->key << endl;
		if (t!=NULL) {
			if (t->key>r) 
				scs(t->left, l, r, sum);
			else if (t->key<l) 
				scs(t->right, l, r, sum);
			else {
				scs_recur(t, sum);
			}
		}
	}
	
    node* makeNode(int value) {
        node *temp = (node*) malloc(sizeof(node));
        temp->key = value;
        temp->left = NULL; 
		temp->right = NULL;
        return temp;
    }

    node* search(node *temp, int value) {
        while (temp != NULL) {
            if (value < temp->key)
                temp = temp->left;
            else if (value > temp->key)
                temp = temp->right;
            else
                return temp;
        }
        return temp;
    }																																									
	
    node* findMin(node* temp)
    {
        if(temp == NULL)
            return NULL;
        else if(temp->left == NULL)
            return temp;
        else
            return findMin(temp->left);
    }
    
    node* removeT(int value, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(value < t->key)
            t->left = removeT(value, t->left);
        else if(value > t->key)
            t->right = removeT(value, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->key = temp->key;
            t->right = removeT(t->key, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    node* in(int value, node* temp)
    {
        if(temp == NULL)
        {
            temp = new node;
            temp->key = value;
            temp->left = temp->right = NULL;
        }
        else if(value < temp->key)
            temp->left = in(value, temp->left);
        else if(value > temp->key)
            temp->right = in(value, temp->right);
        return temp;
    }    

	void inorderT(node *temp) {
		if (temp != NULL) {
			inorderT(temp->left);
		    cout << temp->key << " ";
			inorderT(temp->right);
		}
	}

	void preorderT(node *temp) {
		if (temp != NULL) {
		    cout << temp->key << " ";
			preorderT(temp->left);
			preorderT(temp->right);
		}
	}
	
	void postorderT(node *temp) {
		if (temp != NULL) {
			postorderT(temp->left);
			postorderT(temp->right);
		    cout << temp->key << " ";
		}
	}
	
	void levelorderT(node *temp) {
		
	}

	void printGivenLevel(node* temp, int level)
	{
	    if (temp == NULL)
	        return;
	    if (level == 1)
	        cout << temp->key << " ";
	    else if (level > 1)
	    {
	        printGivenLevel(temp->left, level-1);
	        printGivenLevel(temp->right, level-1);
	    }
	}
 
	/* Compute the "height" of a tree -- the number of
	    nodes along the longest path from the root node
	    down to the farthest leaf node.*/
	int height(node* node)
	{
	    if (node == NULL)
	        return 0;
	    else
	    {
	        /* compute the height of each subtree */
	        int lheight = height(node->left);
	        int rheight = height(node->right);
	 
	        /* use the larger one */
	        if (lheight > rheight)
	            return(lheight + 1);
	        else return(rheight + 1);
	    }
	}

	void printLevelOrder(node* temp)
	{
	    int h = height(temp);
	    int i;
	    for (i = 1; i <= h; i++)
	        printGivenLevel(temp, i);
	}
};


int main() {
	BST tree;
	tree.init();
		
	int N,Q,A,L,R;
	cin >> N >> Q;
	for (int i=0; i<N; i++) {
		cin >> A;
		tree.insert(A);
	}
	for (int i=0; i<Q; i++) {
		cin >> L >> R;
		if (L>R) {
			int temp = R;
			R = L;
			L = temp;
		}
		if (tree.find(L) && tree.find(R) && !tree.isEmpty()) {
			cout << tree.sumConnectingSubtree(L, R) << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}


