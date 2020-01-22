#pragma once
#include <string>
#include <exception>
class ErrorTartalekos
{
private:
	std::string msg;
public:
	ErrorTartalekos(std::string message) : msg(message)
	{}
	std::string getMsg()
	{
		return msg;
	}
};

