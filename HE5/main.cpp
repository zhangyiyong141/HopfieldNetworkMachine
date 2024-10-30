#include <iostream>
#include <vector>
#include "SFMLVisual.h"
#include "HopfieldNetwork.h"

int main() {
    // ����Hopfield�������Ԫ����Ϊ10
    //int num_neurons = 10;
    //HopfieldNetwork network(num_neurons);

    //// ѵ��ģʽ��ʹ��+1��-1��ʾ������δ����
    //std::vector<std::vector<int>> patterns = {
    //    {1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
    //    {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1}
    //};

    //network.train(patterns);

    //// ���ѵ�����Ȩ�ؾ���
    //std::cout << "Weights after training:\n";
    //network.printWeights();

    //// ͨ�����Բ�������������ģʽ
    //std::vector<int> input = { 1, -1, -1, -1, 1, -1, 1, 1, -1, -1 };
    //std::vector<int> result = network.recall(input);

    //// ���������
    //std::cout << "\nRecalled pattern:\n";
    //for (int s : result) {
    //    std::cout << s << " ";
    //}
    //std::cout << "\n";

    // ȷ������һ������64��Ԫ�ص�ģʽ
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

    // ȷ��ģʽ�Ĵ�С�� 8x8
    if (pattern.size() != 64) {
        std::cerr << "Error: Pattern must be of size 8x8 (64 elements)." << std::endl;
        return -1;
    }

    VisualizePattern(pattern, 8);

    return 0;
}
