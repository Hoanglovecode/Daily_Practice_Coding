# include <stdio.h>
# include "conio.h"
# include "math.h" 

# define eps 1e-3
# define max 10

/* ===== Xuat ma tran ===== */
void xuatmt(int a[][max], int n)
{ 
    int i, j;
    for (i=1; i<=n; i++)
    { 
        printf("\n");
        for (j=1; j<=n+1; j++) 
            printf("%5d", a[i][j]);
    }
}

/* ===== Nhap day ===== */
void nhap(float *a, int n)
{ 
    int i;
    for (i=1; i<=n; i++) 
        scanf("%f", a+i);
}

/* ===== Xuat day ===== */
void xuat(float a[], int n)
{ 
    int i;
    for (i=1; i<=n; i++) 
        printf("%8.3f", a[i]);
}

/* ===== Doc file ===== */
int docfile(int a[][max], int *n)
{
    FILE *f;
    int i, j;

    f = fopen("sediel.txt", "r");
    if (f == NULL) return 0;

    fscanf(f, "%d", n);
    for (i=1; i<=*n; i++)
        for (j=1; j<=*n+1; j++)
            if (!feof(f)) fscanf(f, "%d", &a[i][j]);
            else return 0;

    fclose(f);
    return 1;
}

/* ===== Gauss-Seidel ===== */
int gaussSeidel(int a[][max], float x[], float y[], int n)
{
    int i, j, lap, dem = 0;

    do
    { 
        lap = 0; 
        dem++;

        for(i=1; i<=n; i++)
        { 
            float s = 0;

            for (j=1; j<=n; j++)
                if (j != i) s += a[i][j]*x[j];

            y[i] = a[i][n+1] - s;

            if (a[i][i] != 0) 
                y[i] = y[i] / a[i][i];
            else 
                return 0;

            if (fabs(x[i]-y[i]) > eps && dem < 30) 
                lap = 1;
        }

        for (i=1; i<=n; i++) 
            x[i] = y[i];

    } while (lap);

    return (dem < 30);
}

/* ===== MAIN ===== */
int main()
{ 
    int a[max][max];
    float x[max], y[max];
    int n;
    char tt;

    if (!docfile(a, &n))
    {
        printf("\n So lieu ko hop le");
        getch(); 
        return;
    }

    printf("\n Cac he so cua he phuong trinh:\n");
    xuatmt(a, n);

    while (1)
    { 
        printf("\n\n Nhap xap xi nghiem ban dau : ");
        nhap(x, n);

        if (gaussSeidel(a, x, y, n))
        {
            printf("\n Nghiem cua he phuong trinh : ");
            xuat(y, n);
        }
        else 
            printf("\n He phtrinh ko giai duoc bang phuong phap nay");

        printf("\n\n Ban tiep tuc ko(c/k)?");
        tt = getch();
        if (tt != 'c') break;
    }
}