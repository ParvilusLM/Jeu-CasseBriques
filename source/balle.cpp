#include "balle.h"

Balle::Balle(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_tBalle.loadFromFile("donnees/balle.png");

    m_nbBalleCree=0;
}

void Balle::initBalle()
{
    m_vecBalle.clear();
    m_nbBalleCree++;

    m_horlBalle.m_horlJeu.restart();

    ElBalle nouvelleBalle;
    float angl=0.7;
    /*
    do
    {
        angl= 1 + std::rand()/((RAND_MAX + 1u)/360);
    }
    while(angl < 45.f);
    */

    angl=-angl;

    nouvelleBalle.numBalle=m_nbBalleCree;
    nouvelleBalle.angleB=angl;
    nouvelleBalle.etat=CAPTURE;
    nouvelleBalle.dirX=1;
    nouvelleBalle.dirY=1;
    nouvelleBalle.vitesseB=300;
    nouvelleBalle.sBalle.setOrigin(12.5f,12.5f);
    nouvelleBalle.sBalle.setPosition((2.45f*20.f)+300.f,700.f-70.f);
    nouvelleBalle.sBalle.setTexture(m_tBalle);

    m_vecBalle.insert(m_vecBalle.end(),nouvelleBalle);

}

void Balle::mouvementBalle()
{
    m_deltaTime=m_horlBalle.m_horlJeu.restart().asSeconds();
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        float facteur = m_vecBalle.at(compt).vitesseB * m_deltaTime;
        if(m_vecBalle.at(compt).etat==LANCEE)
        {
            m_vecBalle.at(compt).sBalle.move(std::cos(m_vecBalle.at(compt).angleB)*facteur*m_vecBalle.at(compt).dirX,std::sin(m_vecBalle.at(compt).angleB)*facteur*m_vecBalle.at(compt).dirY);
        }
        compt++;
    }
}

void Balle::afficheBalle()
{
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        m_fenetre->draw(m_vecBalle.at(compt).sBalle);
        compt++;
    }
}

std::vector<ElBalle >& Balle::getBalle()
{
    return m_vecBalle;
}

void Balle::effacementBalle()
{
    int dernEl=m_vecBalle.size()-1;
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        if(m_vecBalle.at(dernEl).etat==B_A_DETRUIT)
        {
            m_vecBalle.erase(m_vecBalle.begin()+dernEl);
        }
        compt++;
    }
}

void Balle::inverserAngle(int numBalle,int zoneCollis)
{
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        if(m_vecBalle.at(compt).numBalle == numBalle)
        {
            if(zoneCollis==COLLIS_BORD_G || zoneCollis==COLLIS_BORD_D)
            {
                m_vecBalle.at(compt).dirX=-m_vecBalle.at(compt).dirX;
            }
            else if(zoneCollis==COLLIS_BORD_H || zoneCollis==COLLIS_BORD_B)
            {
                m_vecBalle.at(compt).dirY=-m_vecBalle.at(compt).dirY;
            }
            else if(zoneCollis==COLLIS_BRIQUE_G || zoneCollis==COLLIS_BRIQUE_D)
            {
                m_vecBalle.at(compt).dirX=-m_vecBalle.at(compt).dirX;
            }
            else if(zoneCollis==COLLIS_BRIQUE_H || zoneCollis==COLLIS_BRIQUE_B)
            {
                m_vecBalle.at(compt).dirY=-m_vecBalle.at(compt).dirY;
            }
            else if(zoneCollis==COLLIS_PALETTE_G || zoneCollis==COLLIS_PALETTE_C || zoneCollis==COLLIS_PALETTE_D)
            {
                m_vecBalle.at(compt).dirY=-m_vecBalle.at(compt).dirY;
            }
            else
            {

            }

        }
        compt++;
    }
}

void Balle::resetHorlBalle()
{
    m_horlBalle.m_horlJeu.restart();
}

Balle::~Balle()
{

}

