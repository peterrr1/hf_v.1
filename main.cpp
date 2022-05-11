#include <iostream>
#include "lancolt_lista.hpp"
#include "adatok.hpp"
#include "filekezeles.hpp"


int main() {
    
    Lista ll;
    File ff;
    
    ff.fileBeolvas(ll);




    Adatok peti("Brezovcsik Peter", "Brezo", "1028 Budapest", "brezop@gmail.com", "0640554332", "06204355322");

    ll.beszur(peti);




    Adatok vivi("Kiss Vivien", "Viv", "1022 Budapest", "viv@gmail.com", "0670456622", "06308864532");

    ll.beszur(vivi);



    ll.modosit("06308864532");

    ll.osszesKiir();


    ff.fileKiir(ll);

    return 0;
}
