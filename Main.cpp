#include <gtest/gtest.h>
#include "Calc.h"

//TEST()
//{
//	Calc calc;
//	EXPECT_EQ(0, calc.returnResult());
//}

int main(int argc, char* argv[])
{
	//testing::InitGoogleTest(&argc, argv);

	iCalc* calculator = new Calc;

	calculator->setString(" 4 d 30  +  20f - 2.2 * 2 /");
	cout << calculator->returnResult() << endl;

	IOperation* opr = new Sum;

	system("pause");
	//return RUN_ALL_TESTS();
}