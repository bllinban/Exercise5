#include <stdio.h>
#define MOD 12345
int main() {
    int n;
    printf("Введіть довжину послідовностей n: ");
    scanf("%d", &n);
    int result = countSequences(n);
    printf("Кількість допустимих послідовностей довжиною %d: %d\n", n, result);
    return 0;
}
//обчислення к-сті допустимих послідовностей довжиною n
int countSequences(int n) {
    if (n == 1) return 2; // "0", "1"
    if (n == 2) return 4; // "00", "01", "10", "11"
    
    // зберігання к-стей допустимих послідовностей
    int dp[n+1];
    dp[0] = 1; 
    dp[1] = 2; // "0", "1"
    dp[2] = 4; // "00", "01", "10", "11"
    
    // для інших розмірів послідовностей
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    
    return dp[n];
}