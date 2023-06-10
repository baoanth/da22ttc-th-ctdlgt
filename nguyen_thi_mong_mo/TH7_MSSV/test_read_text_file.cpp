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

    // M? t?p v�n b?n �? �?c
    file = fopen("bac.txt", "r");
    if (file == NULL) {
        printf("Kh�ng th? m? t?p v�n b?n.\n");
        return 1;
    }

    // �?c t?ng d?ng trong t?p v�n b?n
    while (fgets(line, sizeof(line), file)) {
        // Lo?i b? k? t? newline
        line[strcspn(line, "\n")] = '\0';

        // Ph�n t�ch d?ng th�nh hai chu?i b?ng d?u ph?y
        token = strtok(line, ",");
        if (token != NULL) {
        	
            strcpy(ma, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(ten, token);

                // In ra c�c bi?n "ma" v� "ten"
                printf("Ma: %s\n", ma);
                printf("Ten: %s\n", ten);
            }
        }
    }

    // ��ng t?p v�n b?n
    fclose(file);

    return 0;
}

