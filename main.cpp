//Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
//Удалить из последовательности числа, сумма цифр которых равна 18, 
//а среди оставшихся продублировать числа, произведение цифр которых кратно 35.
#include <iostream>
#define N 10000

int main()
{
    int c=0, a, save, save1, sum=0, pr=1, n,nomer=0;
    int mas[N];
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
    for (int i = 0; i < n; i++)
    {
        save = save1 = mas[i];
        pr = 1;
        sum = 0;

        while (save > 0)
        {
            a = save % 10;
            save = save / 10;
            sum += a;
            pr *= a;
        }
        if (sum == 18)
        {
            for (int j = i; j<=n-1; j++)
                mas[j] = mas[j+1];
            n--;
            i--;
        }
        if (pr == 35)
        {
            n++;
            for (int j = n-1; j >= i+1; j--)
                mas[j] = mas[j - 1];
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
}