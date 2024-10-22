#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctype.h>
#include <algorithm>
#include <stack>
#include <functional>
#include <map>
#include <cmath>
#include <sstream>

namespace s21{

enum Type {  
  tNumber,
  tLBracket,
  tRBracket,
  tUnaryOperator,
  tBinaryOperator,
  tFunction,
};

enum Priority {
  pZero,
  pFirst,
  pSecond,
  pThird,
  pFourth,
  pFifth,
};

typedef struct ParsingToken {
    int nIndex;
    Type tValue;
    Priority pValue;
    std::string Value;
} ParsingToken;

static constexpr bool kAdjacencyMatrix_[tFunction+1][tFunction+1] = {
    {0, 0, 1, 0, 1, 0},  // tNumber
    {1, 0, 1, 0, 0, 1},  // tLBracket
    {1, 0, 1, 0, 1, 1},  // tRBracket
    {0, 1, 0, 1, 0, 0},  // tUnaryOperator
    {1, 1, 0, 0, 0, 1},  // tBinaryOperator
    {0, 1, 0, 0, 0, 0},  // tFunction
};

bool checkTokenAdjacency(Type first, Type second);

class MyException : public std::exception {
private:
    std::string str_error_;

public:
    explicit MyException(const std::string &str) : str_error_(str) {}
    ~MyException(){};
    std::string GetErorr() { return str_error_; }
};

struct SortnIndex
{
    bool operator()(const ParsingToken& index1, const ParsingToken& index2)
    {
        return index1.nIndex < index2.nIndex;
    }
};

void PrintInputStringOnGeometric(std::vector<ParsingToken> inputVector);

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    void SetInputString(std::string inputString);
    void PrintInputStirng();
    void ParsingInputStringOnGeometric1();
    void ParsingInputStringOnGeometric2();
    void ParsingInputStringOnGeometric3();
    void ParsingInputStringOnGeometric4();
    void ParsingInputStringOnDigits();
    void SortVector();
    void ValidatorExpresion();
    std::vector<ParsingToken> getOutputResult();
    void countBracket();

    void PrintInputStringOnGeometric();

    bool ParsingOnHaveFunctionIndex(size_t index);
    std::string Substring(int fromIndex);
    std::string getInputString();
private:

    std::string _inputString;
    std::vector<ParsingToken> _inputStringAfterGeometric;
};


class Polish {
    public:
        Polish() = default;
        ~Polish() = default;
        
        void getInputVectorParser(std::vector<ParsingToken> InputVector);
        std::vector<ParsingToken> getOutputVectorPolish();
        void PrintInputStirng();
        void PrintOutputString();
        void isDigits(ParsingToken tmp);
        void isBracket(ParsingToken tmp);
        void priorityOperations(ParsingToken tmp);
        void isEmptyTrueOperations();
        void transformationPolish();


    private:
        std::vector<ParsingToken> _inputString;
        std::vector<ParsingToken> _outputString;
        std::stack<ParsingToken> tmpOperations;
};

class Calculate {
    public:
        Calculate() = default;
        ~Calculate() = default;

        void getInputDataAfterPolish(std::vector<ParsingToken> inputDataAfterPolish);
        double result();

    private:
        std::vector<ParsingToken> _inputDataAfterPolish;
        std::stack<double> _tmpNumbers;
        std::string _result;
};

class Model {
    public:
        Model() = default;
        ~Model() = default;

        void setinputDataTypeStringFromView(std::string input);
        // std::string getinputDataTypeStringFromView();
        void setresultTypeStringFromCalculate();
        std::string getresultTypeStringFromCalculate();
        double getresultDouble();



    private:
        std::string _inputDataTypeStringFromView;
        std::string _resultTypeStringFromCalculate;
        double _resultDouble;
};
}

#endif // EXAMPLEMODEL_H
