#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "BoardInterface.h"
using namespace std;
class Board :public BoardInterface
{
private:
	char arr[3][3] = { '1', '2', '3','4','5','6','7','8','9' };
public:
	Board() {
		
	}
    int getRow(int index) {
        return ((index - 1) / 3);
    }

    int getCol(int index) {
        return ((index - 1) % 3);
    }

    bool isEmpty(int index) {
        if (index < 1 || index>9)return false;
        int row = getRow(index);
        int col = getCol(index);
        if (arr[row][col] == 'o' || arr[row][col] == 'O' || arr[row][col] == 'x' || arr[row][col] == 'X')
            return false;
        return true;
    }

    bool replaceChar(int index, Player p) {
        if (isEmpty(index)) {
            int row = getRow(index);
            int col = getCol(index);
            arr[row][col] = p.getOp();
            return true;
        }
        return false;
    }

    void draw() {
        system("cls");
        for (int i = 0; i < 3; i++) {
            cout << "-----------------" << endl;
            for (int j = 0; j < 3; j++) {
                cout << "|  " << arr[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "-----------------"<< endl;
    }

    bool isFull() {
        int count = 0;
        for (int i = 1; i <= 9; i++) {
            if (isEmpty(i))count++;
        }
        if (count == 0)return true;
        return false;
    }

    bool isWin(Player p) {
        if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][1] == arr[0][2])
            return true;
        if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][1] == arr[1][2])
            return true;
        if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][1] == arr[2][2])
            return true;
        if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[1][0] == arr[2][0])
            return true;
        if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[1][1] == arr[2][1])
            return true;
        if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[1][2] == arr[2][2])
            return true;
        if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[1][1] == arr[2][2])
            return true;
        if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[1][1] == arr[2][0])
            return true;
        return false;


    }
};

