#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::string;
using std::ifstream;

class MyStack<T> {
	static class StackNode<T> {
		T data;
		StackNode next;
	}

	StackNode(T data) {
		this.data = data;
	}

	StackNode<T> top;
	
	T pop() {
		if (top == null) throw new EmptyStackException();
		T item = top.data;
		top = top.next;
		return item;
	}

	void T push(T item) {
		StackNode<T> *t = new StackNode(item);
		t.next = top;
		top = t;
	}
};


int
main(void)
{
}
