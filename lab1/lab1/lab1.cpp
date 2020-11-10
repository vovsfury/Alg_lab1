#include <iostream>
#include <stdexcept>
#include "Elem.h"

using namespace std;

class List
{
public:

	Elem* head, * tail;
	size_t list_size;

	List() {
		head = NULL;
		tail = NULL;
		list_size = 0;
	}

	//checks if list is empty
	bool isEmpty() {
		if (list_size == 0) return 1;
		else return 0;
	}

	//inserts an element at the end of list
	void push_back(int Data) {
		if (isEmpty()) {
			head = new Elem(Data);
			tail = head;
		}
		else {
			tail->next = new Elem(Data);
			tail->next->prev = tail;
			tail = tail->next;
		}
		list_size++;
	}

	//inserts an element at the beginning of list
	void push_front(int Data) {

		if (isEmpty()) {
			head = new Elem(Data);
			tail = head;
		}
		else {
			head->prev = new Elem(Data);
			head->prev->next = head;
			head = head->prev;
		}
		list_size++;
	}

	//deletes the last element in list
	void pop_back() {
		if (list_size == 0) throw runtime_error("Error in pop_back function: list is empty\n");
		if (list_size == 1) {
			delete head;
			head = NULL;
			tail = NULL;
		}
		else {
			Elem* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			current->next = NULL;
			delete tail;
			tail = current;
		}
		list_size--;
	}


	//deletes the first element in list
	void pop_front() {

		if (!isEmpty()) {
			Elem* tmp = head->next;
			delete head;
			head = tmp;
			if (head == NULL) tail = NULL;
			list_size--;
		}
		else throw runtime_error("Error in pop_front function: list is empty\n");
	}


	//Displays an element by index
	Elem* at(size_t index)
	{
		
			if (index >= list_size) {
				throw out_of_range("Error in at function: incorrect index");
			}
			else if (index < 0) {
				throw out_of_range("Error in at function: incorrect index");
			}
			else {
				size_t counter = 0;
				Elem* current = head;
				while (counter != index) {
					current = current->next;
					counter++;
				}
				return current;// ->data;
			}
	}

	//Replaces the element specified by the index with another specified element
	void set(int newdata, size_t index) {
		if (!isEmpty())
		{
			if (index >= list_size) {
				throw out_of_range("Error in set function: incorrect index");
			}
			else if (index < 0) {
				throw out_of_range("Error in set function: incorrect index");
			}
			else {
				size_t counter = 0;
				Elem* current = head;
				while (counter != index) {
					current = current->next;
					counter++;
				}
				current->data = newdata;
				cout << endl;
			}
		}
	}

	//inserts element by index between elements a(index) and b(index-1)
	void insert(int data, size_t index) {
		if (index == 0)
			push_front(data);
		else{
			try {
				Elem* a = at(index);
				Elem* b = a->prev;
				Elem* ins = new Elem(data);
				a->prev = ins;
				ins->next = a;
				b->next = ins;
				ins->prev = b;
				list_size++;
			}
			catch (out_of_range & exception) {
				throw out_of_range("Error in inset function: incorrect index");
			}
		}
	}

	//deletes element by index
	void remove(size_t index) {
		if (!isEmpty())
		{
			if (index > list_size)	throw out_of_range("Error in set function: incorrect index");
			else if (index < 0)		throw out_of_range("Error in set function: incorrect index");
			else if (index == 0)
			{
				pop_front();
			}
			else {
				try {
					Elem* cur = head;
					cur = at(index);
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					delete cur;
					list_size--;
				}
				catch (out_of_range & exception) {
					throw out_of_range("Error in inset function: incorrect index");
				}
			}
		}
	}
	//Displays the current data of list
	void print_to_console(){
		if (isEmpty())
			throw runtime_error("Error in print_to_console function: list is empty\n");
		else {
			cout << "List: ";
			Elem* current = head;
			while (current != NULL)
			{
				current->print();
				current = current->next;
			}
			cout << endl;
		}
	}

	//returns size of list
	size_t get_size() { cout << "Size of list: "; return list_size; }

	//checks if one list is contained in another
	bool contains(List* list2) {
		if (isEmpty())
			throw runtime_error("Error in contains function: list1 is empty\n");
		if (list2->isEmpty())
			throw runtime_error("Error in contains function: list2 is empty\n");
		Elem* tmp2 = list2->head;
		Elem* tmp1 = head;
		size_t counter = 0;
		while (tmp2 != NULL) {
			while (tmp1 != NULL) {
				if (tmp2->data == tmp1->data) {
					counter++;
					break;
				}
				else tmp1 = tmp1->next;
			}
			tmp2 = tmp2->next;
			tmp1 = head;
		}
		if (counter == list2->list_size) return true;
		else return false;
	}

