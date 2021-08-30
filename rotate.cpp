/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先将矩阵转置
        for(int i = 0; i  < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再将其镜像对称
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};