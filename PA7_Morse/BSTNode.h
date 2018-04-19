#pragma once
#include <string>

using std::string;

class BSTNode {
public:
	BSTNode() : BSTNode('\0', "") {};
	BSTNode(const char character, const string &code);
	BSTNode **getNext();
	BSTNode **getPrev();
	char getChar();
	const string& getCode();
	void setNext(BSTNode *pNext);
	void setPrev(BSTNode *pPrev);
private:
	char character;
	string code;
	BSTNode *pNext;
	BSTNode *pPrev;
};