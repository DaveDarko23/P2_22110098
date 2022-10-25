#pragma once
#include "CTree.h"
#include "CASK.h"
#include "Textbox.h"
#include "Button.h"
#include <list>

class Game
{
private:
    Tree arbol = Tree();
    Node* raiz = nullptr;
    short nivel;
    char a;

    void GameLoop(Node* pNodo, Textbox &tb, int oneTime)
    {
        if (pNodo && (oneTime != 0 && oneTime != -1)) {
            tb.setText(pNodo->value);
            oneTime = false;
        }
    }

    void CreateNode(Node* pNodo, string ask, string negative, string positive, bool position)
    {
        (position)
            ? insert(pNodo, negative, positive)
            : insert(pNodo, positive, negative);

        pNodo->value = ask;
    }

    void insert(Node* pNodo, string value1, string value2)
    {
        pNodo->left = arbol.Insertar(pNodo->mID - 1, value1, pNodo->left);
        pNodo->right = arbol.Insertar(pNodo->mID + 1, value2, pNodo->right);
    }

    void setBgButton(Button &btn1, Button& btn2, Button& btn3, sf::RenderWindow& window) {
        btn1.setBackColor((btn1.isMouserOver(window)) ? sf::Color::White : sf::Color::Green);
        btn2.setBackColor((btn2.isMouserOver(window)) ? sf::Color::White : sf::Color::Green);
        btn3.setBackColor((btn3.isMouserOver(window)) ? sf::Color::White : sf::Color::Green);
    }

    void selectCharacter(Button& btn1, Button& btn2, Node* pNodo, int &oneTime, Textbox& tb) {
        btn1.setText("No");
        btn2.setText("Si");
        pNodo = raiz;
        oneTime = 1;
        tb.setText("Pregunta");
    }

public:
    Game() {}

    void Create()
    {
        list<CAsk> a;
        //  a.push_back(ask1);
        a.push_back(CAsk(50, "¿Fue Villano?"));
        a.push_back(CAsk(42, "¿Tiene Sangre Saiyajin?"));
        a.push_back(CAsk(36, "¿Es calvo?"));
        a.push_back(CAsk(32, "¿Es Mujer?"));
        a.push_back(CAsk(31, "Tu Personaje es Yamcha"));
        a.push_back(CAsk(34, "¿Es Cientifica?"));
        a.push_back(CAsk(33, "Tu Personaje es Milk"));
        a.push_back(CAsk(35, "Tu Personaje es Bulma"));
        a.push_back(CAsk(40, "¿Es Maestro?"));
        a.push_back(CAsk(38, "¿Tiene 3 ojos?"));
        a.push_back(CAsk(37, "¿Tu Personaje es Krillin"));
        a.push_back(CAsk(39, "Tu Personaje es Ten Shin Han"));
        a.push_back(CAsk(41, "Tu Personaje es Roshi"));
        a.push_back(CAsk(48, "¿Es Saiyajin puro?"));
        a.push_back(CAsk(44, "¿Tiene un hermano?"));
        a.push_back(CAsk(43, "Tu Personaje es Trunks"));
        a.push_back(CAsk(46, "¿Es el hermano mayor?"));
        a.push_back(CAsk(45, "Tu Personaje es Goten"));
        a.push_back(CAsk(47, "Tu Personaje es Gohan"));
        a.push_back(CAsk(49, "Tu Personaje es Goku"));
        a.push_back(CAsk(60, "¿Fue Creado?"));
        a.push_back(CAsk(54, "¿Es saiyajin?"));
        a.push_back(CAsk(52, "¿Es verde?"));
        a.push_back(CAsk(51, "Tu Personaje es Frezzer?"));
        a.push_back(CAsk(53, "Tu Personaje es Picoro"));
        a.push_back(CAsk(56, "¿Tiene cabello?"));
        a.push_back(CAsk(55, "Tu Personaje es Napa"));
        a.push_back(CAsk(58, "¿Es un principe saijayin?"));
        a.push_back(CAsk(57, "Tu Personaje es Raditz"));
        a.push_back(CAsk(59, "Tu Personaje es Vegeta"));
        a.push_back(CAsk(62, "¿Es verde?"));
        a.push_back(CAsk(61, "Tu Personaje es Majin Buu"));
        a.push_back(CAsk(63, "Tu Personaje es Cell"));

        for (CAsk& as : a)
        {
            if (raiz == nullptr)
                raiz = arbol.Insertar(as.key, as.value, raiz);
            else
                arbol.Insertar(as.key, as.value, raiz);
        }

    }

