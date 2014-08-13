// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// Uniform__new
SEXP Uniform__new(double min, double max);
RcppExport SEXP RcppSerialization_Uniform__new(SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< double >::type min(minSEXP );
        Rcpp::traits::input_parameter< double >::type max(maxSEXP );
        SEXP __result = Uniform__new(min, max);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// Uniform__draw
SEXP Uniform__draw(SEXP xp, int n);
RcppExport SEXP RcppSerialization_Uniform__draw(SEXP xpSEXP, SEXP nSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type xp(xpSEXP );
        Rcpp::traits::input_parameter< int >::type n(nSEXP );
        SEXP __result = Uniform__draw(xp, n);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// Uniform__save
SEXP Uniform__save(SEXP xp, bool is_binary = true, bool is_gzip = true);
RcppExport SEXP RcppSerialization_Uniform__save(SEXP xpSEXP, SEXP is_binarySEXP, SEXP is_gzipSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type xp(xpSEXP );
        Rcpp::traits::input_parameter< bool >::type is_binary(is_binarySEXP );
        Rcpp::traits::input_parameter< bool >::type is_gzip(is_gzipSEXP );
        SEXP __result = Uniform__save(xp, is_binary, is_gzip);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// Uniform__load
SEXP Uniform__load(RawVector src, bool is_binary = true, bool is_gzip = true);
RcppExport SEXP RcppSerialization_Uniform__load(SEXP srcSEXP, SEXP is_binarySEXP, SEXP is_gzipSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< RawVector >::type src(srcSEXP );
        Rcpp::traits::input_parameter< bool >::type is_binary(is_binarySEXP );
        Rcpp::traits::input_parameter< bool >::type is_gzip(is_gzipSEXP );
        SEXP __result = Uniform__load(src, is_binary, is_gzip);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}