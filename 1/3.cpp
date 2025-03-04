#include <iostream>
#include <vector>
#include <string.h>
struct BinNum
{
public:
    int operator[](int n) const
    {
        return num[n];
    }
    BinNum operator+(BinNum &another) const
    {
        BinNum newNum;
        for (size_t i = 0; i < 5; i++)
        {
            newNum.num[i] += ((int)num[i] + (int)another[i]);
            if (newNum[i] > 1)
            {
                newNum.num[i] -= 2;
                if (i >= 4)
                {
                    break;
                }
                newNum.num[i + 1] += 1;
            }
        }
        return newNum;
    }

    int num[5]{0};
};
std::istream &operator>>(std::istream &is, BinNum &num)
{
    std::string str;
    is >> str;
    for (int i = std::max(str.length() - 1, (unsigned long long)4); i >= 0; i--)
    {
        if (str[i] == '1')
        {
            num.num[4 - i] = true;
        }
        else
        {
            num.num[4 - i] = false;
        }
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, BinNum &num)
{
    for (size_t i = 0; i < 5; i++)
    {
        os << (int)num[4 - i];
    }
    return os;
}
template <typename T>
T add(T n1, T n2)
{
    return n1 + n2;
}
char *add(char *n1, char *n2)
{
    char *newChar = new char[strlen(n1) + strlen(n2) + 1];
    strcpy(newChar, n1);
    strcat(newChar, n2);
    return newChar;
}
int main()
{
    int a, b;
    char str1[30], str2[30];
    BinNum num1, num2;
    std::cin >> a >> b >> str1 >> str2 >> num1 >> num2;
    char *result = add(str1, str2);
    auto result2 = add(num1, num2);
    std::cout << add(a, b) << ", " << result << ", " << result2 << std::endl;
}