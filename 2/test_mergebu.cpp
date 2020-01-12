#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "mergebu.h"

int main() {
  string str = "SORTEXAMPLE";
  vector<char> cvec(str.begin(), str.end());

  for (auto elem : cvec) {
    cout << elem << " ";
  }
  cout << endl;

  MergeBU<char> mergesort;
  mergesort.sort(cvec);

  for (auto elem : cvec) {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}