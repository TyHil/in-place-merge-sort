#include <iostream>
void mergeSort(int * x, const int min, const int max) {
  const int mid = (max + min) / 2;//middle of passed data
  if (mid - min > 1) mergeSort(x, min, mid);//split bottom
  if (max - mid > 1) mergeSort(x, mid, max);//split top
  if (max > min) {//merge
    //if (max-min>100) cout << "Merging: min: " << min << " max: " << max << " max-min: " << max-min << '\n';//progress print only displays merges larger than 100 data points
    int p1 = min, p2 = mid, p3 = mid;
    while (p1 < p2 and p3 < max) {
      if (x[p1] < x[p3]) {//use < for ascending and > for descending
        p1++;
        p2++;
      } else {
        int temp = x[p3];//move down
        for (int i = p3; i > p1; i--) x[i] = x[i - 1];
        x[p1] = temp;
        p1++;
        p2++;
        p3++;
      }
    }
  }
}
int main() {
  int n;
  std::cin >> n;
  int * x = new int[n];
  for (int i = 0; i < n; i++) std::cin >> x[i];
  mergeSort(x, 0, n);
  for (int i = 0; i < n; i++) std::cout << x[i] << " ";
  delete [] x;
  return 0;
}
