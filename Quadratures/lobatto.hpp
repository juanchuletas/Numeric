#if !defined(_LOBATTO_H_)
#define _LOBATTO_H_
namespace Quadrature{

    class Lobatto{
        int nQpts;
        double *x; 
        double *w;

        public:
            Lobatto(int _pts);
            ~Lobatto();

    };
}


#endif // _LOBATTO_H_
