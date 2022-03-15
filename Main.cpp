#include "mat.hpp"
#include<iostream>

using namespace ariel;

int main(){
    //normal carpet
    cout << "5x5 Carpet:" << endl;
    cout << mat(5,5,'@','~') << endl;
    cout << endl;
    //row =1
    cout << "5x1 Carpet:" << endl;
    cout << mat(5,1,'#','~') << endl;
    cout << endl;
    //column = 1
    cout << "1x5 Carpet:" << endl;
    cout << mat(1,5,'#','~') << endl;
    cout << endl;
    //row and col = 1:
    cout << "1x1 Carpet:" << endl;
    cout << mat(1,1,'#','~') << endl;
    cout << endl;
    return 0;
}