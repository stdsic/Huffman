g++ -o Queue.o -c Queue.cpp
g++ -o Huffman.o -c Huffman.cpp
g++ -o Compression main.cpp Queue.o Huffman.o
