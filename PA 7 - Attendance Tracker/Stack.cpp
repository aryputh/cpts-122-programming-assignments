#include "Stack.hpp"

Stack::Stack(std::vector<std::string> _stack)
{
	stack = _stack;
}

void Stack::push(std::string _newData)
{
	stack.push_back(_newData);
}

std::string Stack::pop()
{
	std::string lastElement = stack.back();
	stack.pop_back();

	return lastElement;
}

std::string Stack::peek()
{
	if (!stack.empty())
	{
		return stack.front();
	}
	else
	{
		return "N/A";
	}
}

bool Stack::isEmpty()
{
	return stack.empty();
}