#include "decor.h"

using namespace std;

Decor::Decor(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_menu=new Menu(*m_fenetre);

    m_tFondG.loadFromFile("donnees/fondG.png");
    m_sFondG.setTexture(m_tFondG);

    m_tCadreJeu.loadFromFile("donnees/ecranJ.png");
    m_sCadreJeu.setTexture(m_tCadreJeu);
}

Menu& Decor::getMenu()
{
    return *m_menu;
}

void Decor::afficheFondEc()
{
    m_fenetre->draw(m_sFondG);
}

void Decor::afficheCadreJeu()
{
    m_fenetre->draw(m_sCadreJeu);
}

Decor::~Decor()
{

}
