#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

bool jeuEnCours=false;

int main()
{
    RenderWindow fenetre(VideoMode(900,700),"Casse Briques");


    while(fenetre.isOpen())
    {
        Event evenement;
        while(fenetre.pollEvent(evenement))
        {
            if(evenement.type==Event::Closed)
            {
                fenetre.close();
            }

        }

        if(jeuEnCours)
        {

        }
        else
        {

        }

        fenetre.clear(Color(82,82,82));

        if(jeuEnCours)
        {

        }
        else
        {

        }

        fenetre.display();
    }


    return 0;
}
