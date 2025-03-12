#include <iostream>
bool isPrime(int n){
    bool result = true;
    for(int i = 2; i < n; i++){
        result &= (n % i != 0);
        if(!result){
            return false;
        }
    }
    return result;
}
int main(){
    int n;
    std::cin >> n;
    for (int i = 2; i < n; i++)
    {
        if(!isPrime(i)){
            continue;
        }
        if(n % i == 0){
            std::cout << n / i << std::endl;
            break;
        }
    }
}