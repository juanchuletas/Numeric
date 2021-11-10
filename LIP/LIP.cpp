#include "LIP.hpp"

LIP::LIP(){
    //std::cout<<"IP: Default Constructor\n";
}
LIP::LIP(int _order, int qpts)
: Npol{_order+1}, Nqpts{qpts}, grad{_order}{
    //std::cout<<"LIP: Constructor\n";
    p = new Polynomial[Npol];
    xp = new double[Npol];
    double init = -1.0; 
    double fin = 1.0;
    for(int i=0; i<Npol; i++){
        p[i].set(_order,qpts);
        xp[i]  = init + (i/(double)_order)*(fin-init);
    }
}
LIP::~LIP(){
    //std::cout<<"LIP: Destructor\n";
    delete [] p;
    delete [] xp;
}
Polynomial & LIP::operator()(int i,std::string){
    return p[i];
}
int LIP::order(){
    return grad;
}
void LIP::setNodes(double *nodes){
    for(int i=0; i<Npol; i++){
        xp[i] = nodes[i];
    }
}
void LIP::evaluate(double *f){
    for(int q=0; q<Nqpts; q++){
        for(int i=0; i<Npol; i++){
            double prod = 1.0;
            for(int j=0; j<Npol; j++){
                if(i==j)
                    continue;
                prod *= (f[q]-xp[j])/(xp[i]-xp[j]);
            }
            p[i].x[q] = prod;
        }
    }

}
void LIP::derivatives(double *f){

   
   for(int q=0; q<Nqpts; q++){
       for(int i=0; i<Npol; i++){
        double deriv =0.0;
           for(int j=0; j<Npol; j++){
                if(i==j)
                    continue;
                double prod = 1.0;
                for(int k=0; k<Npol; k++){
                    if(i==k)
                        continue;
                    if(j==k)
                        continue;
                    prod *= (f[q]-xp[k])/(xp[i]-xp[k]);
                    
                }
                deriv = deriv + prod/(xp[i]-xp[j]);
                
                p[i].dx[q] = deriv;
           }
       }
   }
}
//NOM MEMBER FUNCTION

double *der(Polynomial &p){
    return p.dx;
}