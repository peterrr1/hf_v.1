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
    
public:
    Lista() : elso(NULL) {}
    
    void beszur(Adatok& adat);
    
    void hozzafuz(Adatok& adat);
    
    void torol(std::string telefonszam);
    
    void nevKeres(std::string nev) const;
    
    bool szamKeres(std::string telefonszam) const;
    
    void modosit(std::string telefonszam);
    
    void kiir(Elem* tmp) const;
    
    void osszesKiir() const;
    
    ~Lista();
    
    friend class File;
};

#endif /* lancolt_lista_hpp */
