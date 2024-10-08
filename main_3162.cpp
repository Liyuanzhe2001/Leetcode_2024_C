#include "bits/stdc++.h"

using namespace std;

int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    int res = 0;
    for (const auto &n1: nums1) {
        for (const auto &n2: nums2) {
            if (n1 % (n2 * k) == 0) {
                res++;
            }
        }
    }
    return res;
}