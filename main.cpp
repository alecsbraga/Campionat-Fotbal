#include <iostream>

using namespace std;

class Echipa
{
    string nume_echipa;
    int nr_partide, nr_partide_castigate, nr_partide_egale, nr_partide_pierdute, punctaj;

public:

    void punctaj_calculat(int nr_partide_castigate,int nr_partide_egale)
    {
        punctaj=nr_partide_castigate*3+nr_partide_egale;

    }
    void afisare_date()
    {
        cout<<nume_echipa<<" "<<nr_partide<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" "<<punctaj<<'\n';
    }
    ///Am redus numarul de constructori la unul, folosind parametri impliciti
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

}

Echipa::Echipa(Echipa &echipa)
{
    this->nume_echipa = echipa.nume_echipa;
    this->nr_partide = echipa.nr_partide;
    this->nr_partide_castigate = echipa.nr_partide_castigate;
    this->nr_partide_egale = echipa.nr_partide_egale;
    this->nr_partide_pierdute = echipa.nr_partide_pierdute;
    this->punctaj = echipa.punctaj;

}

Echipa::~Echipa()
{
    cout<<'\n'<<"Gata cu "<<nume_echipa<<'\n';
}

class Patron
{
    string nume_patron;
    Echipa echipa;
public:
    void afisare_date()
    {
        cout<<"Patron: "<<nume_patron<<" "<<", club: ";
        echipa.afisare_date();
    }
    Patron(string nume_patron, Echipa echipa);
    ~Patron();

};

Patron::Patron(string nume_patron, Echipa echipa)
{
    this->nume_patron = nume_patron;
    this->echipa = echipa;
    afisare_date();
}

Patron::~Patron()
{
    cout<<"Gata cu "<<nume_patron<<endl;
}

class Stadion
{
    string nume_stadion;
    Echipa echipa;
public:
    void afisare_date()
    {
        cout<<"Stadion: "<<nume_stadion<<" ";
        echipa.afisare_date();
    }
    Stadion(string, Echipa);
    ~Stadion();

};

Stadion::Stadion(string nume_stadion, Echipa echipa)
{
    this->nume_stadion = nume_stadion;
    this->echipa = echipa;
    afisare_date();
}

Stadion::~Stadion()
{
    cout<<"Gata cu " << nume_stadion;
}

int main()
{
    Echipa echipa_1("FCSB", 5, 4, 1);
    Patron patron("Gigi Becali", echipa_1);
    Stadion stadion("Ghencea",echipa_1);
    return 0;
}
