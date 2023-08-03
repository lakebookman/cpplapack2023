template<typename T>
void axpy(int n, T alpha, const T* x, int incx, T* y, int incy) {
    //Templated thing probably slow
    int i, ix, iy, m, mp1;

    if (n <= 0) return;
    if (alpha == 0) return;
    if (incx == 1 && incy == 1) {
        m = n % 4;
        if (m != 0) {
            #pragma omp parallel for
            for (i = 0; i < m; ++i) {
                y[i] += alpha * x[i];
            }
        }
        if (n < 4) return;
        mp1 = m + 1;
        #pragma omp parallel for
        for (i = mp1 - 1; i < n; i += 4) {
            y[i] += alpha * x[i];
            y[i + 1] += alpha * x[i + 1];
            y[i + 2] += alpha * x[i + 2];
            y[i + 3] += alpha * x[i + 3];
        }
    } else {
        ix = 0;
        iy = 0;
        if (incx < 0) ix = (1 - n) * incx;
        if (incy < 0) iy = (1 - n) * incy;
        #pragma omp parallel for
        for (i = 0; i < n; ++i) {
            y[iy] += alpha * x[ix];
            ix += incx;
            iy += incy;
        }
    }
}
