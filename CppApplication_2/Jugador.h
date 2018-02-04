/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.h
 * Author: pablomanez
 *
 * Created on 4 de febrero de 2018, 13:32
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>

class Jugador {
public:
    
    Jugador();
    
    void MoverDerecha();
    void MoverIzquierda();
    void Dibujar(sf::RenderWindow& window);
    
    //GETTER
    sf::Vector2f getPos();
    
    virtual ~Jugador();
    
    
private:
    
    sf::Texture texture;
    sf::Sprite sprite;
    
    
    
};

#endif /* JUGADOR_H */

