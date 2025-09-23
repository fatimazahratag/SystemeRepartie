// contact.x
/*
 * File to define the remote procedure calls.
 */

#include <rpc/rpc.h>

struct Contact {
    string nom<100>;
    string numero<20>;
};

struct ContactList {
    struct Contact *contacts_val;
    int contacts_len;
};

program CONTACT_PROG {
    version CONTACT_VER {
        int ajouterContact(Contact) = 1;
        string rechercherContact(string) = 2;
        int supprimerContact(string) = 3;
        ContactList afficherContacts(void) = 4;
    } = 1;
} = 0x31234567;
