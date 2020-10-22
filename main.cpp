#include <iostream>

using namespace std;

class Echipa
{
    string nume_echipa;
    int nr_partide, nr_partide_castigate, nr_partide_egale, nr_partide_pierdute;
    int *punctaj;

public:

    void punctaj_calculat(int nr_partide_castigate,int nr_partide_egale)
    {
        punctaj= new int(nr_partide_castigate*3+nr_partide_egale);

    }
    void afisare_date()
    {
        cout<<nume_echipa<<" "<<nr_partide<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" "<<*punctaj<<'\n';
    }

    ///Am redus numarul de constructori la unul folosind parametri impliciti
   /*
    Echipa();

   Echipa(string);

   Echipa(string, int);

   Echipa(string, int, int);

   Echipa(string, int, int, int);
    */
    Echipa(string nume_echipa = "noname", int nr_partide = 0, int nr_partide_castigate = 0, int nr_partide_egale = 0, int nr_partide_pierdute = 0);

    Echipa(Echipa &);

    ~Echipa();
};
/*
Echipa::Echipa()
{
    nume_echipa = "noname";
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();

}

Echipa::Echipa(string nume_echipa)
{
    this->nume_echipa = nume_echipa;
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide, int nr_partide_castigate)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide, int nr_partide_castigate, int nr_partide_egale)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}
*/
Echipa::Echipa(string nume_echipa, int nr_partide, int nr_partide_castigate, int nr_partide_egale, int nr_partide_pierdute)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    this->nr_partide_pierdute = nr_partide_pierdute;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(Echipa &echipa)
{
    cout<<"Copie club: ";
    this->nume_echipa = echipa.nume_echipa;
    this->nr_partide = echipa.nr_partide;
    this->nr_partide_castigate = echipa.nr_partide_castigate;
    this->nr_partide_egale = echipa.nr_partide_egale;
    this->nr_partide_pierdute = echipa.nr_partide_pierdute;
    this->punctaj = echipa.punctaj;
    afisare_date();
}

Echipa::~Echipa()
{
    delete punctaj;
    cout<<'\n'<<"Gata cu "<<nume_echipa;
}

int main()
{
    Echipa echipa_1;

    Echipa echipa_2("FCSB");

    Echipa echipa_3("FC Dinamo Bucuresti",1);

    Echipa echipa_4("CFR Cluj",2,2);

    Echipa echipa_5("CS U Craiova",3,1,2);

    Echipa echipa_6("Astra Giurgiu",3,1,1,1);

    Echipa echipa_7(echipa_6);

  //  Echipa echipa_8 = echipa_6;

    return 0;
}
