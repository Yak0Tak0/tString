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
  s1.insert(0,"NA POCZATEK");
  s1.insert(s1.size(),'K');
  s1.insert(s1.size()/2,"W SRODKU");
  for (auto i=0ul; i<s1.size(); ++i) cout << s1[i];
  cout << endl;
  for (const auto& c : s1) {
    //c = toupper(c);
    cout << c << "-";
  }
  cout << endl;
  for (auto i=0ul; i<s1.size(); ++i) cout << s1[i];
  cout << endl;
  cout << "Wpisz jakies dane: ";
  cin >> s1;
  s1.push_back("-koncowka-");
  s1.push_back('X');
  cout << "Wpisano: " << s1 << endl;
  cout << "----------------------" << endl;
}