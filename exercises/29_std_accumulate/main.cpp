﻿#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // 调用 `std::accumulate` 计算：
    //       - 数据类型为 float(4byte)；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    int size = std::accumulate(shape, shape+4, 0, [](int init, int v) {
        return init ? init * v : v;
    });
    size *= sizeof(DataType);
//    printf("%d\n", size);
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
