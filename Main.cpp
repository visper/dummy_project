#include "Calc.h"

int main()
{
	iCalc* calculator = new Calc;

	calculator->setString(" 4 d 30  +  20f - 2.2 *");
	cout << calculator->returnResult() << endl;

	system("pause");
}