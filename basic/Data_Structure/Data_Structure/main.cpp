#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Heap.h"

using namespace std;

int main() {
	Stack stack;
	Queue queue;

	for (int i = 0; i < 100; i++) {
		stack.Push(i);
		queue.Enqueue(i);
	}

	for (int i = 0; i < 100; i++) {
		cout << "STACK[" << stack.getSize() << "]: ";
		cout << stack.Pop() << endl;
		cout << "QUEUE[" << queue.getSize() << "]: ";
		cout << queue.Dequeue() << endl;
	}

	for (int i = 0; i < 100; i++) {
		stack.Push(i);
		queue.Enqueue(i);
	}

	for (int i = 0; i < 100; i++) {
		cout << "STACK[" << stack.getSize() << "]: ";
		cout << stack.Pop() << endl;
		cout << "QUEUE[" << queue.getSize() << "]: ";
		cout << queue.Dequeue() << endl;
	}

	int capacity = 10;
	int buffer[] = { 20, 15, 4, 3, 9, 45, 100, 77, 1, 99 };
	Heap heap(false, capacity);
	for (int i = 0; i < 10; i++) {
		heap.Push(buffer[i]);
		heap.PrintBuffer();
	}

	cout << "*** PUSH COMPLETED ***" << endl;

	for (int i = 0; i < 10; i++) {
		cout << heap.Pop() << endl;
		heap.PrintBuffer();
	}

	return 0;
}