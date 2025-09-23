struct Contact {
    string nom<100>;
    string numero<20>;
};

program CONTACT_PROG {
    version CONTACT_VER {
        int ajouterContact(Contact) = 1;
        string rechercherContact(string) = 2;
        int supprimerContact(string) = 3;
        ContactList afficherContacts(void) = 4;
    } = 1;
} = 0x31234567;

struct ContactList {
    Contact contacts<100>;
};
