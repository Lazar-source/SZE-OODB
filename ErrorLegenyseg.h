#pragma once
#include <string>
#include <exception>
class ErrorLegenyseg
{
private:
	std::string msg;
public:
	ErrorLegenyseg(std::string message) : msg(message)
	{}
	std::string getMsg()
	{
		return msg;
	}
};

