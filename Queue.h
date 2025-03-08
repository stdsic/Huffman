#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

struct QNode{
	void *Data;
	size_t Priority;

	QNode(void* _Data = 0, size_t _Priority = 0) : Data(_Data), Priority(_Priority){ ; }
};

class Queue{
private:
	QNode	*Nodes;
	size_t	Capacity,
			UsedSize;

private:
	void SwapNodes(size_t Index1, size_t Index2);
	void EnsureCapacity();
	void ReduceCapacity();

private:
	const size_t GetParent(size_t Index) const { return Index - 1 >> 1; }
	const size_t GetLeftChild(size_t Index) const { return Index * 2 + 1; }

public:
	void Enqueue(QNode NewNode);
	void Dequeue(QNode *ret);

public:
	const bool IsEmpty() const { return UsedSize == 0; }
	const size_t GetUsedSize() const { return UsedSize; }

public:
	Queue(size_t _Capacity = 0) : Capacity(_Capacity), UsedSize(0), Nodes(NULL){
		if(Capacity < 0){ Capacity = 0; };
		if(Capacity > 0){ Nodes = (QNode*)malloc(sizeof(QNode) * Capacity); }
	}

	~Queue(){ if(Nodes){ free(Nodes); } }
};

#endif
