#include "Calc.h"

void Calc::setString(string stringToParse)
{
	this->stringToParse = stringToParse;
}

float Calc::returnResult()
{
	float tmpOperand;

	parseInputString();

	for (int i = operatorsVector.size() - 1; i >= 0; i--)					//{TODO} operands sequence over 2 operation is faulty
	{
		if ('+' == operatorsVector[i])
		{
			tmpOperand = sum(operandsVector[i + SECOND_OPERAND_INDEX], operandsVector[i]);
			reduceVectorSize(tmpOperand);
		}
		else if ('-' == operatorsVector[i])
		{
			tmpOperand = sub(operandsVector[i + SECOND_OPERAND_INDEX], operandsVector[i]);
			reduceVectorSize(tmpOperand);
		}
		else if ('*' == operatorsVector[i])
		{
			tmpOperand = mul(operandsVector[i + SECOND_OPERAND_INDEX], operandsVector[i]);
			reduceVectorSize(tmpOperand);
		}
		else
		{
			tmpOperand = div(operandsVector[i + SECOND_OPERAND_INDEX], operandsVector[i]);
			reduceVectorSize(tmpOperand);
		}

		result = tmpOperand;
	}

	if (1 < operandsVector.size())
	{
		throw runtime_error("incorrec calculation");
	}
	else
	{
		result = operandsVector[0];						//Should be the only in the vector
		return result;
	}
}

void Calc::parseInputString()
{
	parseOperators(stringToParse);					//Call sequence should be like this
	parceOperands(stringToParse);					//parseOperators removes operators from the string
}													//and prepares for further parsing

void Calc::parseOperators(string& str)
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < OPERATORS_QUANTITY; j++)
		{
			if (operatorsToParse(j) == str[i])
			{
				operatorsVector.push_back(str[i]);
				str.erase(i, ERASE_SPACE);	
			}
		}
	}
}

void Calc::parceOperands(string& str)
{
	int operandIndexStart;
	int operandIndexEnd;
	float tmpOperand;
	string tmpString;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if ('0' <= str[i] && '9' >= str[i])
		{
			operandIndexEnd = i;
			for (int j = i; 0 <= j && str[j] != ' '; j--) // {TODO} Wrong symbols before operands causes a mistake
			{
				operandIndexStart = j;
				i = j;								//This allows to "jump" over oparends found and reduces loop's iterations
			}
			
			tmpString = stringToParse.substr(operandIndexStart, operandIndexEnd);
			tmpOperand = stof(tmpString);
			operandsVector.push_back(tmpOperand);
		}
	}
} 

char Calc::operatorsToParse(int index)
{
	char operators[OPERATORS_QUANTITY] = { '+', '-', '*', '/' };
	return operators[index];
}

void Calc::reduceVectorSize(float f)
{
	operandsVector.pop_back();
	operandsVector.pop_back();
	operandsVector.push_back(f);
}
 