#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "HopfieldNetworkMachine.h"

class RectCell {
public:
    RectCell(float x, float y, float width, float height, const std::string& label, HopFieldNetworkMachine* hnm = nullptr)
        : isHovered(false), isPressed(false), isSelected(false) {
        buttonShape.setSize(sf::Vector2f(width, height));
        buttonShape.setPosition(x, y);
        buttonShape.setFillColor(sf::Color::White);
        HNM = hnm;
        // �����ı�
        font.loadFromFile("C://Windows/Fonts/arial.ttf"); // ȷ������Ӧ�������ļ�
        buttonText.setFont(font);
        buttonText.setString(label);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(x + 10, y + 10); // �����ı�λ��
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    void update(const sf::Vector2i& mousePosition, bool mousePressed) {
        if (buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            isHovered = true;
            if (isSelected)
                buttonShape.setFillColor(sf::Color::Magenta); // �����ͣʱ��ɫ
            else
                buttonShape.setFillColor(sf::Color::Yellow); // �����ͣʱ��ɫ
            if (mousePressed && !isPressed) {
                isPressed = true; // ��¼��ť������
                // ��ť�������ִ�в���
                std::cout << "Button clicked!" << std::endl;
                if (HNM)
                    HNM->recall();
                FlipSelected();
            }
        }
        else {
            isHovered = false;
            if (isSelected)
                buttonShape.setFillColor(sf::Color::Black);
            else
                buttonShape.setFillColor(sf::Color::White);
        }

        // �����겻�ٰ��£����ð���״̬
        if (!mousePressed) {
            isPressed = false;
        }
    }
    void FlipSelected() {
        if (getSelected())
            setSelected(false);
        else
            setSelected(true);
    }
    bool getSelected() {
        return isSelected;
    }
    void setSelected(bool b) {
        isSelected = b;
    }
private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
    bool isHovered;
    bool isPressed; // ��¼��ť�Ƿ񱻰���
    bool isSelected;
    HopFieldNetworkMachine* HNM;
};