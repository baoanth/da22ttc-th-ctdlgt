#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];

    // M? t?p vãn b?n ð? ð?c
    file = fopen("bac.txt", "r");
    if (file == NULL) {
        printf("Không th? m? t?p vãn b?n.\n");
        return 1;
    }

    // Ð?c t?ng d?ng trong t?p vãn b?n
    while (fgets(line, sizeof(line), file)) {
        // Lo?i b? k? t? newline
        line[strcspn(line, "\n")] = '\0';

        // Phân tách d?ng thành hai chu?i b?ng d?u ph?y
        token = strtok(line, ",");
        if (token != NULL) {
        	
            strcpy(ma, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(ten, token);

                // In ra các bi?n "ma" và "ten"
                printf("Ma: %s\n", ma);
                printf("Ten: %s\n", ten);
            }
        }
    }

    // Ðóng t?p vãn b?n
    fclose(file);

    return 0;
}

