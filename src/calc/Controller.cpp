#include "Controller.h" 

void s21::Controller::setinputDataTypeStringFromView(std::string input) {
    model->setinputDataTypeStringFromView(input);
};

void s21::Controller::setresultTypeStringFromCalculate(){
    model->setresultTypeStringFromCalculate();
}

std::string s21::Controller::getresultTypeStringFromCalculate(){
    return model->getresultTypeStringFromCalculate();
}

