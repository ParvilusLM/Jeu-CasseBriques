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
    m_decor->getInfo().initInfo2();


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
    m_decor->getInfo().gestionTemps();
    gestMouvBalle();


    if(m_decor->getMenu().getBoutonPress()==PAUSER_ACTIF)
    {
        m_decor->getInfo().demarrerH();
        m_decor->getMenu().resetBoutonPress();

    }
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

    sf::Vector2f nouvPosP; //pour remettre la palette dans le cadre

    if(m_decor->getPalette().getPosPalette().x - 45.f < 2.45f*20.f) //pour si apres deplacement la palette sort du cadre G
    {
        //recadrer pour le cote gauche
        nouvPosP.x=2.45f*20.f+0.1f+45.f;
        nouvPosP.y=HAUTEUR_F-17.5f-20.f;
        m_decor->getPalette().setPosPalette(nouvPosP);
    }

    if(m_decor->getPalette().getPosPalette().x + 45.f > (2.45f*20.f)+600) //pour si apres deplacement la palette sort du bord cadre D
    {
        //recadrer pour le cote droit
        nouvPosP.x=2.45f*20.f+600.f-0.1f-45.f;
        nouvPosP.y=HAUTEUR_F-17.5f-20.f;
        m_decor->getPalette().setPosPalette(nouvPosP);
    }
}

void Controleur::afficheMenu()
{
    m_decor->getMenu().afficheMenu();

    if(m_decor->getMenu().getTypeMenu()==MenuPrincipal)
    {
        afficheInfo();
    }


}

void Controleur::afficheJeu()
{
    m_decor->afficheCadreJeu();
    m_decor->getBrique().afficheBrique();
    m_decor->getPalette().affichePalette();
    m_decor->getBalle().afficheBalle();
    m_decor->getInfo().afficheInfo();

    if(jeuPause)
    {
        afficheMenu();
        if(m_decor->getMenu().getTypeMenu()==MenuEnregScore)
        {
            m_decor->getInfo().afficheNomAEnreg();
        }
    }
}

void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}

void Controleur::afficheInfo()
{
    m_decor->getInfo().afficheInfo();
}

void Controleur::saisieL(char lettre)
{
    //m_decor->getInfo().gestSaisieNom(lettre);
}

void Controleur::sauvegardeScore()
{
    //m_decor->getInfo().sauvegardeScore();
    //jeuSauvegarde=false;
}

void Controleur::reinitTablScore()
{
    //m_decor->getInfo().gestTableauScore();
}

void Controleur::pauseJeu()
{
    if(!jeuPause)
    {
        jeuPause=true;
        m_decor->getInfo().pauseH();
        m_decor->getMenu().setTypeMenu(MenuPause);

    }
}


Controleur::~Controleur()
{

}
