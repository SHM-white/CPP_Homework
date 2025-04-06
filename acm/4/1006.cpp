#include <iostream>
#include <cstring>
const long long MAX_COUNT = 2e5 + 3;
long long treeList[MAX_COUNT];
long long nums[MAX_COUNT];

inline long long read() {
	long long x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

long long inline lowBit(long long value){
    return value & (-value);
}
void add(long long value, long long pos, long long n){
    for (; pos <= n; pos += pos & -pos)
    {
        treeList[pos] += value;
    }
}
long long ask(long long pos, long long n){
    long long result = 0;
    for (; pos; pos -= pos & -pos){
        result += treeList[pos];
    }
    return result;
}
int main()
{
    long long t = read();
    while (t--)
    {
        memset(treeList, 0, sizeof(treeList));
        long long n = read(), q = read();
        for (size_t i = 1; i <= n; i++)
        {
            nums[i] = read();
            add(nums[i], i, n);
        }
        long long result = 0;
        long long count = 0;
        for (size_t i = 0; i < q; i++)
        {
            long long op = read(), x = read(), y = read();
            switch (op)
            {
            case 1:
                add(y - nums[x], x, n);
                nums[x] = y;
                break;
            case 2:
                {
                    long long r = (++count) * (ask(y, n) / 100 - ask(x - 1, n) / 100);
                    //std::cout << r << std::endl;
                    result ^= r;
                }
                break;
            default:
                break;
            }
        }
        std::cout << result;
    }
    return 0;
}