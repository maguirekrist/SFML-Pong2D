//
//  Player.hpp
//  SFMLtest1
//
//  Created by Maguire Krist on 11/19/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"


class Player {
public:
    Player();
    Player(float, float, float, float);
    
    //Data
    float accel;
    
    //Getters and Setters
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    void setX(float);
    void setY(float);
    void setWidth(float);
    void setHeight(float);
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    void setPosition(sf::Vector2f);
    void setVelocity(sf::Vector2f);
    sf::Shape getPlayerShape();
    void updatePlayer(float dt);
    float getVelY();
    float getVelX();
    void setVelY(float);
    void setVelX(float);
    bool collisionBall(Ball);
    void collisionWall(float, float);
    
    
private:
    float width;
    float height;
    sf::RectangleShape playerShape;
    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity;
};

#endif /* Player_hpp */
