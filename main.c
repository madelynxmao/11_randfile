#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// generates and returns a random number by reading in the correct number of bytes from /dev/random
int generate_random_number(){
    // where the random number is being stored
    int random_number[1];

    // open and read /dev/random
    int file_opened = open("/dev/random", O_RDONLY);

    if (file_opened == -1){
        printf("Error: %s\n", strerror(errno));
    }

    // Read sizeof(random_number) bytes from file_opened into random_number
    int populate_random_random = read(file_opened, random_number, sizeof(random_number));

    if (populate_random_random == -1){
        printf("Error: %s\n", strerror(errno));
    }

    close(file_opened);
    return random_number[0];
}

int main(){

    // create array with 10 random numbers
    int array_random[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        array_random[i] = generate_random_number();
        printf("random %d: %d \n", i,array_random[i]);
    }
    printf("\n");

    // open an output file, and write the contents of your array there.
    int output;
    output = open("./output.out", O_RDWR);

    if(output == -1){
        printf("Error: %s\n", strerror(errno));
    }
    
    int new_file;
    printf("\n Writing numbers to file...");
    new_file = write(output, array_random, sizeof(array_random));
  
    int test[10];
    // read new_file into a different array
    printf("\nReading numbers from file...");
    read(output, test, sizeof(test));

    // verifying that the numbers are the same

    printf("Verification that written values were the same:\n");
    for (i = 0; i < 10; i++){
        printf("random %d: %d \n",i, array_random[i]);
    }
    printf("\n");

    close(output);

    return 0;

}

