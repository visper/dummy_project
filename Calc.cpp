#include <functional>
#include <algorithm>

#include "Calc.h"
#include "utils.h"

vector<char> parseOperators(string& str,
                                     std::function<char(int)> operator_to_parse) {
   vector<char> operators_vector;

   for (int i = str.size() - 1; i >= 0; i--)
  {
    for (int j = 0; j < OPERATORS_QUANTITY; j++)
    {
      if (operator_to_parse(j) == str[i])
      {
        operators_vector.push_back(str[i]);
        str.erase(i, ERASE_SPACE);
      }
    }
  }
    return operators_vector;
}

void Calc::setString(string stringToParse)
{
	this->stringToParse = stringToParse;
}

float Calc::returnResult()
{

  parseInputString(); // Should provide error if bad string
  // Not obvious input and output value for parseInputString function

	for (int i = operatorsVector.size() - 1; i >= 0; i--)					//{TODO} operands sequence over 2 operation is faulty
	{
		int firtsOperandIndex = i;
		useOperation(operandsVector[firtsOperandIndex + SECOND_OPERAND_INDEX], operandsVector[i], operatorsVector[i]);
	}
	return result;
}

void Calc::useOperation(float a, float b, char sign)
{
	IOperation* operation = nullptr;

	if ('+' == sign)
	{
		operation = new Sum;
	}
	if ('-' == sign)
	{
		operation = new Sub;
	}
	if ('*' == sign)
	{
		operation = new Mul;
	}
	if ('/' == sign)
	{
		operation = new Div;
	}

	result = operation->calculate(a, b);
	reduceVectorSize(result);
	delete operation;
}

void Calc::parseInputString()
{
	//{TODO}
	//dividentEqualsZero(stringToParse);
  operatorsVector = utils::ExtractOperators(stringToParse);

	//{TODO}
	//parseIncorrectSymbols(stringToParse);
	parseOperands(stringToParse);					
}													

void Calc::parseIncorrectSymbols(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (('0' > str[i] || '9' < str[i]) && '.' != str[i] && str[i] != ' ')
		{
			str.erase(i, SECOND_OPERAND_INDEX);		//{TODO} WTF? )))
		}
	}
}



void Calc::parseOperands(string& str)
{
	int operandIndexStart;
	int operandIndexEnd;
	float tmpOperand;
	string tmpString;

	//{TODO}
	//vector<int> spaces;
	//
	//for (int i = str.size() - 1; 0 <= i; i--)
	//{
	//	if (str[i] == ' ')
	//		spaces.push_back(i);
	//}
	//
	//for (int i = 0; i < spaces.size(); i++)
	//{
	//	tmpString = stringToParse.substr(spaces[i], spaces[i + 1]);
	//	tmpOperand = stof(tmpString);
	//	operandsVector.push_back(tmpOperand);
	//}
	//
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if ('0' <= str[i] && '9' >= str[i])
		{
			operandIndexEnd = i;
			for (int j = i; ' ' != str[j] && 0 <= j; j--) // {TODO} Wrong symbols before operands causes a mistake
			{
				operandIndexStart = j;
				i = j;
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

void Calc::dividentEqualsZero(string& stringToParse)
{
	for (int i = 0; i < stringToParse.size(); i++)
	{
		#ifdef DEBUG
		ASSERT('/' == stringToParse[i] && '0' == stringToParse[i - 1] && ' ' == stringToParse[i - 2]);
		#endif // DEBUG
	}
}
 
float Sum::calculate(float a, float b) const
{
	return a + b;
}

float Sub::calculate(float a, float b) const
{
	return a - b;
}

float Mul::calculate(float a, float b) const
{
	return a * b;
}

float Div::calculate(float a, float b) const 
{
	return a / b;
}
