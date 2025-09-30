#include <iostream>
using namespace std;
void pattern1(int n)
{
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int f = 0; f <= 2 * i; f++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int f = 0; f < 2 * n - (2 * i + 1); f++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int f = 0; f < 2 * i + 1; f++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int f = 0; f < 2 * n - (2 * i + 1); f++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern10(int N)
{
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= 2 * N - 1; i++)
    {
        int stars = i;
        if (i > N)
        {
            stars = 2 * N - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << flag << " ";
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    // 1        1
    // 12      21
    // 123    321
    // 1234  4321
    // 1234554321
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    };
}
void pattern13(int n)
{
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << f << " ";
            f++;
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    // A
    // A B
    // A B C
    // A B C D
    // A B C D E
    for (int i = 1; i <= n; i++)
    {
        for (int j = 65; j < 65 + i; j++)
        {
            cout << (char)j << " ";
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    // A B C D E
    // A B C D
    // A B C
    // A B
    // A
    int alphab = 65;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 65; j <= 65 + (n - i - 1); j++)
        {
            cout << (char)j << " ";
            alphab++;
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    //     A
    //    ABA
    //   ABCBA
    //  ABCDCBA
    // ABCDEDCBA
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern17(int n)
{
    // E
    // E D
    // E D C
    // E D C B
    // E D C B A
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - 1);
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}
void pattern18(int n)
{
    // * * * * * * * * * *
    // * * * *     * * * *
    // * * *         * * *
    // * *             * *
    // *                 *
    // *                 *
    // * *             * *
    // * * *         * * *
    // * * * *     * * * *
    // * * * * * * * * * *
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
            cout << "* ";
        for (int j = 0; j < 2 * i; ++j)
            cout << "  ";
        for (int j = 0; j < n - i; ++j)
            cout << "* ";
        cout << '\n';
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n - i; ++j)
            cout << "* ";
        for (int j = 0; j < 2 * i; ++j)
            cout << "  ";
        for (int j = 0; j < n - i; ++j)
            cout << "* ";
        cout << '\n';
    }
}
void pattern19(int n)
{
    // A
    // B B
    // C C C
    // D D D D
    // E E E E E
    for (int i = 65; i < 65 + n; i++)
    {
        for (int j = 0; j <= i - 65; j++)
        {
            cout << (char)i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    pattern19(n);
}

void print1(int n)
{
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print2(int n)
{
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print3(int n)
{
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n)
{
    // 12345
    // 1234
    // 123
    // 12
    // 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print7(int n)
{
    //      *
    //     ***
    //    ******
    //   ********
    //  ***********
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < n - i; x++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print8(int n)
{
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int x = 0; x < (n - i) * 2 - 1; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < n - i; x++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int x = 0; x < (n - i) * 2 - 1; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < i; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < n - i; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
}