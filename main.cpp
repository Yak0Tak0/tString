#include <iostream>
#include "tstring.h"
using namespace std;

auto fun(const char* c) {
  return TString(c);
}

auto main() -> int {
  TString s1;
  TString s2{"abrakadabra"};
  TString s3 { s2 };
  TString s4 = fun("nowy obiekt nr 1");
  s1 = s2;
  s1 = std::move( s2 );
  s1.insert(0, "NA POCZATEK");
  s1.insert(s1.size(), "NA KONCU");
  s1.erase(0, 11);
  for (auto c : s1) cout << c << "-";
  cout << endl;
  cout << "----------" << endl;
  //komentarz
}