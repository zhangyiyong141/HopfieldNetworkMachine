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

    VisualizePattern();

    return 0;
}
