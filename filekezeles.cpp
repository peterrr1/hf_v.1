#include "filekezeles.hpp"
#include <sstream>



void File::fileBeolvas(Lista& lista) {

    std::fstream file;
    
    file.open("telefonkonyv.txt", std::ios::in);
    try {
        if (!file)
            throw std::runtime_error("\nHiba a fajl megnyitasa kozben.\n");
        else {
            std::string sor;
            
            while (std::getline(file, sor)) {
                
                std::stringstream ss(sor);
                
                std::string tmpNev, tmpBecenev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;
                
                std::getline(ss, tmpNev, ':');
                std::getline(ss, tmpBecenev, ':');
                std::getline(ss, tmpLakcim, ':');
                std::getline(ss, tmpEmail, ':');
                std::getline(ss, tmpMunkSzam, ':');
                std::getline(ss, tmpPrivSzam, ':');
                
                Adatok ujAdat(tmpNev, tmpBecenev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);
                
                lista.hozzafuz(ujAdat);
                
            }
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    file.close();
}



void File::fileKiir(Lista& lista) const {
    
    std::fstream file;
    
    file.open("telefonkonyv.txt", std::ios::out);
    try {
        if (!file)
            throw std::runtime_error("\nHiba a fajl megnyitasa kozben.\n");
        else {
            for (Lista::Elem* tmp = lista.elso; tmp != NULL; tmp = tmp->kov){
                file << tmp->adat.getNev() << ':' << tmp->adat.getBecenev() << ':' <<
                tmp->adat.getLakcim() << ':' << tmp->adat.getEmail() << ':' <<
                tmp->adat.getMunkSzam() << ':' << tmp->adat.getPrivSzam() << '\n';
            }
        }
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    file.close();
};
