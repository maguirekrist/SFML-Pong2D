//
//  Player.cpp
//  SFMLtest1
//
//  Created by Maguire Krist on 11/19/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#include "Player.hpp"
#include "Window.hpp"
#include "Ball.hpp"
#include <iostream>


Player::Player() {
    this->width = 0;
    this->height = 0;
    playerPosition.x = 0;
    playerPosition.y = 0;
    playerVelocity.x = 0;
    playerVelocity.y = 0;
}

Player::Player(float x, float y, float width, float height) {
    this->width = width;
    this->height = height;
    
    playerVelocity.x = 0;
    playerVelocity.y = 0;
    playerPosition.x = x;
    playerPosition.y = y;
    sf::Vector2f playerSize(width, height);
    playerShape.setPosition(x, y);
    playerShape.setSize(playerSize);
    playerShape.setFillColor(sf::Color::White);
}

void Player::updatePlayer(float dt) {
    
    // Clamp velocity
    if(getVelY() > this->accel) {
        setVelY(this->accel);
    } else if(getVelY() < -this->accel) {
        setVelY(-this->accel);
    }
    
    setY(getY() + getVelY() * dt);
    playerShape.setPosition(getX(), getY());
}

float Player::getX() {
    return playerPosition.x;
}

float Player::getY() {
    return playerPosition.y;
}

float Player::getWidth() {
    return this->width;
}

float Player::getHeight() {
    return this->height;
}

void Player::setX(float x) {
    playerPosition.x = x;
}

void Player::setY(float y) {
    playerPosition.y = y;
}

void Player::setWidth(float width) {
    this->width = width;
}

void Player::setHeight(float height) {
    this->height = height;
}

sf::Shape Player::getPlayerShape() {
    return playerShape;
}

sf::Vector2f Player::getPosition() {
    return playerPosition;
}

sf::Vector2f Player::getVelocity() {
    return playerVelocity;
}

void Player::setPosition(sf::Vector2f newPos) {
    playerPosition = newPos;
}

void Player::setVelocity(sf::Vector2f newVel) {
    playerVelocity = newVel;
}

float Player::getVelX() {
    return playerVelocity.x;
}

float Player::getVelY() {
    return playerVelocity.y;
}

void Player::setVelX(float vx) {
    playerVelocity.x = vx;
}

void Player::setVelY(float vy) {
    playerVelocity.y = vy;
}

bool Player::collisionBall(Ball ball) {
    //Check is player is touching bounds of the box
    // AABB
    bool collision = false;
    float preX = getX();
    float preY = getY();
    
    //Ball info
    float ballX = ball.getPosition().x;
    float ballY = ball.getPosition().y;
    float ballWidth = ball.getWidth();
    float ballHeight = ball.getHeight();
    
    if(ballY > getY() && (ballY + ballHeight) < (getY() + getHeight())) {
        if(((getX() + getWidth()) > ballX && ballX > getX()) || ((ballX + ballWidth) > getX() && ballX < getX())) {
                collision = true;
        }
    }
    
    
    if(collision == true) {
        return true;
    } else {
        return false;
    }
    
}

void Player::collisionWall(float wallWidth, float wallHeight) {
    // Check with walls
    float preX = getX();
    float preY = getY();
    if((getY() + getHeight()) > (0 + wallHeight)) {
        setY(preY);
        setVelY(getVelY() * -1);
    }
    if(getY() < 0) {
        setY(preY);
        setVelY(getVelY() * -1);
    }
}





