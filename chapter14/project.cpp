/*
the objective is to be able to play the 15 Puzzle
we will need:

- a user interface to be able to take a move
- a game logic
- a board

clearly, we will define the board as a class, storing the
current board state as a 4x4 array and defining all the different
actions on the board (actions that modify or read the board status)

next, the game logic could be coded in a game class. however, is it
really needed? seems like the only member variable to be stored would be
the board object. all the rest would consist on member functions.
we need at least:
- a global play game function that will make use of the rest of the code
- a function to ask for user input and perform the action


all the code, including the board class, will be defined in this single file
*/

#include <iostream>
#include <array>
#include <numeric>
#include <cstdlib>
#include <random>
#include <algorithm>

template <size_t NROWS = 4, size_t NCOLS = 4>
class Board
{
public:
	Board()
	{
		//std::array<int, NROWS*NCOLS> seq{};
		//std::iota(seq.begin(), seq.end(), 0);
		// generate a solved board, then mix it up
		int k = 0;
		for (int i = 0; i < NROWS; i++)
		{
			for (int j = 0; j < NCOLS; j++)
			{
				m_board[i][j] = (k + 1) % (NROWS * NCOLS);
				k++;
			}
		}
		std::mt19937 mt{ std::random_device{}() };
		std::array<char, 4> possibleMoves{ 'w', 'a', 's', 'd' };
		std::array<char, 1000> randomMoves{};
		std::sample(possibleMoves.begin(), possibleMoves.end(), randomMoves.begin(), 1000, mt);
		for (char move : randomMoves)
		{
			m_board.move(move);
		}
		// randomizing the sequence that will be used to fill the array
		//std::shuffle(seq.begin(), seq.end(), mt);
		//for (int i = 0, k = 0; i < NROWS; i++)
		//{
		//	for (int j = 0; j < NCOLS; ++j)
		//	{
		//		m_board[i][j] = seq[k];
		//		++k;
		//		if (m_board[i][j] == 0)
		//		{
		//			m_emptyRow = i;
		//			m_emptyCol = j;
		//		}
		//	}
		//}
	}

	bool slideUp()
	{
		if (m_emptyRow == NROWS - 1) return false;
		std::swap(m_board[m_emptyRow][m_emptyCol], m_board[m_emptyRow + 1][m_emptyCol]);
		++m_emptyRow;
		return true;
	}

	bool slideLeft()
	{
		if (m_emptyCol == NCOLS - 1) return false;
		std::swap(m_board[m_emptyRow][m_emptyCol], m_board[m_emptyRow][m_emptyCol + 1]);
		++m_emptyCol;
		return true;
	}

	bool slideDown()
	{
		if (m_emptyRow == 0) return false;
		std::swap(m_board[m_emptyRow][m_emptyCol], m_board[m_emptyRow - 1][m_emptyCol]);
		--m_emptyRow;
		return true;
	}

	bool slideRight()
	{
		if (m_emptyCol == 0) return false;
		std::swap(m_board[m_emptyRow][m_emptyCol], m_board[m_emptyRow][m_emptyCol - 1]);
		--m_emptyCol;
		return true;
	}

	bool move()
	{
		/*
		asks for user input. Possible input is:
		w - slide tile up
		a - slide tile left
		s - slide tile down
		d - slide tile right
		q - quit game

		when we refer to a move (up, left, down, right), we refer to moving
		the tiles adjacent to the empty tile
		the function returns false only when q is given
		if a move (w/a/s/d) is given, it will first check that the move was
		valid through a flag. If the move was valid, returns true
		*/
		char m;
		bool flag = false;
		while (true)
		{
			std::cout << "Enter move (w/a/s/d) or quit (q):\n";
			std::cin >> m;
			switch (m)
			{
			case 'w':
				flag = slideUp();
				break;
			case 'a':
				flag = slideLeft();
				break;
			case 's':
				flag = slideDown();
				break;
			case 'd':
				flag = slideRight();
				break;
			case 'q':
				return false;
			default:
				std::cout << "Wrong input, please retry\n";
			}
			if (flag) return true;
			else std::cout << "Invalid move\n";
		}
	}

	bool win()
	{
		// checks if the board is in completed position
		int k = 0;
		for (int i = 0; i < NROWS; ++i)
		{
			for (int j = 0; j < NCOLS; ++j)
			{
				if (m_board[i][j] != (k + 1) % (NROWS * NCOLS)) return false;
				++k;
			}
		}
		return true;
	}

	friend std::ostream& operator<<(std::ostream& out, const Board& board)
	{
		// plots the current board
		for (int i = 0; i < NROWS; ++i)
		{
			for (int j = 0; j < NCOLS; ++j)
			{
				if (board.m_board[i][j] != 0)
					out << board.m_board[i][j];
				out << '\t';
			}
			out << '\n';
		}
		return out;
	}

private:
	std::array<std::array<int, NCOLS>, NROWS> m_board{};
	// these hold the current position of the empty tile
	int m_emptyRow;
	int m_emptyCol;
};


void play15Puzzle()
{
	bool win{ false };
	Board board;
	std::cout << board << std::endl;
	while (true)
	{
		if (!board.move()) break;
		std::cout << board << std::endl;
		if (board.win())
		{
			std::cout << "Congrats! You did it!\n";
			return;
		}
	}
}