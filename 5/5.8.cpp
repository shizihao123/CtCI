#include <iostream>
#include <cstdio>

using namespace std;

void drawHorizontall(char screen[], int width, int height, int x1, int x2, int y) {
    if (y < 0 || y >= height) return ;
    if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
    if (x2 < 0 || x1 >= width) return ;
    x1 = std::max(0, x1);
    x2 = std::min(width - 1, x2);
    for (int i = x1; i <= x2; ++i) {
        screen[width / 8 * y + i / 8] |= 1<<(7 - i % 8);
    }
}

void ShowScreen(char screen[], int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (screen[i * width / 8 + j / 8] & (1<<(7 - j % 8))) {
                std::cout << "*";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    const int width = 64, height = 30;
    char screen[width / 8 * height] = {0};
    drawHorizontall(screen, width, height, 0, 30, 20);
    ShowScreen(screen, width, height);
    return 0;
}
