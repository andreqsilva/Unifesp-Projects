#include <stdio.h>
#include <math.h>

int main() {
    int i, j, l, somas = 0, n, c;

    scanf("%d", &n); 
    
    for(i = 2; i <= n/2; i+=2) {
        c = 0;
        
        for(j = 2; j <= sqrt(i); j++) {
            //printf("%d %d\n", i, j);
            if(i%j == 0) {
                c++;
                break;
            }
        }
        if(c == 0) {
            c = 0;
            for(j = 2; j <= sqrt((n-i)); j+=2) {
                //printf("%d %d\n", n-i, i);
                if((n-i)%j == 0) {
                    c++;
                }
                
                if(j == 2) j--;
            }
            if(c == 0) {
                //printf("%d -> %d [%d] %d\n", i, n-i, j, c);
                somas++;
            }
        }
        
        if(i == 2) i--;
    }

    printf("%d\n", somas);

    return 0;
}
