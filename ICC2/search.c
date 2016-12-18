/* Busca sequencial */
for (i = 0; i < n; i++)
   if (A[i] == x) return (i); // chave encontrada
   return (-1); // chave não encontrada

/* Busca sequencial com sentinela */
A[n] = x;
for (i = 0; x != A[i]; i++)
   if (i < n) return (i); // chave encontrada
   else return (-1); // chave não encontrada
