#include "integrate.hpp"


double Numeric::Integral::compute(Polynomial &a, Polynomial &b, double *w,int qdpts){
    double integral = 0.0;
    for(int i=0; i<qdpts; i++){
        integral = integral +  w[i]*a.x[i]*b.x[i];
    }
    return integral;
}