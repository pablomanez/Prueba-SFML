/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pablomanez
 *
 * Created on 2 de febrero de 2018, 12:56
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
#include <valarray>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

/*
 * 
 */

int main(){
    
    //sf::VideoMode videomode;
    //getDesktopMode() consigue la resolucion maxima de la pantalla, es decir, fullscreen
    
    sf::RenderWindow window(sf::VideoMode(600,500),"Mi titulo",sf::Style::Default);
    window.setMouseCursorVisible(true);
    window.setFramerateLimit(60);
    //sf::sleep(sf::seconds(3));
    
    //A DIBUJAR
    sf::CircleShape circleShape(20);
    circleShape.setFillColor(sf::Color::Red);
    circleShape.setOutlineColor(sf::Color::White);
    circleShape.setOutlineThickness(1);
    circleShape.setOrigin(20,20);
    circleShape.setPosition(100,100);
    
    sf::RectangleShape enemy(sf::Vector2f(50,50));
    enemy.setFillColor(sf::Color::Green);
    enemy.setOutlineThickness(1);
    enemy.setOutlineColor(sf::Color::White);
    
    //CONTROL DEL MOVIMIENTO DEL JUEGO
    bool move = false;
    int dist = 1;
    
    //LOOP DEL JUEGO
    while (window.isOpen()){
        /*
         * 1- HANDLE INPUT, FROM DEVICES AND THE WINDOW
         * 2- UPDATE FRAME, UPDATE THE OBJECTS IN THE SCENE
         * 3- RENDER FRAME, RENDER THE OBJECTS FROM THE SCENE ONTO THE WINDOW
         */
        
        //MANEJAR LOS INPUT
        sf::Event event;
        //while (window.waitEvent(event)){
        while(window.pollEvent(event)){
        
            switch(event.type){
                
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                
                case sf::Event::EventType::KeyPressed:
                    //PUEDE USARSE TAMBIEN KeyBoard::isKeyPressed(sf::KeyBoard::Key::Right) TODO JUNTO
                    if(event.key.code == sf::Keyboard::Key::Right){
                        circleShape.move(dist,0);
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        circleShape.move(-dist,0);
                    }
                    if(event.key.code == sf::Keyboard::Key::Up){
                        circleShape.move(0,-dist);
                    }
                    if(event.key.code == sf::Keyboard::Key::Down){
                        circleShape.move(0,dist);
                    }
                    break;
                    
                case sf::Event::EventType::KeyReleased:
                    if(event.key.code == sf::Keyboard::Key::Escape){
                        window.close();
                    }
                    break;
                    
                default: break;
                
            }
            
            
        }
        
        //----------ACTUALIZACION DE LA ESCENA----------//
                
        //ACTUALIZAR OBJETOS
        if(circleShape.getGlobalBounds().intersects(enemy.getGlobalBounds())){
            window.close();
        }
        
        //RENDER DE LOS OBJETOS
        window.clear(sf::Color::Black);
        
        window.draw(enemy);
        window.draw(circleShape);
        
        window.display();
        
    }
    
    return 0;
    
}


/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/
