#include <iostream>

const int chessboard_x = 8;
const int chessboard_y = 8;

struct Piece{
	enum ID{
		none,
		king,
		queen,
		bishop,
		knight
	};
	ID m_id;
	bool is_white;
	void move(){

	}
	Piece(): m_id(Piece::ID::none), is_white(true){

	}
	Piece(ID id ,bool color): m_id(id), is_white(color){

	}
};

class Chessboard{
	public:
		Piece*** m_ptr = nullptr;
	public:
		Chessboard(){
			m_ptr = new Piece**[chessboard_x];
			for (int i = 0; i < chessboard_x; i++){
				m_ptr[i] = new Piece*[chessboard_y];
			}
		}
		void init(Piece* piece, int x, int y){	
			if (x < 0 || x > 7 || y < 0 || y > 7){
				throw "Invalid coordinates!!!";
			}
			m_ptr[x][y] = piece;
			std::cout << "Piece initialized succesfully" << std::endl;
		}
};

int main()
{
	Piece* W_King = new Piece(Piece::ID::king, true);
	Piece* B_King = new Piece(Piece::ID::king, false);
	Piece* W_Queen = new Piece(Piece::ID::queen, true);

	Chessboard board;

	try
	{
		std::cout << std::endl;

		board.init(W_King,5,5);
		board.init(B_King,6,2);
		board.init(W_Queen,10,9);

		std::cout << std::endl;
		std::cout << "Success!!!" << std::endl;
		std::cout << std::endl;
	}
	catch(const char* c)
	{
		std::cerr << "Error: " << c << std::endl;
	}
	return 0;
}
