#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "HopfieldNetworkMachine.h"

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& label, HopFieldNetworkMachine* hnm)
        : isHovered(false), isPressed(false){
        buttonShape.setSize(sf::Vector2f(width, height));
        buttonShape.setPosition(x, y);
        buttonShape.setFillColor(sf::Color::Green);
        HNM = hnm;
        // 创建文本
        font.loadFromFile("C://Windows/Fonts/arial.ttf"); // 确保有相应的字体文件
        buttonText.setFont(font);
        buttonText.setString(label);
        buttonText.setCharacterSize(22);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(x + 5, y + 10); // 设置文本位置
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    void update(const sf::Vector2i& mousePosition, bool mousePressed) {
        if (buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            isHovered = true;
            buttonShape.setFillColor(sf::Color::Yellow); // 鼠标悬停时变色
            if (mousePressed && !isPressed) {
                isPressed = true; // 记录按钮被按下
                // 按钮被点击，执行操作
                std::cout << "Button clicked!" << std::endl;
                HNM->buttonExe(buttonText.getString());
            }
        }
        else {
            isHovered = false;
            buttonShape.setFillColor(sf::Color::Green);
        }

        // 如果鼠标不再按下，重置按下状态
        if (!mousePressed) {
            isPressed = false;
        }
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
    bool isHovered;
    bool isPressed; // 记录按钮是否被按下
    HopFieldNetworkMachine* HNM;
};