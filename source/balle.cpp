#include "balle.h"

Balle::Balle(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_tBalle.loadFromFile("donnees/balle.png");


}

void Balle::initBalle()
{
    ElBalle nouvelleBalle;
    int angl=0;
    do
    {
        angl=(std::rand()%180)*2*pi/180;
    }
    while(std::abs(std::cos(angl))<0.7f);

    nouvelleBalle.angleB=angl;
    nouvelleBalle.etat=CAPTURE;
    nouvelleBalle.vitesseB=400;
    nouvelleBalle.sBalle.setOrigin(12.5f,12.5f);
    nouvelleBalle.sBalle.setPosition((2.45f*20.f)+300.f,700.f-70.f);
    nouvelleBalle.sBalle.setTexture(m_tBalle);

    m_vecBalle.insert(m_vecBalle.end(),nouvelleBalle);

}

void Balle::deplaceB(int indicB)
{

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

void Balle::getBoitEngloBalle(int indicB)
{

}

Balle::~Balle()
{

}

