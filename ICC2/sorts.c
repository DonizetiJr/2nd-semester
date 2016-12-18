/* Bubble Sort */
void bubble_sort(int v[], int T) {
   int i, j, troca = 1;
   while (troca) {
      troca = 0;
      for (i = 0; i < T-1; i++) {
         for (j = 0; j < T-i-1; j++) {
            if (v[j] > v[j+1]) {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
               troca = 1;
            }
         }
      }
   }
}

/* Insert sort */
void insertsort(int x[], int n) {
   int i, k, y;
   for (k = 0; k < n; k++) {
      y = x[k];
      for (i = k-1; i >= 0 && y < x[i]; i--) {
         x[i+1] = x[i];
      }
      x[i+1] = y;
   }
}

/* Select sort */
void selectsort(int x[], int n) {
   int i, indx, j, maior;
   for (i = n-1; i > 0; i--) {
      maior = x[0];
      indx = 0;
      for (j = 1; j <= i; j++) {
         if (x[j] > maior) {
            maior = x[j];
            indx = j;
         }
         x[indx] = x[i];
         x[i] = maior;
      }
   }
}

/* Quick sort Hoare recursivo */
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

/* Quicksort Lomuto */
int l-Partition(int *a, int l, int r) {
   int i, j, p, t;
   p = a[r];
   i = l;
   for (j = 0; j <= r-1; j++) {
      if (a[j] <= p) {
         t = a[j];
         a[j] = a[i];
         a[i] = t;
         i++;
      }
   }

   t = a[i];
   a[i] = a[r];
   a[r] = t;
   return i;
}

/* Merge sort */
void BottomUpMergeSort(A[], B[], n) {
   // Each 1-element run in A is already "sorted".
   // Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
   for (width = 1; width < n; width = 2 * width) {
      // Array A is full of runs of length width.
      for (i = 0; i < n; i = i + 2 * width) {
         // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
         // or copy A[i:n-1] to B[] ( if(i+width >= n) )
         BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
      }
      // Now work array B is full of runs of length 2*width.
      // Copy array B to array A for next iteration.
      // A more efficient implementation would swap the roles of A and B.
      CopyArray(B, A, n);
      // Now array A is full of runs of length 2*width.
   }
}

//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
BottomUpMerge(A[], iLeft, iRight, iEnd, B[]) {
   i = iLeft, j = iRight;
   // While there are elements in the left or right runs...
   for (k = iLeft; k < iEnd; k++) {
      // If left run head exists and is <= existing right run head.
      if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
         B[k] = A[i];
         i = i + 1;
      } else {
         B[k] = A[j];
         j = j + 1;
      }
   }
}

void CopyArray(B[], A[], n) {
   for(i = 0; i < n; i++)
      A[i] = B[i];
}

/* Heap sort */
void fazheap(int a[], int n) {
   int i;
   // reajusta os elementos em a[0:n-1] para formar um heap
   for (i = (n-1)/2; i >= 0; i- -)
      ajuste(a,i,n-1);
}

void heapsort(int a[], int n) {
   int t, i;
   // a[0:n-1] contém n elementos a ser ordenado.
   // HeapSort rearranja-os em ordem não-decrescente.
   fazheap(a,n); // transforma o vetor em um heap
   // troca o novo máximo com o elemento no final do vetor
   for (i = n-1; i >= 1; i- -) {
      t = a[i];
      a[i] = a[0];
      a[0] = t;
      ajuste(a, 0, i-1);
   }
}

void ajuste(int a[], int i, int n) {
   // Árvores binárias completas com raízes 2(i+1)-1 e 2(i+1) são
   // combinadas com o nó i para formar um heap com raiz i.
   // Nenhum nó tem endereço maior que n-1 ou menor que 0.
   int item, j;
   j = 2*(i+1)-1;
   item = a[i];
   while (j <= n) {
      if ((j < n) && (a[j] < a[j+1]))
      j = j + 1;
      // compara sucessor da esquerda com o da direita : j é o maior
      if (item >= a[j])
      break;
      // uma posição para item é encontrada
      a[(j+1)/2-1] = a[j];
      j = 2*(j+1)-1;
   }
   a[(j+1)/2-1] = item;
}

/* Shell sort */
void shellsort(int x[], int n, int incrments[], int numinc) {
   int incr, j, k, span, y;
   for (incr = 0; incr < numinc; incr++) {
      span = incrmnts[incr]; // span é o tamanho do incremento
      for (j = span; j < n; j++) {
         //insere lemento x[j] em sua posição correta dentro de seu sub-arquivo
         y = x[j];
         for (k = j-span; k >= 0 && y < x[k]; k -= span) {
            x[k+span] = x[k];
         }
         x[k+span] = y;
      }
   }
}

/* Cálculo de Endereço */
void end(int x[], int n) {
   PNO f[10], p;
   int prim, i, j, y;
   struct tipo_no no[NUMELTS];
   for (i = 0; i < n; i++)
      no[i].info = 0;
   for (i = 0; i < n-1; i++)
      no[i].prox = no[i+1].prox;
   no[n-1].prox = NULL;
   for (i = 0; i < 10; i++)
      f[i] = NULL;
   for (i = 0; i < n; i++) {
      y = x[i];
      prim = y/10; // encontra o primeiro dígito do número de dois dígitos ddecimais
      coloca (&f[prim], y);
      // coloca insere y na posição correta na lista ligada apontada por f[prim]
   }
   i = 0;
   for (j = 0; j < 10; j++) {
      p = f[j];
      while (p != NULL) {
         x[i++] = p->info;
         p = p->prox;
      }
   }
}

/* Contagem de menores */
void contagem_de_menores(int A[], int n) {
   int X[n], B[n], i, j;
   for (i = 0; i < n; i++) // inicializando arranjo auxiliar
      x[i] = 0;
   for (i = 1; i < n; i++) { // contando menores
      for (j = i-1; j >= 0; j--) {
         if (A[i] < A[j])
            X[j] += 1;
         else
            X[i] += 1;
      }
      for (i = 0; i < n; i++) // montando arranjo final
         B[X[i]] = A[i];
      for (i = 0; i < n; i++) // copiando arranjo final para original
         A[i] = B[i];
   }
}

/* Contagem de Tipos */
void countingsort(int A[], int n) {
   int B[n], i, j, max;
   max=A[0]; //determinando max
   for (i=1; i<n; i++) {
      if (A[i]>max)
         max=A[i];
   }
   int X[max+1];
   //inicializando arranjo auxiliar
   for (i=0; i<max+1; i++)
      X[i]=0;
   //contando tipos
   for (i=0; i<n; i++)
      X[A[i]]++;
   //montando arranjo final
   j=0;
   for (i=0; i<max+1; i++) {
      while (X[i]!=0) {
         B[j]=i;
         j++;
         X[i]-;
      }
   }
   //copiando arranjo final para original
   for (i=0; i<n; i++)
      A[i]=B[i];
}

/* Radix sort */
for (k = dígito menos significativo; k <= dígito mais
significativo; k++) {
   for (i = 0; i < n; i++) {
      y = x[i];
      j = k-ésimo dígito de y;
      posiciona y no final da fila[j];
   }
   for (qu = 0; qu < 10; qu++)
      coloca elementos da fila[qu] na próxima posição sequencial;
}
