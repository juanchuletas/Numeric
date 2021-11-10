#include "polynomial.hpp"



int main(){
    int order = 1;
    int quadPts  = 5;
    Polynomial *p = new Polynomial(order,quadPts);



    delete [] p;

}