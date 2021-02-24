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
		if (value > currentNode->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parent = currentNode;
			//Change the current node to be the child to its right and continue.
			currentNode = currentNode->getRight();
			
		}
		if (currentNode)
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
	TreeNode* removeNode = nullptr;

	//and another to hold a reference to its parent.
	TreeNode* parentNode = nullptr;

	//Try to find the node that matches the value given and its parent in the tree.
	findNode(value, parentNode, parentNode) == parentNode->getData();
	
	if (findNode(value, parentNode, parentNode) != parentNode->getData())
	{
		//If the node cannot be found return.
		return;
	}


	//Check to see if the node has a right
	if (parentNode->hasRight() == true)
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		TreeNode* iter1 = nullptr;
		TreeNode* iter2 = nullptr;
		//Set the first iterator to point to the right child of the node we want to remove.  
		iter1 = removeNode->getRight();

		//Loop while the first iterator has a value to its left
		while (iter1->getLeft() != nullptr)
		{
			//Set the second iterator to be the value of the first iterator.
			iter2 = iter1;
			//Set the first iterator to be the value to the left of it
			iter1->setLeft(iter1);
		}
		//end loop
	}

	

		//Once the smallest value has been found, copy the data in first iterator to the node we want to remove.
	TreeNode* iter1 = nullptr;
	TreeNode* iter2 = nullptr;
	


		//Check if the second iterator has a left child.
	if (iter2->hasLeft() == true)
	{
		//Check if the left child stores the same data as the node we wanted to remove.
		if (iter2->getLeft() == removeNode)
		{
			//Set the second iterators left child to be the first iterators right child.
			iter2->setLeft(iter1->getRight());
		}
				
	}
			

		//Check if the second iterator has a right child.
	if (iter2->hasRight() == true)
	{
		//Check if the right child contains the same data as the node we want to remove.
		if (iter2->getRight() == removeNode)
		{
			//Set the right child of the second iterator to be the right child of the first iterator.
			{
				iter2->setRight(iter1->getRight());
			}
		}
	}
			
				

		//Delete the first iterator
	delete iter1;

	//Otherwise, if the node doesn't have a right child
	if (removeNode->getRight() == nullptr)
	{
		//check if the parent of the node to remove has a left child.
		if (removeNode->getLeft() != nullptr)
		{
			//Check if the data that the left child holds is the same as the data the node to remove holds.
			if (removeNode->getLeft() == removeNode)
			{
				//Set the left child of the parent node to be the left child of the node to remove.
				{
					parentNode->setLeft(removeNode->getLeft());
				}
			}
				
		}
			
	}

		

		//Check if the parent of the node to remove has a right child.
	if (removeNode->hasRight() == true)
	{
		//Check if the data the right child holds is the same as the data the node to remove holds.
		{
			if (removeNode->getRight() == removeNode)
			{
				//Set the right child of the parent node to be the left child of the node to remove.
				{
					parentNode->setRight(removeNode->getLeft());
				}
			}
		}
				
	}
			

		//Check if the node we want to remove is the root.
	if (removeNode = m_root)
	{
		//Set the root to be its left child.
		{
			removeNode->setLeft(m_root);

		}
	}
			

		//Delete the pointer that points to the node to remove.
	delete removeNode;
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
	TreeNode* currentNode = nullptr;
	//and the other to hold a reference to the parent.
	TreeNode* parent = nullptr;

	//Loop while the current node iterator isn't nullptr/
	while (currentNode != nullptr)
	{
		//Check if the search value is the same as the current nodes data.
		if (searchValue == currentNode->getData())
		{
			//Set the node found argument to be the current node and the parent node to be the parent node iterator.
			nodeFound = currentNode;
			nodeParent = parent;
			
			//Return true.
			return true;
		}
			
	}
		
		//Check if the search value is greater than the value at the current node.
	if (searchValue > currentNode->getData())
		
	{
		//Set the parent node to be the current node.
		parent = currentNode;
		//Set the current node to be the child to the right of the current node.
		currentNode = currentNode->getRight();
	}
			
		//Check if the search value is less than the value at the current node.
	if (searchValue < currentNode->getData())
	{
		//Set the parent node to be the current node.
		parent = currentNode;
		//Set the current node to be its left child.
		currentNode = currentNode->getLeft();
		
	}
			
	//end loop

	//Return false.
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
