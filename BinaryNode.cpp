/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: BinaryNode.cpp
*
*	Purpose: implementation file for BinaryNode source code/class definitions
*
*	Version: 1.00	
*
*	Notes: 
*
*
*************************************************************************/
#include <iostream>
#include "BinaryNode.h"

using namespace std;

template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
	{
		item = NULL;
		leftChildPtr = NULL;
		rightChildPtr = NULL;
	}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode( const ItemType& anItem)
	{
		item = anItem;
		leftChildPtr = rightChildPtr = NULL;
	}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode( const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr)
	{
		item = anItem;
		leftChildPtr = leftPtr;
		rightChildPtr = rightPtr;
	}

template <class ItemType>
void BinaryNode<ItemType>::setItem( const ItemType& anItem)
	{
		item = anItem;
	}

template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
	{
		return item;
	}

template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
	{
		
		return ((leftChildPtr == NULL) && (rightChildPtr == NULL));
	}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
	{
		return leftChildPtr;
	}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
	{
		return rightChildPtr;
	}

template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
	{
		leftChildPtr = leftPtr;
	}

template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
	{
		rightChildPtr = rightPtr;
	}