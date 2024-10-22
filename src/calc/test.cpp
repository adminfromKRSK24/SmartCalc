#include "ExampleModel.h"
#include <gtest/gtest.h>

#define EPS 1e-7

// test constructors

TEST(mathematics, test1) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("2.9+2.9");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (2.9+2.9), EPS);
}

TEST(mathematics, test2) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("1.4356789 - 2.245");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();

    ASSERT_NEAR(smodel.getresultDouble(), (1.4356789 - 2.245), EPS);
}

TEST(mathematics, test5) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("2.1 / (1.5 + 1.678)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (2.1 / (1.5 + 1.678)), EPS);
}

TEST(mathematics, test6) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("2.7856*(5.345-2.345)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (2.7856 * (5.345 - 2.345)), EPS);
}

TEST(mathematics, test7) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("(2^2)+(2^2)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (pow(2, 2) + pow(2, 2)), EPS);
}

TEST(mathematics, test8) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("sqrt(9)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (sqrt(9)), EPS);
}

//TEST(mathematics, test9) {
//    s21::Model smodel;
//    smodel.setinputDataTypeStringFromView("log(10)");
//    smodel.setresultTypeStringFromCalculate();
//    std::string res = smodel.getresultTypeStringFromCalculate();
//
//    ASSERT_NEAR(smodel.getresultDouble(), (log(10)), EPS);
//}

//TEST(mathematics, test12) {
//    s21::Calculator m;
//    m.SetString("ln2.718281828459045");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_NEAR(m.GetResult(), (log(2.718281828459045)), EPS);
//}

TEST(mathematics, test11) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("5.25-10.01");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (5.25 - 10.01), EPS);
}

TEST(mathematics, test12) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("9.45/3.26");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (9.45/3.26), EPS);
}

TEST(mathematics, test13) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("0*3");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (0*3), EPS);
}

TEST(mathematics, test14) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("-0");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (0), EPS);
}

TEST(mathematics, test15) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("sin(2.14/2.1)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (sin(2.14/2.1)), EPS);
}

TEST(mathematics, test16) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("sin(0)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (sin(0)), EPS);
}

TEST(mathematics, test17) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("(-sin(2.14/2.1))");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (-sin(2.14/2.1)), EPS);
}

TEST(mathematics, test18) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("cos(2.14)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (cos(2.14)), EPS);
}

TEST(mathematics, test19) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("cos(0)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (cos(0)), EPS);
}

TEST(mathematics, test20) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("cos(2.14/2.1)+(10.01)*(-1.1)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (cos(2.14/2.1)+(10.01)*(-1.1)), EPS);
}

TEST(mathematics, test21) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("tan(2.14/4.01)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (tan(2.14/4.01)), EPS);
}

TEST(mathematics, test22) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("atan(2.14/4.01)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (atan(2.14/4.01)), EPS);
}

TEST(mathematics, test23) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("asin(-0.91)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (asin(-0.91)), EPS);
}

//TEST(mathematics, test24) {
//    s21::Model smodel;
//    smodel.setinputDataTypeStringFromView("2^2^2^2");
//    smodel.setresultTypeStringFromCalculate();
//    std::string res = smodel.getresultTypeStringFromCalculate();
//
//    std::cout << res <<std::endl;
//
//    ASSERT_NEAR(smodel.getresultDouble(), (pow(2, pow(2, pow(2, 2)))), EPS);
//}

//TEST(mathematics, test25) {
//    s21::Model smodel;
//    smodel.setinputDataTypeStringFromView("4+4*5-23^3/6");
//    smodel.setresultTypeStringFromCalculate();
//    std::string res = smodel.getresultTypeStringFromCalculate();
//
//    ASSERT_NEAR(smodel.getresultDouble(), (4+4*5-23^3/6), EPS);
//}

TEST(mathematics, test26) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("23^3");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (pow(23, 3)), EPS);
}

TEST(mathematics, test27) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("3.56*4-0.7865/45.67+6");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (3.56*4-0.7865/45.67+6), EPS);
}

TEST(mathematics, test28) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("(4+4)*5-23^3/5");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), ((4 + 4) * 5 - pow(23, 3) / 5), EPS);
}

TEST(mathematics, test29) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("(3+4)*(sin(0.245))");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), ((3 + 4) * (sin(0.245))), EPS);
}

