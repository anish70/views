#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int data;
} node_t;

node_t *head = NULL;

void addToList(int d) {
	node_t *t = malloc(sizeof(node_t));
	t->data = d;
	t->next = NULL;

	if (head) {
		node_t *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = t;
	} else {
		head = t;
	}
}

void printList() {
	node_t *temp = head;
	while (temp != NULL) {
		printf("Node: %p, Data: %d\n", temp, temp->data);
		temp = temp->next;
	}
}

void makeCycle(int count) {
	int i = 0;
	node_t *temp = head;

	printf("%s%d\n", __func__, __LINE__);

	while (temp != NULL && i++ < count) {
		temp = temp->next;
	}

	printf("temp-Node: %p, Data: %d\n", temp, temp->data);

	node_t *t = head;
	while (t->next != NULL) {
		t = t->next;
	}
	printf("t-Node: %p, Data: %d\n", t, t->data);

	t->next = temp;
}

int detectCycle() {
	node_t *fast = head;
	node_t *slow = head;

	printf("%s%d\n", __func__, __LINE__);

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			// found cycle
			printf("Cycle Node: %p, Data: %d\n", slow, slow->data);
			return 1;
		}
		printf("Slow Node: %p, Fast Node: %p\n", slow, fast);
	}

	if (fast == NULL || slow == NULL) {
		printf("No Cycle\n");
	}

	return 0;
}

void deleteList() {
	node_t *t;
	node_t *temp = head;

	printf("%s%d\n", __func__, __LINE__);
	while (temp != NULL) {
		printf("Node: %p, Data: %d\n", temp, temp->data);
		t = temp;
		temp = temp->next;
		free(t);
	}

	head = NULL;
}


int main()
{
	for (int i = 0; i < 10; i++) {
		addToList(i + 100);
	}

	printList();

	detectCycle();

	makeCycle(4);

	detectCycle();

}
