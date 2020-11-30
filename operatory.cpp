#include "tstring.h"

using namespace std;

ostream& operator<<( ostream& strumien, const TString& s ) {
    return strumien << ( s.ptr ? s.ptr : "pusty" );
}

istream& operator>>( istream& strumien, TString& s ) {
  string tmp;
  getline( strumien, tmp );
  delete [] s.ptr;
  s.len = tmp.length();
  if ( s.len > 0 ) {
    s.ptr = new char[ s.len+1 ];
    strcpy( s.ptr, tmp.c_str() ); // metoda c_tr() zwraca const char* z obiektu string
  }
  else {
    s.ptr = nullptr;
  }
  return strumien;
}