// learn from milo yip:https://github.com/miloyip/misc/blob/master/tictactoe/tictactoe3.c
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Tictactoe 
{
public:
    Tictactoe(int turn = 0) 
        : turn_{turn}
        {}

    void run()  
    {
        display();
        while (turn_ < 9) {
            human();
            display();
            switch (evaluate()) {
                case  1: printf("O win\n"); return;
                case -1: printf("X win\n"); return;
            }
        } 
        printf("Draw\n");
    }

private:
    void display() const 
    {
        for (auto it = board_.cbegin(); it != board_.cend(); printf(++it != board_.cend() ? "---+---+---\n" : "\n"))
        {
            for (auto it_inner = it->cbegin(); it_inner != it->cend(); ++it_inner)
            {
                printf(" %c ", *it_inner == -1 ? 
                    '1' + static_cast<int>(it - board_.cbegin()) * 3 + static_cast<int>(it_inner - it->cbegin()) : 
                    "OX"[*it_inner]
                    );
                putchar("||\n"[it_inner - it->cbegin()]);
            }
        }
    }

    // col also means x, row y.
    bool move(int col, int row)
    {
        if (board_[row][col] != -1)
        {
            return false;
        }
        board_[row][col] = turn_++ % 2;
        return true;
    }

    void human()
    {
        char c;
        do 
        {
            printf("%c ", "OX"[turn_ % 2]);
            c = getchar();
            while(getchar() != '\n');
            printf("\n");
        } while(c < '1' || c > '9' || !move((c - '1') % 3, (c - '1') / 3));
    }

#define CHECK(j1, i1, j2, i2, j3, i3) \
    if (board_[j1][i1] != -1 && board_[j1][i1] == board_[j2][i2] && board_[j1][i1] == board_[j3][i3]) \
        return board_[j1][i1] == 0 ? 1 : -1;

int evaluate() {
    int i;
    for (i = 0; i < 3; i++) {
        CHECK(i, 0, i, 1, i, 2);    // horizontal
        CHECK(0, i, 1, i, 2, i);    // vertical
    }
    CHECK(0, 0, 1, 1, 2, 2);        // diagonal
    CHECK(0, 2, 1, 1, 2, 0);        // diagonal
    return 0;
}

private:
    vector<vector<int>> board_ = {
        {-1, -1, -1},
        {-1, -1, -1}, 
        {-1, -1, -1}
        };
    int turn_;
};

int main()
{
    Tictactoe t;
    t.run();

    return 0;
}