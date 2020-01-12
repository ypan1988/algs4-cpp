#ifndef _ALGORITHMS_MERGEBU_H
#define _ALGORITHMS_MERGEBU_H

#include <cassert>

#include <algorithm>
#include <vector>

template <typename T> class MergeBU {
private:
  void merge(std::vector<T> &a, std::vector<T> &aux, int lo, int mid, int hi) {
    assert(isSorted(a, lo, mid));
    assert(isSorted(a, mid + 1, hi));

    for (int k = lo; k <= hi; ++k)
      aux[k] = a[k];

    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
      if (i > mid)
        a[k] = aux[j++];
      else if (j > hi)
        a[k] = aux[i++];
      else if (aux[j] < aux[i])
        a[k] = aux[j++];
      else
        a[k] = aux[i++];
    }

    assert(isSorted(a, lo, hi));
  }

public:
  void sort(std::vector<T> &a) {
    int N = a.size();
    std::vector<T> aux(N);
    for (int sz = 1; sz < N; sz = sz + sz) {
      for (int lo = 0; lo < N - sz; lo += sz + sz) {
        merge(a, aux, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N-1));
      }
    }
  }

  bool isSorted(const std::vector<T> &a) { isSorted(a, 0, a.size() - 1); }

  bool isSorted(const std::vector<T> &a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++)
      if (a[i] < a[i - 1])
        return false;
    return true;
  }
};

#endif