#include "gauss.hpp"

Quadrature::GaussChebyshev::GaussChebyshev(int _pts)
: nQpts{_pts}{
  //Coords and weights;
  x = new double[nQpts];
  w = new double[nQpts];
  double oonpp=1.0/(nQpts+1.0);

  // cos ( i*pi / (n+1))
  double cosine;
  // sin ( i*pi / (n+1))
  double sine;
  double sinesq;

  // Fill elements
  for(int i=1;i<=nQpts;i++) {
    // Compute value of sine and cosine
    sine=sin(i*M_PI*oonpp);
    sinesq=sine*sine;
    cosine=cos(i*M_PI*oonpp);

    // Weight is
    w[i-1]=16.0/3.0/(nQpts+1.0)*sinesq*sinesq;

    // Node is
    x[i-1]=1.0 - 2.0*i*oonpp + M_2_PI*(1.0 + 2.0/3.0*sinesq)*cosine*sine;
  }
}
Quadrature::GaussChebyshev::~GaussChebyshev(){
  delete [] x; 
  delete [] w; 
}
double * Quadrature::GaussChebyshev::getCoords(){
  return x;
}
double * Quadrature::GaussChebyshev::getWeights(){
  return w;
}
double Quadrature::GaussChebyshev::operator()(Polynomial &a, Polynomial &b){
  double result = 0.0;
    for(int i=0; i<nQpts; i++){
        result = result +  w[i]*a.x[i]*b.x[i];
    }
    return result;
}
double Quadrature::GaussChebyshev::operator()(Polynomial &a, Polynomial &b,Polynomial &c){
  double result = 0.0;
    for(int i=0; i<nQpts; i++){
        result = result +  w[i]*(a.x[i]*b.x[i]*c.x[i]);
    }
    return result;
}
double Quadrature::GaussChebyshev::operator()(double *a, double *b){
  double result = 0.0;
    for(int i=0; i<nQpts; i++){
        result = result +  w[i]*(a[i]*b[i]);
    }
    return result;
}