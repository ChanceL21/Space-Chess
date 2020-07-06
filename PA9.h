#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

// main class that all specific pieces will inherit from
class Piece
{
protected:
	int player; // 1 for humans, -1 for aliens
	sf::ConvexShape outer_flame; // flame to be displayed whenever a piece is being dragged, or "blasting off"
	sf::ConvexShape inner_flame;
public:
	Piece(int y, int x, int p);
	void update_flame_position(int y, int x); // same for all pieces
	void virtual update_ship_position(int y, int x) = 0; // different for all pieces and needs to be virtual
	void display_flames(sf::RenderWindow& window); // set flames position and draw them
	void virtual display_ship(sf::RenderWindow& window) = 0;
	virtual ~Piece(); // deallocate flame shapes. derived destructors will deallocate rest of ship
};

class Pawn : public Piece
{
private:
	sf::CircleShape pawn_head; // shapes to draw pawn
	sf::ConvexShape pawn_body;
	sf::CircleShape pawn_disc;
public:
	Pawn(int y, int x, int p) : Piece(y, x, p)
	{
		// set shape attributes
		pawn_disc.setRadius(2);
		pawn_disc.setScale(3, 1);
		pawn_disc.setOutlineThickness(2);
		pawn_head.setRadius(10);
		pawn_body.setPointCount(3);
		pawn_head.setOutlineThickness(-4);
		pawn_body.setOutlineThickness(-4);
		// make pawn green if human and red if alien. All other pieces act similarly
		if (p == 1)
		{
			pawn_head.setFillColor(sf::Color::Green);
			pawn_body.setFillColor(sf::Color::Green);
			pawn_head.setOutlineColor(sf::Color(0, 100, 0));
			pawn_body.setOutlineColor(sf::Color(0, 100, 0));
			pawn_disc.setFillColor(sf::Color::Green);
			pawn_disc.setOutlineColor(sf::Color(0, 100, 0));
		}
		else
		{
			pawn_head.setFillColor(sf::Color(255, 0, 0));
			pawn_body.setFillColor(sf::Color(255, 0, 0));
			pawn_head.setOutlineColor(sf::Color(100, 0, 0));
			pawn_body.setOutlineColor(sf::Color(100, 0, 0));
			pawn_disc.setFillColor(sf::Color(255, 0, 0));
			pawn_disc.setOutlineColor(sf::Color(100, 0, 0));
		}
		// set ship position once constructed
		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};

class Rook : public Piece // same as pawn but for rook
{
private:
	sf::ConvexShape rook_head; // rook shapes
	sf::ConvexShape rook_body;
	sf::ConvexShape rook_base;
public:
	Rook(int y, int x, int p) : Piece(y, x, p)
	{
		rook_head.setPointCount(12); // attributes
		rook_body.setPointCount(4);
		rook_base.setPointCount(4);
		rook_head.setOutlineThickness(4);
		rook_body.setOutlineThickness(4);
		rook_base.setOutlineThickness(4);
		if (p == 1) // color
		{
			rook_head.setFillColor(sf::Color::Green);
			rook_body.setFillColor(sf::Color::Green);
			rook_base.setFillColor(sf::Color::Green);
			rook_head.setOutlineColor(sf::Color(0, 100, 0));
			rook_body.setOutlineColor(sf::Color(0, 100, 0));
			rook_base.setOutlineColor(sf::Color(0, 100, 0));
		}
		else
		{
			rook_head.setFillColor(sf::Color(255, 0, 0));
			rook_body.setFillColor(sf::Color(255, 0, 0));
			rook_base.setFillColor(sf::Color(255, 0, 0));
			rook_head.setOutlineColor(sf::Color(100, 0, 0));
			rook_body.setOutlineColor(sf::Color(100, 0, 0));
			rook_base.setOutlineColor(sf::Color(100, 0, 0));
		}
		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};

class Knight : public Piece
{
private:
	sf::ConvexShape knight_body; // shapes
	sf::CircleShape knight_nose;
	sf::CircleShape knight_eye;
	sf::ConvexShape knight_border;
	sf::ConvexShape knight_side;

public:
	Knight(int y, int x, int p) : Piece(y, x, p)
	{
		knight_body.setPointCount(14);// attributes like thickness and number of points to draw shape
		knight_body.setOutlineThickness(3);
		knight_nose.setRadius(1);
		knight_eye.setRadius(1);
		knight_eye.setRotation(150);
		knight_eye.setScale(3, 1);
		knight_border.setPointCount(4);
		knight_side.setPointCount(4);
		if (p == 1) // color
		{
			knight_body.setFillColor(sf::Color::Green);
			knight_body.setOutlineColor(sf::Color(0, 100, 0));
			knight_nose.setFillColor(sf::Color(0, 100, 0));
			knight_eye.setFillColor(sf::Color(0, 100, 0));
			knight_border.setFillColor(sf::Color(0, 100, 0));
			knight_side.setFillColor(sf::Color(0, 100, 0));
		}
		else
		{
			knight_body.setFillColor(sf::Color(255, 0, 0));
			knight_body.setOutlineColor(sf::Color(100, 0, 0));
			knight_nose.setFillColor(sf::Color(100, 0, 0));
			knight_eye.setFillColor(sf::Color(100, 0, 0));
			knight_border.setFillColor(sf::Color(100, 0, 0));
			knight_side.setFillColor(sf::Color(100, 0, 0));
		}
		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};

class Bishop : public Piece
{
private:
	sf::CircleShape bishop_tip; // shapes
	sf::CircleShape bishop_head;
	sf::CircleShape bishop_disc;
	sf::ConvexShape bishop_body;
	sf::ConvexShape bishop_base;
	sf::CircleShape bishop_slash;
public:
	Bishop(int y, int x, int p) : Piece(y, x, p)
	{
		bishop_tip.setRadius(2); // shape parameters
		bishop_head.setRadius(5);
		bishop_disc.setRadius(2);
		bishop_disc.setScale(3, 1);
		bishop_body.setPointCount(3);
		bishop_base.setPointCount(4);
		bishop_tip.setOutlineThickness(2);
		bishop_head.setOutlineThickness(4);
		bishop_disc.setOutlineThickness(2);
		bishop_body.setOutlineThickness(4);
		bishop_base.setOutlineThickness(4);
		bishop_slash.setRadius(1);
		bishop_slash.setRotation(130);
		bishop_slash.setScale(3, 1);

		if (p == 1) // shape color
		{
			bishop_tip.setFillColor(sf::Color::Green);
			bishop_tip.setOutlineColor(sf::Color(0, 100, 0));
			bishop_head.setFillColor(sf::Color::Green);
			bishop_head.setOutlineColor(sf::Color(0, 100, 0));
			bishop_disc.setFillColor(sf::Color::Green);
			bishop_disc.setOutlineColor(sf::Color(0, 100, 0));
			bishop_body.setFillColor(sf::Color::Green);
			bishop_body.setOutlineColor(sf::Color(0, 100, 0));
			bishop_base.setFillColor(sf::Color::Green);
			bishop_base.setOutlineColor(sf::Color(0, 100, 0));
			bishop_slash.setFillColor(sf::Color(0, 100, 0));
		}
		else
		{
			bishop_tip.setFillColor(sf::Color(255, 0, 0));
			bishop_tip.setOutlineColor(sf::Color(100, 0, 0));
			bishop_head.setFillColor(sf::Color(255, 0, 0));
			bishop_head.setOutlineColor(sf::Color(100, 0, 0));
			bishop_disc.setFillColor(sf::Color(255, 0, 0));
			bishop_disc.setOutlineColor(sf::Color(100, 0, 0));
			bishop_body.setFillColor(sf::Color(255, 0, 0));
			bishop_body.setOutlineColor(sf::Color(100, 0, 0));
			bishop_base.setFillColor(sf::Color(255, 0, 0));
			bishop_base.setOutlineColor(sf::Color(100, 0, 0));
			bishop_slash.setFillColor(sf::Color(100, 0, 0));
		}

		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};

class Queen : public Piece
{
private:
	sf::CircleShape queen_tip; // shapes
	sf::CircleShape queen_cover;
	sf::ConvexShape queen_head;
	sf::CircleShape queen_disc;
	sf::ConvexShape queen_body;
	sf::ConvexShape queen_base;
public:
	Queen(int y, int x, int p) : Piece(y, x, p)
	{
		queen_tip.setRadius(2); // shape attributes
		queen_disc.setRadius(2);
		queen_disc.setScale(3, 1);
		queen_cover.setRadius(2);
		queen_cover.setScale(3, 1);
		queen_head.setPointCount(4);
		queen_body.setPointCount(3);
		queen_base.setPointCount(4);
		queen_tip.setOutlineThickness(2);
		queen_head.setOutlineThickness(2);
		queen_disc.setOutlineThickness(2);
		queen_body.setOutlineThickness(4);
		queen_base.setOutlineThickness(4);
		queen_cover.setOutlineThickness(2);

		if (p == 1) // color
		{
			queen_tip.setFillColor(sf::Color::Green);
			queen_tip.setOutlineColor(sf::Color(0, 100, 0));
			queen_head.setFillColor(sf::Color::Green);
			queen_head.setOutlineColor(sf::Color(0, 100, 0));
			queen_disc.setFillColor(sf::Color::Green);
			queen_disc.setOutlineColor(sf::Color(0, 100, 0));
			queen_body.setFillColor(sf::Color::Green);
			queen_body.setOutlineColor(sf::Color(0, 100, 0));
			queen_base.setFillColor(sf::Color::Green);
			queen_base.setOutlineColor(sf::Color(0, 100, 0));
			queen_cover.setFillColor(sf::Color::Green);
			queen_cover.setOutlineColor(sf::Color(0, 100, 0));
		}
		else
		{
			queen_tip.setFillColor(sf::Color(255, 0, 0));
			queen_tip.setOutlineColor(sf::Color(100, 0, 0));
			queen_head.setFillColor(sf::Color(255, 0, 0));
			queen_head.setOutlineColor(sf::Color(100, 0, 0));
			queen_disc.setFillColor(sf::Color(255, 0, 0));
			queen_disc.setOutlineColor(sf::Color(100, 0, 0));
			queen_body.setFillColor(sf::Color(255, 0, 0));
			queen_body.setOutlineColor(sf::Color(100, 0, 0));
			queen_base.setFillColor(sf::Color(255, 0, 0));
			queen_base.setOutlineColor(sf::Color(100, 0, 0));
			queen_cover.setFillColor(sf::Color(255, 0, 0));
			queen_cover.setOutlineColor(sf::Color(100, 0, 0));
		}
		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};

class King : public Piece 
{
private:
	sf::ConvexShape king_cross; // shapes to draw king
	sf::CircleShape king_cover;
	sf::ConvexShape king_head;
	sf::CircleShape king_disc;
	sf::ConvexShape king_body;
	sf::ConvexShape king_base;
public:
	King(int y, int x, int p) : Piece(y, x, p)
	{
		king_disc.setRadius(2); // shape attributes
		king_disc.setScale(3, 1);
		king_cover.setRadius(2);
		king_cover.setScale(3, 1);
		king_cross.setPointCount(12);
		king_head.setPointCount(5);
		king_body.setPointCount(3);
		king_base.setPointCount(4);
		king_head.setOutlineThickness(2);
		king_disc.setOutlineThickness(2);
		king_body.setOutlineThickness(4);
		king_base.setOutlineThickness(4);
		king_cover.setOutlineThickness(2);
		king_cross.setOutlineThickness(2);

		if (p == 1) // color
		{
			king_head.setFillColor(sf::Color::Green);
			king_head.setOutlineColor(sf::Color(0, 100, 0));
			king_disc.setFillColor(sf::Color::Green);
			king_disc.setOutlineColor(sf::Color(0, 100, 0));
			king_body.setFillColor(sf::Color::Green);
			king_body.setOutlineColor(sf::Color(0, 100, 0));
			king_base.setFillColor(sf::Color::Green);
			king_base.setOutlineColor(sf::Color(0, 100, 0));
			king_cover.setFillColor(sf::Color::Green);
			king_cover.setOutlineColor(sf::Color(0, 100, 0));
			king_cross.setFillColor(sf::Color::Green);
			king_cross.setOutlineColor(sf::Color(0, 100, 0));
		}
		else
		{
			king_head.setFillColor(sf::Color(255, 0, 0));
			king_head.setOutlineColor(sf::Color(100, 0, 0));
			king_disc.setFillColor(sf::Color(255, 0, 0));
			king_disc.setOutlineColor(sf::Color(100, 0, 0));
			king_body.setFillColor(sf::Color(255, 0, 0));
			king_body.setOutlineColor(sf::Color(100, 0, 0));
			king_base.setFillColor(sf::Color(255, 0, 0));
			king_base.setOutlineColor(sf::Color(100, 0, 0));
			king_cover.setFillColor(sf::Color(255, 0, 0));
			king_cover.setOutlineColor(sf::Color(100, 0, 0));
			king_cross.setFillColor(sf::Color(255, 0, 0));
			king_cross.setOutlineColor(sf::Color(100, 0, 0));
		}
		update_ship_position(y, x);
	}
	void update_ship_position(int y, int x);
	void display_ship(sf::RenderWindow& window);
};


struct Stats // special struct that holds the private variables of player. Sometimes these need to be copied and reset so a struct class is useful
{
	int player;
	bool king_moved;
	bool kingside_rook_moved;
	bool queenside_rook_moved;
	int king_row;
	int king_col;
	bool promotion;
};

class Player // main player class that the humans and aliens are instantiated as
{
private:
	int player = 0; // 1 for humans -1 for aliens

