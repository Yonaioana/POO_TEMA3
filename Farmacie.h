#ifndef FARMACIE_H_INCLUDED
#define FARMACIE_H_INCLUDED

class Farmacie
{
protected:
    int m_id;
public:
    Farmacie(int id=0);
    Farmacie(const Farmacie &f);
    Farmacie& operator= (const Farmacie &f);
    ~Farmacie();
    virtual void print();
    void SetIdFarmacie(int id);
    int GetIdFarmacie() const;
    friend std::istream& operator>> (std::istream &in, Farmacie &f);
    friend std::ostream& operator<< (std::ostream &out, const Farmacie &f);
    friend class FarmacieFizica;
    friend class FarmacieOnline;

};

class FarmacieFizica : public Farmacie
{


protected:
    std::string m_denumire;
    int m_nrAngajati;
    int m_profit;

public:
    //constructor default
    FarmacieFizica(int id = 0);
    ///constructor cu parametri
    FarmacieFizica(int id, const std::string &denumire, int nrAngajati, int profit);
    ///copy constructor
    FarmacieFizica(const FarmacieFizica &f);
    ///operator=
    FarmacieFizica& operator= (const FarmacieFizica &f);
    ///destructor
    ~FarmacieFizica();
    ///functie virtuala de afisare
    void print();
    ///setter, getter
    void SetDenumire(const std::string &denumire);
    void SetNumarAngajati(int nrAngajati);
    void SetProfit (int profit);
    int GetNumarAngajati() const;
    int GetProfit() const;

    const std::string& GetDenumire() const;
    ///supraincarcare operatori de citire si de afisare
    friend std::istream& operator>> (std::istream &in, FarmacieFizica &f);
    friend std::ostream& operator<< (std::ostream &out, const FarmacieFizica &f);

};

class FarmacieOnline : public Farmacie
{

protected:
    std::string m_web;
    int m_nrVizitatori;
    int m_discount;
    typedef std::tuple<std::string,int,int> m_tuple;
    m_tuple m_dateFarmacie;
    typedef std::vector< m_tuple > m_vec;
    static m_vec m_info;
public:
    //constructor default
    FarmacieOnline(int id=0);
    //constructor cu parametri
    FarmacieOnline(int id, std::string web, int nrVizitatori, int discount);
    //copy constructor
    FarmacieOnline(const FarmacieOnline &f);
    //assignment constructor
    FarmacieOnline& operator= (const FarmacieOnline &f);
    //destructor
    ~FarmacieOnline();
    //functie virtuala de afis
    void print();
    //functie care adauga o farmacie online in vector
    static void addFarmacieOnline(FarmacieOnline &f);
    static void ShowAllFarmaciiOnline();
    //supraincarcare operatori
    friend std::istream& operator>> (std::istream &in, FarmacieOnline &f);
    friend std::ostream& operator<< (std::ostream &out, const FarmacieOnline &f);
    friend bool operator== (const FarmacieOnline &f1, const FarmacieOnline &f2);
};

#endif //FARMACII_H_INCLUDED
