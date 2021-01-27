#ifndef CUSTOM_LIST
#define CUSTOM_LIST

#include <stdexcept>
#include "node.h"
#include "iterator.h"


namespace custom_list
{
	template <typename T>
	class List
	{
	public:
		void Clear()
		{
			Node<T>* current_node = head;
			Node<T>* next_node = nullptr;

			while (current_node)
			{
				next_node = current_node->next;
				delete current_node;
				current_node = next_node;
			}
			head = nullptr;
		}

		void Copy(const List& trainings) {
			Node<T>** current = &head;
			// TODO: delete old list?
			for (auto it = trainings.begin(); it != trainings.end(); ++it)
			{
				*current = new Node<T>(*it);
				current = &(*current)->next;
			}
			
		}

		List(const List& trainings) {
			Copy(trainings);
		}

		List(List&& L) { head = L.head; L.head = nullptr; }

		List& operator= (const List& trainings) {
			if (this != &trainings) {
				Clear();
				Copy(trainings);
			}
			return *this;
		}

		List& operator= (List&& trainings) {
			if (this != &trainings) {
				Clear();
				head = trainings.head;
				trainings.head = nullptr;
			}
			return *this;
		}

		List() : head(nullptr) { };

		~List()
		{
			Clear();
		}

		size_t size()
		{
			size_t length = 0;
			for (Node<T>* current_node = head; current_node != nullptr; current_node = current_node->next)
				++length;
			return length;
		}

		T operator[](size_t index)
		{
			if (head == nullptr || index < 0)
				throw std::out_of_range("Index out of range");

			Node<T>* current_node = head;
			for (size_t current_idx = 0; current_idx < index; ++current_idx)
			{
				current_node = current_node->next;
				if (current_node == nullptr)
					throw std::out_of_range("Index out of range");
			}
			return current_node->value;
		}

		void push_front(T value)
		{
			Node<T>* el = new Node<T>(value);
			el->next = head;
			head = el;
		}

		

		T pop_front()
		{
			if (head == nullptr)
				throw std::out_of_range("The list is empty");
			T res = head->value;
			Node<T>* first = head;
			head = first->next;
			delete first;
			return res;
		}

		CustomIterator<T> begin() const { return CustomIterator<T>(head); }

		CustomIterator<T> end() const { return CustomIterator<T>(nullptr); }
	private:
		Node<T>* head = nullptr;
	};

}
#endif // !CUSTOM_LIST
