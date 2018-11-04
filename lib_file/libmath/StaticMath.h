//
// Created by coast on 18-11-4.
//

#ifndef CPP_PRIMER_PLUS_STATICMATH_H
#define CPP_PRIMER_PLUS_STATICMATH_H
class StaticMath {
public:
    StaticMath(){}; // must be implemented (in header or source file)
    ~StaticMath(){};  // as above

    static double add(double a, double b);
    static double sub(double a, double b);
    static double mul(double a, double b);
    static double div(double a, double b);

    void print();
};
#endif //CPP_PRIMER_PLUS_STATICMATH_H