TEST(mathematics, test30) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("6/cos(35)+(6-76)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (6 / cos(35) + (6 - 76)), EPS);
}

TEST(mathematics, test31) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("4+4*(-4)-23^3/6");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (4 + 4 * (-4) - pow(23, 3) / 6), EPS);
}

TEST(mathematics, test32) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("(-6)+9.8^4");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (-6 + pow(9.8, 4)), EPS);
}

TEST(mathematics, test33) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("10mod5");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (fmod(10, 5)), EPS);
}

TEST(mathematics, test34) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("sin(5+1.4)+sin(-3)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();
    
    ASSERT_NEAR(smodel.getresultDouble(), (sin(+5 + 1.4) + sin(-3)), EPS);
}

TEST(mathematics, test35) {
    s21::Model smodel;
    smodel.setinputDataTypeStringFromView("sqrt(76.89*76.89+76.89)*cos(cos(76.89))*sin(76.89*4)*tan(76.89)");
    smodel.setresultTypeStringFromCalculate();
    std::string res = smodel.getresultTypeStringFromCalculate();

    ASSERT_NEAR(smodel.getresultDouble(), (-302.844933), EPS);
}

//TEST(infnan, test1) {
//    s21::Calculator m;
//    m.SetString("1/0");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_DOUBLE_EQ(m.GetResult(), (INFINITY));
//}
//
//TEST(infnan, test2) {
//    s21::Calculator m;
//    m.SetString("2mod0");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_TRUE(std::isnan(m.GetResult()));
//}
//
//TEST(infnan, test3) {
//    s21::Calculator m;
//    m.SetString("log(-10)");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_TRUE(std::isnan(m.GetResult()));
//}
//
//TEST(infnan, test4) {
//    s21::Calculator m;
//    m.SetString("ln(-10)");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_TRUE(std::isnan(m.GetResult()));
//}
//
//TEST(infnan, test5) {
//    s21::Calculator m;
//    m.SetString("sqrt(-10)");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_TRUE(std::isnan(m.GetResult()));
//}
//
//TEST(infnan, test6) {
//    s21::Calculator m;
//    m.SetString("0^(-1)");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_DOUBLE_EQ(m.GetResult(), (INFINITY));
//}
//
//TEST(infnan, test7) {
//    s21::Calculator m;
//    m.SetString("ln0");
//    m.CreatePolishNotation();
//    m.MakeCalculation();
//    ASSERT_DOUBLE_EQ(m.GetResult(), (-INFINITY));
//}

// TEST(checking, test1) {
//     s21::Calculator m;
//     std::string str{
//         "-3mod3-4.0^8.0+sin(+2)+(-2cos(2.0)*(asin(cos(17.6)+2.023))*1.69+9.0*(12*"
//         "3-tan(456.0/78.0)*7.0))*tan(ln(18.0)/43.134)+7.0^+0.2+8.0/"
//         "9mod9+sqrt(4)-3mod3-4.0^8.0+sin(+2)+(-2cos(2.0)*(asin(cos(17.6)+2.023))*"
//         "1.69+9.0*(12*3-tan(456.0/78.0)*7.0))*tan(ln(18.0)/43.134)+7.0^+0.2+8.0/"
//         "9mod9+sqrt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Length error: Input str is over 255 symbols");
//     }
// }

// TEST(checking, test2) {
//     s21::Calculator m;
//     std::string str{"1+cos(1+"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Number of brackers error: Incorrect input");
//     }
// }

// TEST(checking, test3) {
//     s21::Calculator m;
//     std::string str{"1+tyn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Sybmols error: Incorrect input");
//     }
// }

