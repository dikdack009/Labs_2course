#ifndef CUSTOM_ITERATOR
#define CUSTOM_ITERATOR

#include "node.h"

namespace custom_list
{
	template <typename T>
	class CustomIterator : public std::iterator<std::forward_iterator_tag, Node<T>>
	{
		Node<T>* itr;
	public:
		CustomIterator(Node<T>* head) : itr(head) { }
		CustomIterator& operator++ () {
			if (itr == nullptr)
				throw(std::out_of_range("End of list"));
			itr = itr->next; return *this; 
		}	// prefix ++
		T& operator*() { return itr->value; }
		bool operator==(const CustomIterator& other) const { return itr == other.itr; }
		bool operator!=(const CustomIterator& other) const { return itr != other.itr; }
		T* operator->() { return &itr->value; }
	};
}

#endif // !CUSTOM_ITERATOR
