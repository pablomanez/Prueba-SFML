/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.cpp
 * Author: pablomanez
 * 
 * Created on 4 de febrero de 2018, 13:32
 */

#include <SFML/Graphics.hpp>

#include "Jugador.h"

Jugador::Jugador() {
    //TEXTURA
    this->texture.loadFromFile("p_1.png");

    //SPRITES
    int sc = 4;
    this->sprite.setTexture(this->texture);
    this->sprite.scale(sc,sc);
    this->sprite.setOrigin(6,4);
    this->sprite.setPosition(640/2,480-(8*sc/2)-(sc*2));
    
}

void Jugador::MoverDerecha(){
    this->sprite.move(10,0);
    
    if(this->sprite.getPosition().x > 640-(this->sprite.getGlobalBounds().width/2)){
        this->sprite.move(-10,0);
    }
}

void Jugador::MoverIzquierda(){
    this->sprite.move(-10,0);
    
    if(this->sprite.getPosition().x < 0+((this->sprite.getGlobalBounds().width/2))){
        this->sprite.move(10,0);
    }
}

void Jugador::Dibujar(sf::RenderWindow& window){
    window.draw(this->sprite);
}

void Disparar(){
    Proyectil proy;
}

//GETTER
sf::Vector2f Jugador::getPos(){
    return this->sprite.getPosition();
}



Jugador::~Jugador() {
}

