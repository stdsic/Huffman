#include "Huffman.h"
#include <windows.h>
#include <conio.h>

int main()
{
	const char* Source = "https://github.com/stdsic/Huffman";

	Huffman MyCompression;
	MyCompression.Encode(Source);

    system("cls");
	printf("Origin Source = %s\n", Source);
	printf("Convert BitString = %s\n", MyCompression.GetBitString());

	printf("\n=========================================== Decoding ===========================================\n");
	MyCompression.Decode(MyCompression.GetBitString());
	printf("DecodeString = %s\n", MyCompression.GetDecodeString());
    system("pause");

	return 0;
}
