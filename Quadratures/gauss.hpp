#if !defined(_GAUS_H_)
#define _GAUS_H_
#include<cmath>
#include "../Polynomials/polynomial.hpp"
namespace Quadrature{
    class GaussChebyshev{
        int nQpts;
        double *x;
        double *w;
        public:
            GaussChebyshev(int _pts);
            ~GaussChebyshev();
            //void getCoordsAndWeights(double *x, double *w);
            double * getCoords();
            double * getWeights();
            double operator()(Polynomial &p, Polynomial &);
            double operator()(Polynomial &p, Polynomial &,Polynomial &c);
            double operator()(double *a, double *b);
    };
}



//void gauss_cheby(int n, double *x, double *w);

#endif // _GAUS_H_
