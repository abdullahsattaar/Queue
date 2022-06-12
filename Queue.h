#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue 
{
	int First;
	int Last;
	const int MaxSize = 3;
	int CurrentSize;
	T* QueueArray;
public:
	Queue() 
	{
		First = 0;
		Last = 0;
		CurrentSize = 0;
		QueueArray = new T[MaxSize];
	}
	int isSize()
	{
		return CurrentSize;
	}

	bool isEmpty()
	{
		if (CurrentSize == 0)
			return true;
		return false;
	}

	bool queueFront(T& e)
	{
		if (CurrentSize)
		{
			e = QueueArray[First];
			return true;
		}
		else
			return false;
	}


	bool enqueue(int e1)
	{
		if (CurrentSize <= MaxSize)
		{
			QueueArray[Last] = e1;
			Last++;
			CurrentSize++;
			cout << endl << "Enqueue: " << e1 << endl;
			return true;
		}
		else
			cout << "ERROR!!!! Queue is Full " << endl;
		return false;
	}
	bool dequeue()
	{
		if (CurrentSize) 
		{
			for (int i = 0; i < CurrentSize; ++i)
				QueueArray[i] = QueueArray[i + 1];
			Last--;
			CurrentSize--;
			cout << endl << "Dequeued" << endl;
			return true;
		}
		else
			cout << "Queue is empty " << endl;
		return false;
	}

	void printQueue()
	{
		cout << endl;
		for (int i = 0; i < CurrentSize; ++i)
			cout << QueueArray[i] << " ";
		cout << endl;
	}
};