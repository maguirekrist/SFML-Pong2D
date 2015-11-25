//
//  Window.hpp
//  2DPingPong
//
//  Created by Maguire Krist on 11/19/15.
//  Copyright © 2015 Maguire Krist. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(int, int, std::string);
    
    //Data
    int getWindowWidth();
    int getWindowHeight();
    float getOriginX();
    float getOriginY();
    void createWindow();
    sf::RenderWindow* getWindow();
    
private:
    int width;
    int height;
    std::string title;
    float orginX;
    float orginY;
};

#endif /* Window_hpp */
