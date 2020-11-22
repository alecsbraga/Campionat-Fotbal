#include <iostream>
#include "Echipa.h"
#include "Patron.h"
#include "Stadion.h"
#include "Meci.h"
#include <vector>
#include <fstream>
#include "Campionat.h"

using namespace std;


int main()
{
    Echipa echipa_1("FCSB", 4, 1);
    Echipa echipa_2("FC Dinamo Bucuresti",2, 2, 1);
    Echipa echipa_3("CFR Cluj",3,1,1);
    cout<<echipa_1;
    cout<<echipa_2;
    cout<<echipa_3;
    Patron patron_1("Gigi Becali", echipa_1);
    Patron patron_2("Pablo Cortacero", echipa_2);
    Stadion stadion_1("Ghencea",echipa_1);
    Stadion stadion_2("Stefan Cel Mare",echipa_2);
    Campionat campionat;
    ifstream f("Echipe.in");
    f>>campionat;
    campionat.meciuri();
    campionat.ordoneaza();
    cout<<campionat;
    campionat.cine_a_castigat();
    return 0;
}
