#include<iostream>
#include "TQueue.h"

int main()
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	q.output();

	TQueue<int> q1(q);
	q1.output();
}