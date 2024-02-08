#pragma once
#include <string>
#include "Board.h"
#include "Player.h"
class Game
{
private:
	Player p1;
	Player p2;
	Board myBoard;
	int count = 0;
public:

	void readplayer() {
		cout << "Enter Player 1 Name : " << endl;
	    string p1name;
		cin >> p1name;
		p1.setname(p1name);
		cout << "Enter Player 2 Name : " << endl;
		string p2name;
		cin >> p2name;
		p2.setname(p2name);
		cout << "Select Player 1 Operator 'x' or 'o' : " << endl;
		char x;
		cin >> x;
		p1.setop(x);
		if (p1.getOp() == 'x' || p1.getOp() == 'X') {
			p2.setop('o');
		}
		else
			p2.setop('X');
	}


	void Play() {
		readplayer();
		myBoard.draw();

		while (!myBoard.isFull()) {
			Player currentplayer = p1;
			if (count % 2 == 1) {
				currentplayer = p2;
			}
			while (true)
			{
				int pos;
				cout << "Select Empty Posittion from 1 to 9 : ";
				cin >> pos;
				if (myBoard.replaceChar(pos, currentplayer)) {
					break;
				}
			}

			myBoard.draw();
			if (myBoard.isWin(currentplayer)) {
				cout << "The winner is : " << currentplayer.getname() << endl;
				break;
			}
			count++;
		}

		if(myBoard.isFull()){
			cout << "Game is Draw .." << endl;
		}


	}
};

