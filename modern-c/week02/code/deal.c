/* deal.c - 随机发牌 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

#define SIZE(array) (sizeof(array) / sizeof((array)[0]))

/* t 代表数字 10 */
constexpr char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
/* c: 梅花 d: 方块 h: 红桃 s: 黑桃 */
constexpr char suits[] = {'c', 'd', 'h', 's'};


int main(void) {
    // 设置随机数种子
    srand((unsigned)time(nullptr));
    // 如何保证不重复发牌: 4 * 13 的二维数组 in_hand[i][j] 表示 suits[i]ranks[j] 牌面是否在手上 
    bool in_hand[SIZE(suits)][SIZE(ranks)] = {};

    size_t num_cards = 0; // 手上牌的数量
    printf("Enter number of cards in hand: ");
    scanf("%zu", &num_cards);

    printf("Your hand:");
    while (num_cards) {
        int suit = rand() % SIZE(suits); // 选择花色
        int rank = rand() % SIZE(ranks); // 选择点数
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            --num_cards;
            printf("  %c%c", ranks[rank], suits[suit]);
        }
    }
    puts("");

    return EXIT_SUCCESS;
}
