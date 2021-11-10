#if !defined(_INTEGRATE_H_)
#define _INTEGRATE_H_
#include <iostream>
#include "../Polynomials/polynomial.hpp"
namespace Numeric{    
    namespace Integral{


        double compute(Polynomial &a, Polynomial &b, double *w,int qdpts);

    }
}

#endif // _INTEGRATE_H_
