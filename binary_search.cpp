/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: binary_search.cpp
*
*	Purpose: To implement binary search trees using linked lists
*			 The main objective of this project was to create source code files
*			 and a test driver to add randomly generated numbers to a binary
*			 search tree, present the numbers in their pre, post, and inorder
*			 formats, remove specific values, and clear the search trees
*
*	Version: 1.00	
*
*	Notes: 	 Test driver
*		     Binary Search Tree 1 is made from an array of 100 randonmly generated
*		     numbers in the range 1-200
*		     Binary Search Tree 2 is made from an array of 10 randonmly generated
*		     numbers in the range 1-50
*			
*	Requires: BinarySearchTree.cpp
*			  BinaryNodeTree.cpp
*			  PrecondViolatedExcep.cpp
*			  NotFoundException.cpp
*
*
*************************************************************************/

// header files
#include <iostream>
#include <fstream>
#include <random>
#include "BinarySearchTree.cpp"
#include "BinaryNodeTree.cpp"
#include "PrecondViolatedExcep.cpp"
#include "NotFoundException.cpp"

using namespace std;

int sizeOfBST1 = 100;
int sizeOfBST2 = 10;

// functions defined after main function
int *randomValueCreator1(int* BST1values);
int *randomValueCreator2(int* BST2values);
BinarySearchTree<int>* addToTree1(BinarySearchTree<int>* BST1ptr, int* BST1values);
BinarySearchTree<int>* addToTree2(BinarySearchTree<int>* BST2ptr, int* BST2values);


int main() {

	/* arrays to hold numbers for binary search trees 
	   BST1/2 ~ Binary Search Tree 1/2 */
	int *BST1values = new int[sizeOfBST1 + 1];
	int *BST2values = new int[sizeOfBST2 + 1];

	// filling arrays with random number values 
	BST1values = randomValueCreator1(BST1values);
	BST2values = randomValueCreator2(BST2values);

	// creating node pointers to binary search trees
	BinarySearchTree<int>* BST1ptr = new BinarySearchTree<int>();
	BinarySearchTree<int>* BST2ptr = new BinarySearchTree<int>();
	
	// add the values of the arrays to the binary trees
	BST1ptr = addToTree1(BST1ptr, BST1values);
	BST2ptr = addToTree2(BST2ptr, BST2values);

	/* prints to terminal the heights and number of nodes of both binary search trees
	   after values are added to binary search tree */
	cout << endl << "Height of BST 1: " << BST1ptr->getHeight() << endl;
	cout << "Height of BST 2: " << BST2ptr->getHeight() << endl;
	cout << "Number of Nodes of BST 1: " << BST1ptr->getNumberOfNodes() << endl;
	cout << "Number of Nodes of BST 2: " << BST2ptr->getNumberOfNodes() << endl;

	cout << "-----------------------------------------------" << endl;
	cout << "Inorder output of BST 1: " << endl;
	BST1ptr->inorderTraverse(visit);
	cout << endl << endl;

	cout << "Preorder output of BST 2: " << endl;
	BST2ptr->preorderTraverse(visit);
	cout << endl << endl;

	cout << "Inorder output of BST 2: " << endl;
	BST2ptr->inorderTraverse(visit);
	cout << endl << endl;

	cout << "Postorder output of BST 2: " << endl;
	BST2ptr->postorderTraverse(visit);
	cout << endl << endl;

	cout << "REMOVING VALUES..." << endl;

	/* find and remove certain values of search trees,
	   for duplicates only one value is removed */
	BST1ptr->remove(35);	
	BST1ptr->remove(93);
	BST1ptr->remove(171);
	BST1ptr->remove(179);

	BST2ptr->remove(3);	
	BST2ptr->remove(18);
	BST2ptr->remove(21);
	BST2ptr->remove(43);

	cout << "-----------------------------------------------" << endl;
	cout << "MODIFIED BST 1 (AFTER REMOVAL OF 35, 93, 171, 179): " << endl;

	cout << "Height of BST 1: " << BST1ptr->getHeight() << endl;
	cout << "Number of Nodes of BST 1: " << BST1ptr->getNumberOfNodes() << endl;
	
	cout << "Inorder output of BST 1: " << endl;
	BST1ptr->inorderTraverse(visit);
	cout << endl << endl;


	cout << "MODIFIED BST 2 (AFTER REMOVAL OF 3, 18, 21, 43): " << endl;

	cout << "Height of BST 2: " << BST2ptr->getHeight() << endl;
	cout << "Number of Nodes of BST 2: " << BST2ptr->getNumberOfNodes() << endl;
	
	cout << "Inorder output of BST 2: " << endl;
	BST2ptr->inorderTraverse(visit);
	cout << endl << endl;	

	cout << "-----------------------------------------------" << endl;
	cout << "SHOWING THE BST'S ARE NOT EMPTY BEFORE CLEAR: " << endl << endl;
	
	cout << "Inorder output of BST 1: " << endl;
	BST1ptr->inorderTraverse(visit);
	cout << endl << endl;

	cout << "Inorder output of BST 2: " << endl;
	BST2ptr->inorderTraverse(visit);
	cout << endl << endl;

	cout << "CLEARING BINARY SEARCH TREES..." << endl;
	
	// clear binary search trees
	BST1ptr->clear();
	BST2ptr->clear();

	cout << "-----------------------------------------------" << endl;
	cout << "SHOWING THE BST'S ARE EMPTY AFTER CLEAR: " << endl << endl;

	cout << "Height of BST 1 (should be zero): " << BST1ptr->getHeight() << endl;
	cout << "Inorder output of BST 1 (should be clear): " << endl;
	BST1ptr->inorderTraverse(visit);
	cout << endl;

	cout << "Height of BST 2 (should be zero): " << BST2ptr->getHeight() << endl;
	cout << "Inorder output of BST 2 (should be clear): " << endl;
	BST2ptr->inorderTraverse(visit);
	cout << endl;

	// pointers no longer required and deleted
	delete BST1ptr;
	delete BST2ptr;
	delete BST1values;
	delete BST2values;


		return 0;
}

