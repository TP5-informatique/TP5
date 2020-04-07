#include "Sommets.h"


Sommet::Sommet(int num) : m_numero{num} {}


void Sommet::addSuccesseur(const Sommet* succ) {
    m_successeurs.push_back(succ);
}

const std::vector<const Sommet*>& Sommet::getSuccesseurs() const {
    return m_successeurs;
}

int Sommet::getNumero() const {
    return m_numero;
}

void Sommet::afficher() const {
    std::cout << "   Sommet " << m_numero << " : ";
    for(auto addrSommet : m_successeurs) {
        std::cout << addrSommet->getNumero() << " ";
    }
}

int Sommet::getNbSuccesseur()const{

    int le =0;
    le = (int)m_successeurs.size();
    return le;

}
