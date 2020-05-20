#include "GameLoop.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <exception>

auto GameLoop::run() -> void {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hello window");

  sf::Music music;
  if (!music.openFromFile("resources/audio/Asteroids2.ogg")) {
    throw std::runtime_error("Couldn't find music file");
  }
  music.play();

  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // @TODO: create an input handling abstraction somehow
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Q) {
          window.close();
        }
      }
    }

    window.clear();
    window.display();
  }
}
