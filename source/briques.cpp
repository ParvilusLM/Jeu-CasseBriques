#include "briques.h"


Brique::Brique(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_tBrique.loadFromFile("donnees/spriteSheetBr.png");
    tabBriq[14][12]={0};

}

void Brique::initBrique(int niveau)
{
    chargerNiveau(niveau);

    //cration des briques dans le vecteur m_vecBrique
    int i=0,j=0;
    for(i=0; i<14 ; i++)
    {
        for(j=0 ; j<12 ; j++)
        {
            if(tabBriq[i][j] != C_VIDE)
            {

                ElBrique nouvelBriq;
                nouvelBriq.sBrique.setTexture(m_tBrique);
                nouvelBriq.sBrique.setOrigin(24.f,11.5f);
                nouvelBriq.sBrique.setPosition((j*50.f)+(2.45f*20.f)+24.f,(i*25.f)+(4.5f*20.f)+11.5f);

                if(tabBriq[i][j]==BRIQUE1)
                {
                    nouvelBriq.couleur=1;
                    nouvelBriq.etat=NORMAL;

                    nouvelBriq.sBrique.setTextureRect(sf::IntRect(0,0,48,23));
                }
                else if(tabBriq[i][j]==BRIQUE2)
                {
                    nouvelBriq.couleur=2;
                    nouvelBriq.etat=NORMAL;
                    nouvelBriq.sBrique.setTextureRect(sf::IntRect(96,0,48,23));
                }
                else if(tabBriq[i][j]==BRIQUE3)
                {
                    nouvelBriq.couleur=3;
                    nouvelBriq.etat=NORMAL;
                    nouvelBriq.sBrique.setTextureRect(sf::IntRect(192,0,48,23));

                }
                else if(tabBriq[i][j]==BRIQUE4)
                {
                    nouvelBriq.couleur=4;
                    nouvelBriq.etat=NORMAL;
                    nouvelBriq.sBrique.setTextureRect(sf::IntRect(288,0,48,23));
                }
                else if(tabBriq[i][j]==BRIQUE5)
                {
                    nouvelBriq.couleur=5;
                    nouvelBriq.etat=NORMAL;
                    nouvelBriq.sBrique.setTextureRect(sf::IntRect(384,0,48,23));

                }
                else
                {

                }

                m_vecBrique.insert(m_vecBrique.end(),nouvelBriq);
            }

        }
    }

    //gestiontextures();

}

void Brique::afficheBrique()
{
    int compt=0;
    while(compt<m_vecBrique.size())
    {
        m_fenetre->draw(m_vecBrique.at(compt).sBrique);

        compt++;
    }
}

int Brique::chargerNiveau(int niveau)
{
    FILE* fichier=NULL;
    char ligneFichier[169]={0};
    int i=0,j=0,charLU=0,nbNiveau=0,noLigneChoisi=0;

    fichier=fopen("donnees/niveaux.lvl","r");
    if(fichier==NULL)
    {
        return 0;
    }

    do
    {
        charLU=fgetc(fichier);
        if(charLU == '\n')
            nbNiveau++;
    }while(charLU != EOF);


    noLigneChoisi=niveau;
    rewind(fichier);

    while(noLigneChoisi > 0)
    {
        charLU=fgetc(fichier);
        if(charLU == '\n')
            noLigneChoisi--;
    }

    fgets(ligneFichier,200,fichier);

    for(i=0 ; i<14 ; i++)
    {
        for(j=0 ; j<12 ; j++)
        {
            switch(ligneFichier[(i*12)+j])
            {
            case '0':
                tabBriq[i][j]=  C_VIDE;
                break;

            case '1':
                tabBriq[i][j]=  BRIQUE1;
                break;

            case '2':
                tabBriq[i][j]=  BRIQUE2;
                break;

            case '3':
                tabBriq[i][j]=  BRIQUE3;
                break;

            case '4':
                tabBriq[i][j]=  BRIQUE4;
                break;

            case '5':
                tabBriq[i][j]=  BRIQUE5;
                break;

            default:;
            }
        }
    }

    fclose(fichier);
    return 1;

}
void Brique::changerNiveau(int niveau)
{

}

sf::FloatRect Brique::getPosBriques()
{

}

void Brique::gestiontextures()
{
    int compt=0;
    while(compt<m_vecBrique.size())
    {
        m_vecBrique.at(compt).sBrique.setTexture(m_tBrique);
        if(m_vecBrique.at(compt).etat==NORMAL)
        {
            if(m_vecBrique.at(compt).couleur==1)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(0,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==2)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(96,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==3)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(192,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==4)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(288,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==5)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(384,0,48,23));
            }
            else
            {

            }
        }
        else
        {
            if(m_vecBrique.at(compt).couleur==1)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(48,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==2)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(144,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==3)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(240,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==4)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(336,0,48,23));
            }
            else if(m_vecBrique.at(compt).couleur==5)
            {
                m_vecBrique.at(compt).sBrique.setTextureRect(sf::IntRect(432,0,48,23));
            }
            else
            {

            }
        }

        compt++;
    }
}

Brique::~Brique()
{

}
