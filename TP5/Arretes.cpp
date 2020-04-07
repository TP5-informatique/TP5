#include "Arretes.h"
#include <iostream>
#include <vector>
#include <string>

Arretes::Arretes(int numero, int sommet1,int sommet2, int poids)
{
    m_numero = numero;
    m_poids = poids;
    m_lien.push_back(sommet1);
    m_lien.push_back(sommet2);
}

Arretes::~Arretes()
{

}

void Arretes::afficher()const{
    std::cout << "Arrete " << Arretes.m_numero << " : " << "lien entre les sommets " << Arretes.m_lien[0]
    << "\t" << Arretes.m_lien[1] <<"\t de poids \t" << Arretes.m_poids << std::endl;
}

int Arretes::getLien(int numero)const{
    return Arretes.m_lien[numero];
}

int Arretes::getNum() const
{
    return Arretes.m_numero;
}

int Arretes::getPoids()const
{
    return Arretes.m_poids;
}
