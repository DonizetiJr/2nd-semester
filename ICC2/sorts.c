/* Quick sort recursivo */

void quicksort(int x[], int b, int n) {
  int i, j, k, aux;
  i = b;
  j = n;
  k = x[(b+n) / 2];

  do {
    while (x[i] < k)
      i++;
    while (k < x[j])
      j--;
    if (i <= j) {
      aux = x[i];
      x[j] = aux;
      i++;
      j--;
    }
    
  } while (i <= j);

  if (b < j)
    quicksort(x,b,j);
  if (i < n)
    quicksort(x,i,n);
}
