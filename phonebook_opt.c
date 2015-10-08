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
            temp = temp->pLeft;
        } else {
            temp = temp->pRight;
        }
    }
    return NULL;
}

entry *append(char lastName[], entry *root)
{
    entry *temp = root;
    entry *newleaf;
    if (root == NULL) {
        /* allocate memory for the new entry and put lastName */
        root = (entry *) malloc(sizeof(entry));
        root->pRight = NULL;
        root->pLeft = NULL;
        strcpy(root->lastName, lastName);
        return root;
    } 
    while (temp != NULL) {
        if (strcasecmp(lastName, temp->lastName) <= 0) {
            if (temp->pLeft != NULL) {
                temp = temp->pLeft;
            } else {
                temp->pLeft = (entry *) malloc(sizeof(entry));
                newleaf = temp->pLeft;
                newleaf->pRight = NULL;
                newleaf->pLeft = NULL;                 
                strcpy(newleaf->lastName, lastName);
                temp = NULL;
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
                temp = NULL;
            }
        }
    }
    
    return root;
}
