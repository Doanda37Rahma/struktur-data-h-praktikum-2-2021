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
	
	int height() {
		return maxh(root);
	}
	
	void penomoranGarasi(int *arr, int genapmin) {
		int h=0;
		if (genapmin) 
			garasiA(root, h, arr);
		else garasiB(root, h, arr);
	}

private:
	
	void garasiA(node* t, int h, int* arr) {
		if (t != NULL) {
			if (arr[h] == 0) {
				arr[h] = t->key;
			} else {
				if (h & 1) {
					if (t->key > arr[h])
						arr[h] = t->key;
				} else {
					if (t->key < arr[h])
						arr[h] = t->key;
				}
			}
			garasiA(t->left, h+1, arr);
			garasiA(t->right, h+1, arr);
		}
	}

	void garasiB(node* t, int h, int* arr) {
		if (t != NULL) {
			if (arr[h] == 0) {
				arr[h] = t->key;
			} else {
				if (h & 1) {
					if (t->key < arr[h])
						arr[h] = t->key;
				} else {
					if (t->key > arr[h])
						arr[h] = t->key;
				}
			}
				garasiB(t->left, h+1, arr);
			garasiB(t->right, h+1, arr);
		}
	}

	
	int maxh(node* temp) {
		if (temp==NULL) return 0;
		else 
		{
			int lefth = maxh(temp->left);
			int righth = maxh(temp->right);
			
			if (lefth > righth) 
				return lefth+1;
			else return righth+1;
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
		
	int P, num, h;
	
	cin >> P;
	for (int i=0; i<P; i++) {
		cin >> num;
		tree.insert(num);
	}

	h = tree.height();	
	int A[h+1];
	for (int j=1; j<h; j+=2) 
		A[j] = 0;

	if (h & 1) {
		tree.penomoranGarasi(&A[0], 1);
	} else {
		tree.penomoranGarasi(&A[0], 0);
	}
	
	for (int k=h-1; k>=0; k--) {
		cout << A[k] << " ";
	}
	
	return 0;
}
