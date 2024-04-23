#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <iostream>

class Stack
{
private:
	std::vector<std::string> stack;

public:
	Stack(std::vector<std::string> _stack = std::vector<std::string>());
	void push(std::string _newData);
	std::string pop();
	std::string peek();
	bool isEmpty();
};

#endif