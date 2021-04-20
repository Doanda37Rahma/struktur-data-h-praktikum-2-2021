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
	
	bool findJumlahTiga(int value) {
		bool result = findtiga(root, value);
		return result;
	}

private:
	
	bool findtiga(node *temp, int value) {
		if (temp != NULL) {
			int sum;
			if (temp->left) {
				if (temp->right) {
					sum = temp->key + temp->left->key + temp->right->key;
					if (sum == value) return true;
				}
				if (temp->left->left) {
					sum = temp->key + temp->left->key + temp->left->left->key;
					if (sum == value) return true;
				}
				if (temp->left->right) {
					sum = temp->key + temp->left->key + temp->left->right->key;
					if (sum == value) return true;
				}
			}
			if (temp->right) {
				if (temp->right->right) {
					sum = temp->key + temp->right->key + temp->right->right->key;
					if (sum == value) return true;
				}
				if (temp->right->left) {
					sum = temp->key + temp->right->key + temp->right->left->key;
					if (sum == value) return true;
				}
			}
			if (findtiga(temp->left, value) ||
				findtiga(temp->right, value))
				return true;
			else
				return false;
			 
		}
		return false;
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
	
	int t, sum, n;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		tree.insert(n);
	}
	cin >> sum;
	
	bool result = tree.findJumlahTiga(sum);
	
	if (result) cout << "Penjumlahan angka di tree yang menghasilkan " << sum << " ditemukan" << endl;
	else cout << "Tidak ditemukan penjumlahan angka di tree yang menghasilkan " << sum << endl;

	return 0;
}
