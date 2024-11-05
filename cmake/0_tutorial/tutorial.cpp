//
// Created by coastcao(操海兵) on 2019-09-11.
//

// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#include "func1.h"
#ifdef USE_MYMATH_OPTION
#include "MathFunctions.h"
#endif

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);

#ifdef USE_MYMATH_OPTION
    double outputValue = my_sqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif

    fprintf(stdout,"The square root of %g is %g\n",
            inputValue, outputValue);

    fun1();
    return 0;
}