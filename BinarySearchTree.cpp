/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: BinarySearchTree.cpp
*
*	Purpose: implementation file for BinarySearchTree source code/class definitions
*
*	Version: 1.00	
*
*	Notes: Function details can be found in BinarySearchTree.h
*
*
*************************************************************************/
#include <iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

using namespace std;


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode)
	{
		if(subTreePtr == NULL)
			return newNode;

		else {

			if(subTreePtr->getItem() > newNode->getItem())
				{
					subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
				}

			else {

				subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
			}

			return subTreePtr;
		}
	}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success)
	{
		if(subTreePtr == NULL)
			{
				success = false;
				return NULL;
			}

		if(subTreePtr->getItem() == target)
			{
				subTreePtr = removeNode(subTreePtr);
				success = true;
				return subTreePtr;
			}

		else {

			if(target < subTreePtr->getItem())
				{
					subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
				}

			else if(target > subTreePtr->getItem())
				{
					subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
				}

			return subTreePtr;
		}
	}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
	{
		if(nodePtr->isLeaf())
			{
				delete nodePtr;
				nodePtr = NULL;
				return nodePtr;
			}

		else if(nodePtr->getLeftChildPtr() == NULL)
			{
				BinaryNode<ItemType>* tempPtr = nodePtr->getLeftChildPtr();
				delete nodePtr;
				nodePtr = NULL;
				return tempPtr;
			}

		else {

			ItemType newNodeData;
			nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeData));
			nodePtr->setItem(newNodeData);
			return nodePtr;
		}
	}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor)	
	{
		if(subTreePtr->getLeftChildPtr() == NULL)
			{
				inorderSuccessor = subTreePtr->getItem();
				return removeNode(subTreePtr);
			}

		else {

			subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
			return subTreePtr;
		}
	} 


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const
	{
		if(treePtr == NULL)
			{
				return NULL;
			}

		else if(treePtr->getItem() == target)
			return treePtr;

		else if(treePtr->getItem() > target)
			return findNode(treePtr->getLeftChildPtr(), target);

		else if(treePtr->getItem() < target)
			return findNode(treePtr->getRightChildPtr(), target);
	}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
	{
		rootPtr = NULL;
	}
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree( const ItemType& rootItem)
	{
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
	}
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree( const BinarySearchTree<ItemType>& tree)
	{
		rootPtr = this->copyTree(tree.rootPtr);
	}
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
	{
		this->destroyTree(rootPtr);
	}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
	{
		return (rootPtr == NULL);
	}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
	{
		return this->getHeightHelper(rootPtr);
	}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
	{
		return this->getNumberOfNodesHelper(rootPtr);
	}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
	{
		if(isEmpty())
			{
				throw PrecondViolatedExcep("getRootData() was called with an empty tree.");
				return rootPtr->getItem();
			}
	}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData( const ItemType& newData) const throw(PrecondViolatedExcep)
	{
		throw PrecondViolatedExcep("Unable to change the root's value in a BST.");
	}

template<class ItemType>
bool BinarySearchTree<ItemType>::add( const ItemType& newEntry)
	{
		BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
		rootPtr = insertInorder(rootPtr, newNodePtr);
		return true;
	}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove( const ItemType& anEntry)
	{
		bool success = false;

		rootPtr = removeValue(rootPtr, anEntry, success);

		return success;
	}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
	{
		this->destroyTree(rootPtr);
		rootPtr = NULL;
	}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry( const ItemType& anEntry) const throw(NotFoundException)
	{
		BinaryNode<ItemType>* newNodePtr = findNode(rootPtr, anEntry);

		if(newNodePtr == NULL)
			{
				throw NotFoundException("Entry was not found in tree.");
			}

		else {

			return newNodePtr->getItem();
		}
	}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains( const ItemType& anEntry) const
	{
		return findNode(rootPtr, anEntry);
	}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
	{
		this->preorder(visit, rootPtr);
	}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
	{	
		this->inorder(visit, rootPtr);
	}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
	{
		this->postorder(visit, rootPtr);
	}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
	{
		if(!isEmpty())
			{
				clear();
				this = copyTree(&rightHandSide);
				return *this;
			}
	}
