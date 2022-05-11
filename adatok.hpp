#ifndef adatok_hpp
#define adatok_hpp

#include <iostream>

class Adatok {
    std::string nev;
    std::string becenev;
    std::string lakcim;
    std::string email;
    std::string munkSzam;
    std::string privSzam;
    
public:
    Adatok(std::string aNev = "", std::string aBecenev = "", std::string aLakcim = "",
           std::string aEmail = "", std::string aMunkSzam = "", std::string aPrivSzam = "")
    : nev(aNev), becenev(aBecenev), lakcim(aLakcim), email(aEmail), munkSzam(aMunkSzam), privSzam(aPrivSzam) {}
    
    std::string getNev() const {
        return nev;
    }
    
    std::string getBecenev() const {
        return becenev;
    }

    std::string getLakcim() const {
        return lakcim;
    }
    
    std::string getEmail() const {
        return email;
    }
    
    std::string getMunkSzam() const {
        return munkSzam;
    }
    
    std::string getPrivSzam() const {
        return privSzam;
    }
    
    ~Adatok() {}
};
#endif /* adatok_hpp */
