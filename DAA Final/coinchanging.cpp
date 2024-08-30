#include <iostream>

int main() {
    int coin[] = {50, 20, 10, 5, 2, 1};
    int n;
    std::cout << "Enter the input rupees: ";
    std::cin >> n;
    for (int i = 0; i < 6; i++) {
        int k = n / coin[i];
        n = n % coin[i];
        if (k > 0)
            std::cout << coin[i] << "Rs Coin = " << k << std::endl;
        if (n == 0)
            break;
    }
    return 0;
}
