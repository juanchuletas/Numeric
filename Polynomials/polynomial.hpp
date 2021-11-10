#if !defined(MACRO)
#define MACRO
#include<iostream>
class Polynomial{

    public:
        double *x;
        double *dx; 
        int npts;
        int order;
        Polynomial();
        Polynomial(int _order, int _quadPts);
        ~Polynomial();
        void set(int _order, int _quadPts);
        int getOrder();


};

#endif // MACRO
