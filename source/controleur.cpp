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

}


void Controleur::gestionDplSouris()
{
    m_decor->getMenu().elementActif();
}

void Controleur::gestionSelecSouris()
{
    m_decor->getMenu().selectionElActif();
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
}

void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}


Controleur::~Controleur()
{

}