    void Run()
    {
        bool nodeChild = false;

        int oneTime = 1;
        Node* actualNode = raiz;
        string temp="", ask = "", answer="";

        sf::RenderWindow window(sf::VideoMode(700, 700), "Akinator Dragon Ball Z");
        /*sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
            (sf::VideoMode::getDesktopMode().height / 2) - 680);

        window.setPosition(centerWindow);*/

        window.setKeyRepeatEnabled(true);

        sf::Font arial;
        arial.loadFromFile("arial.ttf");

        Textbox textbox1 = Textbox(15, sf::Color::White, true);
        textbox1.setFont(arial);
        textbox1.setPosition({ 100, 100 });
        textbox1.setText("Pregunta");

        Textbox textbox2 = Textbox(15, sf::Color::White, true);
        textbox2.setFont(arial);
        textbox2.setPosition({ 100, 200 });

        Button btn1("No", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
        btn1.setPosition({ 100, 300 });
        btn1.setFont(arial);

        Button btn2("Si", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
        btn2.setPosition({ 400, 300 });
        btn2.setFont(arial);

        Button btn3("Salir", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
        btn3.setPosition({ 200, 400 });
        btn3.setFont(arial);


        // Main Loop
        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {

                GameLoop(actualNode, textbox2, oneTime);

                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::TextEntered:
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                            textbox2.setSelected(false);

                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                            textbox2.setSelected(true);

                        textbox2.typedOn(event);
                        actualNode->value = textbox2.getText();

                        if(oneTime == 0)
                            ask = actualNode->value;
                        if (oneTime == -1)
                            answer = actualNode->value;

                        cout << "Pregunta: " << ask <<endl;
                        cout << "Respuesta: " << answer << endl;
                        cout << "Respuesta Anterior: " << temp << endl;
                        break;
                    case sf::Event::MouseMoved:
                        setBgButton(btn1, btn2, btn3, window);
                        break;
                    case sf::Event::MouseButtonPressed:
                        if (btn1.isMouserOver(window)) {
                            if (actualNode->left) {
                                actualNode = actualNode->left;

                                if (!actualNode->left) 
                                    textbox1.setText("¿Es el personaje que estabas buscando?");

                            }
                            else {
                                cout << "No es el personaje" << endl;
                                textbox1.setText("Ingrese la Pregunta");
                                textbox2.clearText();
                                textbox2.setSelected(true);
                                if (oneTime == 1) {
                                    temp = actualNode->value;
                                    oneTime = 0;
                                    btn2.setText("Listo");
                                }
                                actualNode->value = "";

                                if (oneTime == -1) {
                                    CreateNode(actualNode, ask, answer, temp, false);
                                    selectCharacter(btn1, btn2, actualNode, oneTime, textbox1);
                                }
                            }
                        }

                        if (btn2.isMouserOver(window)) {
                            if (actualNode->right) {
                                actualNode = actualNode->right;

                                if (!actualNode->left) {
                                    textbox1.setText("¿Es el personaje que estabas buscando?");
                                }
                            }
                            else {
                                if (oneTime == -1) {
                                    CreateNode(actualNode, ask, temp, answer, true);
                                    selectCharacter(btn1, btn2, actualNode, oneTime, textbox1);
                                }

                                if (oneTime == 0) {
                                    textbox1.setText("Ingrese el Personaje");
                                    textbox2.clearText();
                                    textbox2.setSelected(true);
                                    actualNode->value = "";
                                    oneTime--;
                                    btn1.setText("Falso");
                                    btn2.setText("Verdadero");
                                }
                                else {
                                    actualNode = raiz;
                                    textbox1.setText("Pregunta");
                                }
                            }
                        }
                        if (btn3.isMouserOver(window)) {
                            window.close();
                        break;
                        }
                        break;
                }
            }

            window.clear(sf::Color::Blue);
            textbox2.drawTo(window);
            textbox1.drawTo(window);
            if(oneTime != 0)
                btn1.drawTo(window);
            btn2.drawTo(window);
            btn3.drawTo(window);
            window.display();
        }
    }
};