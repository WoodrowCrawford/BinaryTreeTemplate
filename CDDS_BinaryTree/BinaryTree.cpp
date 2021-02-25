#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty() == true)
	{
		m_root = new TreeNode(value);
	}

	//Create a TreeNode pointer that will act as an iterator pointing to the current node and set it to the root.
	TreeNode* currentNode = nullptr;
	currentNode = m_root;
	//Create a TreeNode pointer that will act as an iterator pointing to the parent 
	TreeNode* parent = nullptr;
	//of the current node and set it to the root.
	parent = currentNode;
	parent = m_root;

	//Loop until the the current node iterator reaches a nullptr.
	while (currentNode != nullptr)
	{
		//Check if the value we want to add to the tree is less than the value at the current node.
		if (value < currentNode->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parent = currentNode;
			//Change the current node to be the child to its left and continue.
			currentNode = currentNode->getLeft();
		}
		


		//Check if the value we want to add to the tree is greater than the value at the current node.
		else if (value > currentNode->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parent = currentNode;
			//Change the current node to be the child to its right and continue.
			currentNode = currentNode->getRight();
			
		}
		else if (value == currentNode->getData())
		{
			if (value == currentNode->getData())
			{
				return;
			}
		}
		//If the value is the same as a value already in the list return 
		
	}

	//end loop

	//If the value we want to add is less than the value of the parent node, insert the value to the left.
	if (value < parent->getData())
	{
		parent->setLeft(new TreeNode(value));
		
		
	}
	//Otherwise, insert the value to the right.
	else
	{
		parent->setRight(new TreeNode(value));
	}
}


void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	
	TreeNode* current = m_root;
	//and another to hold a reference to its parent.
	TreeNode* parentNode = current;
	TreeNode* minNode = nullptr;


	
	
	

	findNode(value, current, parentNode);
	if (current == nullptr)
	{
		//If the node cannot be found return.
		return;
	}


	//Check to see if the node has a right
	if (current->hasRight() == true)
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		minNode = current->getRight();
		parentNode = current;

		//Set the first iterator to point to the right child of the node we want to remove.  


		//Loop while the first iterator has a value to its left
		while (minNode->hasLeft() == true)
		{
			//Set the second iterator to be the value of the first iterator.
			parentNode = minNode;
			//Set the first iterator to be the value to the left of it
			minNode = minNode->getLeft();
		}
		current->setData(minNode->getData());


		if (minNode == parentNode->getLeft())
		{
			parentNode->setLeft(parentNode->getRight());
			delete minNode;
		}

		if (minNode == parentNode->getRight())
		{
			parentNode->setRight(minNode->getLeft());
			delete minNode;
		}


	}

		else if (!current->hasRight())
		{
			if (current == parentNode->getLeft())
			{
				parentNode->setLeft(current->getLeft());
				delete current;
			}
			
			if (current == parentNode->getRight())
			{
				parentNode->setRight(current->getLeft());
				delete current;
			}

			if (minNode == m_root)
			{
				m_root = current->getLeft();
				remove (current->getData());
			}

		}
		//end loop
	

	
	

}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* iterator = nullptr;
	iterator = m_root;
	

	//Loop through the tree while the iterator isn't nullptr.
	while (iterator != nullptr)
	{
		//Check if the node has the data we want
		if (iterator->getData() == value)
		{
			//Return the iterator
			return iterator;
		}



		//If the node doesn't have the data we want, check to see if it's higher in value.
		if (value > iterator->getData())
		{

			//Set the iterator to be its current right child.
			iterator = iterator->getRight();
		}


		//If the node doesn't have the data we want, check to see if it's lower in value.
		if (value < iterator->getData())
		{
			//Set the iterator to be its current left child.
			iterator = iterator->getLeft();
		}
	}
	//end loop

	//Return nullptr
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	TreeNode* currentNode = m_root;
	//and the other to hold a reference to the parent.
	TreeNode* parent = currentNode;

	//Loop while the current node iterator isn't nullptr/
	while (currentNode != nullptr)
	{
		//Check if the search value is the same as the current nodes data.
		if (searchValue < currentNode->getData())
		{
			parent = currentNode;
			//if (currentNode->hasLeft()) return false;
			currentNode = currentNode->getLeft();
		}

		else if (searchValue > currentNode->getData())
		{
			parent = currentNode;
			//if (currentNode->hasRight()) return false;
			currentNode = currentNode->getRight();
		}
		
		else if (searchValue == currentNode->getData())
		{
			
			nodeFound = currentNode;
			nodeParent = parent; 
			return true;
		}
		
	}
	return false;
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (currentNode)
	{
		if (currentNode->hasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (currentNode->hasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		currentNode->draw(x, y, currentNode == selected);
	}
}
