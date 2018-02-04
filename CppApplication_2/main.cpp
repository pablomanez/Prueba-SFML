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
#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
#include <valarray>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Jugador.h"

using namespace std;

/*
 * 
 */

int main(){
    
    //sf::VideoMode videomode;
    //getDesktopMode() consigue la resolucion maxima de la pantalla, es decir, fullscreen
    
    sf::RenderWindow window(sf::VideoMode(640,480),"Mi titulo",sf::Style::Default);
    window.setMouseCursorVisible(true);
    window.setFramerateLimit(60);
    //sf::sleep(sf::seconds(3));
    
    //A DIBUJAR
    /*
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
    enemy.setPosition(400,100);
    */
    
    //CARGA DE IMAGENES Y TEXTURAS
    /*
    sf::Image image;
    //PARA PREVENCION DE BUGS
    if(!image.loadFromFile("../Sprites/p_1.png")){
        return -1;
    }
    */
    
    //ESTA ES LA CLASE QUE USARA EL JUGADOR
    Jugador player;
    
    
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
                        player.MoverDerecha();
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        player.MoverIzquierda();
                    }
                    if(event.key.code == sf::Keyboard::Key::Space){
                        player.Disparar();
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
        sf::Text text,t11;
        sf::Font font1;
        font1.loadFromFile("monoMMM_5.ttf");
        
        sf::String x1 = to_string(player.getPos().x);
        
        t11.setFont(font1);
        t11.setString(x1);
        t11.setFillColor(sf::Color::White);
        
        
        //RENDER DE LOS OBJETOS
        window.clear(sf::Color::Black);
        
        window.draw(t11);
        player.Dibujar(window);
        
        
        window.display();
        
    }
    
    return 0;
    
}