	// position of player's king
	int king_row;
	int king_col;

	// boolean values for castling. A player can only castle if their king and the rook they are castling with has not moved
	bool king_moved = false;
	bool kingside_rook_moved = false;
	bool queenside_rook_moved = false;

	// becomes true when player's pawn is in the enemy's back rank and is ready for promotion
	bool promotion = false;
public:
	Player(int p, int kr, int kc);
	int confirm_start(int board[8][8], int row1, int col1); // only lets a player drag a piece if it is their own
	int make_move(int board[8][8], Piece* display_board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2); // main movement and validation function
	void copy_stats(Stats& temp_stats); // copy stats from player private variables to stats struct
	void get_stats(Stats& temp_stats); // copy stats from stats struct back to player private variables
	void revoke_en_passant(int board[8][8]); // sets all 11/-11 in board to 0. These represent en passant squares that need to be removed after 1 turn
	int evaluate_board(int board[8][8], string& terminal1, string& terminal2); // returns 0 if game continues, 1 if player is checkmated, and 2 if it is a draw
	int lack_of_material(int board[8][8]); // if only kings remain
	void compare_boards(int board[8][8], int board_copy[8][8], Piece* display_board[8][8]); // checks what changes were made in 2D int array and affects display board
	bool get_promotion(); // returns bool stored in promotion private variable
	void finish_promotion(int board[8][8], Piece* display_board[8][8], int piece_promoted); // finalizes piece chosen when a player promotes a pawn and sets promotion back to false

