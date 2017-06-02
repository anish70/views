#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <mutex>
#include <map>
 
using namespace std;
 
class Chopstick {
public:
	mutex *chop_lock;	

	Chopstick() {
		chop_lock = new mutex;
	}

	~Chopstick() {
		delete chop_lock;
	}

	void pick() {
		chop_lock->lock();
	}

	void put_down() {
		chop_lock->unlock();
	}
};

class Philospher : public Chopstick {
	public:
		Chopstick *left;
		Chopstick *right;

	Philospher() {
		this->left = new Chopstick();
		this->right = new Chopstick();
	}

	~Philospher() {
		delete left;
		delete right;
	}

	void PutDown(int i) {
		right->put_down();
		left->put_down();
		cout << "Putdown " << i << "Philospher\n";
	}

	void Eat(int i) {
		Pickup(i);
		Chew(i);
		this->PutDown(i);
	}

	void Chew(int i) { cout << "Chewing " << i << "Philospher\n";}

	void Pickup(int i) {
		left->pick();
		right->pick();
		cout << "Pickup " << i << "Philospher\n";
	}


	void Run(int i) {
		Eat(i);
	}
};



int
main(int argc, char **argv)
{
	int bites = 10;
	Philospher *p[bites];

	for (int i = 0; i < bites; i++) {
		p[i] = new Philospher();
		p[i]->Run(i);
	}

	// delete[] p;	
}
