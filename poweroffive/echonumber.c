#include <stdio.h>
#include <gmp.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

bool is_this_echo(char* r) {
	if(strlen(r) %2 != 0)
		return false;
	
	for(int i=0; i<strlen(r)/2; i++) {
		if(r[i] != r[i+ strlen(r)/2])
			return false;
	}
	return true;
}

int
main(int argc, const char * argv[])
{
    time_t start, end;
    time(&start);
    mpz_t n;
    mpz_init(n);


	mpz_t i; mpz_init(i); 
	char r[40];
	mpz_t k; mpz_init(k);
    for (;;) {
		mpz_add_ui(i, i, 1);
        mpz_pow_ui(n, i, 2);
        mpz_get_str(r, 10, n);
		mpz_mod_ui(k, n, 100000000000);
		if(mpz_cmp_ui(k, 0) == 0)
        {
            gmp_printf("%Zd\n", i);
            printf("\033[A\033[2K");
        }
        
		if(is_this_echo(r))
			printf("\n\n%s\n\n", r);
    }
    
    mpz_clear(n);

    time(&end);
    printf("%.f second consumed.\n", difftime(end, start));
    return 0;
}