	// makes sure player made a valid move. return 1 if move valid, 0 if invalid. returns 2 if trying to castle through a check
	int valid_move(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2);
	// returns 1 if user move is valid single jump or double jump, else 0
	int valid_move_pawn(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2);
	// returns 1 if valid diagonal attack, else 0
	int valid_move_pawn_attack(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2);

	// all "possible_moves" functions take in parameter "side". 1 means possible moves of allies (for that piece), -1 means possible moves of enemies (for that piece)

	// used only for hypothetical board building to see if a king is in check from a enemy pawn attack (pass in -1 for side). 
	// also used to see if an ally pawn attack can help a king escape check (pass in 1 for side)
	void pawn_possible_attacks(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// used for seeing if a pawn move or attack blocks a check
	void pawn_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// used in hypothetical board building but also in actual rook move. pass in 1 for side if rook is ally to current player, -1 if enemy
	void rook_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// for hypothetical moves and actual moves. changes possible_moves array to show 1 where possible move is.
	void knight_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// sets possible moves for bishop for both hypothetical boards and actual bishop movements
	void bishop_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// checks for queen possible moves. queen is combination of rook and bishop, so this function just calls their functions
	void queen_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);
	// looks for possible king moves and fills 1 in possible_moves array if the space is a possible move
	void king_possible_attacks(int board[8][8], int row1, int col1, int possible_moves[8][8], int side);

