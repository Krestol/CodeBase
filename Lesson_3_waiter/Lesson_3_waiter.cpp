// Lesson_3_waiter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void main(int argc, char *argv[])
{
	//std::cin.get();

	printf("[Child] Started with:\n");
	for (int i = 0; i < argc; ++i)
	{
		printf("[%d] %s\n", i, argv[i]);
	}

	std::cout << "Put any key to exit...";
	std::cin.get();
}