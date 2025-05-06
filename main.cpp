#include "Huffman.h"
#include <conio.h>

int main()
{
	const char* Source = "https://github.com/stdfrog";

	Huffman MyCompression;
	MyCompression.Encode(Source);

	printf("Origin Source = %s\n", Source);
	printf("Convert BitString = %s\n", MyCompression.GetBitString());

	printf("========== Decoding ==========\n");
	MyCompression.Decode(MyCompression.GetBitString());
	printf("DecodeString = %s\n", MyCompression.GetDecodeString());

	return 0;
}
