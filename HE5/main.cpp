#include <iostream>
#include <vector>
#include "SFMLVisual.h"
#include "HopfieldNetwork.h"

int main() {
    // 定义Hopfield网络的神经元数量为10
    //int num_neurons = 10;
    //HopfieldNetwork network(num_neurons);

    //// 训练模式，使用+1和-1表示激活与未激活
    //std::vector<std::vector<int>> patterns = {
    //    {1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
    //    {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1}
    //};

    //network.train(patterns);

    //// 输出训练后的权重矩阵
    //std::cout << "Weights after training:\n";
    //network.printWeights();

    //// 通过测试部分输入来回忆模式
    //std::vector<int> input = { 1, -1, -1, -1, 1, -1, 1, 1, -1, -1 };
    //std::vector<int> result = network.recall(input);

    //// 输出回忆结果
    //std::cout << "\nRecalled pattern:\n";
    //for (int s : result) {
    //    std::cout << s << " ";
    //}
    //std::cout << "\n";

    // 确保定义一个包含64个元素的模式
    std::vector<int> pattern = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, -1, -1, -1, -1, -1, 1, 1,
        1, -1, -1, -1, -1, -1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
        1, -1, -1, -1, -1, -1, 1, 1,
        1, -1, -1, -1, -1, -1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1
    };

    // 确保模式的大小是 8x8
    if (pattern.size() != 64) {
        std::cerr << "Error: Pattern must be of size 8x8 (64 elements)." << std::endl;
        return -1;
    }

    VisualizePattern(pattern, 8);

    return 0;
}
