#ifndef __RCPPSERIALIZATION_HPP__
#define __RCPPSERIALIZATION_HPP__

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <Rcpp.h>

namespace RcppSerialization {

template<typename T>
std::string serialize(T* m, bool is_binary, bool is_gzip) {
  std::stringstream os;
  {
    boost::iostreams::filtering_stream<boost::iostreams::output> f;
    if (is_gzip) f.push(boost::iostreams::gzip_compressor());
    f.push(os);
    if (is_binary) {
      boost::archive::binary_oarchive oa(f);
      oa << *m;
    } else {
      boost::archive::text_oarchive oa(f);
      oa << *m;
    }
  }
  return os.str();
}

template<typename T>
SEXP rcpp_serialize(T* m, bool is_binary, bool is_gzip) {
  const std::string src(serialize<T>(m, is_binary, is_gzip));
  Rcpp::RawVector retval(src.size());
  memcpy(&retval[0], src.c_str(), src.size());
  return retval;  
}

template<typename T>
void rcpp_deserialize(T* m, Rcpp::RawVector src, bool is_binary, bool is_gzip) {
  typedef boost::iostreams::basic_array_source<char> Device;
  boost::iostreams::stream<Device> stream((char *) &src[0], src.size());
  boost::iostreams::filtering_stream<boost::iostreams::input> f;
  if (is_gzip) f.push(boost::iostreams::gzip_decompressor());
  f.push(stream);
  if (is_binary) {
    boost::archive::binary_iarchive ia(f);
    ia >> *m;
  } else {
    boost::archive::text_iarchive ia(f);
    ia >> *m;
  }  
}

template<typename T>
uint32_t signature(T* m) {
  std::string raw(serialize<T>(m, false, true));
  return ::SuperFastHash(raw.c_str(), raw.size(), 0);
}

}

#endif //__RCPPSERIALIZATION_HPP__