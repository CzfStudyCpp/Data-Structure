#pragma once
#include<utility>
class AVL
{

	struct Node
	{
		int data;
		Node* left;
		Node* right;
		int height;
		Node(const int& _data, Node* lt, Node* rt, int h = 0)
			:data{ _data }, left{ lt }, right{ rt }, height{ h } {}
		Node(const int&& _data, Node* lt, Node* rt, int h = 0)
			:data{ std::move(_data) }, left{ lt }, right{ rt }, height{ h } {}
	};
	int height(Node* t)const;
	Node* root;

public :

	AVL();
	void insert(const int& x);
	void print();
private:
	static const int Allowd = 1;
	void insert(const int& x, Node*& t);
	void balance(Node*& t);
	void rotateWithLeftChild(Node*& t);
	void rotateWithRightChild(Node*& t);
	void  doubleWithLeftChild(Node*& t);
	void  doubleWithRightChild(Node*& t);
	void print(Node*t);

};

