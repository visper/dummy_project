#include "Parser.h"

#include <iostream> //just for test
#include <string>

Parser::Parser(const std::vector <std::string>& line)
    : rawLines(line)
{}

void Parser::parse()
{   
    for(size_t i = 0; i < rawLines.size(); ++i) {
        //check for operator
        ///TODO: check Factory applicance
        if(rawLines[i] == std::string("+")) {
            Token t(TOper::ADD);
            tokens.push_back(t);
        } else if (rawLines[i] == std::string("-")) {
            Token t(TOper::SUB);
            tokens.push_back(t);
        } else if (rawLines[i] == std::string("*")) {
            Token t(TOper::MUL);
            tokens.push_back(t);
        } else if (rawLines[i] == std::string("/")) {
            Token t(TOper::DIV);
            tokens.push_back(t);
        } else { //check for number
          long double dd;
               dd = std::stod (rawLines[i]);

           Token t(dd);
           tokens.push_back(t);
        }
    }
}

const std::vector<Token> &Parser::getTokens()
{
    return tokens;
}
