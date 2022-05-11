#include "lancolt_lista.hpp"

//beszúr egy elemet a lista elejére
void Lista::beszur(Adatok& adat) {
    Elem *ujElem = new Elem(adat);
    
    if (elso == NULL)
        elso = ujElem;
    else {
        ujElem->kov = elso;
        elso = ujElem;
    }
    elemszam++;
}



//hozzáfűz egy elemet a lista végéhez
void Lista::hozzafuz(Adatok& adat) {
    Elem *ujElem = new Elem(adat);
    
    if (elso == NULL)
        elso = ujElem;
    else {
        Elem* tmp = elso;
        while (tmp->kov != NULL) {
            tmp = tmp->kov;
        }
        tmp->kov = ujElem;
    }
    elemszam++;
}



//torol a listából egy meghatározott elemet, ha az benne van
void Lista::torol(std::string telefonszam) {
    try {
        if (elso == NULL)
            throw std::length_error("\nNem lehet ures listat torolni.\n");
        else {
            Elem* elozo = NULL;
            for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
                if (tmp->adat.getPrivSzam() == telefonszam || tmp->adat.getMunkSzam() == telefonszam) {
                    if (tmp == elso) {
                        elso = tmp->kov;
                        delete tmp;
                        elemszam--;
                        break;
                    }
                    else {
                        elozo->kov = tmp->kov;
                        delete tmp;
                        elemszam--;
                        break;
                    }
                }
                elozo = tmp;
            }
        }
    }
    catch (std::length_error& err) {
        std::cerr << err.what() << std::endl;
    }
}



void Lista::nevKeres(std::string nev) const {
    bool talalat = false;
    for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (nev == tmp->adat.getNev()) {
            kiir(tmp);
            talalat = true;
        }
    }
    if (!talalat) {
        std::cout << "\nNem talalhato szemely a megadott nevvel.\n" << std::endl;
    }
}



void Lista::szamKeres(std::string telefonszam) const {
    bool talalat = false;
    for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (telefonszam == tmp->adat.getPrivSzam() || telefonszam == tmp->adat.getMunkSzam()) {
            kiir(tmp);
            talalat = true;
        }
    }
    if (!talalat) {
        std::cout << "\nNem talalhato szemely a megadott telefonszammal.\n" << std::endl;
    }
}



void Lista::kiir(Elem* tmp) const {
    std::cout << tmp->adat.getNev() << '\n' << tmp->adat.getBecenev() << '\n' << tmp->adat.getLakcim() <<
    '\n' << tmp->adat.getEmail() << '\n' << tmp->adat.getMunkSzam() << '\n' << tmp->adat.getPrivSzam() << '\n' << std::endl;
}



//elemek kiírása
void Lista::osszesKiir() const {
    for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
        kiir(tmp);
    }
}



//destruktor
Lista::~Lista() {
    while (elemszam != 0) {
        Elem* tmp = elso;
        elso = elso->kov;
        tmp = NULL;
        delete tmp;
        elemszam--;
    }
}
