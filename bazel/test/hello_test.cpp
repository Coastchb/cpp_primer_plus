#include "lib/weather.h"
#include "gtest/gtest.h"

TEST(HelloTEST, getWeather){
    EXPECT_EQ(print_weather(), "It is sunny today!\n");
}