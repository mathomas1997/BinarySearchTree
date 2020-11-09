/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: BinaryNodeTree.cpp
*
*	Purpose: implementation file for BinaryNodeTree source code/class definitions
*
*	Version: 1.00	
*
*	Notes: Function details can be found in BinaryNodeTree.h
*
*
*************************************************************************/

#include <iostream>
#include "BinaryNodeTree.h"
#include "BinaryNode.cpp"

using namespace std;

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
	{
		rootPtr = NULL;
	}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const ItemType& rootItem)
	{
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
	}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr)
	{
		rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
	}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const BinaryNodeTree<ItemType>& tree)
	{
		rootPtr = copyTree(tree.rootPtr);
	}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
	{
		destroyTree(rootPtr);
	}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
	{
		if(subTreePtr == NULL)
			return 0;

		else
			return max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())) + 1;
	}

template<class ItemType>		
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
	{
		if(subTreePtr == NULL)
			return 0;

		else
			return getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) + 1;
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
	{
		if(subTreePtr != NULL)
			{	
				destroyTree(subTreePtr->getLeftChildPtr());
				destroyTree(subTreePtr->getRightChildPtr());
				delete subTreePtr;
			}
	}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
	{
		if(subTreePtr == NULL)
			return newNodePtr;

		else {
			BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
			BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

			if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
				{
					rightPtr = balancedAdd(rightPtr, newNodePtr);
					subTreePtr->setRightChildPtr(rightPtr);
				}

			else if(getHeightHelper(leftPtr) < getHeightHelper(rightPtr))
				{
					leftPtr = balancedAdd(leftPtr, newNodePtr);
					subTreePtr->setLeftChildPtr(leftPtr);
				}

			return subTreePtr;
		}
	} 

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success)
	{
		if(subTreePtr == NULL)
			return NULL;

		if(subTreePtr->getItem() == target)
			{
				subTreePtr = moveValuesUpTree(subTreePtr);
				success = true;
				return subTreePtr;
			}

		else {

			BinaryNode<ItemType>* targetPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
			subTreePtr->setLeftChildPtr(targetPtr);
		
			if(success == false)
				{
					targetPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
					subTreePtr->setRightChildPtr(targetPtr);
				}

			return subTreePtr;
		}

	}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		int heightLeft = getHeightHelper(leftPtr);
		int heightRight = getHeightHelper(rightPtr);

		if(heightLeft > heightRight)
			{
				subTreePtr->setItem(leftPtr->getItem());
				leftPtr = moveValuesUpTree(leftPtr);
				subTreePtr->setLeftChildPtr(leftPtr);

				return subTreePtr;
			}

		else if(heightLeft < heightRight)
			{
				if(rightPtr != NULL)
					{
						subTreePtr->setItem(rightPtr->getItem());
						rightPtr = moveValuesUpTree(rightPtr);
						subTreePtr->setRightChildPtr(rightPtr);

						return subTreePtr;
					}

				else {

					delete subTreePtr;
					return NULL;
				}
			} 
	}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const
	{
		if(treePtr == NULL)
			return NULL;

		if(treePtr->getItem() == target)
			{
				success = true;
				return treePtr;
			}

		else {

			BinaryNode<ItemType>* targetPtr = findNode(treePtr->getLeftChildPtr(), target, success);	
			
			if(success == false)
				{
					targetPtr = findNode(treePtr->getRightChildPtr(), target, success);
				}

			return targetPtr;
			}
	}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree( const BinaryNode<ItemType>* treePtr) const
	{
		BinaryNode<ItemType>* newTreePtr = NULL;

		if(treePtr != NULL)
			{
				newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), NULL, NULL);
				newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
				newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
			}
		
		return newTreePtr;

	}


template<class ItemType>
void visit(ItemType& anItem) 
	{
		cout << anItem << " ";
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
	{
		if(treePtr != NULL)
			{
				ItemType item = treePtr->getItem();
				visit(item);

				preorder(visit, treePtr->getLeftChildPtr());
				preorder(visit, treePtr->getRightChildPtr());
			}
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
	{
		if(treePtr != NULL)
			{
				inorder(visit, treePtr->getLeftChildPtr());

				ItemType item = treePtr->getItem();
				visit(item);

				//test value of item
				// cout << item;
				
				inorder(visit, treePtr->getRightChildPtr());
			}
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
	{
		if(treePtr != NULL)
			{
				postorder(visit, treePtr->getLeftChildPtr());
				postorder(visit, treePtr->getRightChildPtr());

				ItemType item = treePtr->getItem();
				visit(item);
			}
	}

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
	{
		return rootPtr == NULL;
	}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
	{
		return getHeightHelper(rootPtr);
	}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const 
	{	
		return getNumberOfNodesHelper(rootPtr);
	}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
	{
		if(isEmpty())
			throw PrecondViolatedExcep("getRootData() was called with an empty tree.");
			return rootPtr->getItem();
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData( const ItemType& newData)
	{
		if(isEmpty())
			rootPtr = new BinaryNode<ItemType>(newData, NULL, NULL);

		else
			rootPtr->setItem(newData);
	}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add( const ItemType& newData) 
	{
		BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
		rootPtr = balancedAdd(rootPtr, newNodePtr);

		return true;
	}

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove( const ItemType& data) 
	{
		bool success = false;

		rootPtr = removeValue(rootPtr, data, success);

		return success;
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
	{
		destroyTree(rootPtr);
		rootPtr = NULL;
	}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry( const ItemType& anEntry) const throw(NotFoundException)
	{
		bool success = false;
		BinaryNode<ItemType>* newNodePtr = findNode(rootPtr, anEntry, success);

		if(success == true)
			{
				return newNodePtr->getItem();
			}

		else
			throw NotFoundException("Entry was not found in the tree.");
	}
	
template<class ItemType>	
bool BinaryNodeTree<ItemType>::contains( const ItemType& anEntry) const
	{
		bool success = false;

		findNode(rootPtr, anEntry, success);

		return success;
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse( void visit(ItemType&)) const
	{
		preorder(visit, rootPtr);
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse( void visit(ItemType&)) const
	{
		inorder(visit, rootPtr);
	}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse( void visit(ItemType&)) const
	{
		postorder(visit, rootPtr);
	}

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide)
	{
		if(!isEmpty())
			{
				clear();
				this = copyTree(&rightHandSide);

				return *this;
			}
	}
