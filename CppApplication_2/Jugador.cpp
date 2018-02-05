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
#include <iostream>
#include "Proyectil.h"

#include "Jugador.h"
#include "Enemigo.h"

#define disp 5

Jugador::Jugador() {
    //TEXTURA
    this->texture.loadFromFile("../Sprites/p_1.png");

    //SPRITES
    int sc = 4;
    this->sprite.setTexture(this->texture);
    this->sprite.scale(sc,sc);
    this->sprite.setOrigin(6,4);
    this->sprite.setPosition(640/2,480-(8*sc/2)-(sc*2));
    
}

void Jugador::MoverDerecha(){
    this->sprite.move(disp,0);
    
    if(this->sprite.getPosition().x > 640-(this->sprite.getGlobalBounds().width/2)){
        this->sprite.move(-disp,0);
    }
}

void Jugador::MoverIzquierda(){
    this->sprite.move(-disp,0);
    
    if(this->sprite.getPosition().x < 0+((this->sprite.getGlobalBounds().width/2))){
        this->sprite.move(disp,0);
    }
}

void Jugador::Dibujar(sf::RenderWindow& window){
    //PRIMERO DIBUJO MI SPRITE
    window.draw(this->sprite);
    
    
    //DESPUES LOS DISPAROS
    if(!disparos.empty()){
        
        std::stack<Proyectil> aux;
        while(!disparos.empty()){
            Proyectil proy = disparos.top();
            disparos.pop();

            //std::cout << proy.getPos().x << std::endl;
            if(proy.getPos().y<0){
                //SE DESTRUYE EL PROYECTIL
                
                
                std::cout << "Se destruye el proyectil" << std::endl;
            }
            else{
                //SE MUEVE
                proy.Mover();
                proy.Dibujar(window);
                aux.push(proy);
            }

        }
        
        while(!aux.empty()){
            disparos.push(aux.top());
            aux.pop();
            
        }
        
    }
}

void Jugador::Disparar(){
    sf::Vector2f posJ = this->sprite.getPosition();
    
    Proyectil proy(true,posJ);
    
    this->disparos.push(proy);
    
}

//GETTER
sf::Vector2f Jugador::getPos(){
    return this->sprite.getPosition();
}

std::stack<Proyectil> Jugador::getDisparos() {
    return this->disparos;
}

//SETTER

void Jugador::setDisparos(std::stack<Proyectil> proy) {
    this->disparos = proy;
}




Jugador::~Jugador() {
    
}

