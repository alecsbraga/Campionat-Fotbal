#include <variant>
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

    try
    {
        get<Echipa>(echipa_1);
    }
    catch(const bad_variant_access& e)
    {
        cout<<e.what()<<endl;
    }

    Patron patron_2("Pablo Cortacero", echipa_2);
    Stadion stadion_1("Ghencea",echipa_1);
    Stadion stadion_2("Stefan Cel Mare",echipa_2);
    Campionat campionat;

    ifstream f;
    try
    {
        f.open("Echipe.in");
        f>>campionat;
        campionat.joaca();
        campionat.ordoneaza();
        cout<<campionat;
        campionat.cine_a_castigat();

    }
    catch (const ifstream::failure& e)
    {
        cout<<"Execeptie deschidere/citire fisier";
    }
    f.close();

    return 0;
}
