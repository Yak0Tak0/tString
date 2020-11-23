#include "tstring.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

TString::TString(const char* s) {
  if(s != nullptr){
    len = strlen(s);
    ptr = new char[len+1];  // +1 bo na końcu jest jeszcz \0 kończące literał napisowy
    strcpy(ptr, s);
  }
  #ifdef DEBUG
    cout << "TString c-tor: [" << ptr << "]" << endl;
  #endif
}

TString::~TString() {
  #ifdef DEBUG
    cout << "TString d-tor: [" << ptr << "]" << endl;
  #endif
  delete [] ptr;
}

TString::TString( const TString& s) : ptr(nullptr), len(s.len) {
  if (len > 0){
    ptr = new char[len+1];
    strcpy(ptr, s.ptr);
  }
  #ifdef DEBUG
    cout << "TString cc-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
  #endif
}

TString& TString::operator=( const TString& s){
  if ( this != &s ) { // if (*this != s)
    delete [] ptr;
    ptr = nullptr;
    len = s.len;
    if (len>0){
      ptr = new char[len+1];
      strcpy(ptr, s.ptr);
    }
  }
  #ifdef DEBUG
    cout << "TString copy operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
  #endif
  return *this;
}

TString::TString( TString&& s ) : ptr(s.ptr), len(s.len) {
  s.ptr = nullptr;
  s.len = 0;
  #ifdef DEBUG
    cout << "TString move c-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
  #endif
}

TString& TString::operator=(TString&& s){
  if( this != &s ) {
    delete [] ptr;
    len = s.len;
    ptr = s.ptr;
    s.len = 0;
    s.ptr = nullptr;
  }
  #ifdef DEBUG
    cout << "TString move operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
  #endif
  return *this;
}

char& TString::operator[](size_t n) {
  if ( ptr==nullptr ) throw "pusty obiekt";
  if ( n < len ) return ptr[n];
  throw out_of_range("In TString::operator[] argument out of scope");
}

const char& TString::operator[](size_t n) const {
  if ( ptr==nullptr ) throw "pusty obiekt";
  if ( n < len ) return ptr[n];
  throw out_of_range("In TString::operator[] argument out of scope");
}

char* TString::insert( size_t pos, const char* c) {
  if (pos>=0 && pos<=len) {
    size_t oldlen = len;
    len = len+strlen(c);
    char* tmp = new char[ len+1 ];
    strcpy( tmp, ptr );
    for( size_t i=pos; i<pos+strlen(c); ++i){
      tmp[i] = c[i-pos];
    }
    for(size_t i=pos; i <oldlen; ++i) {
      tmp[i+strlen(c)] = ptr[i];
    }
    delete [] ptr;
    ptr = tmp;
    return ptr+pos;
  }
  else{
    throw out_of_range("zly argument");
  }
  return ptr;
}

char* TString::insert(size_t pos, char c) {
  return insert(pos, string( { c } ).c_str());
}

char* TString::erase(size_t pos, size_t l) {
    if (pos <= len && pos >= 0 && l < len - pos){
        char *tmp = new char[len];
        strcpy(tmp, ptr);
        for (size_t i = pos; i <= len; ++i) {
            if (i + l <= len - pos) {
                tmp[i] = tmp[i + l];
            }
        }
        delete[] ptr;
        len = len - l;
        ptr = tmp;
    }
    else {
        throw out_of_range("In TString::erase(pos, l) argument out of range");
    }
    return ptr;
}