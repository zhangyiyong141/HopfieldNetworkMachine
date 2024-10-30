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
        // �����ı�
        font.loadFromFile("C://Windows/Fonts/arial.ttf"); // ȷ������Ӧ�������ļ�
        buttonText.setFont(font);
        buttonText.setString(label);
        buttonText.setCharacterSize(22);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(x + 5, y + 10); // �����ı�λ��
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    void update(const sf::Vector2i& mousePosition, bool mousePressed) {
        if (buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            isHovered = true;
            buttonShape.setFillColor(sf::Color::Yellow); // �����ͣʱ��ɫ
            if (mousePressed && !isPressed) {
                isPressed = true; // ��¼��ť������
                // ��ť�������ִ�в���
                std::cout << "Button clicked!" << std::endl;
                HNM->buttonExe(buttonText.getString());
            }
        }
        else {
            isHovered = false;
            buttonShape.setFillColor(sf::Color::Green);
        }

        // �����겻�ٰ��£����ð���״̬
        if (!mousePressed) {
            isPressed = false;
        }
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
    bool isHovered;
    bool isPressed; // ��¼��ť�Ƿ񱻰���
    HopFieldNetworkMachine* HNM;
};