//
//  main.c
//  poweroffive
//
//  Created by pilhoon on 11/11/13.
//  Copyright (c) 2013 pilhoon. All rights reserved.
//

#include <stdio.h>
#include <gmp.h>
#include <stdbool.h>
#include <time.h>

bool
contains_zero(char* a)
{
    int n = (int)strlen(a);
    for(int i=0; i<n; i++)
    {
        if(a[i] == '0')
            return true;
    }
    return false;
}

int
main(int argc, const char * argv[])
{
    time_t start, end;
    time(&start);
    int limit=100000;
    mpz_t n, k;
    mpz_init(n);
    mpz_init(k);
    mpz_set_ui(n, 1);
    mpz_set_ui(k, 1);
    char r[limit];
    char r2[limit];
    for (int i=0; i<limit; i++) {
        mpz_mul_ui(n, n, 5);
        mpz_mul_ui(k, k, 2);
        mpz_get_str(r, 10, n);
        mpz_get_str(r2, 10, k);
        
        if(!contains_zero(r) && !contains_zero(r2)) {
            printf("----\n");
            gmp_printf("%Zd\n", n);
            printf("5^%d %ld digits and 2^%d is ..\n", i+1, strlen(r), i+1);
            gmp_printf("%Zd\n", k);
        }
//        printf("%d\n", i);
    }
    
    mpz_clear(n);
    mpz_clear(k);

    time(&end);
    printf("%.f second consumed.\n", difftime(end, start));
    return 0;
}

