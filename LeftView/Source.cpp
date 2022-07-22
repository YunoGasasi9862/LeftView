#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
struct Node
{
	int data;
   struct Node* left;
   struct Node* right;

   Node(int x) //constructor
   {
	   data = x;
	   left = right = NULL;
   }

};
//do the same fucntion with depth-first SEARCH




std::vector<int> leftView(Node* root)
{
	std::vector<int> answer;
	Node* temp = root;
	answer.push_back(temp->data);

	while (temp != NULL)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
			answer.push_back(temp->data);

		}
		
		if (temp!=NULL && temp->left == NULL)
		{
			if (temp->right!=NULL)
			{
				temp = temp->right;
				answer.push_back(temp->data);

			}
		}

		if (temp->left == NULL && temp->right == NULL)
		{
			temp = temp->left;
		}
	}



	return answer;

}

int main(void)
{

	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(5);
	root->left->right = new Node(1);
	root->left->right->right = new Node(7);


	//3 4 N 2 7 N 2 1 N 9 1

	std::vector<int> answer = leftView(root);
	return 0;
}