#ifndef NODE
#define NODE

namespace custom_list
{
	template <typename T>
	struct Node
	{
		T value;
		Node<T>* next;

		Node(T value_) : value(value_), next(nullptr) { }
	};
}

#endif // !NODE
