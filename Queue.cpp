#include "Queue.h"

void Queue::SwapNodes(size_t Index1, size_t Index2){
	QNode *Temp = (QNode*)malloc(sizeof(QNode));

	memcpy(Temp, &Nodes[Index1], sizeof(QNode));
	memcpy(&Nodes[Index1], &Nodes[Index2], sizeof(QNode));
	memcpy(&Nodes[Index2], Temp, sizeof(QNode));

	free(Temp);
}

#define max(a,b) (((a) > (b)) ? (a) : (b))
void Queue::EnsureCapacity(){
	if(UsedSize == Capacity){
		Capacity = max(1, Capacity * 2);
		Nodes = (QNode*)realloc(Nodes, sizeof(QNode) * Capacity);
	}
}

void Queue::ReduceCapacity(){
	if(UsedSize <= (Capacity / 2)){
		Capacity /= 2;
		Nodes = (QNode*)realloc(Nodes, sizeof(QNode) * Capacity);
	}
}

void Queue::Enqueue(QNode NewNode){
	EnsureCapacity();
	Nodes[UsedSize] = NewNode;

	size_t C = UsedSize++;
	// 부모 노드만 비교
	while(C > 1){
		size_t P = GetParent(C);
		if(Nodes[C].Priority >= Nodes[P].Priority){break;}

		SwapNodes(P, C);
		C = P;
	}
}

void Queue::Dequeue(QNode *ret){
	memcpy(ret, &Nodes[0], sizeof(QNode));
	memset(&Nodes[0], 0, sizeof(QNode));

	SwapNodes(0, --UsedSize);

	// 형제 노드를 포함
	size_t P = 0;
	while(1){
		size_t	L = GetLeftChild(P),
				R = L + 1;

		if(L >= UsedSize){break;}
		size_t S = ((((R) >= (UsedSize)) || ((Nodes[L].Priority) < (Nodes[R].Priority))) ? (L) : (R));

		if(Nodes[P].Priority <= Nodes[S].Priority){ break; }
		SwapNodes(P, S);
		P = S;
	}

	ReduceCapacity();
}
