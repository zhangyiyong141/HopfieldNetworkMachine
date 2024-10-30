#pragma once
#include "HopfieldNetwork.h"

class HopFieldNetworkMachine {
public:
    // 定义Hopfield网络的神经元数量为10
    int num_neurons = 64;
    int size_col = 8;
    int size_row = 8;
    std::vector<int> OncePattern;
    std::vector<std::vector<int>> patterns;
    std::vector<int> result;
    HopfieldNetwork* network;

    HopFieldNetworkMachine(int neurons){
        num_neurons = neurons;
        network = new HopfieldNetwork(num_neurons);
        OncePattern.resize(num_neurons);
        result.resize(num_neurons);
        patterns.push_back(OncePattern);
    }
    // 使用Hebbian规则训练Hopfield网络
    void train() {
        printPattern();
        patterns.clear();
        patterns.push_back(OncePattern);
        network->train(patterns);
        printWeights();
    }
    // 使用Hopfield网络进行回忆操作
    void recall() {
        result = network->recall(OncePattern);
        printResult();
    }
    void printPattern() const {
        for (int i = 0; i < size_row; i++) {
            for (int j = 0; j < size_col; j++) {
                if (OncePattern[i * size_col + j] == 1)
                    std::cout << "." << " ";
                else
                    std::cout << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void printResult() const{
        for (int i = 0; i < size_row; i++) {
            for (int j = 0; j < size_col; j++) {
                if (result[i * size_col + j] == 1)
                    std::cout << "." << " ";
                else if (result[i * size_col + j] == -1)
                    std::cout << "  ";
            }
            std::cout << std::endl;
        }
    }
    void printWeights() const {
        network->printWeights();
    }
    void buttonExe(const std::string action) {
        if (action == "Study") {
            this->train();
        }
        else if (action == "Identify") {
            this->recall();
        }
    }
};