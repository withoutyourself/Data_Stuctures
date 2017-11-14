// SingleList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	SingleList<int> link;
	for (int i = 0; i < 10; i++)
	{
		link.insert(i, i);
	}
	cout << link.size() << endl;
	link.insert_head(1111);
	link.insert_last(2222);
	SingleList<int>::pointer ptr = link.getHead();
	while (ptr != nullptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;

	}
	getchar();


    return 0;
}

