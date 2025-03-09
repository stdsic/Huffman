#include "Queue.h"
#include <conio.h>

int main()
{
	Queue PQ;

	QNode NewNode[] = {
		{(void*)"밥먹기", 1},
		{(void*)"코딩", 22},
		{(void*)"샤워", 17},
		{(void*)"게임", 99},
		{(void*)"잠자기", 2},
		{(void*)"커피", 10},
		{(void*)"미팅", 4},
	};


	printf("작업을 큐에 등록합니다.\n");
	for(int i=0; i<7; i++){
		printf("작업명: %s(%d)\n", (char*)NewNode[i].Data, NewNode[i].Priority);
		PQ.Enqueue(NewNode[i]);
	}
	printf("등록을 완료하였습니다.\n");

	printf("작업을 시작하려면 아무 키나 누르세요.\n");
	_getch();

	printf("등록된 작업을 수행합니다.\n");
	printf("==========작업 시작==========\n\n");

	QNode Popped;
	while(!(PQ.IsEmpty())){
		PQ.Dequeue(&Popped);
		printf("작업명: %s(%d)\n", (char*)Popped.Data, Popped.Priority);
	}

	printf("\n==========작업 완료==========");
	return 0;
}
