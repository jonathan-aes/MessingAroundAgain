#include "BSTNode.h"

BSTNode::BSTNode(const char character, const string &code) {
	this->character = character;
	this->code = code;
	this->pNext = nullptr;
	this->pPrev = nullptr;
}

BSTNode **BSTNode::getNext() {
	return &(this->pNext);
}

BSTNode **BSTNode::getPrev() {
	return &(this->pPrev);
}

char BSTNode::getChar() {
	return this->character;
}

const string& BSTNode::getCode() {
	return this->code;
}

void BSTNode::setNext(BSTNode *pNext) {
	this->pNext = pNext;
}

void BSTNode::setPrev(BSTNode *pPrev) {
	this->pPrev = pPrev;
}