#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "CGame.h"

using namespace std;
int main()
{
    Game game = Game();

    game.Create();
    game.Run();

    return 0;
}

/*#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    //Creo mi ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Evento MouseButtonPressed SFML");
    window.setFramerateLimit(60);

    //creo mi gameloop
    while (window.isOpen())
    {
        //limpio la ventana
        window.clear(sf::Color::White);

        //mostrar en pantalla
        window.display();

        sf::Event event;

        while (window.pollEvent(event))
        {
            //evento presionar boton del mouse
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    cout << "Boton izquierdo presionado" << endl;
                    cout << "posicion x: " << event.mouseButton.x << " - posicion y: " << event.mouseButton.y << endl;
                }
            }


            //Evento Cerrar
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}*/