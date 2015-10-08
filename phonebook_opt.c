#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *root)
{
    entry *temp = root;
    while (temp != NULL) {
        if (strcasecmp(temp->lastName, lastname) == 0){
            return temp;
        } else if (strcasecmp(temp->lastName, lastname) < 0){
            temp = temp->pRight;
        } else {
            temp = temp->pLeft;
        }
    }
    return NULL;
}

entry *append(char lastName[], entry *root)
{
    entry *temp = root;
    entry *newleaf;
    int put = 0;

    while (put == 0) {
        if (strcasecmp(lastName, temp->lastName) <= 0) {
            if (temp->pLeft != NULL) {
                temp = temp->pLeft;
            } else {
                temp->pLeft = (entry *) malloc(sizeof(entry));
                newleaf = temp->pLeft;
                newleaf->pRight = NULL;
                newleaf->pLeft = NULL;                 
                strcpy(newleaf->lastName, lastName);
                put = 1;
            }
        } else {
            if (temp->pRight != NULL) {
                temp = temp->pRight;
            } else {
                temp->pRight = (entry *) malloc(sizeof(entry));
                newleaf = temp->pRight;
                newleaf->pRight = NULL;
                newleaf->pLeft = NULL;
                strcpy(newleaf->lastName, lastName);
                put = 1;
            }
        }
    }
    
    return temp;
}
