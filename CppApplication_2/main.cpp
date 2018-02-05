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
#include <array>

#include "Jugador.h"
#include "Enemigo.h"

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
    
    //////////////////////////////////////////
    //CREACION DE LOS ENEMIGOS Y DEL JUGADOR//
    //////////////////////////////////////////
    
    //JUGADOR
    Jugador player;
    
    //ENEMIGOS
    int tam = 7;
    int fil = 8;
    //std::array<Enemigo,7> arr_enem;
    
    //SACAR LAS DIMENSIONES DE UN ARRAY DE 1 Y SOLO 1 DIMENSION
    //Enemigo arr_enem[tam];
    //cout << "filas: " << sizeof(arr_enem)/sizeof(Enemigo) << endl; //HORIZONTAL
    
    //SACAR LAS DIMENSIONES DE UN ARRAY DE 2 Y SOLO 2 DIMENSIONES
    Enemigo arr_enem[tam][fil];
    cout << "columnas: " << (sizeof(arr_enem[0])/sizeof(Enemigo)) << endl; //VERTICAL
    cout << "filas: " << (sizeof(arr_enem)/sizeof(arr_enem[0])) << endl; //HORIZONTAL
    /*
    for(int i = 0; i<(sizeof(arr_enem)/sizeof(Enemigo)); i++){
        arr_enem[i].setCaract(1,sf::Vector2f(42+(16*4*i),80));
        
    }
    */
    
    for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
        for(int i = 0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
            arr_enem[i][j].setCaract(1,sf::Vector2f(42+(16*4*i),80+(35*j)));

        }
    }
    
    
    //cout << sizeof(arr_enem)/sizeof(Enemigo);
    
        
    //VARIABLES LOCALES
    bool right = false;
    bool left = false;
    bool dir_enem = true;
    
    //LOOP DEL JUEGO
    while (window.isOpen()){
        /*
         * 1- HANDLE INPUT, FROM DEVICES AND THE WINDOW
         * 2- UPDATE FRAME, UPDATE THE OBJECTS IN THE SCENE
         * 3- RENDER FRAME, RENDER THE OBJECTS FROM THE SCENE ONTO THE WINDOW
         */
                
        /////////////////////
        //MANEJAR LOS INPUT//
        /////////////////////
        sf::Event event;
        //while (window.waitEvent(event)){
        while(window.pollEvent(event)){
        
            switch(event.type){
                
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                
                case sf::Event::EventType::KeyPressed:
                    //PUEDE USARSE TAMBIEN KeyBoard::isKeyPressed(sf::KeyBoard::Key::Right) TODO JUNTO
                    if(event.key.code == sf::Keyboard::Key::Space && event.key.code == sf::Keyboard::Key::Right){
                        right = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Space && event.key.code == sf::Keyboard::Key::Left){
                        left = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Right){
                        right = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        left = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Space){
                        player.Disparar();
                    }
                    break;
                    
                case sf::Event::EventType::KeyReleased:
                    if(event.key.code == sf::Keyboard::Key::Space && event.key.code == sf::Keyboard::Key::Right){
                        right = false;
                    }
                    if(event.key.code == sf::Keyboard::Key::Space && event.key.code == sf::Keyboard::Key::Left){
                        left = false;
                    }
                    if(event.key.code == sf::Keyboard::Key::Right){
                        right = false;
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        left = false;
                    }
                    if(event.key.code == sf::Keyboard::Key::Escape){
                        window.close();
                    }
                    break;
                    
                default: break;
                
            }
            
            
        }
        
        //----------ACTUALIZACION DE LA ESCENA----------//
                
        //////////////////////
        //ACTUALIZAR OBJETOS//
        //////////////////////
        
        //MOVIMIENTO JUGADOR
        if(right){
            player.MoverDerecha();
        }
        else if(left){
            player.MoverIzquierda();
        }
        
        //MOVIMIENTO ENEMIGOS
        
        for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
            for(int i = 0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                arr_enem[i][j].Mover(dir_enem);


            }
        }
        
        int first = 0;
        int last = (sizeof(arr_enem)/sizeof(Enemigo))-1;
        for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
            for(int i=0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                //BUSCO EL PRIMER ENEMIGO DEL ARRAY, QUE NO SE HAYA ELIMINADO
                if(arr_enem[i][j].getPuntuacion()!=0){
                    first = i;
                    break;
                }
            }
            for(int i=0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                //BUSCO EL ULTIMO ENEMIGO DEL ARRAY, QUE NO SE HAYA ELIMINADO
                if(arr_enem[i][j].getPuntuacion()!=0){
                    last = i;
                }
            }
        

        
            if(dir_enem && arr_enem[last][j].getPos().x+42 > 640){
                //SE SALEN DEL MAPA POR LA DERECHA
                dir_enem = false;
                for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
                    for(int i = 0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                        arr_enem[i][j].Mover(dir_enem);
                        arr_enem[i][j].MoverVertical();
                    }
                }
            }
            else if(!dir_enem && arr_enem[first][j].getPos().x-42 < 0){
                // SE SALEN DEL MAPA POR LA IZQUIERDA
                dir_enem = true;
                for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){    
                    for(int i = 0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                        arr_enem[i][j].Mover(dir_enem);
                        arr_enem[i][j].MoverVertical();
                    }
                }
            }
        }
        
        
        //COMPRUEBO LOS DISPAROS UNA VEZ SE HA MOVIDO TODO
        std::stack<Proyectil> disparos = player.getDisparos();
        std::stack<Proyectil> disparos_aux;
        std::stack<Enemigo> arr_enem_aux;
        Enemigo enemigo_aux;
        
        bool mata = false;
        
        while(!disparos.empty()){
            mata = false;
            
            Proyectil aux = disparos.top();
            disparos.pop();
            for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
                for(int i=0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                    if(aux.getGBounds().intersects(arr_enem[i][j].getGBounds())){
                        mata = true;
                        //enemigo_aux = arr_enem[i];
                        arr_enem[i][j] = enemigo_aux;

                        break;
                    }
                }
            }
            
            if(!mata){
                disparos_aux.push(aux);
            }
            else{
                arr_enem_aux.push(enemigo_aux);
                cout << "Se destruye el proyectil"<< endl;
            }
        }
        while(!disparos_aux.empty()){
            disparos.push(disparos_aux.top());
            disparos_aux.pop();
        }
        
        player.setDisparos(disparos);
        
        
        //TEXTO DE LA X DEL JUGADOR
        sf::Text text,t11;
        sf::Font font1;
        font1.loadFromFile("monoMMM_5.ttf");
        
        sf::String x1 = to_string(player.getPos().x);
        
        t11.setFont(font1);
        t11.setString(x1);
        t11.setFillColor(sf::Color::White);
        
        
        
        /////////////////////////
        //RENDER DE LOS OBJETOS//
        /////////////////////////
        window.clear(sf::Color::Black);
        
        window.draw(t11);
        player.Dibujar(window);
                
        
        for(int j = 0; j<(sizeof(arr_enem[0])/sizeof(Enemigo)); j++){
            for(int i = 0; i<(sizeof(arr_enem)/sizeof(arr_enem[0])); i++){
                arr_enem[i][j].Dibujar(window);

            }
        }
        
        
        
        window.display();
        
    }
    
    return 0;
    
}

