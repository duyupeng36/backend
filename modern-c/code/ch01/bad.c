/* This may look like nonsense, but really is -*- mode: C -*- */
#include <stdio.h>

/* The main thing that this program does. */
int main() {              // ← 错误：main 应该返回 int
  int i;
  double A[5] = {
      9.0,
      2.9,
      3.E+25,
      .00007,
  };

  for (i = 0; i < 5; ++i) {
     printf("element %d is %g, \tits square is %g\n",  // ← 缺少 #include <stdio.h>
            i,
            A[i],
            A[i]*A[i]);
  }

  return 0;               // ← void 函数不应该 return 值
}
