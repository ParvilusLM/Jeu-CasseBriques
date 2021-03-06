#include "menu.h"

using namespace std;

Menu::Menu(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tMenuP.loadFromFile("donnees/menuP.png");
    m_tMenuI.loadFromFile("donnees/instruct.png");
    m_tMenuI1.loadFromFile("donnees/instruct1.png");
    m_tMenuI2.loadFromFile("donnees/instruct2.png");
    m_tMenuI3.loadFromFile("donnees/instruct3.png");
    m_tMenuPause.loadFromFile("donnees/pause.png");
    m_tMenuFinP.loadFromFile("donnees/gameOver.png");
    m_tMenuEnregScore.loadFromFile("donnees/meilleur_score.png");

    m_tSelectEScore.loadFromFile("donnees/selectEScore.png");
    m_tSelectInstr.loadFromFile("donnees/selectInstruct.png");
    m_tSelectMGO.loadFromFile("donnees/selectMGO.png");
    m_tSelectMP.loadFromFile("donnees/selectMP.png");
    m_tSelectMPause.loadFromFile("donnees/selectMPaus.png");



    //definitions boiteEBoutons
    boiteEBJ.width=14.f*20.f;
    boiteEBJ.height=3.5f*20.f;
    boiteEBJ.left=15.5f*20.f;
    boiteEBJ.top=27.f*20.f;

    boiteEBI.width=3.f*20.f;
    boiteEBI.height=3.f*20.f;
    boiteEBI.left=9.96f*20.f;
    boiteEBI.top=30.7f*20.f;

    boiteEBQ.width=3.f*20.f;
    boiteEBQ.height=3.f*20.f;
    boiteEBQ.left=32.2f*20.f;
    boiteEBQ.top=30.8f*20.f;

    boiteEBPr.width=2.2f*20.f;
    boiteEBPr.height=2.2f*20.f;
    boiteEBPr.left=15.9f*20.f;
    boiteEBPr.top=28.9f*20.f;

    boiteEBSuiv.width=2.2f*20.f;
    boiteEBSuiv.height=2.2f*20.f;
    boiteEBSuiv.left=26.9f*20.f;
    boiteEBSuiv.top=28.9f*20.f;

    boiteEBOk.width=4.2f*20.f;
    boiteEBOk.height=2.2f*20.f;
    boiteEBOk.left=20.4f*20.f;
    boiteEBOk.top=28.9f*20.f;

    boiteEBPR.width=8.4f*20.f;
    boiteEBPR.height=2.3f*20.f;
    boiteEBPR.left=17.8f*20.f;
    boiteEBPR.top=15.f*20.f;

    boiteEBPI.width=8.4f*20.f;
    boiteEBPI.height=2.3f*20.f;
    boiteEBPI.left=17.8f*20.f;
    boiteEBPI.top=18.f*20.f;

    boiteEBPQ.width=8.4f*20.f;
    boiteEBPQ.height=2.3f*20.f;
    boiteEBPQ.left=17.8f*20.f;
    boiteEBPQ.top=21.f*20.f;

    boiteEBFQ.width=2.5f*20.f;
    boiteEBFQ.height=2.1f*20.f;
    boiteEBFQ.left=16.f*20.f;
    boiteEBFQ.top=23.9f*20.f;

    boiteEBFR.width=2.5f*20.f;
    boiteEBFR.height=2.1f*20.f;
    boiteEBFR.left=25.5f*20.f;
    boiteEBFR.top=23.9f*20.f;

    boiteEBESOk.width=2.f*20.f;
    boiteEBESOk.height=2.f*20.f;
    boiteEBESOk.left=21.f*20.f;
    boiteEBESOk.top=21.f*20.f;

    m_typeMenu=MenuPrincipal;
    initMenuP();
    initMenuI();
    initMenuI1();
    initMenuI2();
    initMenuI3();
    initMenuP();
    initMenuPause();
    initMenuFinPart();
    initMenuEnregScore();

    m_boutonPress=AUCUN_EL_ACT;

}

void Menu::initMenuP()
{
    m_sMenuP.setTexture(m_tMenuP);


}

void Menu::initMenuI()
{
    m_sMenuI.setTexture(m_tMenuI);
}

void Menu::initMenuI1()
{
    m_sMenuI1.setTexture(m_tMenuI1);
}

void Menu::initMenuI2()
{
    m_sMenuI2.setTexture(m_tMenuI2);
}

void Menu::initMenuI3()
{
    m_sMenuI3.setTexture(m_tMenuI3);
}

void Menu::initMenuPause()
{
    m_sMenuPause.setTexture(m_tMenuPause);
}

void Menu::initMenuFinPart()
{
    m_sMenuFinP.setTexture(m_tMenuFinP);
}

void Menu::initMenuEnregScore()
{
    m_sMenuEnregScore.setTexture(m_tMenuEnregScore);
}

