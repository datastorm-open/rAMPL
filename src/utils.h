#ifndef GUARD_utils_h
#define GUARD_utils_h

#include <string>
#include <Rcpp.h>

template <class T>
Rcpp::XPtr<T> getObj(const std::string &type, SEXP s) {
  std::string rtypename = "Rcpp_" + type;
  Rcpp::S4 s4obj(s);
  if ( !s4obj.is( rtypename.c_str() ) ) {
    Rf_error( (std::string("object is not of the type ")+type).c_str() );
  }
  Rcpp::Environment env(s4obj);
  Rcpp::XPtr<T> xptr(env.get(".pointer"));
  return xptr;
}

#endif
