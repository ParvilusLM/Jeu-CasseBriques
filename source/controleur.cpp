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
    int nbBriques=m_decor->getBrique().getBriques().size();
    m_decor->getInfo().setNbBriqRest(nbBriques);
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
    if(m_decor->getMenu().getBoutonPress()==PAUSER_ACTIF)
    {
        m_decor->getInfo().demarrerH();
        m_decor->getBalle().resetHorlBalle();
        m_decor->getMenu().resetBoutonPress();

    }

    m_decor->getPalette().donneesMaJ();
    m_decor->getInfo().gestionTemps();

    gestMouvBalle();
    gestCollisBalle();
}

void Controleur::gestCollisBalle()
{

    int compt=0;
    while(compt < m_decor->getBalle().getBalle().size())
    {
        int collision=AUCUNE_COLLIS;

        //collision cote gauche
        if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x-12.5f < 2.45f*20.f)
        {
            collision=COLLIS_BORD_G;
            m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(2.45f*20.f + 0.1f + 12.5f,m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y);
        }
        else if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x+12.5f > 2.45f*20.f +600.f) //collision cote droit
        {
            collision=COLLIS_BORD_D;
            m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(2.45f*20.f +600.f - 0.1f - 12.5f,m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y);
        }
        else if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y-12.5f < 4.5f*20.f) //collision cote haut
        {
            collision=COLLIS_BORD_H;
            m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,4.5f*20.f+12.5f+0.1f);
        }
        else if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y+12.5f > 4.5f*20.f +600.f) //collision cote bas
        {
            if(m_decor->getBalle().getBalle().size()>1)
            {
                m_decor->getBalle().getBalle().at(compt).etat==B_A_DETRUIT;
            }

            //collision=COLLIS_BORD_B;
            //m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
            //m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,4.5f*20.f+600.f-12.5f-0.1f);
        }
        else
        {

        }

        //determiner la zone des briques
        sf::FloatRect zoneBriques;
        zoneBriques.width=600.f;
        zoneBriques.height=350.f;
        zoneBriques.left=2.45f*20.f;
        zoneBriques.top=4.5f*20.f;

        //determiner la zone de la palette
        sf::FloatRect zonePalette;
        zonePalette.width=600.f;
        zonePalette.height=60.f;
        zonePalette.left=2.45f*20.f;
        zonePalette.top=4.5f*20.f+600.f-60.f;



        //determiner un rayon de detection pour la balle
        sf::FloatRect zoneDetectCollis;
        zoneDetectCollis.width=50.f;
        zoneDetectCollis.height=50.f;
        zoneDetectCollis.left=m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x-25.f;
        zoneDetectCollis.top=m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y-25.f;

        //collision avec les briques
        if(zoneDetectCollis.intersects(zoneBriques))
        {
            int compt2=0;
            while(compt2<m_decor->getBrique().getBriques().size())
            {
                if(zoneDetectCollis.intersects(m_decor->getBrique().getBriques().at(compt2).sBrique.getGlobalBounds()))
                {
                    if(m_decor->getBalle().getBalle().at(compt).sBalle.getGlobalBounds().intersects(m_decor->getBrique().getBriques().at(compt2).sBrique.getGlobalBounds()))
                    {
                        if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x-24.f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x+24.f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y)
                        {
                            collision=COLLIS_BRIQUE_B;

                        }

                        if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x-24.f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x+24.f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y)
                        {
                            collision=COLLIS_BRIQUE_H;
                        }

                        if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y-12.5f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y+12.5f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x)
                        {
                            collision=COLLIS_BRIQUE_G;
                        }

                        if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y-12.5f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y+12.5f &&
                           m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x > m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x)
                        {
                            collision=COLLIS_BRIQUE_D;
                        }

                        m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);


                        if(collision==COLLIS_BRIQUE_G)
                        {
                            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x-24.f-12.5f-0.1f,m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y);
                        }
                        else if(collision==COLLIS_BRIQUE_D)
                        {
                            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().x+24.f+12.5f+0.1f,m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y);
                        }
                        else if(collision==COLLIS_BRIQUE_H)
                        {
                            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y-11.5f-12.5f-0.1f);
                        }
                        else if(collision==COLLIS_BRIQUE_B)
                        {
                            m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,m_decor->getBrique().getBriques().at(compt2).sBrique.getPosition().y+11.5f+12.5f+0.1f);
                        }
                        else
                        {

                        }

                        if(collision==COLLIS_BRIQUE_G || collision==COLLIS_BRIQUE_D || collision==COLLIS_BRIQUE_H || collision==COLLIS_BRIQUE_B)
                        {
                            if(m_decor->getBrique().getBriques().at(compt2).etat==NORMAL)
                            {
                                m_decor->getBrique().getBriques().at(compt2).etat=CASSE;
                            }
                            else if(m_decor->getBrique().getBriques().at(compt2).etat==CASSE)
                            {
                                m_decor->getBrique().getBriques().at(compt2).etat=DETRUIT;
                            }
                            else
                            {

                            }
                        }
                        std::cout<<"oohhh"<<std::endl;
                    }

                }

                compt2++;
            }

            m_decor->getBrique().effacementBriques();
        }

        //collision avec la palette
        if(zoneDetectCollis.intersects(zonePalette))
        {
            if(zoneDetectCollis.intersects(m_decor->getPalette().getPalette().sPalette.getGlobalBounds()))
            {
                if(m_decor->getBalle().getBalle().at(compt).sBalle.getGlobalBounds().intersects(m_decor->getPalette().getPalette().sPalette.getGlobalBounds()))
                {
                    float taillePal= m_decor->getPalette().getPalette().sPalette.getGlobalBounds().width;
                    float tailleCoteP=0.f;
                    float tailleCentreP=0.f;

                    if(taillePal==90.f)
                    {
                        tailleCoteP=16.f;
                        tailleCentreP=taillePal-(tailleCoteP*2);
                    }
                    else if(taillePal==120.f)
                    {
                        tailleCoteP=16.f;
                        tailleCentreP=taillePal-(tailleCoteP*2);
                    }
                    else
                    {

                    }


                    if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x > m_decor->getPalette().getPalette().sPalette.getPosition().x - (taillePal/2.f) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x < m_decor->getPalette().getPalette().sPalette.getPosition().x - ((taillePal/2.f)+tailleCoteP) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getPalette().getPalette().sPalette.getPosition().y)
                    {
                        collision=COLLIS_PALETTE_G;
                        m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
                        m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,HAUTEUR_F-35.f-20.f-12.5f-0.1f);
                    }
                    else if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x > m_decor->getPalette().getPalette().sPalette.getPosition().x + (tailleCentreP/2.f) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x < m_decor->getPalette().getPalette().sPalette.getPosition().x + (tailleCentreP/2.f) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getPalette().getPalette().sPalette.getPosition().y)
                    {
                        collision=COLLIS_PALETTE_D;
                        m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
                        m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,HAUTEUR_F-35.f-20.f-12.5f-0.1f);
                    }
                    else if(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x >= m_decor->getPalette().getPalette().sPalette.getPosition().x - (tailleCentreP/2.f) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x <= m_decor->getPalette().getPalette().sPalette.getPosition().x + (tailleCentreP/2.f) &&
                       m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().y < m_decor->getPalette().getPalette().sPalette.getPosition().y)
                    {
                        collision=COLLIS_PALETTE_C;
                        m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
                        m_decor->getBalle().getBalle().at(compt).sBalle.setPosition(m_decor->getBalle().getBalle().at(compt).sBalle.getPosition().x,HAUTEUR_F-35.f-20.f-12.5f-0.1f);
                    }
                    else
                    {

                    }

                    //m_decor->getBalle().inverserAngle(m_decor->getBalle().getBalle().at(compt).numBalle,collision);
                }

            }
        }




        compt++;
    }

    m_decor->getBalle().effacementBalle();

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
