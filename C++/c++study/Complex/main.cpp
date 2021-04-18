#include <iostream>
using namespace std;

#include "complex.cpp"

int main(){
    Complex c1(1,3),c2;
    c2=c1;
    c2.Show();
    
    return 0;
}