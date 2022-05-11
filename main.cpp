#include <iostream>
#include "lancolt_lista.hpp"
#include "adatok.hpp"
#include "filekezeles.hpp"


int main() {
    
    Lista ll;
    File ff;
    
    ff.fileBeolvas(ll);
    
    
    ll.torol("06204355322");
    
    
    Adatok peti("Peter", "Peti", "Budapest", "brezop@gmail.com", "06304343554", "06204355322");
    
    ll.beszur(peti);
    
    
    Adatok vivi("Vivien", "Vivi", "Budapest", "vivien@gmail.com", "06708822122", "06306574998");
    
    ll.beszur(vivi);
    
    
    Adatok gabor("Gabor", "Gabi", "Gyor", "gabor@gmail.com", "06506783991", "06208876887");
    
    ll.hozzafuz(gabor);
    
    
    ll.torol("06204355322");
    
    
    ll.hozzafuz(peti);
    
    Adatok david("David Dick", "Dav", "Nagykanizsa", "david@freemail.hu", "06201111112", "06909999112");
    
    ll.beszur(david);
    
    ll.torol("06201111112");
    
    std::cout << ll.meret() << std::endl;
    
    ll.osszesKiir();
    
    ll.nevKeres("Vivien");
    
    ll.nevKeres("Andras");
    
    ll.szamKeres("06204355322");
    
    ll.szamKeres("06303333333");
    
    ff.fileKiir(ll);
    
    return 0;
}
