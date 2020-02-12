#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>
using namespace std;


class Exception : public exception 
{
	string msg;

public:
	
	Exception(const string& msg)
	{
		this->msg = msg;
	}

	virtual const char *what()
	{
		return msg.c_str();
	}
};

#endif
