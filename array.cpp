#include <iostream>

class Arr
{
private:
    void scambio(int &x, int &y)
    {
        int a;
        a = x;
        x = y;
        y = a;
    }

public:
    int size;
    int *V = (int *)malloc(sizeof(int));

    Arr(int *V, int size)
    {
        this->V = V;
        this->size = size;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << V[i] << std::endl;
        }
    }

    void bubble_ott(int v[], int n)
    {
        int sup, pos;
        sup = n;
        pos = 0;

        while (sup != 0)
        {
            pos = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] > v[i + 1])
                {
                    pos = i;
                    scambio(v[i], v[i + 1]);
                }
            }
            sup = pos;
        }
    }

    void selection_ott(int v[], int n)
    {
        int min, i, j;
        for (i = 0; i < n - 1; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if (v[min] > v[j])
                {
                    min = j;
                }
            }
            scambio(v[min], v[i]);
        }
    }

    int sequenziale(int v[], int n, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == k)
            {
                return i;
            }
        }
        return -1;
    }

    int binary(int v[], int n, int x)
    {
        int sup = n - 1, inf = 0, m = 0;
        while (inf < sup && v[m] != x)
        {
            m = (inf + sup) / 2;
            if (v[m] < x)
                inf = m + 1;
            if (v[m] > x)
                sup = m - 1;
        }
        if (v[m] == x)
        {
            return m;
        }
        else
        {
            return -1;
        }
    }

    void insertion_sort(int v[], int n)
    {
        int value, hole;

        for (int i = 1; i < n; i++)
        {
            value = v[i];
            hole = i;
            while (hole > 0 && v[hole - 1] > value)
            {
                v[hole] = v[hole - 1];
                hole = hole - 1;
            }
            v[hole] = value;
        }
    }

    // 1.divide and conquer
    // 2. recursive
    // 3. Stable
    // 4. not In-place
    // 5. o(nlogn)
    void merge(int l[], int nl, int r[], int nr, int a[], int na)
    {
        int i = 0, j = 0, k = 0;
        while (i < nl && j < nr)
        {
            if (l[i] <= r[j])
            {
                a[k] = l[i];
                k++;
                i++;
            }
            else
            {
                a[k] = r[j];
                j++;
                k++;
            }
        }
        // in base al sottoarray con posizione rimanenti non collocate verra eseguito il ciclo
        while (i < nl)
        {
            a[k] = l[i];
            i++;
            k++;
        }
        while (j < nr)
        {
            a[k] = r[j];
            j++;
            k++;
        }
    }

    void mergesort(int a[], int n)
    {

        if (n < 2)
        {
            return;
        }

        int mid = n / 2;

        int nl = mid;
        int nr = n - mid;

        int *left = new int[nl];
        int *right = new int[nr];

        for (int i = 0; i < nl; i++)
        {
            left[i] = a[i];
        }
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = a[i];
        }
        mergesort(left, nl);
        mergesort(right, nr);
        merge(left, nl, right, nr, a, n);
    }
};

int main()
{
    int *v = new int[12]{6, 4, 7, 2, -6, -67, 54, 67, 21, 5, 3, 0};
    int size = 12;

    Arr a(v, size);
    a.mergesort(v, size);
    a.print();

    return 0;
}
