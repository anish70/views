#include <iostream>

using namespace std;
 
void *
aligned_malloc(size_t size, size_t alignment)
{
	void *p1;
	void *p2;
	int offset = alignment -1 + sizeof(void *);

	if ((p1 = (void*) malloc(size + offset)) == NULL) {
		return NULL;
	}

	cout << "Unaligned: " << p1 << endl;
	p2 = (void *) (((size_t)p1 + offset) & ~(alignment -1));
	((void **)p2)[-1] = p1;

	cout << "Aligned: " << p2 << "Size: " <<  (size + offset) << endl;
	return p2;
}

void
aligned_free(void *r)
{
	void *p1 = ((void **)r)[-1];
	cout << "Free: %p" << p1 << endl;
	free(p1);
}

int
main(int argc, char *argv[])
{
	int alignment;
	cout << "Enter Alignment?";
	cin >> alignment;

	int addr;
	cout << "Enter Address?";
	cin >> addr;
        void *r = aligned_malloc(addr, alignment);
	aligned_free(r);
}
