#include "BST.h"

using std::ifstream;
using std::cout;

BST::BST() {
	ifstream infile;
	MorseData table[50];
	int len = 0;

	infile.open(fileName, std::ios::in);
	
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile >> table[len].character;
			infile >> table[len].code;
			len++;
		}
		insertNode(table, len);
	}
}
BST::BST(const BST &tree) {
	pHead = insertNode(tree.getHead());
}
BST::~BST() {
	destroyTree(pHead);
}
void BST::operator=(const BST &tree) {
	destroyTree(pHead);
	pHead = insertNode(tree.getHead());
}
void BST::insertNode(MorseData *data, int len) {
	if (len == 1) {
		insertNode(data[0].character, data[0].code);
	}
	else if (len != 0) {
		insertNode(data[len / 2].character, data[len / 2].code);
		insertNode(data, (len / 2));
		insertNode(&data[(len / 2) + 1], len - (len / 2) - 1);
	}
}
void BST::insertNode(char character, string &code) {
	BSTNode **pBranch = &pHead, *newNode = new BSTNode(character, code);
	int height = 0;

	while (*pBranch != nullptr) {
		if ((**pBranch).getChar() > character) {
			pBranch = (**pBranch).getPrev();
		}
		else {
			pBranch = (**pBranch).getNext();
		}
		height++;
	}
	if (height > this->height) {
		this->height = height;
	}
	*pBranch = newNode;
}
BSTNode *BST::insertNode(BSTNode *node) {
	if (node != nullptr) {
		BSTNode *newNode = new BSTNode(node->getChar(), node->getCode());
		BSTNode *nextPtr = insertNode(*node->getNext());
		BSTNode *prevPtr = insertNode(*node->getPrev());
		newNode->setNext(nextPtr);
		newNode->setPrev(prevPtr);
		return newNode;
	}
	else {
		return nullptr;
	}
}

void BST::print() {
	print(pHead, 0);
}

void BST::print(BSTNode *node, int height) {
	if (node == nullptr) {
		return;
	}
	else if (*(node->getNext()) == nullptr && *(node->getPrev()) == nullptr) {
		for (int i = 0; i < height; i++) {
			cout << "   ";
		}
		cout << node->getChar() << "\n";
	} else {
		height++;
		print(*node->getNext(), height);

		for (int i = 0; i < height - 1; i++) {
			cout << "   ";
		}
		cout << node->getChar() << "\n";

		print(*node->getPrev(), height);
	}
}

BSTNode *BST::getHead() const{
	return pHead;
}

const string BST::search(char character) {
	return search(character, pHead);
}
const string BST::search(char character, BSTNode *node) {
	if (node == nullptr) { // Not found
		return "null";
	}

	char ch = node->getChar();

	if (ch == character) { // Found
		return node->getCode();
	}
	else if (character < ch) { // Look back
		return search(character, *node->getPrev());
	}
	else if (character > ch) { // Look forward
		return search(character, *node->getNext());
	}
}
void BST::destroyTree(BSTNode *node) {
	if (node != nullptr) {
		destroyTree(*node->getNext());
		destroyTree(*node->getPrev());
		delete(node);
	}
}