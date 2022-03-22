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

    //Errors
    try{
        cout << mat(3,6,'&','*') << endl;
    }
    catch (exception e){
        cout << "Even input Error!" << endl;
    }
    try{
        cout << mat(0,6,'&','*') << endl;
    }
    catch (exception e){
        cout << "Zero input Error!" << endl;
    }
    try{
        cout << mat(-3,6,'&','*') << endl;
    }
    catch (exception e){
        cout << "Negative input Error!" << endl;
    }
    try{
        cout << mat(3,6,32,'*') << endl;
    }
    catch (exception e){
        cout << "Symbol not in range Error!" << endl;
    }
    cout << endl;
    return 0;
}