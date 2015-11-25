//
//  Ball.cpp
//  2DPingPong
//
//  Created by Maguire Krist on 11/20/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#include "Ball.hpp"

Ball::Ball(float x, float y, float width, float height) {
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    
    this->velocity.x = -100;
    this->velocity.y = 0;
    
    sf::Vector2f ballShapeSize(width, height);
    this->ballShape.setPosition(x, y);
    this->ballShape.setSize(ballShapeSize);
    this->ballShape.setFillColor(sf::Color::Red);
    
}

void Ball::updateBall(float dt) {
    //setVelY(getVelY() + -this->accel * 2);
    //setVelX(getVelX() + this->accel * 2);
    
    // Clamp velocity y
    if(getVelY() > this->accel) {
        setVelY(this->accel);
    } else if(getVelY() < -this->accel) {
        setVelY(-this->accel);
    }
    // Clamp velocity x
    if(getVelX() > this->accel) {
        setVelX(this->accel);
    } else if(getVelX() < -this->accel) {
        setVelX(-this->accel);
    }
    
    
    float newX = getX() + getVelX() * dt;
    float newY = getY() + getVelY() * dt;
    sf::Vector2f newPos(newX, newY);
    setPosition(newPos);
    ballShape.setPosition(getX(), getY());
    
}

void Ball::collisionWall(float wallWidth, float wallHeight) {
    // Check with walls
    if((getY() + getHeight()) > (0 + wallHeight)) {
        setVelY(getVelY() * -1);
    }
    if(getY() < 0) {
        setVelY(getVelY() * -1);
    }
}

sf::Vector2f Ball::getPosition() {
    return this->position;
}

sf::Vector2f Ball::getVelocity() {
    return this->velocity;
}

sf::RectangleShape Ball::getShape() {
    return this->ballShape;
}

float Ball::getX() {
    return this->position.x;
}

float Ball::getY() {
    return this->position.y;
}

float Ball::getWidth() {
    return this->width;
}

float Ball::getHeight() {
    return this->height;
}

float Ball::getVelX() {
    return this->velocity.x;
}

float Ball::getVelY() {
    return this->velocity.y;
}

void Ball::setPosition(sf::Vector2f newPos) {
    this->position = newPos;
}

void Ball::setVelocity(sf::Vector2f newVel) {
    this->velocity = newVel;
}

void Ball::setX(float x) {
    this->position.x = x;
}

void Ball::setY(float y) {
    this->position.y = y;
}

void Ball::setWidth(float width) {
    this->width = width;
}

void Ball::setHeight(float height) {
    this->height = height;
}

void Ball::setVelX(float velX) {
    this->velocity.x = velX;
}

void Ball::setVelY(float velY) {
    this->velocity.y = velY;
}

