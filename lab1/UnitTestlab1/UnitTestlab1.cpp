#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1/lab1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab1
{
	TEST_CLASS(UnitTestlab1)
	{
	public:
		
		List list;
		TEST_METHOD(e_constuctor)
		{
			Elem* tmp = new Elem(3);
			Assert::AreEqual(tmp->data, 3);
			Assert::IsNull(tmp->next);
			Assert::IsNull(tmp->prev);
		}
		TEST_METHOD(l_constuctor)
		{
			size_t tmp = 0;
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);
			Assert::AreEqual(list.list_size, tmp);
		}
		TEST_METHOD(isEmpty)
		{
			size_t tmp = 0;
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);
			Assert::AreEqual(list.list_size, tmp);
		}
		TEST_METHOD(not_isEmpty)
		{
			list.head = new Elem;
			list.tail = new Elem;
			list.head->next = list.tail;
			list.tail->prev = list.head;
			list.list_size = 2;
			Assert::IsFalse(list.isEmpty());
		}
		TEST_METHOD(at_correct_index)
		{
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Elem* a0 = list.at(0);
			Elem* a1 = list.at(1);
			Elem* a2 = list.at(2);
			Assert::AreEqual(a0->data, 1);
			Assert::AreEqual(a1->data, 2);
			Assert::AreEqual(a2->data, 3);

		}
		TEST_METHOD(at_incorrect_index)
		{
			try {
				Elem* inc = list.at(0);
			}
			catch (std::out_of_range &exception) {
				Assert::AreEqual("Error in at function: incorrect index", exception.what());
			}
		}
		TEST_METHOD(push_back)
		{
			size_t x = 2;
			list.list_size = 0;
			list.push_back(333);
			list.push_back(33);
			Assert::AreEqual(list.list_size, x);
		}
		TEST_METHOD(push_front)
		{
			size_t x = 2;
			list.list_size = 0;
			list.push_front(333);
			list.push_front(33);
			Assert::AreEqual(list.list_size, x);
		}
		TEST_METHOD(pop_back_empty)
		{
			try {
				list.pop_back();
			}
			catch (std::runtime_error &exception) {
				Assert::AreEqual("Error in pop_back function: list is empty\n", exception.what());
			}
		}
		TEST_METHOD(pop_front_empty)
		{
			try {
				list.pop_front();
			}
			catch (std::runtime_error & exception) {
				Assert::AreEqual("Error in pop_front function: list is empty\n", exception.what());
			}
		}
		TEST_METHOD(pop_front)
		{
			size_t x = 1;
			list.push_front(333);
			list.push_front(333);
			list.pop_front();
			Assert::AreEqual(list.list_size, x);

		}
		TEST_METHOD(pop_back)
		{
			size_t x = 1;
			list.push_front(333);
			list.push_front(333);
			list.pop_back();
			Assert::AreEqual(list.list_size, x);
		}
		TEST_METHOD(set_incorrect_index)
		{
			try{
				list.set(33, -1);
			}
			catch (const std::out_of_range& exception){
				Assert::AreEqual("Error in at function: incorrect index", exception.what());
			}
		}
		TEST_METHOD(set)
		{
			list.push_front(1);
			list.push_front(2);
			list.push_front(1);
			list.set(33, 1);
			Elem* tmp = list.at(1);
			Assert::AreEqual(tmp->data, 33);
		}

		TEST_METHOD(remove_empty)
		{
			try{
				list.remove(0);
			}
			catch (runtime_error & exception){
				Assert::AreEqual(exception.what(), "Error in pop_front function: list is empty\n");
			}
		}
		TEST_METHOD(remove_out_of_range)
		{
			try {
				list.push_front(1);
				list.remove(3);
			}
			catch (out_of_range & exception) {
				Assert::AreEqual(exception.what(), "Error in set function: incorrect index");
			}
		}
		TEST_METHOD(remove_first)
		{
			size_t size = 1;
			list.push_front(3);
			list.push_front(6);
			list.remove(0);
			Assert::AreEqual(list.list_size, size);
			Assert::AreEqual(list.head->data, 3);
		}
		TEST_METHOD(remove)
		{
			size_t size = 2;
			list.push_front(3);
			list.push_front(6);
			list.push_front(9);
			list.remove(1);
			Assert::AreEqual(list.list_size, size);
			Assert::AreEqual(list.head->data, 9);
			Assert::AreEqual(list.tail->data, 3);
		}

		TEST_METHOD(print_to_console) {
			try {
				list.print_to_console();
			}
			catch (runtime_error & exception) {
				Assert::AreEqual("Error in print_to_console function: list is empty\n", exception.what());
			}
		}

		TEST_METHOD(insert_zero_index)
		{
			size_t size = 1;
			list.insert(12, 0);
			Assert::AreEqual(list.list_size, size);
			Assert::AreEqual(list.head->data, 12);
		}

		TEST_METHOD(insert_incorrect_index)
		{
			try {
				list.push_front(3);
				list.insert(12, 3);
			}
			catch(out_of_range & exception){
				Assert::AreEqual("Error in inset function: incorrect index", exception.what());
			}
		}

		TEST_METHOD(insert)
		{
			size_t size = 3;
			list.push_front(3);
			list.push_front(6);
			list.insert(9, 1);
			Assert::AreEqual(list.list_size, size);
			Assert::AreEqual(list.head->next->data, 9);
		}

		TEST_METHOD(contains_list1_empty)
		{
			try{
				List list2;
				list.contains(&list2);
			}
			catch (runtime_error & exception){
				Assert::AreEqual("Error in contains function: list1 is empty\n", exception.what());
			}
		}

		TEST_METHOD(contains_list2_empty)
		{
			try {
				List list2;
				list.push_front(30);
				list.contains(&list2);
			}
			catch (runtime_error & exception) {
				Assert::AreEqual("Error in contains function: list2 is empty\n", exception.what());
			}
		}
		TEST_METHOD(contains_true)
		{
			List list2;
			list.push_front(2);
			list.push_front(8);
			list.push_front(3);
			list.push_front(6);
			list.push_front(0);

			list2.push_front(8);
			list2.push_front(3);
			//list2.push_front(44);

			Assert::IsTrue(list.contains(&list2));

		}
		TEST_METHOD(contains_false)
		{
			List list2;
			list.push_front(2);
			list.push_front(8);
			list.push_front(3);
			list.push_front(6);
			list.push_front(0);

			list2.push_front(8);
			list2.push_front(3);
			list2.push_front(44);

			Assert::IsFalse(list.contains(&list2));
		}
		TEST_METHOD(clear){
			list.push_front(3);
			list.push_front(6);
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}

		/*TEST_METHOD(get_size)
		{
			size_t size = 3;
			list.push_front(3);
			list.push_back(6);
			list.push_front(9);
			list.get_size();
			Assert::AreEqual(list.list_size, size);
		}*/

	};
}
