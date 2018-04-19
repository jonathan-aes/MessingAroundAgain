#pragma once
#include "BSTNode.h"
#include <iostream>
#include <fstream>

typedef struct MorseData {
	char character;
	string code;
} MorseData;

class BST {
public:
	BST();
	// Copies the given tree
	BST(const BST &tree);
	// Deletes all the nodes in the tree
	~BST();
	// Deletes the old tree and creates a new one copying the given tree
	void operator=(const BST &tree);
	// Prints the binary search tree sideways
	void print();
	// Searches for the given character, returns the string "null" if not found
	const string search(char character);
	// Returns the tree head
	BSTNode *getHead() const;
private:
	// Inserts nodes based off the given MorseData array. Array must be sorted.
	void insertNode(MorseData *data, int len);
	// Inserts a single node, given a character and code.
	void insertNode(char character, string &code);
	// Inserts a single node, which is a copy of the given node (aside from next/prev pointers)
	BSTNode *insertNode(BSTNode *node);
	// Prints a specific node and its descendants.
	void print(BSTNode *node, int height);
	// Searches for a character in a specific tree.
	const string search(char character, BSTNode *node);
	// Destroys a given tree.
	void destroyTree(BSTNode *node);


	int height = 0;
	const string fileName = "morseTable.txt";
	BSTNode *pHead = nullptr;
};

