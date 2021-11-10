#if !defined(_LIL_H_)
#define _LIL_H_
#include <string>
#include "../Polynomials/polynomial.hpp"

class LIP {
    int Npol;
    int grad;
    int Nqpts;
    double *xp;
    Polynomial *p;

    public:
        LIP();
        LIP(int order, int qpts);
        ~LIP();
        void evaluate(double *x);
        void derivatives(double *f);
        void setNodes(double *nodes);
        int order();
        Polynomial & operator()(int,std::string);
};

double * der(Polynomial &p);

#endif // _LIL_H_