	// checks if player tried to castle. if good castle, changes board and returns 1. if almost good castle, but the enemy had a castle square in check, then returns 2. if completely invalid, returns 0.
	int castle(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2);

	// cycles through all of player's pieces until a move is possible that results in their own king not being in check.
	// if a move is found, returns 1 immediately. If no move is found, returns 0

	// checks if the piece at row, col is guarded by any piece of the opponent. Often the king's position will be passed as the row and col, but not always.
	// returns 1 if the space is guarded, 0 if not.
	int guarded(int board[8][8], int row, int col);
	// used to determine if there is a checkmate, stalemate, or neither. returns 1 if its neither, returns 0 if its a checkmate or stalemate
	int has_move_that_removes_check(int board[8][8]);
	// given a piece type, coordinates of the piece, and an array with the possible moves of the piece, determines if it has a move that results in no check
	int hyopthetical_board(int piece, int piece_row, int piece_col, int board[8][8], int possible_moves[8][8]);
};

// class for test functions. each method is one of 5 test functions
class Test
{
private:
	Player humans = { 1, 7, 4 };
	Player aliens = { -1, 0, 4 };
	string terminal1; // set dummy terminals
	string terminal2;
public:
	Test();
	int test_board_evaluation_checkmate(); // tests checkmate prints out test 1 passed or failed
	int test_board_evaluation_stalemate(); // tests stalemate prints out test 2 passed or failed
	int test_board_evaluation_continue(); // tests that the game continues
	int test_conversions(); // tests conversions between col and x, row and y. row/col refer to index in arrays, x/y to pixels in displayed graphics
	int test_confirm_start(); // tests piece select function
};


// sets up integer array and piece display array with pawns, rooks, knights, biships, queens, and kings in their starting positions
void set_up_board(int board[8][8], Piece* display_board[8][8]);

// deep copies source into destination
void copy_board(int source[8][8], int destination[8][8]);

// index -> pixel  and  pixel -> index conversion functions. Just formulas
int y_to_row(int y);
int x_to_col(int x);
int row_to_y(int row);
int col_to_x(int col);

// prints board. for debugging
void print_board(int board[8][8]);

// converts a piece's position (row 7-0, col 0-7) to letter and number (row 1-8, col A-H). for printing out where a piece moves to
string convert_to_letter_number(int row2, int col2);

// for printing out the piece that moved and piece that was destroyed, if there is one
string convert_to_piece_name(int board[8][8], int row, int col);

// fill board with zeroes (usually for resetting possible_moves array)
void initialize_board(int board[8][8]);