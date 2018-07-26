//
// Created by 操海兵 on 16/05/2018.
//

#ifndef CH_9_NAMESP_H
#define CH_9_NAMESP_H

#include <string>
//using namespace std;

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amout;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}

#endif //CH_9_NAMESP_H
