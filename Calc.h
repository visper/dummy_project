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

class iCalc
{
public:
	virtual void setString(string) = 0;
	virtual float returnResult() = 0;
};

class Calc : public iCalc
{
public:
	void setString(string);
	float returnResult();

private:
	string stringToParse;
	vector<float> operandsVector;
	vector<char> operatorsVector;
	float result;

	void parseInputString();
	void parseOperators(string&);
	void parceOperands(string&);

	float sum(float a, float b) { return a + b; };
	float sub(float a, float b) { return a - b; };
	float mul(float a, float b) { return a * b; };
	float div(float a, float b) { if (b == 0.0) throw runtime_error("fuckin' idiot!"); else return a / b; } //error code is better here
	
	char operatorsToParse(int);
	void reduceVectorSize(float);
};

// 2 3 + 2 * 4 + 5 -