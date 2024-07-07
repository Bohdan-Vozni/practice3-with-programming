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


/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


  

int main() {
    int n;
    printf("Input: ");
    scanf_s("%d", &n);

   //if (n > 0 && n <= 30) {
   // }
        int totalCombinations = pow(2, n);

        FILE* f;
        errno_t err;
        err = fopen_s(&f, "Array.txt", "w");
        if (err != 0) {
            perror("Error");
            return 13;
        }
        int bill=0;
        for (int i = 0; i < totalCombinations; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                
                if ((i & (1 << j)) == 0) {
                    fwrite("5", sizeof(char), 1, f);
                    count++;
                }
                else {
                    fwrite("9", sizeof(char), 1, f);
                    count--;
                }

                if (count == 3) {
                    break;
                    bill++;
                }
            }
            fwrite("\n", sizeof(char), 1, f);
            
        }
        printf("\nbill %d\n", bill);
        
        fclose(f);
       
        err = fopen_s(&f, "Array.txt", "r");
        if (err != 0) {
            perror("Error");
            return 13;
        }
        char *buffer = (char *)malloc(totalCombinations*(n+2)* sizeof(char*));
        while (fgets(buffer, sizeof(buffer), f) != NULL) {
            printf("%s", buffer);
        }

        char* next_token;
        char* token = strtok_s(buffer,"\n", &next_token);
     
    

        while (token!=NULL) {
            printf("%s", token[1]);
            token = strtok_s(NULL, "\n", &next_token);
       
        }
        
        
      
        free(buffer);

        
     

    return 0;
}
*/