/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: BinaryNode.h
*
*	Purpose: header file for BinaryNode source code/class definitions
*
*	Version: 1.00	
*
*	Notes: 
*
*
*************************************************************************/
#include <iostream>
#include "BinaryTreeInterface.h"

#ifndef BINARY_NODE

#define BINARY_NODE

template<class ItemType>
class BinaryNode {

private:

		ItemType item; 
		BinaryNode<ItemType>* leftChildPtr; 
		BinaryNode<ItemType>* rightChildPtr; 

public:

		BinaryNode();
		BinaryNode( const ItemType& anItem);
		BinaryNode( const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);
		void setItem( const ItemType& anItem);
		ItemType getItem() const;
		bool isLeaf() const;
		BinaryNode<ItemType>* getLeftChildPtr() const;
		BinaryNode<ItemType>* getRightChildPtr() const;
		void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
		void setRightChildPtr(BinaryNode<ItemType>* rightPtr);



}; 

#endif
