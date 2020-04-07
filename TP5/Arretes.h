#ifndef ARRETES_H
#define ARRETES_H
#include <vector>

class Arretes
{
    public:
        Arretes(int numero, int sommet1, int sommet2, int poids);
        ~Arretes();
        void afficher ()const;
        int getPoids ()const;
        int getNum ()const;
        int getLien (int numero) const;

    private:
        int m_numero, m_poids;
        std::vector<int> m_lien;
};

#endif // ARRETES_H
