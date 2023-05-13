#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

int main() {

    HashTable *table = createHashTable(1000);
    FILE *file = fopen("file.txt", "r");

    while (1) {
        printf("\nEnter the command:\n 1 - load\n 2 - add\n 3 - delete\n 4 - find\n 5 - printf\n 6 - out\nCommand:  ");
        int command;
        fflush(stdin);
        scanf("%d", &command);

        if (command == 1) {
            int n;
            printf("Amount of rows ");
            scanf("%d", &n);

            if (file == NULL) {
                printf("Error with file \n");
                continue;
            }

            char key[50];
            int count = 0;
            while (count < n && fscanf(file, "%s", key) != EOF) {
                if (key[strlen(key) - 1] == '\n') {
                    key[strlen(key) - 1] = '\0';
                }
                char *value = generateRandomIpAddress();

                char* copiedKey = (char*) malloc(sizeof(char) * (strlen(key) + 1));
                strcpy(copiedKey, key);
                putHashTableEntry(table, copiedKey, value);
                count++;
            }

            printf("Download was successful.\n");
        }
        else if (command == 2) {
            char key[50];
            printf("Enter the row: ");
            scanf("%s", key);

            char *value = generateRandomIpAddress();
            char* copiedKey = (char*) malloc(sizeof(char) * (strlen(key) + 1));
            strcpy(copiedKey, key);
            putHashTableEntry(table, copiedKey, value);
            printf("The element was added.\n");
        }
        else if (command == 3) {
            char key[50];
            printf("Enter the row: ");
            scanf("%s", key);

            deleteHashTableEntry(table, key);

            printf("The element was deleted.\n");
        }
        else if (command == 4) {
            char key[50];
            printf("Enter the row: ");
            scanf("%s", key);

            struct HashTableEntry *entry = getHashTableEntry(table, key);

            if (entry != NULL) {
                if (strcmp(entry->key, key) == 0)
                    printf("Ip address: %s\n", entry->value);
                while (entry->next != NULL) {
                    entry = entry->next;
                    if (strcmp(entry->key, key) == 0)
                        printf("Ip address: %s\n", entry->value);
                }
            } else {
                printf("The element was not found.\n");
            }
        }
        else if (command == 5)output(table);
        else if (command == 6) {
            break;
        }
        else {
            printf("Error: you enter incorrect data!.\n");
        }
    }
    fclose(file);

    return 0;
}
