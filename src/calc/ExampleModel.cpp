#include "ExampleModel.h"

std::vector<std::string> NameFunctions{"sin", "cos", "tan", "log"}; // p5
std::vector<std::string> NameFunctionsFour{"asin", "acos", "atan", "sqrt", "ln"}; // p5
std::vector<std::string> NameFunctionsTwo{"(-", "(+"}; // p 4
std::vector<std::string> NameFunctionsPone{"+", "-"}; // p1
std::vector<std::string> NameFunctionsPtwo{"*", "/", "%"}; // p2
std::vector<std::string> NameFunctionsPtree{"^"}; // p3
std::vector<std::string> NameFunctionsPzeroL{"("}; // p0
std::vector<std::string> NameFunctionsPzeroR{")"}; // p0

std::map<std::string, std::function<double(double)>> functionMap = {
    {"sin",  [](double x) { return sin(x);  }},
    {"cos",  [](double x) { return cos(x);  }},
    {"tan",  [](double x) { return tan(x);  }},
    {"asin", [](double x) { return asin(x); }},
    {"acos", [](double x) { return acos(x); }},
    {"atan", [](double x) { return atan(x); }},
    {"sqrt", [](double x) { return sqrt(x); }},
    {"log",  [](double x) { return log(x);  }}
};

std::map<std::string, std::function<double(double, double)>> binaryOperatorMap = {
    {"+", [](double x, double y) { return x + y; }},
    {"-", [](double x, double y) { return y - x; }},
    {"*", [](double x, double y) { return x * y; }},
    {"/", [](double x, double y) { return y / x; }},
    {"^", [](double x, double y) { return pow(y, x); }},
    {"%", [](double x, double y) { return fmod(y, x); }}
};

void s21::Parser::ValidatorExpresion() {

    for (int i = 0; i < _inputStringAfterGeometric.size() - 1; ++i) {
        
        bool tmp;

        tmp = checkTokenAdjacency(_inputStringAfterGeometric[i].tValue, _inputStringAfterGeometric[i+1].tValue);

        if (tmp == false) {
            throw s21::MyException("zalypa");
        }
    }
}

