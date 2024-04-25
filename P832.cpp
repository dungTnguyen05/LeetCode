/*
832. Flipping an Image
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.
For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
For example, inverting [0,1,1] results in [1,0,0].

Constraints:
n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res(image.size());

        for (int i = 0; i < image.size(); i++) {
            for (int j = image[i].size() - 1; j >= 0; j--) {
                res[i].push_back(1 - image[i][j]);
            }
        }

        return res;
    }
};