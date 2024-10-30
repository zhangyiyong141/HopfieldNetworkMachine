#pragma once
#include <iostream>
#include <vector>
class HopfieldNetwork {
private:
    std::vector<std::vector<int>> weights;
    int num_neurons;

public:
    HopfieldNetwork(int n) : num_neurons(n) {
        weights.resize(n, std::vector<int>(n, 0));
    }

    // 使用Hebbian规则训练Hopfield网络
    void train(const std::vector<std::vector<int>>& patterns) {
        std::cout << "EXE Training." << std::endl;
        for (const auto& pattern : patterns) {
            for (int i = 0; i < num_neurons; i++) {
                for (int j = 0; j < num_neurons; j++) {
                    if (i != j) {
                        weights[i][j] += pattern[i] * pattern[j];
                    }
                }
            }
        }
        std::cout << "EXE Finished." << std::endl;
    }

    // 使用Hopfield网络进行回忆操作
    std::vector<int> recall(const std::vector<int>& input, int max_iterations = 64) {
        std::vector<int> state = input;

        for (int iteration = 0; iteration < max_iterations; iteration++) {
            bool stable = true;

            for (int i = 0; i < num_neurons; i++) {
                int sum = 0;
                for (int j = 0; j < num_neurons; j++) {
                    sum += weights[i][j] * state[j];
                }
                int new_state = (sum >= 0) ? 1 : -1;
                if (state[i] != new_state) {
                    stable = false;
                    state[i] = new_state;
                }
            }

            if (stable) {
                break;
            }
        }
        return state;
    }

    void printWeights() const {
        for (const auto& row : weights) {
            for (int w : row) {
                if (w == 0)
                    std::cout << "00 ";
                else if (w < 0)
                    std::cout << w << " ";
                else if (w > 0)
                    std::cout << "+" << w << " ";
            }
            std::cout << "\n";
        }
    }
};