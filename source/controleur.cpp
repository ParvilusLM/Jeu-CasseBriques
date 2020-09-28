#include "controleur.h"

using namespace std;

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0)
{
    m_fenetre= &fenetre;
    m_decor=new Decor(*m_fenetre);
}

void Controleur::debutJeu()
{
    m_decor->getBrique().initBrique(0);
    m_decor->getPalette().initPalette();
    m_decor->getBalle().initBalle();

}


void Controleur::gestionDplSouris()
{
    m_decor->getMenu().elementActif();
}

void Controleur::gestionSelecSouris()
{
    m_decor->getMenu().selectionElActif();
}


void Controleur::gestionMaJ()
{
    m_decor->getPalette().DonneesMaJ();
    gestMouvBalle();
}

bool Controleur::gestCollisBalle()
{

}

bool Controleur::gestCollisPalette()
{
    bool collision=false;

    if(m_decor->getPalette().getPosPalette().x - 45.f < 2.45f*20.f)
    {

        collision=true;
    }

    if(m_decor->getPalette().getPosPalette().x + 45.f > (2.45f*20.f)+600)
    {
        collision=true;
    }

    return collision;
}

void Controleur::gestMouvBalle()
{
    m_decor->getBalle().mouvementBalle();
}

void Controleur::gestMouvPalette(int dir)
{
    if(!gestCollisPalette())
    {
        m_decor->getPalette().mouvementPalette(dir);
    }
}

void Controleur::afficheMenu()
{
    m_decor->getMenu().afficheMenu();
    /*
    if(m_decor->getMenu().getTypeMenu()==MenuPrincipal)
    {
        afficheInfo();
    }
    */

}

void Controleur::afficheJeu()
{
    m_decor->afficheCadreJeu();
    m_decor->getBrique().afficheBrique();
    m_decor->getPalette().affichePalette();
    m_decor->getBalle().afficheBalle();
}

void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}


Controleur::~Controleur()
{

}
