/*
 
 An image is represented by a 2-D array of integers, each integer representing the pixe
 value of the image (from 0 to 65535).
 
 Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood
 fill, and a pixel value newColor, "flood fill" the image.
 
 To perform a "flood fill", consider the starting pixel, plus any pixels connected
 4-directionally to the starting pixel of the same color as the starting pixel, plus any
 pixels connected 4-directionally to those pixels (also with the same color as the starting
 pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
 
 
 At the end, return the modified image.
 
 ////////////Example 1 ///////////
 Input:
 image = [[1,1,1],[1,1,0],[1,0,1]] sr = 1, sc = 1, newColor = 2
 
 Output: [[2,2,2],[2,2,0],[2,0,1]]
 
 Explanation:
 From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 by a path of the same color as the starting pixel are colored with the new color.
 Note the bottom corner is not colored 2, because it is not 4-directionally connected
 to the starting pixel.

 
 */

#include <iostream>
#include <vector>
using namespace std;

void fillIt(vector<vector<int>>& image, int nSr, int nScm, int newColor, int val){
    if(nSr < 0 ||nSr >= image.size()) return;
    else if(nScm < 0 ||nScm >= image[nSr].size()) return;
    
    if(image[nSr][nScm] != newColor && image[nSr][nScm] == val) image[nSr][nScm] = newColor;
    else return;
    
    fillIt(image, nSr+1, nScm, newColor, val);
    fillIt(image, nSr-1, nScm, newColor, val);
    fillIt(image, nSr, nScm+1, newColor, val);
    fillIt(image, nSr, nScm-1, newColor, val);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int val = image[sr][sc];
    fillIt(image, sr, sc, newColor,val);
    return image;
}

int main() {
    vector<vector<int>> image {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    
    floodFill(image, sr, sc, newColor);
    
    return 0;
}
