#include "Graphe.h"
#include <fstream>
#include <queue>
#include <stack>

Graphe::Graphe(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if(!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'orientation du graphe.");
    }
    int ordre;
    ifs >> ordre;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de la taille du graphe.");
    }
    for(int i=0; i<ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
    }
    int num1, num2, num3;
    for(int i=0; i<taille; ++i) {
        ifs >> num1 >> num2 >> num3;
        if(ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un.e arc/arête.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2]);
        if(!m_estOriente && num1 < num2) {
            m_sommets[num2]->addSuccesseur(m_sommets[num1]);
        }
        m_arretes.push_back(new Arretes(i,num1,num2,num3));
    }
}

Graphe::~Graphe() {
    for(auto addrSommet : m_sommets) {
        delete addrSommet;
    }
    for(auto addrArretes : m_arretes)
    {
        delete addrArretes;
    }
}

void Graphe::afficher() const {
    std::cout << std::endl << "Graphe ";
    std::cout << (m_estOriente ? "orienté" : "non orienté") << std::endl;
    std::cout << "Ordre : " << m_sommets.size() << std::endl;
    std::cout << "Liste d'adjacences : " << std::endl;
    for(auto addrSommet : m_sommets) {
        addrSommet->afficher();
        std::cout << std::endl;
    }
    std::cout << "Liste des arretes : " << std::endl;
    for(auto addrArretes : m_arretes) {
        addrArretes->afficher();
        std::cout << std::endl;
    }

}

std::vector<std::vector<int>> Graphe::kruskal()const{
    std::vector<std::vector<int>> listeSommets;

    for(size_t e=0 ; e<m_sommets.size();++e)
    {
        listeSommets[e].push_back((int)e);
    }
    int ancienPlusPetit=0,positionSommet1=-1, positionSommet2=-1;
    int sommet1 , sommet2;
    int arreteSelec = -1;
    bool action = false;

    while(action==false){
    int lePluspetit=m_arretes[0].getPoids();
    //test de l'arrete la plus legere
    for (size_t y=0;y<m_arretes.size();++y)
    {
        if (lePluspetit>m_arretes[y].getPoids() &&m_arretes[y].getPoids() > ancienPlusPetit)
        {
            lePluspetit=m_arretes[y].getPoids();
            arreteSelec = (int)y;
        }
    }
    sommet1 = m_arretes[arreteSelec].getLien(0);
    sommet2 = m_arretes[arreteSelec].getLien(1);
    // check position sommet 1
    for (size_t a=0; a< listeSommets.size();++a)
    {
        for(size_t f=0; f<listeSommets[a].size();f++)
        {
            if(listeSommets[a][f]==sommet1)
            {
                positionSommet1=a;
            }
        }
    }
    // check position sommet 2
    for (size_t a=0; a< listeSommets.size();++a)
    {
        for(size_t f=0; f<listeSommets[a].size();f++)
        {
            if(listeSommets[a][f]==sommet1)
            {
                positionSommet2=a;
                if((int)a==positionSommet1)
                {
                    action = false;
                }
                else
                {
                    action = true;
                }
            }
        }
    }
    ancienPlusPetit=lePluspetit;
}
    if (action==true)
    {
        for(size_t d=0;d<listeSommets[positionSommet1].size();++d)
        {
            listeSommets[positionSommet2].push_back(listeSommets[positionSommet1][d]);
            listeSommets[positionSommet1][d]=-1;
        }
    }
    action =false;


    return listeSommets;
}
