//
//  Ball.hpp
//  2DPingPong
//
//  Created by Maguire Krist on 11/20/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float, float, float, float);
    
    void updateBall(float);
    void collisionWall(float, float);
    
    //Data
    float accel;
    
    //Getters and Setters
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::RectangleShape getShape();
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    float getVelX();
    float getVelY();
    
    void setPosition(sf::Vector2f);
    void setVelocity(sf::Vector2f);
    void setX(float);
    void setY(float);
    void setWidth(float);
    void setHeight(float);
    void setVelX(float);
    void setVelY(float);
    
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape ballShape;
    float width;
    float height;
};

#endif /* Ball_hpp */
