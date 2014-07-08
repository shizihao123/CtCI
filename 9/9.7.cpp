#include <iostream>
#include <vector>

using namespace std;

typedef int Color;

void DFS(std::vector<std::vector<Color> > &screen, int x, int y, Color color, Color newcolor) {
    if (0 <= x && x < screen[0].size() && 0 <= y && y < screen.size()) {
        if (screen[y][x] == color) {
            screen[y][x] = newcolor;
            DFS(screen, x - 1, y, color, newcolor);
            DFS(screen, x + 1, y, color, newcolor);
            DFS(screen, x, y - 1, color, newcolor);
            DFS(screen, x, y + 1, color, newcolor);
        }
    }
}

void fill(std::vector<std::vector<Color> > &screen, int x, int y, Color newcolor) {
    int height = screen.size();
    if (height == 0) throw std::string("screen empty");
    int width = screen[0].size();
    if (width == 0) throw std::string("screen empty");
    if (x < 0 || y < 0 || x >= width || y >= height) {
        throw std::string("screen out of range");
    }
    DFS(screen, x, y, screen[y][x], newcolor);
}

int main() {
    std::vector<std::vector<Color> > screen = {{1, 1, 1,}, {0, 1, 0}, {1, 0, 1}};
    fill(screen, 0, 0, 0);
    for (int i = 0; i < screen.size(); ++i) {
        for (int j = 0; j < screen[0].size(); ++j) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

