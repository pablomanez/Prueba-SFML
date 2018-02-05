/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Proyectil.h
 * Author: pablomanez
 *
 * Created on 4 de febrero de 2018, 16:04
 */

#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Proyectil {
public:
    Proyectil(bool b,sf::Vector2f o);
    void Dibujar(sf::RenderWindow& window);
    void Mover();
    
    //GETTER
    sf::Vector2f getPos();
    sf::FloatRect getGBounds();
    
    virtual ~Proyectil();
    
private:
    //TRUE SI ES ALIADO, FALSE SI ES ENEMIGO
    bool aliado;
    sf::Vector2f origen;
    //SPRITE
    sf::RectangleShape shape;

};

#endif /* PROYECTIL_H */

