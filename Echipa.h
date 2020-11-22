#ifndef ECHIPA_H_INCLUDED
#define ECHIPA_H_INCLUDED
#include <iostream>

class Echipa
{
    std::string nume_echipa;
    int nr_partide_castigate, nr_partide_egale, nr_partide_pierdute;

public:

    void a_castigat_un_meci()
    {
        nr_partide_castigate++;
    }

    void a_pierdut_un_meci()
    {
        nr_partide_pierdute++;
    }

    void a_facut_egal()
    {
        nr_partide_egale++;
    }

    int Punctaj()
    {
       return (3*nr_partide_castigate+nr_partide_egale);
    }

    void echipa_nume() const
    {
        std::cout<<nume_echipa;
    }


    Echipa(std::string nume_echipa = "noname", int nr_partide_castigate = 0, int nr_partide_egale = 0, int nr_partide_pierdute = 0)
        :nume_echipa{nume_echipa},
         nr_partide_castigate{nr_partide_castigate},
         nr_partide_egale{nr_partide_egale},
         nr_partide_pierdute{nr_partide_pierdute}
    {

    }

    Echipa(const Echipa &echipa)
        :nume_echipa{echipa.nume_echipa},
         nr_partide_castigate{echipa.nr_partide_castigate},
         nr_partide_egale{echipa.nr_partide_egale},
         nr_partide_pierdute{echipa.nr_partide_pierdute}
    {

    }

    Echipa& operator=(const Echipa &echipa);

    friend std::ostream& operator<<(std::ostream&, Echipa& );

    friend std::istream& operator>>(std::istream&, Echipa& );

    ~Echipa();

};

#endif // ECHIPA_H_INCLUDED