namespace s21{

void Parser::SetInputString(std::string inputString) {
    _inputString = inputString;
}

std::vector<ParsingToken> Parser::getOutputResult() {
    std::vector<ParsingToken> tmp;

    tmp = this->_inputStringAfterGeometric;

    return tmp;
}

void PrintInputStringOnGeometric(std::vector<ParsingToken> inputVector) {

   for (auto element : inputVector) {
       std::cout << "_inputStringAfterGeometric Index = " << element.nIndex << std::endl;
       std::cout << "_inputStringAfterGeometric Type = " << element.tValue << std::endl;
       std::cout << "_inputStringAfterGeometric Priprity = " << element.pValue << std::endl;
       std::cout << "_inputStringAfterGeometric Value = " << element.Value << std::endl;
       std::cout << std::endl;
   }
}


std::string Parser::getInputString() {

    std::string tmp = _inputString;

    return tmp;
}

void Parser::ParsingInputStringOnGeometric3() {
    int indexInputString = 0;

    while (indexInputString < _inputString.length()) {

        std::string tmp;

        tmp = _inputString.substr(indexInputString, 3);
        
        for (size_t indexNameFunctions = 0; indexNameFunctions < 3; indexNameFunctions++) {
            if (tmp == NameFunctions[indexNameFunctions] && _inputString[indexInputString-1] != 'a') {
                ParsingToken temp{indexInputString, tFunction, pFifth, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }
        }
        
        indexInputString++;
    }
}

void Parser::ParsingInputStringOnGeometric4() {
    int indexInputString = 0;

    while (indexInputString < _inputString.length()) {

        std::string tmp, tmp2;

        tmp = _inputString.substr(indexInputString, 4);
        tmp2 = _inputString.substr(indexInputString, 2);
        
        for (size_t indexNameFunctionsFour = 0; indexNameFunctionsFour < 5; indexNameFunctionsFour++) {
            if (tmp == NameFunctionsFour[indexNameFunctionsFour]) {
                ParsingToken temp{indexInputString, tFunction, pFifth, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }
            
            if (tmp2 == NameFunctionsFour[indexNameFunctionsFour]) {
                ParsingToken temp{indexInputString, tFunction, pFifth, tmp2};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }
        }
        
        indexInputString++;
    }
}

void Parser::ParsingInputStringOnGeometric2() {
    int indexInputString = 0;

    while (indexInputString < _inputString.length()) {

        std::string tmp;

        tmp = _inputString.substr(indexInputString, 2);
        
        for (size_t indexNameFunctionsTwo = 0; indexNameFunctionsTwo < 2; indexNameFunctionsTwo++) {
            if (tmp == NameFunctionsTwo[indexNameFunctionsTwo]) {
                ParsingToken temp{indexInputString+1, tUnaryOperator, pFourth, "~"};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }
        }
        
        indexInputString++;
    }
}

void Parser::ParsingInputStringOnGeometric1() {
    int indexInputString = 0;

    while (indexInputString < _inputString.length()) {

        std::string tmp;

        tmp = _inputString.substr(indexInputString, 1);
        
        for (size_t indexNameFunctionsOne = 0; indexNameFunctionsOne < 7; indexNameFunctionsOne++) {

            if (indexNameFunctionsOne < NameFunctionsPone.size() && tmp == NameFunctionsPone[indexNameFunctionsOne] && indexInputString > 0 && _inputString[indexInputString-1] != '(') {
                ParsingToken temp{indexInputString, tBinaryOperator, pFirst, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }

            if (indexNameFunctionsOne < NameFunctionsPtwo.size() && tmp == NameFunctionsPtwo[indexNameFunctionsOne]) {
                ParsingToken temp{indexInputString, tBinaryOperator, pSecond, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }


            if (indexNameFunctionsOne < NameFunctionsPtree.size() && tmp == NameFunctionsPtree[indexNameFunctionsOne]) {
                ParsingToken temp{indexInputString, tBinaryOperator, pThird, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }

            if (indexNameFunctionsOne < NameFunctionsPzeroL.size() && tmp == NameFunctionsPzeroL[indexNameFunctionsOne]) {
                ParsingToken temp{indexInputString, tLBracket, pZero, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }        
            
            if (indexNameFunctionsOne < NameFunctionsPzeroR.size() && tmp == NameFunctionsPzeroR[indexNameFunctionsOne]) {
                ParsingToken temp{indexInputString, tRBracket, pZero, tmp};
                _inputStringAfterGeometric.push_back(temp);
                break;   
            }            
            }
        
        indexInputString++;
    }
}

void Parser::ParsingInputStringOnDigits() {
    int indexInputString = 0;

    while (indexInputString < _inputString.length()) {

        if ((isdigit(_inputString[indexInputString]) != 0) || (_inputString[indexInputString] == '.')) {
            int indexNum = indexInputString;

            std::string tmp;

            while ((isdigit(_inputString[indexInputString]) != 0) || (_inputString[indexInputString] == '.')) {
                indexInputString++;
            }

            tmp = _inputString.substr(indexNum, indexInputString - indexNum);

            ParsingToken temp{indexNum, tNumber, pZero, tmp};
            _inputStringAfterGeometric.push_back(temp);
            indexInputString--;           
        }

        indexInputString++;   
    }

}

void Parser::SortVector() {
    std::sort(_inputStringAfterGeometric.begin(), _inputStringAfterGeometric.end(), SortnIndex());
}

void Parser::countBracket() {
    int i = 0;
    int j = 0;

    for (auto element : _inputStringAfterGeometric) {
        if (element.tValue == tLBracket) {
            i++; 
        } else if (element.tValue == tRBracket) {
            j++;
        }
    }

    if (i != j) { 
        throw s21::MyException("zalypa");
    }
}

void Polish::getInputVectorParser(std::vector<ParsingToken> InputVector) {
    _inputString = InputVector;
}

void Polish::isDigits(ParsingToken tmp) {
    if (tmp.tValue == tNumber) {
        _outputString.push_back(tmp);
    }
}

void Polish::isBracket(ParsingToken tmp) {
    if (tmp.tValue == tLBracket) {
        tmpOperations.push(tmp);
    } else if (tmp.tValue == tRBracket) {
        while (tmpOperations.top().tValue != tLBracket) {
            _outputString.push_back(tmpOperations.top());
            tmpOperations.pop();
        }

        if (tmpOperations.top().tValue == tLBracket) {
            tmpOperations.pop();
        }
    }

}

void Polish::priorityOperations(ParsingToken tmp) {
    if (tmp.tValue == tFunction || tmp.tValue == tUnaryOperator || tmp.tValue == tBinaryOperator) {
        if (tmpOperations.empty() == true) {
            tmpOperations.push(tmp);
        }

        if (tmp.pValue > tmpOperations.top().pValue) {
            tmpOperations.push(tmp);
        } else if (tmp.pValue <= tmpOperations.top().pValue) {
            while (tmp.pValue <= tmpOperations.top().pValue) {
                _outputString.push_back(tmp);
                tmpOperations.pop();
            }
            
            tmpOperations.push(tmp);
        }
    }
        
}

void Polish::isEmptyTrueOperations() {
    if (tmpOperations.empty() != true) {
        while (tmpOperations.empty() != true) {
            _outputString.push_back(tmpOperations.top());
            tmpOperations.pop();
        }
    }
}

void Polish::transformationPolish() {
    
    for (auto tmp : _inputString) {

        if (tmp.tValue == tNumber) {
            _outputString.push_back(tmp);
        } else
            
        if (tmp.tValue == tLBracket) {
            tmpOperations.push(tmp);
        } else if (tmp.tValue == tRBracket) {
            

            while ((tmpOperations.empty() != true) && (tmpOperations.top().tValue != tLBracket)) {
                _outputString.push_back(tmpOperations.top());
                tmpOperations.pop();
            }

            if (tmpOperations.top().tValue == tLBracket) {
                tmpOperations.pop();
            }
        } else


        

        if (tmp.tValue == tFunction || tmp.tValue == tBinaryOperator || tmp.tValue == tUnaryOperator) {
            if (tmpOperations.empty() == true) {
                tmpOperations.push(tmp);
            } else

            if ((tmpOperations.empty() != true) && (tmp.pValue > tmpOperations.top().pValue)) {
                tmpOperations.push(tmp);
            } else
            
            if ((tmpOperations.empty() != true) && (tmp.pValue <= tmpOperations.top().pValue)) {
                    
                    while ((tmpOperations.empty() != true) && (tmp.pValue <= tmpOperations.top().pValue)) {
                        _outputString.push_back(tmpOperations.top());
                        tmpOperations.pop();
                    }
                
                    tmpOperations.push(tmp);
            }
        }
    }

    this->isEmptyTrueOperations();
}

std::vector<ParsingToken> Polish::getOutputVectorPolish() {
    std::vector<ParsingToken> result = _outputString;

    return result;
}

void Calculate::getInputDataAfterPolish(std::vector<ParsingToken> inputDataAfterPolish) {

    _inputDataAfterPolish = inputDataAfterPolish;
}

double Calculate::result() {

    double result = 0;

    for (auto element : _inputDataAfterPolish) {
        if (element.tValue == tNumber) {
            _tmpNumbers.push(std::stod(element.Value));
            // std::cout << "=" << _tmpNumbers.top() << std::endl; // удалить
        } else if (element.tValue == tFunction) {

            // Пример строки содержащей имя функции
            std::string functionName = element.Value;

            // Проверяем, есть ли такая функция в ассоциативном массиве и вызываем её
            if (functionMap.find(functionName) != functionMap.end()) {
                result = functionMap[functionName](_tmpNumbers.top());
                _tmpNumbers.pop();
                _tmpNumbers.push(result);
            }

        } else if (element.tValue == tUnaryOperator) {
            result = (_tmpNumbers.top() * -1);
            _tmpNumbers.pop();
            _tmpNumbers.push(result);
        } else if (element.tValue == tBinaryOperator) {

            // Пример строки содержащей имя функции
            std::string functionName = element.Value;

            // Проверяем, есть ли такая функция в ассоциативном массиве и вызываем её
            if (binaryOperatorMap.find(functionName) != binaryOperatorMap.end()) {
                double x = _tmpNumbers.top(); _tmpNumbers.pop();
                double y = _tmpNumbers.top(); _tmpNumbers.pop();
                
                result = binaryOperatorMap[functionName](x, y);

                _tmpNumbers.push(result);
            }            
        }
    }

    return result;
}

void Model::setinputDataTypeStringFromView(std::string input) {
    _inputDataTypeStringFromView = input;
}

// std::string Model::getinputDataTypeStringFromView() {
//     std::string res;

//     res = _inputDataTypeStringFromView;

//     return res;
// }

void Model::setresultTypeStringFromCalculate() {
    s21::Parser string1;
    string1.SetInputString(_inputDataTypeStringFromView);

    std::string tmp;
    tmp = string1.getInputString();

    string1.ParsingInputStringOnGeometric4();
    string1.ParsingInputStringOnGeometric3();
    string1.ParsingInputStringOnGeometric2();
    string1.ParsingInputStringOnGeometric1();
    string1.ParsingInputStringOnDigits();
    string1.SortVector();
    string1.countBracket();
    string1.ValidatorExpresion();


    s21::Polish test;
    test.getInputVectorParser(string1.getOutputResult());
    test.transformationPolish();

    s21::Calculate res;
    res.getInputDataAfterPolish(test.getOutputVectorPolish());
    _resultDouble = res.result();


    std::ostringstream oss;
    oss << _resultDouble;
    _resultTypeStringFromCalculate = oss.str();
}

std::string Model::getresultTypeStringFromCalculate() {
    std::string res;

    res = _resultTypeStringFromCalculate;

    return res;
}



double Model::getresultDouble() {
    double res = 0;

    res = _resultDouble;

    return res;
}

}

bool s21::checkTokenAdjacency(Type first, Type second) {
    return kAdjacencyMatrix_[first][second];
}
