//
// Created by coastcao(操海兵) on 2019-09-03.
//

#include<iostream>
int sum(int a, ...){
    int *temp = &a, sum=0;
    //++temp;
    for (int i = 0; i < a; ++i)
        sum+=*temp++;
    return sum;
}
int main(){
    std::cout<<sum(4, 1, 2, 3, 4)<<std::endl;
    return 0;
}
