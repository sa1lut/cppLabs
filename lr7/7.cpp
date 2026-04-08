#include <SFML/Graphics.hpp>
#include <ctime>
#include "shapes.h"

int main() {
    srand(time(0)); // аналог Randomize

    sf::RenderWindow window(sf::VideoMode(800, 600), "Task 7");

    Krug k;
    Ring r;

    k.init(100, 100, 40, sf::Color::Red);
    r.init(300, 200, 50, sf::Color::Green, 5);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        k.show(window);
        r.show(window);

        k.fly(10);
        // анимация содержит движение, изменение толщины и цвета
        r.animate(10);

        window.display();

        sf::sleep(sf::milliseconds(100)); // Delay(300)
    }

    return 0;
}