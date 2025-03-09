#include "Huffman.h"

void Huffman::Encode(const char* src){
	SourceLength = strlen(src);

	for(int i=0; i<MAX_CHAR; i++){
		SymbolTable[i].Symbol = i;
		SymbolTable[i].Frequency = 0;
	}

	for(int i=0; i<SourceLength; i++){
		SymbolTable[src[i]].Frequency++;
	}

	// Set Huffman PrefixTree
	BuildTree();

	// Set BitCodeTable
	char CharacterCode[MAX_LEVEL];
	memset(BitCodeTable, 0, sizeof(BitCodeTable));
	BuildBitCodeTable(Root, CharacterCode, 0);

	// Set Bit
	for(int i=0; i<SourceLength; i++){
		size_t nBit = BitCodeTable[src[i]].Size;
		for(int j=0; j<nBit; j++){
			SetBit(BitCodeTable[src[i]].Code[j]);
		}
	}
}

void Huffman::BuildTree(){
	Queue PQ;

	// src에 있는 문자를 큐에 등록
	for(int i=0; i<MAX_CHAR; i++){
		if(SymbolTable[i].Frequency > 0){
			HuffmanNode *NewHNode = new HuffmanNode(SymbolTable[i].Symbol, SymbolTable[i].Frequency);
			QNode NewQNode((void*)NewHNode, NewHNode->Data.Frequency);
			PQ.Enqueue(NewQNode);
		}
	}

	while(PQ.GetUsedSize() > 1){
		QNode QNodeLeft,
			  QNodeRight;

		PQ.Dequeue(&QNodeLeft);
		PQ.Dequeue(&QNodeRight);

		HuffmanNode *HNodeLeft = (HuffmanNode*)QNodeLeft.Data,
					*HNodeRight = (HuffmanNode*)QNodeRight.Data,
					*HParentNode = new HuffmanNode('\0', HNodeLeft->Data.Frequency + HNodeRight->Data.Frequency);

		HParentNode->Left = HNodeLeft;
		HParentNode->Right = HNodeRight;

		QNode QNewNode((void*)HParentNode, HParentNode->Data.Frequency);
		PQ.Enqueue(QNewNode);
	}

	if(Root){ DestroyTree(Root); }
	QNode Tree;
	PQ.Dequeue(&Tree);
	Root = (HuffmanNode*)Tree.Data;
}

void Huffman::BuildBitCodeTable(HuffmanNode *Tree, char Code[MAX_LEVEL], size_t Size){
	if(Tree == NULL){ return; }

	if(Tree->Left != NULL){
		Code[Size] = 0;
		BuildBitCodeTable(Tree->Left, Code, Size + 1);
	}

	if(Tree->Right != NULL){
		Code[Size] = 1;
		BuildBitCodeTable(Tree->Right, Code, Size + 1);
	}

	if(Tree->Left == NULL && Tree->Right == NULL){
		// LeafNode
		for(int i=0; i<Size; i++){
			BitCodeTable[Tree->Data.Symbol].Code[i] = Code[i];
		}

		BitCodeTable[Tree->Data.Symbol].Size = Size;
	}
}

void Huffman::SetBit(char BitCode){
	if(Encoded.Length % BYTE_UNIT == 0){
		Encoded.buf= (unsigned char*)realloc(Encoded.buf, Encoded.Length / BYTE_UNIT + 1);
		Encoded.buf[Encoded.Length / BYTE_UNIT] = 0;
	}

	unsigned char Mask = 0x80;		// 128, 1000 0000
	Mask >>= Encoded.Length % BYTE_UNIT;

	if(BitCode == 1){
		Encoded.buf[Encoded.Length / BYTE_UNIT] |= Mask;
	}else{
		Encoded.buf[Encoded.Length / BYTE_UNIT] &= ~Mask;
	}

	Encoded.Length++;
}

void Huffman::ConvertBitString(){
	if(BitString){ free(BitString); }

	BitString = (char*)malloc(Encoded.Length + 1);

	for(int i=0; i<Encoded.Length; i++){
		unsigned char Mask = 0x80;
		Mask >>= i % BYTE_UNIT;

		BitString[i] = ((Encoded.buf[i / BYTE_UNIT] & Mask) == Mask) + '0';
	}
}

const char* Huffman::GetBitString(){
	ConvertBitString();
	return (const char*)BitString;
}

void Huffman::Decode(){

}

void Huffman::DestroyTree(HuffmanNode* Tree){
	if(Tree == NULL){ return; }

	DestroyTree(Tree->Left);
	DestroyTree(Tree->Right);
	DestroyNode(Tree);
}

void Huffman::DestroyNode(HuffmanNode* Target){
	free(Target);
}
