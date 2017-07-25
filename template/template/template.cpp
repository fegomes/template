// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <math.h>

#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>

enum etype {
	tint = 0,
	tstring = 1,
	tdouble = 2
};

template < etype t >
class type {
public:
	type() {}
	virtual ~type() {}
};

template <>
class type <etype::tint> {
public:
	type(int v) : value(std::move(v)) {}
	virtual ~type() {}
	
	std::string ctype() { return "int"; }
	std::string str() { return boost::lexical_cast<std::string>(value); }

	void increase(int v) {
		value += v;
	}

	void decrease(int v) {
		value -= v;
	}

public:
	int value;
};

template <>
class type <etype::tstring> {
public:
	type(std::string v) : value(std::move(v)) {}
	virtual ~type() {}

	std::string ctype() { return "string"; }
	std::string str() { return value; }


public:
	std::string value;
};

template <>
class type <etype::tdouble> {
public:
	type(double v) : value(std::move(v)) {}
	virtual ~type() {}

	std::string ctype() { return "double"; }
	std::string str() { return boost::lexical_cast<std::string>(value); }

	int round() {
		return (int) lround(value);
	}

	int truncate() {
		return (int) trunc(value);
	}
public:
	double value;
};

int main()
{
	type<etype::tint> age = 28;
	type<etype::tstring> name = "Fernando";
	type<etype::tdouble> height = 1.66;

	std::cout << age.str() << "-"<< age.ctype() << std::endl;
	std::cout << name.str() << "-" << name.ctype() << std::endl;
	std::cout << height.round() << "-" << height.truncate() << std::endl;

	int pause;
	std::cin >> pause;

	return 0;
}