void Menu::setTypeMenu(int menuActuel)
{
    if(menuActuel==MenuPrincipal)
    {
        m_typeMenu=MenuPrincipal;
    }
    else if(menuActuel==MenuInstructions1)
    {
        m_typeMenu=MenuInstructions1;
    }
    else if(menuActuel==MenuInstructions2)
    {
        m_typeMenu=MenuInstructions2;
    }
    else if(menuActuel==MenuInstructions3)
    {
        m_typeMenu=MenuInstructions3;
    }
    else if(menuActuel==MenuPause)
    {
        m_typeMenu=MenuPause;
    }
    else if(menuActuel==MenuFinPartie)
    {
        m_typeMenu=MenuFinPartie;
    }
    else if(menuActuel==MenuEnregScore)
    {
        m_typeMenu=MenuEnregScore;
    }
    else
    {

    }
}

TypeMenu Menu::getTypeMenu()
{
    return m_typeMenu;
}

void Menu::afficheMenuP()
{
    m_fenetre->draw(m_sMenuP);
}

void Menu::afficheMenuI()
{
    m_fenetre->draw(m_sMenuI);
}

void Menu::afficheMenuI1()
{
    m_fenetre->draw(m_sMenuI1);
}

void Menu::afficheMenuI2()
{
    m_fenetre->draw(m_sMenuI2);
}

void Menu::afficheMenuI3()
{
    m_fenetre->draw(m_sMenuI3);
}

void Menu::afficheMenuPause()
{
    m_fenetre->draw(m_sMenuPause);
}

void Menu::afficheMenuFinPart()
{
    m_fenetre->draw(m_sMenuFinP);
}

void Menu::afficheMenuEnregScore()
{
    m_fenetre->draw(m_sMenuEnregScore);
}

void Menu::afficheMenu()
{
    if(m_typeMenu==MenuPrincipal)
    {
        afficheMenuP();
    }
    else if(m_typeMenu==MenuInstructions1)
    {
        afficheMenuI();
        afficheMenuI1();
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        afficheMenuI();
        afficheMenuI2();
    }
    else if(m_typeMenu==MenuInstructions3)
    {
        afficheMenuI();
        afficheMenuI3();
    }
    else if(m_typeMenu==MenuPause)
    {
        afficheMenuPause();
    }
    else if(m_typeMenu==MenuFinPartie)
    {
        afficheMenuFinPart();
    }
    else if(m_typeMenu==MenuEnregScore)
    {
        afficheMenuEnregScore();
    }
    else
    {

    }

    if(m_elementActif!=AUCUN_EL_ACT)
    {
        m_fenetre->draw(m_sIndicSelect);
    }

}

void Menu::retourMenuP()
{
    m_typeMenu=MenuPrincipal;
    m_elementActif=AUCUN_EL_ACT;
}

