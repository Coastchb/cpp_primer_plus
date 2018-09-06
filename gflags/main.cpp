// Created by Coast Cao(Coastchb@sina.com) on 2018/9/6
#include <gflags/gflags.h>
#include <iostream>

DEFINE_string(message, "Hello,world", "message to show");
int main(int argc, char * argv[]){
    google::SetUsageMessage("Example of gflags");
    google::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << FLAGS_message << std::endl;
}