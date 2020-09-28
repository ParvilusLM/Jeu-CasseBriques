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

    m_horlBalle.restart();
    ElBalle nouvelleBalle;
    float angl=0.7f;
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
    nouvelleBalle.etat=LANCEE;
    nouvelleBalle.vitesseB=20;
    nouvelleBalle.sBalle.setOrigin(12.5f,12.5f);
    nouvelleBalle.sBalle.setPosition((2.45f*20.f)+300.f,700.f-70.f);
    nouvelleBalle.sBalle.setTexture(m_tBalle);

    m_vecBalle.insert(m_vecBalle.end(),nouvelleBalle);

}

void Balle::mouvementBalle()
{
    m_deltaTime=m_horlBalle.restart().asSeconds();
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        float facteur = m_vecBalle.at(compt).vitesseB * m_deltaTime;
        if(m_vecBalle.at(compt).etat==LANCEE)
        {
            m_vecBalle.at(compt).sBalle.move(std::cos(m_vecBalle.at(compt).angleB)*facteur,std::sin(m_vecBalle.at(compt).angleB)*facteur);
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

std::vector<ElBalle > Balle::getBalle()
{
    return m_vecBalle;
}

void Balle::inverserAngle(int numBalle)
{
    int compt=0;
    while(compt<m_vecBalle.size())
    {
        if(m_vecBalle.at(compt).numBalle == numBalle)
        {
            m_vecBalle.at(compt).angleB=-m_vecBalle.at(compt).angleB;
        }
        compt++;
    }
}

Balle::~Balle()
{

}

