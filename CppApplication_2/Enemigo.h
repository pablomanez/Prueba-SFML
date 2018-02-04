/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.h
 * Author: pablomanez
 *
 * Created on 4 de febrero de 2018, 20:33
 */

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Enemigo {
public:
    Enemigo();
    Enemigo(int i,sf::Vector2f pos);
    void Mover(bool dir);
    void MoverVertical();
    void Dibujar(sf::RenderWindow& window);
    
    //GETTER
    sf::Vector2f getPos();
    
    //SETTER
    void setCaract(int num, sf::Vector2f pos);
    virtual ~Enemigo();
    
private:
    
    int puntuacion;
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif /* ENEMIGO_H */

