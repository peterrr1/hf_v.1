#include "lancolt_lista.hpp"



//beszúr egy elemet a lista elejére
void Lista::beszur(Adatok& adat) {
    try {
        if (this->szamKeres(adat.getPrivSzam()) || this->szamKeres(adat.getMunkSzam())) {
            throw std::runtime_error("\nMar letezik bejegyzes az adott telefonszammal.\n");
        }
        Elem *ujElem = new Elem(adat);
        
        if (elso == NULL)
            elso = ujElem;
        else {
            ujElem->kov = elso;
            elso = ujElem;
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
}


//hozzáfűz egy elemet a lista végéhez
void Lista::hozzafuz(Adatok& adat) {
    try {
        if (this->szamKeres(adat.getPrivSzam()) || this->szamKeres(adat.getMunkSzam())) {
            throw std::runtime_error("\nMar letezik bejegyzes az adott telefonszammal.\n");
        }
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
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
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
                        break;
                    }
                    else {
                        elozo->kov = tmp->kov;
                        delete tmp;
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



bool Lista::szamKeres(std::string telefonszam) const {
    bool talalat = false;
    for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
        if (telefonszam == tmp->adat.getPrivSzam() || telefonszam == tmp->adat.getMunkSzam()) {
            //kiir(tmp);
            talalat = true;
        }
    }
    return talalat;
}



void Lista::modosit(std::string telefonszam) {
    try {
        if (!this->szamKeres(telefonszam)) {
            throw std::runtime_error("\nA megadott telefonszam nem talalhato.\n");
        } 

        Elem* tmp = elso;
        Elem* elozo = NULL;

        while (tmp != NULL) {
            if (tmp->adat.getPrivSzam() == telefonszam || tmp->adat.getMunkSzam() == telefonszam) {
                std::cout << "\nA modositani kívant bejegyzes: " << std::endl;
                kiir(tmp);

                std::string tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;

                std::cout << "Nev: ";
                std::getline(std::cin, tmpNev);

                std::cout << "Becenev: ";
                std::getline(std::cin, tmpBecNev);

                std::cout << "Lakcim: ";
                std::getline(std::cin, tmpLakcim);

                std::cout << "Email: ";
                std::getline(std::cin, tmpEmail);

                std::cout << "Munkahelyi szam: ";
                std::getline(std::cin, tmpMunkSzam);

                std::cout << "Privat szam: ";
                std::getline(std::cin, tmpPrivSzam);
                
                std::cout << std::endl;

                Adatok ujAdat(tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);

                Elem* ujElem = new Elem(ujAdat);

                if (elso == tmp){
                    ujElem->kov = tmp->kov;
                    elso = ujElem;
                    delete tmp;
                }
                else {
                    ujElem->kov = tmp->kov;
                    elozo->kov = ujElem;
                    delete tmp;
                }
                break;
            }
            elozo = tmp;
            tmp = tmp->kov;
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
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
    Elem* tmp = elso;
    while (tmp != NULL) {
        Elem* tmpKov = tmp->kov;
        delete tmp;
        tmp = tmpKov;
    }
}
