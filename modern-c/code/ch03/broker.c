/*  broker.c - 计算股票经纪人的佣金  */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <trade>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // 获取交易金额：字符串转换为数值
    double trade = strtod(argv[1], nullptr);
    double commission = {0.0};

    if (trade < 2500.0) {
        commission = 30.0 + trade * 0.017;
    } else if (trade < 6250.0) {
        commission = 56.0 + trade * 0.0066;
    } else if (trade < 20000.0) {
        commission = 76.0 + trade * 0.0034;
    } else if (trade < 50000.0) {
        commission = 100.0 + trade * 0.0022;
    } else if (trade < 500000.0) {
        commission = 155.0 + trade * 0.0011;
    } else {
        commission = 255.0 + trade * 0.0009;
    }

    if (commission < 39.0) {
        commission = 39.0;
    }

    printf("Trade is $%.2f commision is $%.2f\n", trade, commission);

    return EXIT_SUCCESS;
}

