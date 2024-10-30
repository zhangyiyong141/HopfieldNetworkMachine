#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"
#include "Rectangle.h"
#include "HopfieldNetworkMachine.h"
bool studyButtonClicked(int mouseX, int mouseY, int buttonX, int buttonY, int buttonWidth, int buttonHeight) {
    if (mouseX >= buttonX && mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY && mouseY <= buttonY + buttonHeight)
        return true;
    return false;
}
void VisualizePattern() {
    int size = 8;
    // 定义Hopfield网络的神经元数量为10
    int num_neurons = 64;
    HopFieldNetworkMachine* HNMachine = new HopFieldNetworkMachine(num_neurons);

    //初始化单元格绘制
    float cellSize = 50; // 每个单元格的大小
    unsigned int windowSize = size * 50;
    std::vector<RectCell*> cells(num_neurons);
    std::vector<RectCell*> cellsOutput(num_neurons);
    int idx = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            RectCell* newCell = new RectCell(j * cellSize, i * cellSize, cellSize, cellSize, "", HNMachine);
            cells[idx] = newCell;
            idx++;
        }
    }
    idx = 0;
    float baseSecondNetHeight = cellSize * (size + 1);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            RectCell* newCell = new RectCell(j * cellSize, baseSecondNetHeight+(i * cellSize), cellSize, cellSize, "");
            cellsOutput[idx] = newCell;
            idx++;
        }
    }

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize * 2 + 50), "Hopfield Pattern Visualization");
    // 创建按钮
    Button Button_CM(0, size * cellSize, 150, 50, "Clear Memory", HNMachine);
    Button Button_S(175, size * cellSize, 100, 50, "Study", HNMachine);
    Button Button_I(300, size * cellSize, 100, 50, "Identify", HNMachine);

    while (window.isOpen()) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        Button_CM.update(mousePosition, mousePressed);
        Button_S.update(mousePosition, mousePressed);
        Button_I.update(mousePosition, mousePressed);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // 检测鼠标左键点击
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 获取鼠标点击位置
                    float x = static_cast<float>(event.mouseButton.x);
                    float y = static_cast<float>(event.mouseButton.y);

                    std::cout << "Click on: " << x << ", " << y << std::endl;
                    if (studyButtonClicked(x, y, 175, size * cellSize, 100, 50)) {
                        for (int i = 0; i < cells.size(); i++) {
                            cells[i]->setSelected(false);
                            cells[i]->update(mousePosition, mousePressed);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < cells.size(); i++) {
            cells[i]->update(mousePosition, mousePressed);
            if (cells[i]->getSelected())
                HNMachine->OncePattern[i] = 1;
            else
                HNMachine->OncePattern[i] = -1;
        }
        for (int i = 0; i < cellsOutput.size(); i++) {
            if (HNMachine->result[i] == 1)
                cellsOutput[i]->setSelected(true);
            else if (HNMachine->result[i] == -1)
                cellsOutput[i]->setSelected(false);
            cellsOutput[i]->update(mousePosition, mousePressed);
        }

        //从clear下面开始绘制，鼠标事件在clear上面
        window.clear(sf::Color::White);

        for (auto itr : cells) {
            itr->draw(window);
        }
        for (auto itr : cellsOutput) {
            itr->draw(window);
        }

        // 绘制按钮
        Button_CM.draw(window);
        Button_S.draw(window);
        Button_I.draw(window);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // 绘制水平黑线（在每个方格的上下边缘）
                sf::Vertex line1[] = {
                    sf::Vertex(sf::Vector2f(j * cellSize, (i + 1) * cellSize), sf::Color::Black), // 下边缘的起点
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, (i + 1) * cellSize), sf::Color::Black) // 下边缘的终点
                };
                window.draw(line1, 2, sf::Lines);

                // 绘制垂直黑线（在每个方格的左右边缘）
                sf::Vertex line2[] = {
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, i * cellSize), sf::Color::Black), // 右边缘的起点
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, (i + 1) * cellSize), sf::Color::Black) // 右边缘的终点
                };
                window.draw(line2, 2, sf::Lines);
            }
        }
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // 绘制水平黑线（在每个方格的上下边缘）
                sf::Vertex line1[] = {
                    sf::Vertex(sf::Vector2f(j * cellSize, baseSecondNetHeight+(i + 1) * cellSize), sf::Color::Black), // 下边缘的起点
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, baseSecondNetHeight+(i + 1) * cellSize), sf::Color::Black) // 下边缘的终点
                };
                window.draw(line1, 2, sf::Lines);

                // 绘制垂直黑线（在每个方格的左右边缘）
                sf::Vertex line2[] = {
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, baseSecondNetHeight+i * cellSize), sf::Color::Black), // 右边缘的起点
                    sf::Vertex(sf::Vector2f((j + 1) * cellSize, baseSecondNetHeight+(i + 1) * cellSize), sf::Color::Black) // 右边缘的终点
                };
                window.draw(line2, 2, sf::Lines);
            }
        }

        window.display();
    }
}
