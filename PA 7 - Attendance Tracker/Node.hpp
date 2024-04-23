#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
	T data;
	Node<T>* nextPtr;

public:
	Node(T _data, Node<T>* _nextPtr = nullptr);

	Node<T>* getNextPtr() const;
	T* getData();

	void setNextPtr(Node<T>* _newData);
};

template<class T>
Node<T>::Node(T _data, Node<T>* _nextPtr)
{
	data = _data;
	nextPtr = _nextPtr;
}

template<class T>
Node<T>* Node<T>::getNextPtr() const
{
	return nextPtr;
}

template<class T>
T* Node<T>::getData()
{
	return &data;
}

template<class T>
void Node<T>::setNextPtr(Node<T>* _newPtr)
{
	nextPtr = _newPtr;
}

#endif