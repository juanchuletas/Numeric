#include "polynomial.hpp"


Polynomial::Polynomial(){
    //std::cout<<"Polynomial: Default Constructor\n";
}
Polynomial::Polynomial(int _order, int _quadPts)
: npts{_quadPts},order{_order+1}{
    //std::cout<<"Polynomial: Constructor\n";
    x = new double[npts];
}
Polynomial::~Polynomial(){
    //std::cout<<"Polynomial: Destructor\n";
    delete [] x;
}

int Polynomial::getOrder(){
    return order;
}
void Polynomial::set(int _order, int _quadPts){
    order = _order+1;
    npts = _quadPts;
    x = new double[npts];
    dx = new double[npts];
}
