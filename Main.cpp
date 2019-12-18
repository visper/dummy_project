#include "Calc.h"
#include "utils.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

class ProjectTest : public ::testing::Test {

};

TEST_F(ProjectTest, Run) {

  iCalc* calculator = new Calc();

  calculator->setString(" 4 d 30  +  20f - 2.2 * 2 /");
  float actual = calculator->returnResult() ;
  float expected = 15.4;
  EXPECT_FLOAT_EQ(actual, expected);
}


TEST_F(ProjectTest, parseOperatorsTest) {

//  iCalc* calculator = new Calc();
//  calculator->setString(" 4 d 30  +  20f - 2.2 * 2 /");

  std::string input = " 4 d 30  +  20f - 2.2 * 2 /";
  auto operators = utils::ExtractOperators(input);

//  EXPECT_EQ(input , " 4 d 30    20f  2.2  2 ");
  EXPECT_EQ(operators ,
            std::vector<char>({'/', '*', '-', '+'}));
}

///home/developer/sdl/dev-006/dummy_project/Main.cpp:20: Failure
//      Expected: actual
//      Which is: 2.4666667
//To be equal to: expected
//      Which is: 15.4
//[  FAILED  ] ProjectTest.Run (0 ms)
//[ RUN      ] ProjectTest.parseOperatorsTest


///home/developer/sdl/dev-006/dummy_project/Main.cpp:31: Failure
//      Expected: input
//      Which is: " 4 d 30   20f 2.2 2 "
//To be equal to: " 4 d 30   20f 2.2 2"
///home/developer/sdl/dev-006/dummy_project/Main.cpp:33: Failure
//      Expected: operators
//      Which is: { '+' (43, 0x2B), '-' (45, 0x2D), '*' (42, 0x2A), '/' (47, 0x2F) }
//To be equal to: std::vector<char>({'/', '*', '-', '+'})
//      Which is: { '/' (47, 0x2F), '*' (42, 0x2A), '-' (45, 0x2D), '+' (43, 0x2B) }
}  // namespace testing
}  // namespace dev


