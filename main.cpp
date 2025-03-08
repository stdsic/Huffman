#include "Queue.h"

/*
void PrintNode(Node* Node){
	printf("작업명: %s (우선순위: %d)\n", Node->Data, Node->Priority);
}

int main()
{
	Queue PQ;
	Node Popped;

	Node Nodes[7]={
		{(void*)"코딩", 34},
		{(void*)"고객미팅", 12},
		{(void*)"커피타기", 87},
		{(void*)"문서작성", 45},
		{(void*)"디버깅", 35},
		{(void*)"이닦기", 66},
		{(void*)"밥먹기", 22}
	};

	PQ.Enqueue(Nodes[0]);
	PQ.Enqueue(Nodes[1]);
	PQ.Enqueue(Nodes[2]);
	PQ.Enqueue(Nodes[3]);
	PQ.Enqueue(Nodes[4]);
	PQ.Enqueue(Nodes[5]);
	PQ.Enqueue(Nodes[6]);

	printf("큐에 남아있는 작업의 수: %d\n", PQ.GetUsedSize());
	printf("작업 시작\n");

	while(!(PQ.IsEmpty())){
		PQ.Dequeue(&Popped);
		PrintNode(&Popped);
	}

	printf("작업 후 큐에 남아있는 작업의 수: %d\n", PQ.GetUsedSize());

	return 0;
}
*/

void PrintNode(QNode* Node){
	printf("작업명: %s (우선순위: %d)\n", Node->Data, Node->Priority);
}

int main()
{
	Queue PQ;
	QNode Popped;

	QNode Nodes[7]={
		{(void*)"코딩", 34},
		{(void*)"고객미팅", 12},
		{(void*)"커피타기", 87},
		{(void*)"문서작성", 45},
		{(void*)"디버깅", 35},
		{(void*)"이닦기", 66},
		{(void*)"밥먹기", 22}
	};

	PQ.Enqueue(Nodes[0]);
	PQ.Enqueue(Nodes[1]);
	PQ.Enqueue(Nodes[2]);
	PQ.Enqueue(Nodes[3]);
	PQ.Enqueue(Nodes[4]);
	PQ.Enqueue(Nodes[5]);
	PQ.Enqueue(Nodes[6]);

	printf("큐에 남아있는 작업의 수: %d\n", PQ.GetUsedSize());
	printf("작업 시작\n");

	while(!(PQ.IsEmpty())){
		PQ.Dequeue(&Popped);
		PrintNode(&Popped);
	}

	printf("작업 후 큐에 남아있는 작업의 수: %d\n", PQ.GetUsedSize());

	return 0;
}
