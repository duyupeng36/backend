#!/bin/bash
# 测试用例：sign_count.c
# 统计数组中的正数、负数、零的个数

# 编译
gcc -std=c23 -Wall -Werror -o sign_count sign_count.c || exit 1

echo "=== 测试 1：混合数据 ==="
# 预期: 正数=3, 负数=3, 零=1
echo "7 -3 0 42 -8 15 -1" | ./sign_count
echo "预期: pos=3, neg=3, zero=1"

echo ""
echo "=== 测试 2：全正数 ==="
echo "1 2 3 4 5" | ./sign_count
echo "预期: pos=5, neg=0, zero=0"

echo ""
echo "=== 测试 3：全零 ==="
echo "0 0 0" | ./sign_count
echo "预期: pos=0, neg=0, zero=3"
