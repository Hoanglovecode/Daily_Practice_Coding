#include <stdio.h>
#include <math.h>
#define MAX 100
#define EPS 1e-6
// 🔹 Nhập dữ liệu
void nhap(int *n, double a[][MAX], double x[]) {
    printf("Nhap n: ");
    scanf("%d", n);
    printf("Nhap ma tran a (n x n+1):\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j <= *n; j++)
            scanf("%lf", &a[i][j]);
    printf("Nhap x ban dau:\n");
    for (int i = 0; i < *n; i++)
        scanf("%lf", &x[i]);
}
// 🔹 Chuẩn hóa ma trận
void chuanHoa(int n, double a[][MAX]) {
    for (int i = 0; i < n; i++) {
        double t = a[i][i];
        for (int j = 0; j <= n; j++)
            a[i][j] /= t;
    }
}
// 🔹 Tính r ban đầu
void tinhR(int n, double a[][MAX], double x[], double r[]) {
    for (int i = 0; i < n; i++) {
        r[i] = a[i][n];
        for (int j = 0; j < n; j++)
            r[i] -= a[i][j] * x[j];
    }
}
// 🔹 Tìm chỉ số k có |r[k]| lớn nhất
int timMaxR(int n, double r[]) {
    int k = 0;
    double max = fabs(r[0]);

    for (int i = 1; i < n; i++) {
        if (fabs(r[i]) > max) {
            max = fabs(r[i]);
            k = i;
        }
    }
    return k;
}
// 🔹 Kiểm tra còn lặp không
int conLap(int n, double r[]) {
    for (int i = 0; i < n; i++)
        if (fabs(r[i]) > EPS)
            return 1;
    return 0;
}
// 🔹 Thuật toán chính
void giaiHe(int n, double a[][MAX], double x[]) {
    double r[MAX];
    // Tính r ban đầu
    tinhR(n, a, x, r);
    do {
        int k = timMaxR(n, r);
        // Cập nhật x[k]
        x[k] = x[k] + r[k];
        // Cập nhật r
        double d = r[k];
        for (int i = 0; i < n; i++)
            r[i] = r[i] - a[i][k] * d;

    } while (conLap(n, r));
}
// 🔹 Xuất nghiệm
void xuat(int n, double x[]) {
    printf("\nNghiem:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.6lf\n", i + 1, x[i]);
}
// 🔹 Main
int main() {
    int n;
    double a[MAX][MAX], x[MAX];

    nhap(&n, a, x);
    chuanHoa(n, a);
    giaiHe(n, a, x);
    xuat(n, x);

    return 0;
}