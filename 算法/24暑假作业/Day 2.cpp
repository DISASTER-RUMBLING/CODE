#define _CRT_SECURE_NO_WARNINGS

// 1.D
// 2.D
// 3.B
// 4.B
// 5.D

//------------------------------------------------------------------------------

//6.
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param str string字符串
//     * @return int整型
//     */
//    int FirstNotRepeatingChar(string str) {
//        map<char, int> mmp;
//        for (int i = 0; i < str.size(); i++) {
//            mmp[str[i]] += 1;
//        }
//        for (int i = 0; i < str.size(); i++) {
//            if (mmp[str[i]] == 1) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

//7.
//class Solution {
//public:
//    bool isUnique(string astr) {
//        map<char, bool> mmp;
//        for (int i = 0; i < astr.size(); i++) {
//            if (!mmp[astr[i]]) {
//                mmp[astr[i]] += 1;
//            }
//            else {
//                return false;
//            }
//        }
//        return true;
//    }
//};