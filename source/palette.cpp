#include "palette.h"

using namespace std;

Palette::Palette(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tPalette.loadFromFile("donnees/spriteSheetPalette.png");
    m_tProjectiles.loadFromFile("donnees/projectile.png");


}

void Palette::initPalette()
{
    //horloge
    m_horlPalette.restart();

    m_palette.sPalette.setOrigin(45.f,17.5f);
    m_palette.sPalette.setPosition(LARGEUR_F/2,HAUTEUR_F-17.5f-20.f);
    m_palette.sPalette.setTexture(m_tPalette);
    m_palette.sPalette.setTextureRect(sf::IntRect(0,0,90,35));

    m_palette.etat=NORMAL;
    m_palette.vitesseP=800;


}

sf::Vector2f Palette::getPosPalette()
{
    return m_palette.sPalette.getPosition();
}

std::vector<sf::FloatRect > Palette::getPosProjectiles()
{

}

void Palette::mouvementPalette(int dir)
{
    if(dir==DIR_GAUCHE)
    {
        m_palette.sPalette.move(-m_palette.vitesseP*m_deltaTime,0);
    }
    else
    {
        m_palette.sPalette.move(m_palette.vitesseP*m_deltaTime,0);
    }
}

void Palette::mouvementProjectiles()
{

}

void Palette::setPosPalette(sf::Vector2f posPalette)
{
    m_palette.sPalette.setPosition(posPalette);
}

ElPalette& Palette::getPalette()
{
    return m_palette;
}

void Palette::affichePalette()
{
    m_fenetre->draw(m_palette.sPalette);
}

void Palette::afficheProjectiles()
{

}

void Palette::donneesMaJ()
{
    m_deltaTime=m_horlPalette.restart().asSeconds();
}

Palette::~Palette()
{

}
