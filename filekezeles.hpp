#ifndef filekezeles_hpp
#define filekezeles_hpp

#include <iostream>
#include <fstream>
#include "lancolt_lista.hpp"

class File {
public:
    void fileBeolvas(Lista& lista);
    
    void fileKiir(Lista& lista) const;
};


#endif /* filekezeles_hpp */
