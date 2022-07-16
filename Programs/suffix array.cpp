#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 200005;
char str[MAX];
int N, h, sa[MAX], pos[MAX], tmp[MAX], lcp[MAX];

bool compare(int i, int j) {
  if(pos[i] != pos[j]) return pos[i] < pos[j]; // compare by the first h chars
  i += h, j += h; // if prefvious comparing failed, use 2*h chars
  return (i < N && j < N) ? pos[i] < pos[j] : i > j; // return results
}

void build() {
  N = strlen(str);
  for(int i=0; i<N; ++i) sa[i] = i, pos[i] = str[i]; // initialize variables
  for(h=1;;h<<=1) {
    sort(sa, sa+N, compare); // sort suffixes
    for(int i=0; i<N-1; ++i) tmp[i+1] = tmp[i] + compare(sa[i], sa[i+1]); // bucket suffixes
    for(int i=0; i<N; ++i) pos[sa[i]] = tmp[i]; // update pos (reverse mapping of suffix array)
    if(tmp[N-1] == N-1) break; // check if done
  }
}

void lcp_compute() {
  for(int i=0, k=0; i<N; ++i)
    if(pos[i] != N-1) {
      for(int j=sa[pos[i]+1]; str[i+k] == str[j+k];) k++;
      lcp[pos[i]] = k;
      if(k) k--;
    }
}

// It works assuming you have builded the concatenated string and
// computed the suffix and the lcp arrays
// text.length() ---> tlen
// pattern.length() ---> plen
// concatenated string: str

bool match(int tlen, int plen) {
  int total = tlen + plen;
  int pos = -1;
  for(int i=0; i<total; ++i)
    if(total-sa[i] == plen)
      { pos = i; break; }
  if(pos == -1) return false; 
  int lo, hi;
  lo = hi = pos;
  while(lo-1 >= 0 && lcp[lo-1] >= plen) lo--;
  while(hi+1 <  N && lcp[hi] >= plen) hi++;
  for(int i=lo; i<=hi; ++i)
    if(total-sa[i] >= 2*plen)
      return true;
  return false;
}

int main() {
  printf("enter the string : ");
  scanf("%s", str);
  build();
  match(1,7);
  for(int i=0; i<N; ++i)
   printf("%d\n", sa[i]);
  return 0;
}
