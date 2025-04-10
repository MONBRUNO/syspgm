#include <stdio.h>

int main() {
    int num, i;
    int binary[8] = {0}; // Array to store binary digits (8 bits for numbers up to 255)
    int oneCount = 0;    // Counter for number of 1s
    
    // Input number between 0 and 225
    printf("Enter a number between 0 and 225: ");
    scanf("%d", &num);
    
    // Check if number is in valid range
    if (num < 0 || num > 225) {
        printf("Error: Number must be between 0 and 225.\n");
        return 1;
    }
    
    // Convert to binary and store in array
    for (i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
        
        // Count the number of 1s
        if (binary[i] == 1) {
            oneCount++;
        }
    }
    
    // Output full binary representation
    printf("Binary representation: ");
    for (i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
    
    // Output count of 1s
    printf("Number of 1s: %d\n", oneCount);
    
    // Output upper 4 bits
    printf("Upper 4 bits: ");
    for (i = 0; i < 4; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
    
    return 0;
}