// TEST(checking, test4) {
//     s21::Calculator m;
//     std::string str{"cs(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test5) {
//     s21::Calculator m;
//     std::string str{"sn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test6) {
//     s21::Calculator m;
//     std::string str{"tn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test7) {
//     s21::Calculator m;
//     std::string str{"acs(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test8) {
//     s21::Calculator m;
//     std::string str{"asn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test9) {
//     s21::Calculator m;
//     std::string str{"atnn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test10) {
//     s21::Calculator m;
//     std::string str{"sqt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test11) {
//     s21::Calculator m;
//     std::string str{"l(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test12) {
//     s21::Calculator m;
//     std::string str{"lg(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test13) {
//     s21::Calculator m;
//     std::string str{"5md4"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test14) {
//     s21::Calculator m;
//     std::string str{")+(1-2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test15) {
//     s21::Calculator m;
//     std::string str{"+1-2*()"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test16) {
//     s21::Calculator m;
//     std::string str{"+1-2*(x+sin)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test17) {
//     s21::Calculator m;
//     std::string str{"+1-2*(x+sin(1))9.56"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test18) {
//     s21::Calculator m;
//     std::string str{".1+1-2*(x+sin(1))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test19) {
//     s21::Calculator m;
//     std::string str{"1+1-2*x+sin(1.)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test20) {
//     s21::Calculator m;
//     std::string str{"1+1-2*x.+sin(1)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test21) {
//     s21::Calculator m;
//     std::string str{"(1+1-2*x).(+sin(1))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test22) {
//     s21::Calculator m;
//     std::string str{"(1+1-2*x)+(+sin(1...3))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test23) {
//     s21::Calculator m;
//     std::string str{"(1+1-2*x)+(+sin(1.3.3))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test24) {
//     s21::Calculator m;
//     std::string str{"1+1.3e2.1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test25) {
//     s21::Calculator m;
//     std::string str{"1+1.3e(2+1)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test26) {
//     s21::Calculator m;
//     std::string str{"1+1.3e/2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test27) {
//     s21::Calculator m;
//     std::string str{"1+1.3emod3"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test28) {
//     s21::Calculator m;
//     std::string str{"1+39843902984083901248908423904890238485495849e+409"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp size error: Incorrect input");
//     }
// }

// TEST(checking, test29) {
//     s21::Calculator m;
//     std::string str{"1+2x2+4"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "x error: Incorrect input");
//     }
// }

// TEST(checking, test30) {
//     s21::Calculator m;
//     std::string str{"1+xsin(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "x error: Incorrect input");
//     }
// }

// TEST(checking, test31) {
//     s21::Calculator m;
//     std::string str{"1+sin(0.2)+"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test32) {
//     s21::Calculator m;
//     std::string str{"(1+sin(0.2)-)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test33) {
//     s21::Calculator m;
//     std::string str{"(1+sin(0.2)-*2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test34) {
//     s21::Calculator m;
//     std::string str{"(1+sin(0.2)-+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test35) {
//     s21::Calculator m;
//     std::string str{"(1+sin(0.2)**2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol (*/^) error: Incorrect input");
//     }
// }

// TEST(checking, test36) {
//     s21::Calculator m;
//     std::string str{"(1+sin(0.2)*2/)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol (*/^) error: Incorrect input");
//     }
// }

// TEST(checking, test37) {
//     s21::Calculator m;
//     std::string str{"mod5+2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test38) {
//     s21::Calculator m;
//     std::string str{"5*mod3+2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test39) {
//     s21::Calculator m;
//     std::string str{"5*(mod3+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test40) {
//     s21::Calculator m;
//     std::string str{"5*(4mod+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test41) {
//     s21::Calculator m;
//     std::string str{"5*acos"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "acos() error: Incorrect input");
//     }
// }

// TEST(checking, test42) {
//     s21::Calculator m;
//     std::string str{"asin*1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "asin() error: Incorrect input");
//     }
// }

// TEST(checking, test43) {
//     s21::Calculator m;
//     std::string str{"5+atan*1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "atan() error: Incorrect input");
//     }
// }

// TEST(checking, test44) {
//     s21::Calculator m;
//     std::string str{"5*cos"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "cos() error: Incorrect input");
//     }
// }

// TEST(checking, test45) {
//     s21::Calculator m;
//     std::string str{"(5+2)+cos(1)+sin"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "sin() error: Incorrect input");
//     }
// }

// TEST(checking, test46) {
//     s21::Calculator m;
//     std::string str{"(5+2)+cos(1)+05tan(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "tan() error: Incorrect input");
//     }
// }

// TEST(checking, test47) {
//     s21::Calculator m;
//     std::string str{"(5+2)+cos(1)+05sqrt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "sqrt() error: Incorrect input");
//     }
// }

// TEST(checking, test48) {
//     s21::Calculator m;
//     std::string str{"(5+2)+cos(1)+log"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "log() error: Incorrect input");
//     }
// }

// TEST(checking, test49) {
//     s21::Calculator m;
//     std::string str{"(5+2)+cos(1)+ln/5"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "ln() error: Incorrect input");
//     }
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

