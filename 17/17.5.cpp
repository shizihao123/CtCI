#include <iostream>

struct Result {
    int hit;
    int fakehit;
};

Result check(char fact[], char guess[]) {
    Result result = { 0, 0 };
    bool used[4][2] = { false };
    for (int i = 0; i < 4; ++i) {
        if (fact[i] == guess[i]) {
            ++ result.hit;
            used[i][0] = used[i][1] = true;
        }
    }
    for (int i = 0; i < 4; ++i) if (!used[i][0]) {
        for (int j = 0; j < 4; ++j) {
            if (used[i][0] == used[j][1] && fact[i] == guess[j]) {
                ++ result.fakehit;
                used[i][0] = used[j][1] = true;
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    Result result = check("RGBY", "GGRR");
    std::cout << result.hit << " " << result.fakehit << std::endl;
    return 0;
}
