#include "contact.h"
#include <stdio.h>
#include <string.h>
#include <rpc/rpc.h>

#define MAX_CONTACTS 100

static Contact contactList[MAX_CONTACTS];
static int contactCount = 0;

int *ajoutercontact_1_svc(Contact *c, struct svc_req *rqstp) {
    static int result;
    if (contactCount >= MAX_CONTACTS) {
        result = 0;
    } else {
        contactList[contactCount++] = *c;
        result = 1;
    }
    return &result;
}

char **recherchercontact_1_svc(char **nom, struct svc_req *rqstp) {
    static char result[20];
    static char *res_ptr;

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contactList[i].nom, *nom) == 0) {
            strcpy(result, contactList[i].numero);
            res_ptr = result;
            return &res_ptr;
        }
    }

    strcpy(result, "Non trouvé");
    res_ptr = result;
    return &res_ptr;
}

int *supprimercontact_1_svc(char **nom, struct svc_req *rqstp) {
    static int result;
    result = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contactList[i].nom, *nom) == 0) {
            contactList[i] = contactList[--contactCount];
            result = 1;
            break;
        }
    }
    return &result;
}

ContactList *affichercontacts_1_svc(void *argp, struct svc_req *rqstp) {
    static ContactList result;
    result.contacts.contacts_len = contactCount;
    result.contacts.contacts_val = contactList;
    return &result;
}
