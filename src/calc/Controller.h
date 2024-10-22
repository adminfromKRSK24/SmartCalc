#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "ExampleModel.h"

namespace s21{

class Controller {
    public:
    Controller(Model *m) : model(m){}
        ~Controller() = default;

//        void setInput();
//        std::string getInput();

//        void setResult();
//        std::string getResult();
        void setinputDataTypeStringFromView(std::string input);
        void setresultTypeStringFromCalculate();
        std::string getresultTypeStringFromCalculate();

    private:
        Model *model;

        std::string _input;
        std::string _result;
        double _res;
        std::string _error;
};

}




#endif // CONTROLLER_H
