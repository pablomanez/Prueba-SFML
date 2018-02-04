/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.cpp
 * Author: pablomanez
 * 
 * Created on 4 de febrero de 2018, 20:33
 */

#include <SFML/Graphics/Texture.hpp>

#include "Enemigo.h"
Enemigo::Enemigo(){
    
}
Enemigo::Enemigo(int i,sf::Vector2f pos) {
    
    int sc = 3;
    switch (i){
        case 1:
            this->puntuacion = 10;
            
            this->texture.loadFromFile("../Sprites/e_1.png");            
            this->sprite.setTexture(this->texture);
            this->sprite.scale(sc,sc);
            this->sprite.setOrigin(8,7/2); //16-7
            this->sprite.setPosition(pos.x,pos.y);
            
            break;
        default:
            this->puntuacion = 10;
            break;
    }
    
}

void Enemigo::Mover(bool dir) {
    if(dir){
        this->sprite.move(1,0);
    }
    else{
        this->sprite.move(-1,0);
    }
}

void Enemigo::MoverVertical() {
    
    this->sprite.move(0,10);
    
}


void Enemigo::Dibujar(sf::RenderWindow& window) {

    window.draw(sprite);
    
}

void Enemigo::setCaract(int i, sf::Vector2f pos) {
    
    int sc = 3;
    switch (i){
        case 1:
            this->puntuacion = 10;
            
            this->texture.loadFromFile("../Sprites/e_1.png");            
            this->sprite.setTexture(this->texture);
            this->sprite.scale(sc,sc);
            this->sprite.setOrigin(8,7/2); //16-7
            this->sprite.setPosition(pos.x,pos.y);
            
            break;
        default:
            this->puntuacion = 10;
            break;
    }
    
    
}

sf::Vector2f Enemigo::getPos() {
    return this->sprite.getPosition();
}




Enemigo::~Enemigo() {
}

