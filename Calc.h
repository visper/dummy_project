#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;				// {TODO} add tests

// ------ GLOBALS ------

const int OPERATORS_QUANTITY = 4;
const int ERASE_SPACE = 2;
const int SECOND_OPERAND_INDEX = 1;

// ---------------------

class IOperation
{
public:
	virtual float calculate(float, float) const = 0;
};

class Sum : public IOperation
{
public:
	float calculate(float, float) const override;
};

class Sub : public IOperation
{
public:
	float calculate(float, float) const override;
};

class Mul : public IOperation
{
public:
	float calculate(float, float) const override;
};

class Div : public IOperation
{
public:
	float calculate(float, float) const override;
};

class iCalc
{
public:
	virtual void setString(string) = 0;
	virtual float returnResult() = 0;
};

class Calc : public iCalc
{
	//{TODO} move string parsing to another class
	//		 use Calc class like fasade for IOperation
	//		 and IStringPrser
public:
	void setString(string);
	float returnResult();
	Calc() : stringToParse(""), operandsVector(0), operatorsVector(0), result(0) {};

private:
	string stringToParse;
	vector<float> operandsVector;
	vector<char> operatorsVector;
	float result;

	void parseInputString();
	void dividentEqualsZero(string&);
	void parseOperators(string&);
	void parseIncorrectSymbols(string&);
	void parseOperands(string&);
	void useOperation(float, float, char);
	char operatorsToParse(int);
	void reduceVectorSize(float);
	
};

// 2 3 + 2 * 4 + 5 -
