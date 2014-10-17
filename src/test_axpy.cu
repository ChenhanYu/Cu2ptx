#include <stdio.h>

__global__ void daxpy_asm_1_1(
  double*       __restrict__ y,
  double                     alpha,
  const double* __restrict__ x )
{
  /*
  for ( int i = 0; i < 8; i++) y[ i ] += alpha * x[ i ];
  asm volatile (
    "\n\t"
    "\n\t"
    :
    "+l"( y )
    :
    "d"(alpha),
    "l"(x)
  );
  */
  #include "axpy.asm"
}

int main()
{
  double y[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  double x[8] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
  double alpha = -1.2;

  double *y_d, *x_d;

  cudaMalloc( ( void** ) &y_d, sizeof(double) * 8 );
  cudaMalloc( ( void** ) &x_d, sizeof(double) * 8 );

  cudaMemcpy( y_d, y, sizeof(double) * 8, cudaMemcpyHostToDevice );
  cudaMemcpy( x_d, x, sizeof(double) * 8, cudaMemcpyHostToDevice );

  daxpy_asm_1_1<<< 1, 1 >>>( y_d, alpha, x_d );

  cudaMemcpy( y, y_d, sizeof(double) * 8, cudaMemcpyDeviceToHost );

  printf("%4.2f, %4.2f, %4.2f, %4.2f\n", y[0], y[1], y[2], y[3]);

  return 0;
}
