#include "Gestionar.h"
#include <iostream>
#include <vector>
#include <algorithm>

//instantierea vectorului de obiecte
template <class T>
std::vector<T> GestionareFarmacii<T>::m_arr;

template <class T>
GestionareFarmacii<T>::GestionareFarmacii()
{
    std::cout<<"Am creat un obiect GestionareFarmacii"<<std::endl;
    m_indexFarmacie = 0;
    m_idLant = 0;
}

template <class T>
GestionareFarmacii<T>::~GestionareFarmacii()
{
    std::cout<<"Am distrus obiectul GestionareFarmacii cu id-ul lantului: "<<m_idLant<<std::endl;
}

template <class T>
void GestionareFarmacii<T>::SetIndexFarmacie(int val)
{
    m_indexFarmacie = val;
}

template <class T>
int GestionareFarmacii<T>::GetIndexFarmacie(T) const
{
    return m_indexFarmacie;
}

template <class T>
void GestionareFarmacii<T>::SetIdLant(int id)
{
    m_idLant = id;
}
template <class T>
int GestionareFarmacii<T>::GetIdLant() const
{
    return m_idLant;
}

template <class T>
void GestionareFarmacii<T>::addFarmacie(T t)
{
    m_indexFarmacie++;
    m_arr.push_back(t);

}

template <class T>
void GestionareFarmacii<T>::removeFarmacie(T t)
{
    m_arr.erase(std::remove(m_arr.begin(), m_arr.end(), t), m_arr.end());
    m_indexFarmacie--;
}

template <class T>
void GestionareFarmacii<T>::afiseazaFarmacii()
{
    for (unsigned int i = 0; i<m_arr.size(); i++)
        std::cout<<m_arr[i]<<std::endl;//obiectul de tipul T din m_arr
}
