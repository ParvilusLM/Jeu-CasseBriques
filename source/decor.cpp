#include "decor.h"

using namespace std;

Decor::Decor(sf::RenderWindow& fenetre):m_fenetre(0),m_menu(0),m_brique(0),m_palette(0),m_balle(0),m_info(0)
{
    m_fenetre=&fenetre;

    m_menu=new Menu(*m_fenetre);
    m_brique=new Brique(*m_fenetre);
    m_palette=new Palette(*m_fenetre);
    m_balle=new Balle(*m_fenetre);
    m_info=new Info(*m_fenetre);

    m_tFondG.loadFromFile("donnees/fondG.png");
    m_sFondG.setTexture(m_tFondG);

    m_tCadreJeu.loadFromFile("donnees/ecranJ.png");
    m_sCadreJeu.setTexture(m_tCadreJeu);
}

Menu& Decor::getMenu()
{
    return *m_menu;
}

Brique& Decor::getBrique()
{
    return *m_brique;
}

Palette& Decor::getPalette()
{
    return *m_palette;
}

Balle& Decor::getBalle()
{
    return *m_balle;
}

Info& Decor::getInfo()
{
    return *m_info;
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
    delete m_menu;
    delete m_info;
    delete m_palette;
    delete m_balle;
    delete m_balle;
}
