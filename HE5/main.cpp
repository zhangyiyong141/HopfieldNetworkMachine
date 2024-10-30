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

    VisualizePattern();

    return 0;
}
