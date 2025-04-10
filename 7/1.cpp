#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <numeric>
#include <array>

template <typename T>
    requires std::ranges::range<T>
typename T::value_type sum(const T &arg)
{
    typename T::value_type result{};
    for (const auto& i : arg){
        result += i;
    }
    return result;
}

template <typename T, std::size_t N>
T sum(const T (&arr)[N])
{
    T result{};
    for (const auto& i : arr) {
        result += i;
    }
    return result;
}

int main(){
    int arr[] = {564, 5435, 2345};
    double arr2[]{43563.3, 13854.78, 41245.74, 5464.647};
    float arr3[]{435486.4f, 545.64f, 45343.34352f};
    std::cout << sum(std::vector{123, 456}) << "\n"
              << sum(std::vector{std::string("11234"), std::string("674344")}) << "\n"
              << sum(std::vector{345.21f, 896.21f}) << "\n"
              << sum(std::vector{834.145l, 8145.5638l}) << "\n"
              << sum(std::vector{531654ll, 812346ll}) << "\n"
              << sum(arr) << "\n"
              << sum(arr2) << "\n"
              << sum(arr3) << "\n";
}