#ifndef __HUFFMAN_H_
#define __HUFFMAN_H_
#include "Queue.h"

#define MAX_CHAR	256
#define MAX_LEVEL	8
#define BYTE_UNIT	8

struct SymbolInfo{
	char Symbol;
	size_t Frequency;

	SymbolInfo(char _Symbol = 0, size_t _Frequency = 0) : Symbol(_Symbol), Frequency(_Frequency){ ; }
};

struct HuffmanNode{
	SymbolInfo Data;
	struct HuffmanNode *Left;
	struct HuffmanNode *Right;

	HuffmanNode(SymbolInfo NewData) : Data(NewData), Left(NULL), Right(NULL){ ; }
	HuffmanNode(char _Symbol = 0, size_t _Frequency = 0) : Data(_Symbol, _Frequency), Left(NULL), Right(NULL){ ; } 
};

struct BitCode{
	char Code[MAX_LEVEL];
	size_t Size;

	BitCode() : Size(0) { memset(Code, 0, sizeof(char) * MAX_LEVEL); }
};

struct Buffer{
	unsigned char *buf;
	size_t Length;
	
	Buffer() : buf(NULL), Length(0){ ; }
};

class Huffman{
private:
	size_t SourceLength;

private:
	HuffmanNode	*Root;
	SymbolInfo	SymbolTable[MAX_CHAR];
	BitCode		BitCodeTable[MAX_CHAR];
	Buffer		Encoded;
	char		*BitString,
				*Decoded;

private:
	void DestroyTree(HuffmanNode* Tree);
	void DestroyNode(HuffmanNode* Target);

private:
	void BuildTree();
	void BuildBitCodeTable(HuffmanNode *Tree, char Code[MAX_LEVEL], size_t Size);

private:
	void SetBit(char BitCode);
	void ConvertBitString();

public:
	const char* GetBitString();

public:
	void Encode(const char* src);
	void Decode();

public:
	Huffman() : Root(NULL), SourceLength(0), BitString(NULL), Decoded(NULL) { ; }
	~Huffman(){ 
		if(Root){ DestroyTree(Root); }
		if(Encoded.buf){ free(Encoded.buf); }
		if(Decoded){ free(Decoded); }
		if(BitString){ free(BitString); }
	}
};

#endif
