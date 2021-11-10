#include "../LIP/LIP.hpp"
#include "../Quadratures/gauss.hpp"



int main(){


    //Order of the Lagrange Interpolating Polynomial 
    int order = 6;
    std::string x;
    //Number of quadrature points to perform the numeric integrals
    //int quadPts  = 80;
    int quadPts  = 80;
    //Gauss-Chebyshev Quadrature:
    Quadrature::GaussChebyshev Integral{quadPts};
    //Lagrange interpolation polynomials:
    LIP g{order,quadPts};
    // Numeric Integral: coords & weights:
    double *xcoords;
    double *weights;
    xcoords = Integral.getCoords();
    weights = Integral.getWeights();
    //Evaluates the LIP and its derivatives:
    g.evaluate(xcoords);
    g.derivatives(xcoords);
    //Gets the LIP order:
    int data = g.order();
    printf("The order of the LIP is: %d\n",data);
    double result1 = Integral(g(0,x),g(0,x),g(1,x));
    printf("The integral of L(0,x)*L(0,x) is: %.10lf\n",result1);
    /*Computes the integral of the LIP derivatives*/

    double result2 = Integral(der(g(0,x)),der(g(1,x)));

    printf("The integral of L'(0,x)*L'(0,x) is: %.10lf\n",result2); 

    return 0;    
}