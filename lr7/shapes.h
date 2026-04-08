#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>

class Point {
protected:
    int x, y;
    sf::Color cvet;

public:
    void init(int XN, int YN, sf::Color Color) {
        x = XN;
        y = YN;
        cvet = Color;
    }

    virtual void show(sf::RenderWindow& window) {}

    virtual void hide(sf::RenderWindow& window) {}

    void locat(int& XL, int& YL) {
        XL = x;
        YL = y;
    }

    void fly(int cost) {
        int XX, YY;

        locat(XX, YY);

        // перемещение x
        do {
            XX = XX + (rand() % (2 * cost + 1) - cost);
        } while (!(XX > 0 && XX < 800)); // 800 - ширина окна

        // перемещение y
        do {
            YY = YY + (rand() % (2 * cost + 1) - cost);
        } while (!(YY > 0 && YY < 600)); // 600 - высота окна

        x = XX;
        y = YY;
    }

    // Деструктор
    virtual ~Point() {}
};

class Krug : public Point {
protected:
    int radius;

public:
    void init(int XN, int YN, int R, sf::Color Color) {
        Point::init(XN, YN, Color);
        radius = R;
    }

    void show(sf::RenderWindow& window) override {
        sf::CircleShape circle(radius);
        circle.setFillColor(cvet);
        circle.setPosition(x, y);
        window.draw(circle);
    }

    void hide(sf::RenderWindow& window) override {
        sf::CircleShape circle(radius);
        circle.setFillColor(sf::Color::Black);
        circle.setPosition(x, y);
        window.draw(circle);
    }
};


class Ring : public Krug {
protected:
    int width;

public:
    void init(int XN, int YN, int R, sf::Color Color, int Wid) {
        Krug::init(XN, YN, R, Color);
        width = Wid;
    }

    void show(sf::RenderWindow& window) override {
        sf::CircleShape ring(radius);

        ring.setPosition(x, y);
        ring.setOutlineColor(cvet);
        ring.setOutlineThickness(width);
        ring.setFillColor(sf::Color::Transparent);

        window.draw(ring);
    }

    // Сужение/расширение кольца
    void resize(int delta) {
        width += delta;

        if (width < 1) width = 1;
        if (width > radius) width = radius;
    }

    // Случайная смена цвета
    void changeColor() {
        cvet = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }

    // Анимация
    void animate(int cost) {
        // движение
        fly(cost);

        // случайно меняем толщину
        resize((rand() % 3) - 1); // -1, 0, +1

        // иногда меняем цвет
        if (rand() % 10 == 0) {
            changeColor();
        }
    }
};

#endif