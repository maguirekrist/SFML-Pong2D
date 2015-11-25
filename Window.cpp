//
//  Window.cpp
//  2DPingPong
//
//  Created by Maguire Krist on 11/19/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#include "Window.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

sf::RenderWindow* renderWindow;

Window::Window(int width, int height, string title) {
    this->width = width;
    this->height = height;
    this->title = title;
}

int Window::getWindowHeight() {
    return this->height;
}

int Window::getWindowWidth() {
    return this->width;
}

void Window::createWindow() {
    renderWindow = new sf::RenderWindow(sf::VideoMode(this->width, this->height), this->title);
}

sf::RenderWindow* Window::getWindow() {
    return renderWindow;
}
