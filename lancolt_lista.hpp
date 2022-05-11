#ifndef lancolt_lista_hpp
#define lancolt_lista_hpp

#include <iostream>
#include "adatok.hpp"

class Lista {
    struct Elem {
        Adatok adat;
        Elem* kov;
        Elem(Adatok& ujAdat) : adat(ujAdat), kov(NULL) {}
    };
    
    Elem* elso;
    int elemszam;
    
public:
    Lista() : elso(NULL), elemszam(0) {}
    
    void beszur(Adatok& adat);
    
    void hozzafuz(Adatok& adat);
    
    void torol(std::string telefonszam);
    
    void nevKeres(std::string nev) const;
    
    void szamKeres(std::string telefonszam) const;
    
   // void modosit(std::string telefonszam);
    
    void kiir(Elem* tmp) const;
    
    void osszesKiir() const;
    
    int meret() const {
        return elemszam;
    }
    
    ~Lista();
    
    friend class File;
};

#endif /* lancolt_lista_hpp */
