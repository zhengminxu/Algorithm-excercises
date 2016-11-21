

#ifndef prime_h
#define prime_h


#endif
int is_prime(int n){
    if(n <= 1)
        return 0;
    int m = floor(sqrt(n) + 0.5);  //除到平方根就可以了，因为合数c = a * b, a <= sqrt(c), b >= sqrt(c)
    for (int i = 2; i <=m; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
    
}
