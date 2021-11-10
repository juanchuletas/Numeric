#include "lobatto.hpp"

Quadrature::Lobatto::Lobatto(int _pts)
: nQpts{_pts}{
    x = new double[nQpts];
    w = new double[nQpts];
}