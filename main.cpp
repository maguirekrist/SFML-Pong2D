
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Window.hpp"
#include "Ball.hpp"
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include <sstream>

int main(int, char const**)
{
    
    Window window(720, 480, "Pong");
    window.createWindow();
    
    Player player1(100, 100, 60, 120);
    player1.accel = 100;
    
    Player player2(window.getWindowWidth() - 150, 100, 60, 120);
    player2.accel = 100;
    
    Ball ball(400, 150, 20, 20);
    ball.accel = 100;

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Pong", font, 50);
    text.setPosition(window.getWindow()->getView().getCenter().x - 50, 10);
    text.setColor(sf::Color::White);

    sf::Clock deltaClock;
    
    bool computerOn = false;
    
    // Start the game loop
    while (window.getWindow()->isOpen())
    {
        // Process events
        sf::Time deltaTime = deltaClock.restart();
        sf::Event event;
        while (window.getWindow()->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.getWindow()->close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.getWindow()->close();
            }
        
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                player1.setVelY(player1.getVelY() + -player1.accel * 2);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                player1.setVelY(player1.getVelY() + player1.accel * 2);
            }
            //Allows for two player person games on the same computer
            if(!computerOn) {
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
                    player2.setVelY(player2.getVelY() + -player2.accel * 2);
                }
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                    player2.setVelY(player2.getVelY() + player2.accel * 2);
                }
            }
            
        }
        
        //Check Collision
        if(player1.collisionBall(ball)) {
            float half = player1.getY() + player1.getHeight() / 2;
            if(ball.getY() > half){
                ball.setVelY(ball.accel);
                ball.setVelX(ball.getVelX() * -1);
            } else if(ball.getY() < half) {
                ball.setVelY(-ball.accel);
                ball.setVelX(ball.getVelX() * -1);
            }
        }
        if(player2.collisionBall(ball)) {
            float half = player2.getY() + player2.getHeight() / 2;
            if(ball.getY() > half){
                ball.setVelY(ball.accel);
                ball.setVelX(ball.getVelX() * -1);
            } else if(ball.getY() < half) {
                ball.setVelY(-ball.accel);
                ball.setVelX(ball.getVelX() * -1);
            }
        }
        
        //Update game objects
        player1.updatePlayer(deltaTime.asSeconds());
        player1.collisionWall(window.getWindowWidth(), window.getWindowHeight());
        player2.updatePlayer(deltaTime.asSeconds());
        player2.collisionWall(window.getWindowWidth(), window.getWindowHeight());
        ball.updateBall(deltaTime.asSeconds());
        ball.collisionWall(window.getWindowWidth(), window.getWindowHeight());
        
        if(computerOn) {
            // BASIC PONG AI
            if(ball.getY() + ball.getHeight() / 2 > player2.getY() + player2.getHeight() / 2) {
                player2.setVelY(player2.getVelY() + player2.accel);
            } else if(ball.getY() + ball.getHeight() / 2 < player2.getY() + player2.getHeight() / 2) {
                player2.setVelY(player2.getVelY() + -player2.accel);
            }
            
            //AI Collision ? This needs to be here in order for it to work ? I HAVE NO IDEA WHY!
            if(player2.getY() + player2.getHeight() > 0 + window.getWindowHeight()) {
                player2.setVelY(player2.accel * -1);
            }
            if(player2.getY() < 0) {
                player2.setVelY(player2.accel);
            }
        }
        
        //Debug text
        std::stringstream debugText;
        debugText << "Y: " << player1.getVelY() << " Y: " << player2.getVelY() << std::endl;
        text.setString(debugText.str());
    
        
        // render shit
        window.getWindow()->clear();
        
        window.getWindow()->draw(text);
        window.getWindow()->draw(player1.getPlayerShape());
        window.getWindow()->draw(player2.getPlayerShape());
        window.getWindow()->draw(ball.getShape());
        
        window.getWindow()->display();
        
    }

    return EXIT_SUCCESS;
}


