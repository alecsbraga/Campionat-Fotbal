#include <iostream>
#include <cstring>

using namespace std;

class Echipa
{
    char nume_echipa[30];
    int nr_partide, nr_partide_castigate, nr_partide_egale, nr_partide_pierdute, punctaj;

public:

    void afisare_date()
    {
        cout<<nume_echipa<<" "<<nr_partide<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" "<<punctaj<<'\n';
    }

    Echipa();

    Echipa(const char []);

    Echipa(const char [], int);

    Echipa(const char [], int, int);

    Echipa(const char [], int, int, int)
    ;
    Echipa(const char [], int, int, int, int);

    Echipa(const char [], int, int, int, int, int);

    Echipa(Echipa &);

    ~Echipa();
};

Echipa::Echipa()
{
    strcpy(nume_echipa,"noname");
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj = 0;
    afisare_date();

}

Echipa::Echipa(const char nume_echipa[30])
{
    strcpy(this->nume_echipa, nume_echipa);
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj = 0;
    afisare_date();
}

Echipa::Echipa(const char nume_echipa[30], int nr_partide)
{
    strcpy(this->nume_echipa, nume_echipa);
    this->nr_partide = nr_partide;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj = 0;
    afisare_date();
}

Echipa::Echipa(const char nume_echipa[30], int nr_partide, int nr_partide_castigate)
{
    strcpy(this->nume_echipa, nume_echipa);
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj = 0;
    afisare_date();
}

Echipa::Echipa(const char nume_echipa[30], int nr_partide, int nr_partide_castigate, int nr_partide_egale)
{
    strcpy(this->nume_echipa, nume_echipa);
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    nr_partide_pierdute = 0;
    punctaj = 0;
    afisare_date();
}

Echipa::Echipa(const char nume_echipa[30], int nr_partide, int nr_partide_castigate, int nr_partide_egale, int nr_partide_pierdute)
{
    strcpy(this->nume_echipa, nume_echipa);
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    this->nr_partide_pierdute = nr_partide_pierdute;
    this->punctaj = 0;
    afisare_date();
}

Echipa::Echipa(const char nume_echipa[30], int nr_partide, int nr_partide_castigate, int nr_partide_egale, int nr_partide_pierdute, int punctaj)
{
    strcpy(this->nume_echipa, nume_echipa);
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    this->nr_partide_pierdute = nr_partide_pierdute;
    this->punctaj = punctaj;
    afisare_date();
}

Echipa::Echipa(Echipa &echipa)
{
    cout<<"Copie club: ";
    strcpy(this->nume_echipa,echipa.nume_echipa);
    this->nr_partide = echipa.nr_partide;
    this->nr_partide_castigate = echipa.nr_partide_castigate;
    this->nr_partide_egale = echipa.nr_partide_egale;
    this->nr_partide_pierdute = echipa.nr_partide_pierdute;
    this->punctaj = echipa.punctaj;
    afisare_date();
}

Echipa::~Echipa()
{
    cout<<'\n'<<"Gata cu "<<nume_echipa;
}

int main()
{
    Echipa echipa_1;

    Echipa echipa_2("FCSB");

    Echipa echipa_3("FC Dinamo Bucuresti",1);

    Echipa echipa_4("CFR Cluj",2,2);

    Echipa echipa_5("CS U Craiova",3,1,2);

    Echipa echipa_6("Astra Giurgiu",3,0,0,3);

    Echipa echipa_7("Arges Pitesti",3,3,0,0,9);

    Echipa echipa_8(echipa_7);

    Echipa echipa_9 = echipa_6;

    return 0;
}
