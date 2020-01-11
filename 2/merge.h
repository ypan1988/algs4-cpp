#include <cassert>
#include <vector>

template <typename T> class Merge {
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

  void sort(std::vector<T> &a, std::vector<T> &aux, int lo, int hi) {
    if (hi <= lo)
      return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
  }

public:
  void sort(std::vector<T> &a) {
    std::vector<T> aux(a.size());
    sort(a, aux, 0, a.size() - 1);
  }

  bool isSorted(const std::vector<T> &a) { isSorted(a, 0, a.size() - 1); }

  bool isSorted(const std::vector<T> &a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++)
      if (a[i] < a[i - 1])
        return false;
    return true;
  }
};