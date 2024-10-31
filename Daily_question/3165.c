//
//  3165.c
//  C_code_alo
//
//  Created by deathot on 10/31/24.
//

#define MAX(a, b) ((b) > (a) ? (b) : (a))

// 根据本题的数据范围，unsigned int 足矣，无需 long long
typedef struct {
    unsigned int f00; // 第一个数一定不选，最后一个数一定不选
    unsigned int f01; // 第一个数一定不选，最后一个数可选可不选
    unsigned int f10; // 第一个数可选可不选，最后一个数一定不选
    unsigned int f11; // 第一个数可选可不选，最后一个数可选可不选，也就是没有任何限制
} Data;

typedef Data* SegmentTree;

// 合并左右儿子
void maintain(SegmentTree t, int o) {
    Data a = t[o * 2], b = t[o * 2 + 1];
    t[o].f00 = MAX(a.f00 + b.f10, a.f01 + b.f00);
    t[o].f01 = MAX(a.f00 + b.f11, a.f01 + b.f01);
    t[o].f10 = MAX(a.f10 + b.f10, a.f11 + b.f00);
    t[o].f11 = MAX(a.f10 + b.f11, a.f11 + b.f01);
}

// 用 nums 初始化线段树
void build(SegmentTree t, int* nums, int o, int l, int r) {
    if (l == r) {
        t[o].f11 = MAX(nums[l], 0);
        return;
    }
    int m = (l + r) / 2;
    build(t, nums, o * 2, l, m);
    build(t, nums, o * 2 + 1, m + 1, r);
    maintain(t, o);
}

// 把 nums[i] 改成 val
void update(SegmentTree t, int o, int l, int r, int i, int val) {
    if (l == r) {
        t[o].f11 = MAX(val, 0);
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        update(t, o * 2, l, m, i, val);
    } else {
        update(t, o * 2 + 1, m + 1, r, i, val);
    }
    maintain(t, o);
}

int maximumSumSubsequence(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    SegmentTree t = calloc(2 << (32 - __builtin_clz(numsSize)), sizeof(Data));
    build(t, nums, 1, 0, numsSize - 1);

    long long ans = 0;
    for (int i = 0; i < queriesSize; i++) {
        update(t, 1, 0, numsSize - 1, queries[i][0], queries[i][1]);
        ans += t[1].f11; // 注意 f11 没有任何限制，也就是整个数组的打家劫舍
    }

    free(t);
    return ans % 1000000007;
}