	//Deletes list
	void clear()
	{
		while (!isEmpty())
			pop_front();
	}

	~List()
	{
		clear();
	}
};

int main() {
	
	
	/*
	List list1;
	cout << "isEmpty function test:" << endl;
	if (list1.isEmpty() == 0) cout << "List1 isn't empty" << endl;
	if (list1.isEmpty() == 1) cout << "List1 is empty" << endl << endl;
	cout << "print_to_console function test:" << endl;
	try{
		list1.print_to_console();
	}
	catch (exception & exception) {
		cout << exception.what() << endl;
	}
	cout << "get_size function test:" << endl;
	cout << list1.get_size() << endl << endl;
	cout << "push_front and push_back test + isEmpty, get_size and print_to_console test:" << endl;
	list1.push_back(9);
	list1.push_back(12);
	list1.push_back(15);
	list1.push_front(6);
	list1.push_front(3);
	if (list1.isEmpty() == 0) cout << "List1 isn't empty" << endl;
	if (list1.isEmpty() == 1) cout << "List1 is empty" << endl << endl;
	try {
		list1.print_to_console();
	}
	catch (exception & exception) {
		cout << exception.what() << endl;
	}
	cout << list1.get_size() << endl << endl;
	cout << "pop_front and pop_back test + get_size and print_to_console test:" << endl;
	list1.pop_back();
	list1.pop_front();
	try {
		list1.print_to_console();
	}
	catch (exception & exception) {
		cout << exception.what() << endl;
	}
	cout << list1.get_size() << endl << endl;
	cout << "at function test:" << endl;
	cout << "try to print element with index 1:" << endl;
	list1.at(1)->print();
	cout << endl << "try to print element with index 2:" << endl;
	list1.at(2)->print();
	try{
		cout<< endl << "try to print element with index 3:" << endl;
		list1.at(3)->print();
	}
	catch (exception& exception){
		cout << exception.what() << endl << endl;
	}
	cout << "set function test:";
	size_t index = 0;
	list1.set(30, index);
	list1.print_to_console();
	try {
		index = 3;
		list1.set(33, index);
	}
	catch (exception & exception) {
		cout << exception.what() << endl << endl;
	}
	cout << "clear function test:" << endl;
	list1.clear();
	if (list1.isEmpty() == 1) cout << "List1 is empty" << endl << endl;
	return 0;*/


	/*
	List list1;
	size_t index;
	list1.push_front(3); 
	list1.push_front(3);
	list1.push_front(6);
	list1.push_front(9);
	try {
		cout << "remove function test:" << endl;
		index = 2;
		list1.remove(index);
		list1.print_to_console();
		index = 3;
		list1.remove(index);
	}
	catch (exception & exception) {
		cout << exception.what() << endl << endl;
	}
	try {
		cout << "insert function test:" << endl;
		index = 2;
		list1.insert(33, index);
		list1.print_to_console();
		index = 4;
		list1.insert(66, index);
	}
	catch (exception & exception) {
		cout << exception.what() << endl << endl;
	}*/

/*
	cout << "contains function test:" << endl;
	List list1;
	size_t index;
	List list2;
	list1.push_front(3);
	list1.push_front(6);
	list1.push_front(9);
	list1.push_front(12);
	list1.push_front(15);
	cout << "List 1: ";
	list1.print_to_console();

	list2.push_front(3);
	list2.push_front(9);
	list2.push_front(44);
	cout << "List 2: ";
	list2.print_to_console();
	if (list1.contains(&list2) == 0) cout << "List 1 dosen't contain list 2" << endl << endl;
	if (list1.contains(&list2) == 1) cout << "List 1 contains list 2"  << endl << endl;

	list2.pop_front();
	cout << "List 1: ";
	list1.print_to_console();
	cout << "List 2: ";
	list2.print_to_console();
	if (list1.contains(&list2) == 0) cout << "List 1 dosen't contain list 2" << endl << endl;
	if (list1.contains(&list2) == 1) cout << "List 1 contains list 2" << endl<<endl;

	list2.push_front(15);
	cout << "List 1: ";
	list1.print_to_console();
	cout << "List 2: ";
	list2.print_to_console();
	if (list1.contains(&list2) == 0) cout << "List 1 dosen't contain list 2" << endl;
	if (list1.contains(&list2) == 1) cout << "List 1 contains list 2" << endl;*/
}