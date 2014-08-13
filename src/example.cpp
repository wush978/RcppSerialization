#include "RcppSerialization.hpp"
#include "example.hpp"

using namespace Rcpp;

//'@export
//[[Rcpp::export]]
SEXP Uniform__new(double min, double max) {
  Rcpp::XPtr<Uniform> ptr(new Uniform(min, max));
  return ptr;
}

//'@export
//[[Rcpp::export]]
SEXP Uniform__draw(SEXP xp, int n) {
  return Rcpp::XPtr<Uniform>(xp)->draw(n);
}

//'@export
//[[Rcpp::export]]
SEXP Uniform__save(SEXP xp, bool is_binary = true, bool is_gzip = true) {
  Rcpp::XPtr<Uniform> p(xp);
  return RcppSerialization::rcpp_serialize<Uniform>(*p, is_binary, is_gzip);
}

//'@export
//[[Rcpp::export]]
SEXP Uniform__load(RawVector src, bool is_binary = true, bool is_gzip = true) {
  XPtr<Uniform> retval(new Uniform(0, 0));
  RcppSerialization::rcpp_deserialize<Uniform>(*retval, src, is_binary, is_gzip);
  return retval;
}