/* creates random values for Binary Search Tree 1 (100 values, range 1-200)
   takes in array declared in main function and returns the same array */

int *randomValueCreator1(int* BST1values)
{
		for(int valueIndex = 0; valueIndex < sizeOfBST1; valueIndex++)
		{
			BST1values[valueIndex] = rand() % 200 + 1;
		}

		return BST1values;
}

/*	creates random values for Binary Search Tree 1 (10 values, range 1-50)
	takes in array declared in main function and returns the same array */

int *randomValueCreator2(int* BST2values)
{
		for(int valueIndex = 0; valueIndex < sizeOfBST2; valueIndex++)
		{	
			BST2values[valueIndex] = rand() % 50 + 1;
		}

		return BST2values;
}

/*	adds values from array into first Binary Search Tree
  	takes in Binary Search Tree pointer and array full of random values
	returns Binary Search Tree pointer after values have been added */

BinarySearchTree<int>* addToTree1(BinarySearchTree<int>* BST1ptr, int* BST1values)
{
		for(int valueIndex = 0; valueIndex < sizeOfBST1; valueIndex++)
		{
			BST1ptr->add(BST1values[valueIndex]);
		}

		return BST1ptr;
}

/*	adds values from array into second Binary Search Tree
	takes in Binary Search Tree pointer and array full of random values
	returns Binary Search Tree pointer after values have been added */

BinarySearchTree<int>* addToTree2(BinarySearchTree<int>* BST2ptr, int* BST2values)
{
		for(int valueIndex = 0; valueIndex < sizeOfBST2; valueIndex++)
		{
			BST2ptr->add(BST2values[valueIndex]);
		}

		return BST2ptr;
}
