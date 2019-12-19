#include "Token.h"

Token::Token(const bool is_number, const TOper::Operand opr, const long double num)
    : is_num_(is_number)
{
    if(is_num_) {
        number_ = num;
        operator_ = TOper::NONE;
    } else {
        operator_ = opr;
        number_ = 0; //default
    }
}

Token::Token(const long double num)
    : is_num_(true)
    , number_(num)
    , operator_(TOper::NONE)
{}

Token::Token(const TOper::Operand opr)
    : is_num_(false)
    , number_(0)
    , operator_(opr)
{}

TOper::Operand Token::getOperand()
{
    return operator_;
}

long double Token::getNumber()
{
    return number_;
}

bool Token::is_number()
{
    return is_num_;
}
