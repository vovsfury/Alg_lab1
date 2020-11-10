#ifndef ELEM
#define ELEM

using namespace std;
class Elem {

public:

	int data;
	Elem* next, * prev;

	Elem(int Data = 0) {
		data = Data;
		next = NULL;
		prev = NULL;
	}

	void print() { cout << data << " "; }

	~Elem() {}

};
#endif
