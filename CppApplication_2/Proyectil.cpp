/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Proyectil.cpp
 * Author: pablomanez
 * 
 * Created on 4 de febrero de 2018, 16:04
 */

#include <SFML/Graphics/RenderWindow.hpp>

#include "Proyectil.h"

#define disp 10

Proyectil::Proyectil(bool b,sf::Vector2f o) {
    
    this->aliado = b;
    this->origen = o;
    
    this->shape.setSize(sf::Vector2f(4,8));
    this->shape.setFillColor(sf::Color::White);
    this->shape.setPosition(o.x,o.y);
    
    
    
}

void Proyectil::Mover() {

    if(this->aliado){
        //HACIA ARRIBA
        this->shape.move(0,-disp);
        
    }
    else{
        //HACIA ABAJO
        
    }
    
}

void Proyectil::Dibujar(sf::RenderWindow& window) {
    window.draw(this->shape);
}

//GETTER
sf::Vector2f Proyectil::getPos(){
    
    return this->shape.getPosition();
    
}

sf::FloatRect Proyectil::getGBounds() {
    return this->shape.getGlobalBounds();
}


Proyectil::~Proyectil() {
    
    
}

