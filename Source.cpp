#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Input digit of number: ");
    scanf_s("%d", &n);
   
    if (n >= 30 || n < 1) {
        printf("Error");
        return 13;
    }
    
   
   
        int totalCombinations = pow(2, n);

       

        int bill=0;
        for (int i = 0; i < totalCombinations; i++) {
            int count1 = 0;
            int count2 = 0;
            for (int j = n - 1; j >= 0; j--) {
                
                if ((i & (1 << j)) == 0) {
                    count2=0;
                    count1++;
                 //   printf("5");
                }
                if((i & (1 << j)) !=0) {
                    count1=0;
                    count2++;
                  //  printf("9");

                }

                 if (count1 == 3 || count2 == 3) {
                    bill++;
                  //  printf("~");
                    break;
                  }
            }
           
            //printf("\n");

        }
        printf("\nNumber of combination: %d\n", totalCombinations - (bill));
        
       
     

    return 0;
}

