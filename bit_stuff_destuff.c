#include <stdio.h>
#include <string.h>

int main() {
    char flag[] = "01111110"; 
    int size = 100;

    
    char data[size]; 
    int i = 0;
    int f = 1;
    printf("Enter the data bits:\n");
   while(f == 1){
    scanf("%c", &data[i]);
    if (data[i] == '\n'){
        f = 0;
    }
    i++;
   }
    // Printing the original data
    printf("Original data: %s\n", data);
    int newsize = size;
    int count = 0;
    int j = 0;
    for (int i = 0; i < newsize; i++) {
        if (data[i] == flag[j]) {
            count++;
        } else {
            count = 0;
        }
        if (count == 6) {
            // Perform bit stuffing by shifting the array to the right
            for (int j = newsize; j > i; j--) {
                data[j + 1] = data[j];
            }
            data[i + 1] = '0'; // Insert '0' after 6 consecutive repeated elements
            count = 0; // Reset the counter
            i++; // Move past the inserted '0'
            newsize++;
        }
        j++;
        if(j == 6)
            j = 0;
        
    }

    printf("Data after bit stuffing: %s\n", data);
    count = 0;
    for(int i =0; i<newsize; i++){
        if (data[i] == flag[i]){
            count = count + 1;
        }
        if (count==6){
            for (int j =i; j<newsize; j++){
                data[j+1] =  data[j+2];
            }
            count = 0;
            i++;
        }       

    }
    printf("Data after bit destuffing: %s\n", data);

    return 0;
}