void Menu::elementActif()
{

    if(m_typeMenu==MenuPrincipal)
    {
        m_sIndicSelect.setTexture(m_tSelectMP);
        if(collisionTS(boiteEBJ))
        {
            m_elementActif=JOUER_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(boiteEBJ.left-10.f,boiteEBJ.top-10.f,boiteEBJ.width+15.f,boiteEBJ.height+15.f));
            m_sIndicSelect.setPosition(boiteEBJ.left-10.f,boiteEBJ.top-10.f);
        }
        else if(collisionTS(boiteEBI))
        {
            m_elementActif=INSTRUCTIONS_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(boiteEBI.left,boiteEBI.top,boiteEBI.width,boiteEBI.height));
            m_sIndicSelect.setPosition(boiteEBI.left,boiteEBI.top);
        }
        else if(collisionTS(boiteEBQ))
        {
            m_elementActif=QUITTER_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(31.f*20.f,30.f*20.f,4.2f*20.f,4.2f*20.f));
            m_sIndicSelect.setPosition(31.f*20.f,30.f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuInstructions1)
    {
        m_sIndicSelect.setTexture(m_tSelectInstr);
        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(20.f*20.f,28.f*20.f,6.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(20.f*20.f,28.f*20.f);
        }
        else if(collisionTS(boiteEBSuiv))
        {
            m_elementActif=SUIVANT_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(26.f*20.f,28.f*20.f,4.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(26.f*20.f,28.f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        m_sIndicSelect.setTexture(m_tSelectInstr);
        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(20.f*20.f,28.f*20.f,6.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(20.f*20.f,28.f*20.f);
        }
        else if(collisionTS(boiteEBSuiv))
        {
            m_elementActif=SUIVANT_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(26.f*20.f,28.f*20.f,4.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(26.f*20.f,28.f*20.f);
        }
        else if(collisionTS(boiteEBPr))
        {
            m_elementActif=PRECEDENT_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(15.f*20.f,28.f*20.f,4.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(15.f*20.f,28.f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuInstructions3)
    {
        m_sIndicSelect.setTexture(m_tSelectInstr);

        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(20.f*20.f,28.f*20.f,6.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(20.f*20.f,28.f*20.f);
        }
        else if(collisionTS(boiteEBPr))
        {
            m_elementActif=PRECEDENT_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(15.f*20.f,28.f*20.f,4.f*20.f,4.f*20.f));
            m_sIndicSelect.setPosition(15.f*20.f,28.f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuPause)
    {
        m_sIndicSelect.setTexture(m_tSelectMPause);

        if(collisionTS(boiteEBPR))
        {
            m_elementActif=PAUSER_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(17.f*20.f,14.f*20.f,10.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(17.f*20.f,14.f*20.f);
        }
        else if(collisionTS(boiteEBPI))
        {
            m_elementActif=PAUSEI_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(15.f*20.f,17.5f*20.f,12.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(15.f*20.f,17.5f*20.f);
        }
        else if(collisionTS(boiteEBPQ))
        {
            m_elementActif=PAUSEQ_ACTIF;

            m_sIndicSelect.setTextureRect(sf::IntRect(15.f*20.f,21.f*20.f,12.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(15.f*20.f,21.f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuFinPartie)
    {
        m_sIndicSelect.setTexture(m_tSelectMGO);

        if(collisionTS(boiteEBFQ))
        {
            m_elementActif=FINPQ_ACTIF;
            m_sIndicSelect.setTextureRect(sf::IntRect(16.f*20.f,23.6f*20.f,3.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(16.f*20.f,23.6f*20.f);
        }
        else if(collisionTS(boiteEBFR))
        {
            m_elementActif=FINPR_ACTIF;
            m_sIndicSelect.setTextureRect(sf::IntRect(25.f*20.f,23.6f*20.f,3.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(25.f*20.f,23.6f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuEnregScore)
    {
        m_sIndicSelect.setTexture(m_tSelectEScore);

        if(collisionTS(boiteEBESOk))
        {
            m_elementActif=ESOk_ACTIF;
            m_sIndicSelect.setTextureRect(sf::IntRect(20.5f*20.f,20.5f*20.f,3.f*20.f,3.f*20.f));
            m_sIndicSelect.setPosition(20.5f*20.f,20.5f*20.f);
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else
    {

    }

}

void Menu::selectionElActif()
{
    if(m_typeMenu==MenuPrincipal)
    {
        if(m_elementActif==JOUER_ACTIF)
        {
            jeuEnCours=true;
            jeuDebut=true;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==INSTRUCTIONS_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==QUITTER_ACTIF)
        {
            quitterJeu();
        }
        else
        {

        }

    }
    else if(m_typeMenu==MenuInstructions1)
    {
        if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==SUIVANT_ACTIF)
        {
            m_typeMenu=MenuInstructions2;
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        if(m_elementActif==PRECEDENT_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }
            m_elementActif=AUCUN_EL_ACT;

        }
        else if(m_elementActif==SUIVANT_ACTIF)
        {
            m_typeMenu=MenuInstructions3;
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuInstructions3)
    {
        if(m_elementActif==PRECEDENT_ACTIF)
        {
            m_typeMenu=MenuInstructions2;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuPause)
    {
        if(m_elementActif==PAUSER_ACTIF)
        {
            jeuPause=false;
            m_boutonPress=PAUSER_ACTIF;
            m_elementActif=AUCUN_EL_ACT;

        }
        else if(m_elementActif==PAUSEI_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==PAUSEQ_ACTIF)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            m_typeMenu=MenuPrincipal;
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuFinPartie)
    {
        if(m_elementActif==FINPQ_ACTIF)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            jeuFinPartie=false;
            m_typeMenu=MenuPrincipal;
            m_elementActif=AUCUN_EL_ACT;
        }
        else if(m_elementActif==FINPR_ACTIF)
        {
            jeuPause=false;
            jeuRejouer=true;
            m_typeMenu=MenuPrincipal;
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuEnregScore)
    {
        if(m_elementActif==ESOk_ACTIF)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            jeuFinPartie=false;
            jeuSauvegarde=true;
            m_typeMenu=MenuPrincipal;
            m_elementActif=AUCUN_EL_ACT;
        }
        else
        {

        }
    }
    else
    {

    }

}

int Menu::getBoutonPress()
{
    return  m_boutonPress;
}

void Menu::resetBoutonPress()
{
    m_boutonPress=AUCUN_EL_ACT;
}


bool Menu::collisionTS(sf::FloatRect elem)
{
    bool collision=false;
    if((elem.left<sourisX && elem.left+elem.width>sourisX) && (elem.top<sourisY && elem.top+elem.height>sourisY))
    {
        collision=true;
    }
    return collision;
}

void Menu::quitterJeu()
{
    m_fenetre->close();
}

Menu::~Menu()
{

}
