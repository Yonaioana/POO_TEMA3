#ifndef GESTIONAR_H_INCLUDED
#define GESTIONAR_H_INCLUDED
#include <vector>

template<class T>
class GestionareFarmacii
{
private:
    int m_indexFarmacie;
    int m_idLant;
    static std::vector<T> m_arr;

public:

    GestionareFarmacii();
    ~GestionareFarmacii();
    void SetIndexFarmacie(int val);
    int GetIndexFarmacie(T) const;

    void SetIdLant(int id);
    int GetIdLant() const;

    void addFarmacie(T t);
    void removeFarmacie(T t);
    static void afiseazaFarmacii();

};

#endif // GESTIONARE_H_INCLUDED
