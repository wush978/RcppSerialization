#ifndef __EXAMPLE_HPP__
#define __EXAMPLE_HPP__

#include <Rcpp.h>

class Uniform {
public:
  Uniform(double min_, double max_) : min(min_), max(max_) { }
  
  Rcpp::NumericVector draw(int n) {
    Rcpp::RNGScope scope;
    return Rcpp::runif(n, min, max);
  }
private:
  double min, max;

friend class boost::serialization::access;

template<class Archive>
void serialize(Archive & ar, const unsigned int version)
{
  ar & min;
  ar & max;
}

};

#endif //__EXAMPLE_HPP__