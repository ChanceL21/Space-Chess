#include "PA9.h"


// Piece (and derived classes) methods


Piece::Piece(int y, int x, int p) // y and x are the graphical center in pixels of the piece.
{
	player = p; // 1 for humans, -1 for aliens
	outer_flame.setPointCount(7); // for flame shapes
	inner_flame.setPointCount(3);

	if (p == 1) // flames appear orange/yellow for humans
	{
		outer_flame.setFillColor(sf::Color(255, 165, 0));
		inner_flame.setFillColor(sf::Color::Yellow);
	}
	else // flames appear purple/lavender for aliens
	{
		outer_flame.setFillColor(sf::Color(255, 0, 255));
		inner_flame.setFillColor(sf::Color(230, 230, 250));
	}

	// set the flame position
	update_flame_position(y, x);
}

void Piece::update_flame_position(int y, int x)
{
	// setting the flame position
	outer_flame.setPoint(0, sf::Vector2f(x - 6, y + 24));
	outer_flame.setPoint(1, sf::Vector2f(x - 4, y + 34));
	outer_flame.setPoint(2, sf::Vector2f(x - 2, y + 32));
	outer_flame.setPoint(3, sf::Vector2f(x, y + 38));
	outer_flame.setPoint(4, sf::Vector2f(x + 2, y + 32));
	outer_flame.setPoint(5, sf::Vector2f(x + 4, y + 34));
	outer_flame.setPoint(6, sf::Vector2f(x + 6, y + 24));

	inner_flame.setPoint(0, sf::Vector2f(x - 2, y + 24));
	inner_flame.setPoint(1, sf::Vector2f(x, y + 32));
	inner_flame.setPoint(2, sf::Vector2f(x + 2, y + 24));
}

void Piece::display_flames(sf::RenderWindow& window)
{
	// drawing flames to window passed (always main window)
	window.draw(outer_flame);
	window.draw(inner_flame);
}

Piece::~Piece()
{
	// virtual destructor so derived pieces properly deallocate
}

void Pawn::update_ship_position(int y, int x) // virtual function since every "ship" (piece) is different. 
{// setting positions of shapes. The positions are set in constructor but also when a piece is dragged around the screen
	pawn_head.setPosition(sf::Vector2f(x - 10, y - 12));

	pawn_body.setPoint(0, sf::Vector2f(x, y - 12));
	pawn_body.setPoint(1, sf::Vector2f(x + 12, y + 24));
	pawn_body.setPoint(2, sf::Vector2f(x - 12, y + 24));

	pawn_disc.setPosition(sf::Vector2f(x - 6, y + 5));
}
void Pawn::display_ship(sf::RenderWindow& window)
{// drawing shapes to window
	window.draw(pawn_body);
	window.draw(pawn_disc);
	window.draw(pawn_head);
}

void Rook::update_ship_position(int y, int x)
{
	// setting rook shape positions
	rook_head.setPoint(0, sf::Vector2f(x - 10, y - 8));
	rook_head.setPoint(1, sf::Vector2f(x + 10, y - 8));
	rook_head.setPoint(2, sf::Vector2f(x + 10, y - 12));
	rook_head.setPoint(3, sf::Vector2f(x + 6, y - 12));
	rook_head.setPoint(4, sf::Vector2f(x + 6, y - 10)); 
	rook_head.setPoint(5, sf::Vector2f(x + 2, y - 10));
	rook_head.setPoint(6, sf::Vector2f(x + 2, y - 12));
	rook_head.setPoint(7, sf::Vector2f(x - 2, y - 12));
	rook_head.setPoint(8, sf::Vector2f(x - 2, y - 10));
	rook_head.setPoint(9, sf::Vector2f(x - 6, y - 10));
	rook_head.setPoint(10, sf::Vector2f(x - 6, y - 12));
	rook_head.setPoint(11, sf::Vector2f(x - 10, y - 12));

	rook_body.setPoint(0, sf::Vector2f(x - 7, y + 20));
	rook_body.setPoint(1, sf::Vector2f(x + 7, y + 20));
	rook_body.setPoint(2, sf::Vector2f(x + 7, y - 8));
	rook_body.setPoint(3, sf::Vector2f(x - 7, y - 8));

	rook_base.setPoint(0, sf::Vector2f(x - 9, y + 20));
	rook_base.setPoint(1, sf::Vector2f(x + 9, y + 20));
	rook_base.setPoint(2, sf::Vector2f(x + 7, y + 16));
	rook_base.setPoint(3, sf::Vector2f(x - 7, y + 16));
}
void Rook::display_ship(sf::RenderWindow& window)
{ // drawing shapes to window
	window.draw(rook_body);
	window.draw(rook_head);
	window.draw(rook_base);
}

void Knight::update_ship_position(int y, int x)
{ // setting knight positions
	knight_body.setPoint(0, sf::Vector2f(x - 2, y + 8));
	knight_body.setPoint(1, sf::Vector2f(x - 5, y + 14));
	knight_body.setPoint(2, sf::Vector2f(x - 11, y + 17));
	knight_body.setPoint(3, sf::Vector2f(x - 12, y + 21));
	knight_body.setPoint(4, sf::Vector2f(x + 16, y + 21));
	knight_body.setPoint(5, sf::Vector2f(x + 14, y + 2));
	knight_body.setPoint(6, sf::Vector2f(x + 1, y - 11));
	knight_body.setPoint(7, sf::Vector2f(x + 1, y - 7));
	knight_body.setPoint(8, sf::Vector2f(x - 4, y - 11));
	knight_body.setPoint(9, sf::Vector2f(x - 4, y - 7));
	knight_body.setPoint(10, sf::Vector2f(x - 12, y + 1));
	knight_body.setPoint(11, sf::Vector2f(x - 14, y + 5));
	knight_body.setPoint(12, sf::Vector2f(x - 13, y + 9));
	knight_body.setPoint(13, sf::Vector2f(x - 9, y + 11));

	knight_nose.setPosition(sf::Vector2f(x - 11, y + 5));

	knight_eye.setPosition(sf::Vector2f(x + 2, y - 2));

	knight_border.setPoint(0, sf::Vector2f(x - 10, y + 17));
	knight_border.setPoint(1, sf::Vector2f(x - 10, y + 15));
	knight_border.setPoint(2, sf::Vector2f(x + 17, y + 15));
	knight_border.setPoint(3, sf::Vector2f(x + 17, y + 17));

	knight_side.setPoint(0, sf::Vector2f(x - 9, y + 14));
	knight_side.setPoint(1, sf::Vector2f(x - 15, y + 22));
	knight_side.setPoint(2, sf::Vector2f(x - 12, y + 21));
	knight_side.setPoint(3, sf::Vector2f(x - 4, y + 14));
}

void Knight::display_ship(sf::RenderWindow& window) // drawing knight shapes to screen
{
	window.draw(knight_body);
	window.draw(knight_nose);
	window.draw(knight_eye);
	window.draw(knight_border);
	window.draw(knight_side);
}

void Bishop::update_ship_position(int y, int x) // setting position of bishop shapes
{
	bishop_tip.setPosition(sf::Vector2f(x - 2, y - 19));

	bishop_head.setPosition(sf::Vector2f(x - 5, y - 12));

	bishop_disc.setPosition(sf::Vector2f(x - 6, y));

	bishop_body.setPoint(0, sf::Vector2f(x, y - 5));
	bishop_body.setPoint(1, sf::Vector2f(x + 7, y + 20));
	bishop_body.setPoint(2, sf::Vector2f(x - 7, y + 20));

	bishop_base.setPoint(0, sf::Vector2f(x - 9, y + 20));
	bishop_base.setPoint(1, sf::Vector2f(x + 9, y + 20));
	bishop_base.setPoint(2, sf::Vector2f(x + 7, y + 16));
	bishop_base.setPoint(3, sf::Vector2f(x - 7, y + 16));

	bishop_slash.setPosition(sf::Vector2f(x + 5, y - 10));
}
void Bishop::display_ship(sf::RenderWindow& window) // drawing bishop to screen
{
	window.draw(bishop_body);
	window.draw(bishop_base);
	window.draw(bishop_disc);
	window.draw(bishop_head);
	window.draw(bishop_tip);
	window.draw(bishop_slash);
}

void Queen::update_ship_position(int y, int x) // queen positions
{
	queen_tip.setPosition(sf::Vector2f(x - 2, y - 19));

	queen_head.setPoint(0, sf::Vector2f(x - 9, y - 14));
	queen_head.setPoint(1, sf::Vector2f(x - 2, y));
	queen_head.setPoint(2, sf::Vector2f(x + 2, y));
	queen_head.setPoint(3, sf::Vector2f(x + 9, y - 14));

	queen_disc.setPosition(sf::Vector2f(x - 6, y));

	queen_cover.setPosition(sf::Vector2f(x - 6, y - 16));

	queen_body.setPoint(0, sf::Vector2f(x, y - 5));
	queen_body.setPoint(1, sf::Vector2f(x + 7, y + 20));
	queen_body.setPoint(2, sf::Vector2f(x - 7, y + 20));

	queen_base.setPoint(0, sf::Vector2f(x - 9, y + 20));
	queen_base.setPoint(1, sf::Vector2f(x + 9, y + 20));
	queen_base.setPoint(2, sf::Vector2f(x + 7, y + 16));
	queen_base.setPoint(3, sf::Vector2f(x - 7, y + 16));
}
void Queen::display_ship(sf::RenderWindow& window) // draw queen
{
	window.draw(queen_body);
	window.draw(queen_base);
	window.draw(queen_disc);
	window.draw(queen_head);
	window.draw(queen_cover);
	window.draw(queen_tip);
}

void King::update_ship_position(int y, int x) // king shape positions
{
	int total_y = -25; // for debugging. made it easier to change coordinates all together
	int m = 2;
	king_cross.setPoint(0, sf::Vector2f(x - 1 * m, y - 1 * m + total_y));
	king_cross.setPoint(1, sf::Vector2f(x + 1 * m, y - 1 * m + total_y));
	king_cross.setPoint(2, sf::Vector2f(x + 1 * m, y + 1 * m + total_y));
	king_cross.setPoint(3, sf::Vector2f(x + 3 * m, y + 1 * m + total_y));
	king_cross.setPoint(4, sf::Vector2f(x + 3 * m, y + 3 * m + total_y));
	king_cross.setPoint(5, sf::Vector2f(x + 1 * m, y + 3 * m + total_y));
	king_cross.setPoint(6, sf::Vector2f(x + 1 * m, y + 5 * m + total_y));
	king_cross.setPoint(7, sf::Vector2f(x - 1 * m, y + 5 * m + total_y));
	king_cross.setPoint(8, sf::Vector2f(x - 1 * m, y + 3 * m + total_y));
	king_cross.setPoint(9, sf::Vector2f(x - 3 * m, y + 3 * m + total_y));
	king_cross.setPoint(10, sf::Vector2f(x - 3 * m, y + 1 * m + total_y));
	king_cross.setPoint(11, sf::Vector2f(x - 1 * m, y + 1 * m + total_y));




	king_head.setPoint(0, sf::Vector2f(x - 9, y - 14));
	king_head.setPoint(1, sf::Vector2f(x - 4, y));
	king_head.setPoint(2, sf::Vector2f(x, y + 1));
	king_head.setPoint(3, sf::Vector2f(x + 4, y));
	king_head.setPoint(4, sf::Vector2f(x + 9, y - 14));

	king_disc.setPosition(sf::Vector2f(x - 6, y));

	king_cover.setPosition(sf::Vector2f(x - 6, y - 16));

	king_body.setPoint(0, sf::Vector2f(x, y - 8));
	king_body.setPoint(1, sf::Vector2f(x + 7, y + 20));
	king_body.setPoint(2, sf::Vector2f(x - 7, y + 20));

	king_base.setPoint(0, sf::Vector2f(x - 9, y + 20));
	king_base.setPoint(1, sf::Vector2f(x + 9, y + 20));
	king_base.setPoint(2, sf::Vector2f(x + 7, y + 16));
	king_base.setPoint(3, sf::Vector2f(x - 7, y + 16));
}
void King::display_ship(sf::RenderWindow& window) // draw the king
{
	window.draw(king_body);
	window.draw(king_base);
	window.draw(king_disc);
	window.draw(king_head);
	window.draw(king_cover);
	window.draw(king_cross);
}


// Player methods



Player::Player(int p, int kr, int kc) // player constructor, takes in 1/-1 for, and the king's position in row and col. Set in main and in teste function
{
	player = p;
	king_row = kr;
	king_col = kc;
}

int Player::confirm_start(int board[8][8], int row1, int col1) // make sure clicked asteroid has player's piece on it before dragging along screen
{
	if (board[row1][col1] == 0) // start square is empty
		return 0;

	if ((board[row1][col1] < 0) != (player < 0)) // start square is the opponent's piece
	{
		return 0;
	}

	return 1; // start square is player's own piece
}

int Player::make_move(int board[8][8], Piece* display_board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2)
{
	if (row1 == row2 && col1 == col2) // if put back in same square
		return 0; // still player's turn. board not updated

	terminal2 = ""; // reset string that prints to screen

	// copy board and player's stats
	int temp_board[8][8];
	Stats temp_stats;
	copy_board(board, temp_board);
	copy_stats(temp_stats);

	// physically moves the pieces to new places if move is possible. 
	//If move is not possible, returns 0. if it is, returns 1, if castling on a guarded square, returns 2.
	int valid = valid_move(board, row1, col1, row2, col2, terminal1, terminal2); 

	if (valid == 0) // invalid move
	{
		terminal1 = "That is not a valid trajectory!";
		terminal2 = "";
		return 0; // still player's turn. board not updated
	}
	else if (valid == 2) // invalid castling. print statement already taken care of in valid_move function
	{
		return 0; // still player's turn. board not updated
	}

	if (guarded(board, king_row, king_col)) // if chosen move leaves own player in check
	{
		if (player == 1)
			terminal1 = "Flying there leaves Air Force One targeted!";
		else
			terminal1 = "Hovering there leaves High Prophet sighted!";
		terminal2 = "";
		// revert board state and return 0
		copy_board(temp_board, board);
		get_stats(temp_stats);
		return 0; // still player's turn. board not updated
	}

	revoke_en_passant(board); // set 11/-11 to 0

	compare_boards(board, temp_board, display_board); // update board changes in the display board
	return 1; // end player's turn. board updated.
}

void Player::copy_stats(Stats& temp_stats) // copy player -> stats
{
	// don't need to copy player integer representation because that won't change mid game
	temp_stats.king_row = king_row;
	temp_stats.king_col = king_col;
	temp_stats.king_moved = king_moved;
	temp_stats.kingside_rook_moved = kingside_rook_moved;
	temp_stats.queenside_rook_moved = queenside_rook_moved;
	temp_stats.promotion = promotion;
}

void Player::get_stats(Stats& temp_stats) // copy stats -> player
{
	// don't need to copy player name or integer representation because that won't change mid game
	king_row = temp_stats.king_row;
	king_col = temp_stats.king_col;
	king_moved = temp_stats.king_moved;
	kingside_rook_moved = temp_stats.kingside_rook_moved;
	queenside_rook_moved = temp_stats.queenside_rook_moved;
	promotion = temp_stats.promotion;
}

void Player::revoke_en_passant(int board[8][8]) // when a pawn double jumps, a 11/-11 is left in the space is jumped over
{ // this is so that an enemy pawn can target that square to do an en passant capture. But after one turn, en passant is waived and should go back to a 0 (empty).
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if ((player < 0) != (board[row][col] < 0) && abs(board[row][col]) == 11) // 11 and -11 represent ghost pawns
				board[row][col] = 0;
		}
	}
}

// returns 0 if still playing, 1 if checkmate, 2 if draw
int Player::evaluate_board(int board[8][8], string& terminal1, string& terminal2)
{
	if (lack_of_material(board)) // only kings left
	{
		terminal2 = "Ceasefire! Not enough ships to continue battle!";
		return 2; // not enough material to checkmate. game ends
	}


	if (!has_move_that_removes_check(board)) // player can't make a move where end result is no check
	{
		if (guarded(board, king_row, king_col)) // and guarded
		{
			if (player == 1)
				terminal2 = "Spacemate! Aliens conquer Earth!";
			else
				terminal2 = "Spacemate! Humans defend Earth!";
			return 1; // checkmate. game ends
		}
		else
		{
			terminal2 = "Ceasefire! Invasion ends in a stalemate!";
			return 2; // stalemate. game ends
		}
	}

	if (guarded(board, king_row, king_col)) // but stil has a move to get out of check, then just print a check statement and continue game
	{
		if (player == 1)
		{
			terminal2 = "Air Force One has been targeted!";
		}
		else
		{
			terminal2 = "High Prophet has been sighted!";
		}
	}

	return 0; // game continues
}

int Player::lack_of_material(int board[8][8]) // returns 1 if only kings
{
	int zero_count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 0)
				zero_count++;
		}
	}
	if (zero_count == 62) // 64 total spaces. if all but 2 are empty, then only kings can remain
		return 1;
	else
		return 0;
}

void Player::compare_boards(int board[8][8], int board_copy[8][8], Piece* display_board[8][8]) // compares current board state to the previous.
{ // if there are differences, it dynamically allocates a new piece appropriate to each updated place in the board
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (board[row][col] != board_copy[row][col])
			{
				if (abs(board[row][col]) == 0) // empty slot
				{
					delete display_board[row][col]; // make pointer null
					display_board[row][col] = nullptr;
				}
				else if (abs(board[row][col]) == 1) // pawn
				{
					delete display_board[row][col];
					display_board[row][col] = new Pawn(row_to_y(row), col_to_x(col), player);
				}
				else if (abs(board[row][col]) == 2) // rook
				{
					delete display_board[row][col];
					display_board[row][col] = new Rook(row_to_y(row), col_to_x(col), player);
				}
				else if (abs(board[row][col]) == 3) // knight
				{
					delete display_board[row][col];
					display_board[row][col] = new Knight(row_to_y(row), col_to_x(col), player);
				}
				else if (abs(board[row][col]) == 4) // bishop
				{
					delete display_board[row][col];
					display_board[row][col] = new Bishop(row_to_y(row), col_to_x(col), player);
				}
				else if (abs(board[row][col]) == 5) // queen
				{
					delete display_board[row][col];
					display_board[row][col] = new Queen(row_to_y(row), col_to_x(col), player);
				}
				else if (abs(board[row][col]) == 6) // king
				{
					delete display_board[row][col];
					display_board[row][col] = new King(row_to_y(row), col_to_x(col), player);
				}
			}
		}
	}
}

bool Player::get_promotion() // for access in main
{
	return promotion;
}

void Player::finish_promotion(int board[8][8], Piece * display_board[8][8], int piece_promoted) // turns pawn in back rank to chosen piece
{
	int row = 0;

	if (player == -1) // if alien
	{
		row = 7; // check human back rank, otherwise checks alien back rank
	}
	int col = 0;
	for (col = 0; col < 8; col++)
	{
		if (abs(board[row][col]) == 1) // found pawn
		{
			break;
		}
	}
	// set that space to promoted piece in board
	board[row][col] = player * piece_promoted;

	if (piece_promoted == 2) // update display board to match as well
	{
		delete display_board[row][col];
		display_board[row][col] = new Rook(row_to_y(row), col_to_x(col), player);
	}
	else if (piece_promoted == 3)
	{
		delete display_board[row][col];
		display_board[row][col] = new Knight(row_to_y(row), col_to_x(col), player);
	}
	else if (piece_promoted == 4)
	{
		delete display_board[row][col];
		display_board[row][col] = new Bishop(row_to_y(row), col_to_x(col), player);
	}
	else if (piece_promoted == 5)
	{
		delete display_board[row][col];
		display_board[row][col] = new Queen(row_to_y(row), col_to_x(col), player);
	}

	promotion = false;
}

// makes sure player made a valid move. return 1 if move valid, 0 if invalid. returns 2 if trying to castle through a check
int Player::valid_move(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2)
{
	int valid = 0; // starts out as zero, maybe will change to 1 or 2
	int possible_moves[8][8]; // array for storing where a piece can move. 1 means a piece can move to that space, else 0
	initialize_board(possible_moves); // fill it with zeroes

	// take absolute value of the piece at grabbed location because alien pieces are negative
	switch (abs(board[row1][col1])) {
	case 1: // piece is pawn
		// pawn is coded differently from other pieces because its attack moves and non-attack moves are different
		valid = valid_move_pawn(board, row1, col1, row2, col2, terminal1, terminal2); // checks if move was a valid single jump or double jump
		if (valid == 0)
			valid = valid_move_pawn_attack(board, row1, col1, row2, col2, terminal1, terminal2); // else, checks if move was a valid diagonal attack
		if (valid == 1 && (row2 == 0 || row2 == 7)) // if pawn in promotion row, print out promotion messages and set promotion to true
		{
			promotion = true;
			if (player == 1)
				terminal2 = "Repawn Drone has docked on the Mothership!";
			else
				terminal2 = "Escape Pawn has landed on Earth!";
		}
		return valid;
	case 2: // piece is rook
		rook_possible_moves(board, row1, col1, possible_moves, 1); // fill possible moves where rook can go to, pass in 1 for ally
		break;
	case 3: // piece is knight
		knight_possible_moves(board, row1, col1, possible_moves, 1); // pass in 1 for ally
		break;
	case 4: // piece is bishop
		bishop_possible_moves(board, row1, col1, possible_moves, 1); // pass in 1 for ally
		break;
	case 5: // piece is queen
		queen_possible_moves(board, row1, col1, possible_moves, 1); // pass in 1 for ally
		break;
	case 6: // piece is king
		valid = castle(board, row1, col1, row2, col2, terminal1, terminal2); // check if they tried to castle
		if (valid == 1 || valid == 2) // if good castle or castle through check, can return valid now
			return valid;
		else // if completely improper castle, then we check for a normal king move
			king_possible_attacks(board, row1, col1, possible_moves, 1);
		break;
	}

	if (possible_moves[row2][col2] == 1)
	{
		valid = 1; // user clicked in an allowed space
		if (abs(board[row1][col1]) == 2) // if piece is rook
		{
			// update that rook moved for castling reasons
			if (player == 1) // human rook
			{
				if (row1 == 7) // human rook row
				{
					if (col1 == 0)
						queenside_rook_moved = true;
					if (col1 == 7)
						kingside_rook_moved = true;
				}
			}
			else // alien rook
			{
				if (row1 == 0) // alien rook row
				{
					if (col1 == 0)
						queenside_rook_moved = true;
					if (col1 == 7)
						kingside_rook_moved = true;
				}
			}
		}

		if (abs(board[row1][col1]) == 6) // update king row and col for seeing if king is in check. update king_moved for castling reasons
		{
			king_row = row2;
			king_col = col2;
			king_moved = true;
		}

		if (board[row2][col2] != 0 && abs(board[row2][col2]) != 11) // not empty space, captured piece
		{
			if (player == 1) // human attack
				terminal1 = convert_to_piece_name(board, row1, col1) + " shoots down " + convert_to_piece_name(board, row2, col2) + " at asteroid " + convert_to_letter_number(row2, col2) + "!";
			else // alien attack
				terminal1 = convert_to_piece_name(board, row1, col1) + " abducts " + convert_to_piece_name(board, row2, col2) + " at asteroid " + convert_to_letter_number(row2, col2) + "!";
			board[row2][col2] = board[row1][col1]; // set end square equal to the piece that was grabbed
			board[row1][col1] = 0; // set the old square to 0
		}
		else // moved to empty space
		{
			if (player == 1) // human non-attack move
				terminal1 = convert_to_piece_name(board, row1, col1) + " flies to asteroid " + convert_to_letter_number(row2, col2) + ".";
			else // alien non-attack move
				terminal1 = convert_to_piece_name(board, row1, col1) + " hovers to asteroid " + convert_to_letter_number(row2, col2) + ".";
			board[row2][col2] = board[row1][col1];
			board[row1][col1] = 0;
		}
	}
	return valid; // return outcome so that outer function knows what to do
}

// returns 1 if user move is valid single jump or double jump, else 0
int Player::valid_move_pawn(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2)
{
	if (col1 == col2 && board[row2][col2] == 0) // correct column, and new space is empty
	{
		if (row2 == row1 - player) // single jump
		{
			if (player == 1) // human move
			{
				terminal1 = "Repawn Drone flies to asteroid " + convert_to_letter_number(row2, col2) + ".";
			}
			else // alien move
			{
				terminal1 = "Escape Pawn hovers to asteroid " + convert_to_letter_number(row2, col2) + ".";
			}
			board[row2][col2] = board[row1][col1];
			board[row1][col1] = 0;
			return 1;
		}
		if (row2 == row1 - 2 * player && board[row1 - player][col1] == 0 && (row1 == 1 || row1 == 6)) // double jump (can only be first move)
		{
			if (player == 1) // human double
			{
				terminal1 = "Repawn Drone flies to asteroid " + convert_to_letter_number(row2, col2) + ".";
			}
			else // alien double
			{
				terminal1 = "Escape Pawn hovers to asteroid " + convert_to_letter_number(row2, col2) + ".";
			}
			board[row1 - player][col1] = 11 * player; // set skipped square to -11 or 11, depending on player, for en passant
			board[row2][col2] = board[row1][col1];
			board[row1][col1] = 0;
			return 1;
		}
	}
	return 0;
}

// returns 1 if valid diagonal attack, else 0
int Player::valid_move_pawn_attack(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2)
{
	if (col2 == col1 + 1 || col2 == col1 - 1 || col2 == col1 + 7 || col2 == col1 - 7) // make sure move was to left or right col (or through portal)
	{
		if (row2 == row1 - player) // make sure move was up/down one row
		{
			if (board[row2][col2] != 0 && ((board[row2][col2] < 0) != (player < 0))) // make sure its not an empty space or an ally piece
			{
				if (abs(board[row2][col2]) == 11)
					board[row2 + player][col2] = 0; // en passant. enemy pawn that doubled jumped is removed
				if (player == 1) // human attack
				{
					terminal1 = "Repawn Drone shoots down " + convert_to_piece_name(board, row2, col2) + " at asteroid " + convert_to_letter_number(row2, col2) + "!";
				}
				else // alien attack
				{
					terminal1 = "Escape Pawn abducts " + convert_to_piece_name(board, row2, col2) + " at asteroid " + convert_to_letter_number(row2, col2) + "!";
				}
				board[row2][col2] = board[row1][col1];
				board[row1][col1] = 0;
				return 1;
			}
		}
	}
	return 0;
}

// used only for hypothetical board building to see if a king is in check from a enemy pawn attack (pass in -1 for side). also used to see if an ally pawn attack can help a king escape check (pass in 1 for side)
void Player::pawn_possible_attacks(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	// three scenarios: pawn in leftmost collumn, pawn in rightmost collumn, pawn in one of other 6 collumns
	// check for valid attack in a square by making sure it is an enemy piece from the perspective of the pawn

	if (col1 == 0) // leftmost collumn
	{
		if (board[row1 - side * player][7] != 0 && ((board[row1 - side * player][7] < 0) != (side * player < 0))) // check for valid left attack through portal
			possible_moves[row1 - side * player][7] = 1;
		if (board[row1 - side * player][1] != 0 && ((board[row1 - side * player][1] < 0) != (side * player < 0))) // check for attack to right column
			possible_moves[row1 - side * player][1] = 1;
	}
	else if (col1 == 7) // rightmost collumn
	{
		if (board[row1 - side * player][6] != 0 && ((board[row1 - side * player][6] < 0) != (side * player < 0))) // check for left attack
			possible_moves[row1 - side * player][6] = 1;
		if (board[row1 - side * player][0] != 0 && ((board[row1 - side * player][0] < 0) != (side * player < 0))) // check for right attack through portal
			possible_moves[row1 - side * player][0] = 1;
	}
	else // other collumn
	{
		if (board[row1 - side * player][col1 - 1] != 0 && ((board[row1 - side * player][col1 - 1] < 0) != (side * player < 0))) // check for normal left attack
			possible_moves[row1 - side * player][col1 - 1] = 1;
		if (board[row1 - side * player][col1 + 1] != 0 && ((board[row1 - side * player][col1 + 1] < 0) != (side * player < 0))) // check for normal right attack
			possible_moves[row1 - side * player][col1 + 1] = 1;
	}
}

// used for seeing if a pawn move or attack blocks a check
void Player::pawn_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	pawn_possible_attacks(board, row1, col1, possible_moves, side); // fill possible moves board with attacks first

	// see if pawn has a single jump or double jump possibility
	if (board[row1 - player][col1] == 0)
	{
		possible_moves[row1 - player][col1] = 1;
		if (board[row1 - 2 * player][col1] == 0 && (row1 == 1 || row1 == 6))
			possible_moves[row1 - 2 * player][col1] = 1;
	}
}

// used in hypothetical board building but also in actual rook move. pass in 1 for side if rook is ally to current player, -1 if enemy
void Player::rook_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	// rook can move four directions, up down left right, so this function checks these and puts '1' in the grid if the rook can move there

	// check downward direction
	bool collision = false;
	for (int i = row1 + 1; i <= 7 && collision == false; i++) // loop ends if it rook hits lower wall or collides with another piece
	{
		if (board[i][col1] == 0 || abs(board[i][col1]) == 11) // check if space is empty
		{
			possible_moves[i][col1] = 1; // update possible moves
		}
		else if (board[i][col1] < 0 == (side * player < 0)) // if piece is ally piece
		{
			collision = true; // end loop by updating collision. do not add current space to possible moves since it is an ally piece
		}
		else // piece is enemy piece
		{
			// end loop by updating collision. this time, add current space to possible moves, since the rook can move to an enemy space (capture)
			possible_moves[i][col1] = 1;
			collision = true;
		}
	}

	// check upward direction. similar to downward part
	collision = false;
	for (int i = row1 - 1; i >= 0 && collision == false; i--) // check if rook hits upper wall
	{
		if (board[i][col1] == 0 || abs(board[i][col1]) == 11)
		{
			possible_moves[i][col1] = 1;
		}
		else if (board[i][col1] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[i][col1] = 1;
			collision = true;
		}
	}

	// check right direction. since there are portals, we dont end loop when the rook hits the right wall. instead, we teleport it to the left wall. 
	collision = false;
	for (int i = col1 + 1; collision == false; i++)
	{
		if (i == 8) // pass through right portal
			i = 0;
		if (board[row1][i] == 0 || abs(board[row1][i]) == 11)
		{
			possible_moves[row1][i] = 1;
		}
		else if (board[row1][i] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[row1][i] = 1;
			collision = true;
		}
	}

	// check left direction. similar to right direction, but goes through opposite portal
	collision = false;
	for (int i = col1 - 1; collision == false; i--)
	{
		if (i == -1) // pass through left portal
			i = 7;
		if (board[row1][i] == 0 || abs(board[row1][i]) == 11)
		{
			possible_moves[row1][i] = 1;
		}
		else if (board[row1][i] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[row1][i] = 1;
			collision = true;
		}
	}
}

// for hypothetical moves and actual moves. changes possible_moves array to show 1 where possible move is.
void Player::knight_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	// at most, knight can move to 8 squares. these 8 squares are in 4 rows. the function is initially split into the four rows. each row has a right attack and a left attack

	int end_col = 0; // initialize end_col

	// row one space below knight
	if (row1 + 1 < 8) // check if this space is in bounds
	{
		if (col1 >= 6) // if in right two collumns, set end_col to 6 to the left (move through right portal)
			end_col = col1 - 8 + 2;
		else // not moving through portal, moves two to the right
			end_col = col1 + 2;
		if (board[row1 + 1][end_col] == 0 || abs(board[row1 + 1][end_col]) == 11 || (board[row1 + 1][end_col] < 0) != (side * player < 0)) // empty space or enemy piece
			possible_moves[row1 + 1][end_col] = 1; // set as possible move

		if (col1 <= 1) // in left two collumns, set end_col to 6 to the right (move through left portal)
			end_col = col1 + 8 - 2;
		else // not moving through portal, moves two to the left
			end_col = col1 - 2;
		if (board[row1 + 1][end_col] == 0 || abs(board[row1 + 1][end_col]) == 11 || (board[row1 + 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 + 1][end_col] = 1;
	}

	// two rows below knight
	if (row1 + 2 < 8)
	{
		if (col1 == 7) // if in right collumn, set end_col to 7 to the left (move through right portal)
			end_col = col1 - 8 + 1;
		else // not moving through portal, moves 1 to right
			end_col = col1 + 1;
		if (board[row1 + 2][end_col] == 0 || abs(board[row1 + 2][end_col]) == 11 || (board[row1 + 2][end_col] < 0) != (side * player < 0))
			possible_moves[row1 + 2][end_col] = 1;

		if (col1 == 0) // if in left collumn, set end_col to 7 to the right (move through left portal)
			end_col = col1 + 8 - 1;
		else // not moving thorugh portal, moves 1 left
			end_col = col1 - 1;
		if (board[row1 + 2][end_col] == 0 || abs(board[row1 + 2][end_col]) == 11 || (board[row1 + 2][end_col] < 0) != (side * player < 0))
			possible_moves[row1 + 2][end_col] = 1;
	}

	// one row above knight. simlilar to "one row below knight"
	if (row1 - 1 >= 0)
	{
		if (col1 >= 6)
			end_col = col1 - 8 + 2;
		else
			end_col = col1 + 2;
		if (board[row1 - 1][end_col] == 0 || abs(board[row1 - 1][end_col]) == 11 || (board[row1 - 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 1][end_col] = 1;

		if (col1 <= 1)
			end_col = col1 + 8 - 2;
		else
			end_col = col1 - 2;
		if (board[row1 - 1][end_col] == 0 || abs(board[row1 - 1][end_col]) == 11 || (board[row1 - 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 1][end_col] = 1;
	}

	// two rows above knight. similar to "two rows below knight"
	if (row1 - 2 >= 0)
	{
		if (col1 == 7)
			end_col = col1 - 8 + 1;
		else
			end_col = col1 + 1;
		if (board[row1 - 2][end_col] == 0 || abs(board[row1 - 2][end_col]) == 11 || (board[row1 - 2][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 2][end_col] = 1;

		if (col1 == 0)
			end_col = col1 + 8 - 1;
		else
			end_col = col1 - 1;
		if (board[row1 - 2][end_col] == 0 || abs(board[row1 - 2][end_col]) == 11 || (board[row1 - 2][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 2][end_col] = 1;
	}
}

// sets possible moves for bishop for both hypothetical boards and actual bishop movements
void Player::bishop_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	// four diagonals to check. function is split into these four. inside for loop is simimlar to rook.
	// with the rook, we checked for a wall when moving up/down and for a portal when moving right/left.
	// with bishop, we have to check for a wall and portal in all four cases because of diagonal movement.

	bool collision = false;

	// down and right diagonoal. 
	for (int i = row1 + 1, j = col1 + 1; i <= 7 && collision == false; i++, j++) // check for lower wall and piece collision
	{
		if (j == 8) // move through right portal
			j = 0;
		if (board[i][j] == 0 || abs(board[i][j]) == 11)
		{
			possible_moves[i][j] = 1;
		}
		else if (board[i][j] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[i][j] = 1;
			collision = true;
		}
	}

	collision = false;
	// down and left diagonal. 
	for (int i = row1 + 1, j = col1 - 1; i <= 7 && collision == false; i++, j--) // lower wall and piece collision check
	{
		if (j == -1) // move through left portal
			j = 7;
		if (board[i][j] == 0 || abs(board[i][j]) == 11)
		{
			possible_moves[i][j] = 1;
		}
		else if (board[i][j] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[i][j] = 1;
			collision = true;
		}
	}

	// up and right diagonal
	collision = false;
	for (int i = row1 - 1, j = col1 + 1; i >= 0 && collision == false; i--, j++) // upper wall and piece collision check
	{
		if (j == 8) // through right portal
			j = 0;
		if (board[i][j] == 0 || abs(board[i][j]) == 11)
		{
			possible_moves[i][j] = 1;
		}
		else if (board[i][j] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[i][j] = 1;
			collision = true;
		}
	}

	collision = false;
	// up and left diagonal
	for (int i = row1 - 1, j = col1 - 1; i >= 0 && collision == false; i--, j--) // upper wall and piece collision check
	{
		if (j == -1) // through left portal
			j = 7;
		if (board[i][j] == 0 || abs(board[i][j]) == 11)
		{
			possible_moves[i][j] = 1;
		}
		else if (board[i][j] < 0 == (side * player < 0))
		{
			collision = true;
		}
		else
		{
			possible_moves[i][j] = 1;
			collision = true;
		}
	}
}

// checks for queen possible moves. queen is combination of rook and bishop, so this function just calls their functions
void Player::queen_possible_moves(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	rook_possible_moves(board, row1, col1, possible_moves, side);
	bishop_possible_moves(board, row1, col1, possible_moves, side);
}

// checks if player tried to castle. if good castle, changes board and returns 1. if almost good castle, but the enemy had a castle square in check, then returns 2. if completely invalid, returns 0.
int Player::castle(int board[8][8], int row1, int col1, int row2, int col2, string& terminal1, string& terminal2)
{
	if (king_moved == false) // to castle, king must not have moved
	{
		if (kingside_rook_moved == false) // kingside rook also must not have moved
		{
			if (player == 1) // human
			{
				if (row2 == 7 && col2 == 6) // tried to put in correct square for kingside castle (two spaces to right)
				{
					if (board[7][5] == 0 && board[7][6] == 0 && board[7][7] == 2) // check if spaces are open and rook is there
					{
						if (!guarded(board, 7, 4) && !guarded(board, 7, 5) && !guarded(board, 7, 6)) // check if spaces are in check
						{
							// if it gets this far, make the board changes. 
							board[7][6] = 6; // king move
							board[7][5] = 2; // rook move
							board[7][7] = 0; // old rook place is now empty
							king_row = 7; // new king row
							king_col = 6; // new king col
							board[row1][col1] = 0; // old king place is now empty
							king_moved = true; // true now, so no more caslting
							kingside_rook_moved = true;
							terminal1 = "Air Force One bunkers 3 o'clock.";
							return 1;
						}
						else // got through all if statements expect for last one, meaning castling illegally crosses a check. 
						{
							terminal1 = "Air Force One can't bunker through targeted asteroid!";
							return 2;
						}
					}
				}
			}
			else // alien. same stuff, but on alien side of board (and negative numbers for alien pieces)
			{
				if (row2 == 0 && col2 == 6)
				{
					if (board[0][5] == 0 && board[0][6] == 0 && board[0][7] == -2)
					{
						if (!guarded(board, 0, 4) && !guarded(board, 0, 5) && !guarded(board, 0, 6))
						{
							board[0][6] = -6;
							board[0][5] = -2;
							board[0][7] = 0;
							king_row = 0;
							king_col = 6;
							board[row1][col1] = 0;
							king_moved = true;
							kingside_rook_moved = true;
							terminal1 = "High Prophet takes refuge portside.";
							return 1;
						}
						else
						{
							terminal1 = "High Prophet can't take refuge through sighted asteroid!";
							return 2;
						}
					}
				}
			}
		}

		if (queenside_rook_moved == false) // same as kingside, but now checking queenside castling for human/alien
		{
			if (player == 1)
			{
				if (row2 == 7 && col2 == 2)
				{
					if (board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && board[7][0] == 2)
					{
						if (!guarded(board, 7, 4) && !guarded(board, 7, 3) && !guarded(board, 7, 2))
						{
							board[7][2] = 6;
							board[7][3] = 2;
							board[7][0] = 0;
							king_row = 7;
							king_col = 2;
							board[row1][col1] = 0;
							king_moved = true;
							queenside_rook_moved = true;
							terminal1 = "Air Force One bunkers 9 o'clock.";
							return 1;
						}
						else
						{
							terminal1 = "Air Force One can't bunker through targeted asteroid!";
							return 2;
						}
					}
				}
			}
			else
			{
				if (row2 == 0 && col2 == 2)
				{
					if (board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && board[0][0] == -2)
					{
						if (!guarded(board, 0, 4) && !guarded(board, 0, 3) && !guarded(board, 0, 2))
						{
							board[0][2] = -6;
							board[0][3] = -2;
							board[0][0] = 0;
							king_row = 0;
							king_col = 2;
							board[row1][col1] = 0;
							king_moved = true;
							queenside_rook_moved = true;
							terminal1 = "High Prophet takes refuge starboard.";
							return 1;
						}
						else
						{
							terminal1 = "High Prophet can't take refuge through sighted asteroid!";
							return 2;
						}
					}
				}
			}
		}
	}
	return 0;
}

// looks for possible king moves and fills 1 in possible_moves array if the space is a possible move
void Player::king_possible_attacks(int board[8][8], int row1, int col1, int possible_moves[8][8], int side)
{
	// the 8 possible king moves surrounding the king are checked in four catogories: 3 downward moves (including 2 diagonal), 3 upward moves (including 2 diagonal), 1 right move, 1 left move

	int end_col = 0;

	// downward moves
	if (row1 + 1 <= 7) // make sure dont hit lower wall
	{
		// downward center attack
		if (board[row1 + 1][col1] == 0 || abs(board[row1 + 1][col1]) == 11 || (board[row1 + 1][col1] < 0) != (side * player < 0))
			possible_moves[row1 + 1][col1] = 1;

		// downward right attack
		if (col1 == 7) // if in right col, attack through right portal
			end_col = 0;
		else // if not, attack to right col (normal)
			end_col = col1 + 1;
		if (board[row1 + 1][end_col] == 0 || abs(board[row1 + 1][end_col]) == 11 || (board[row1 + 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 + 1][end_col] = 1;

		//downward left attack
		if (col1 == 0) // if in left col, attack through left portal
			end_col = 7;
		else // if not, attack to left col (normal)
			end_col = col1 - 1;
		if (board[row1 + 1][end_col] == 0 || abs(board[row1 + 1][end_col]) == 11 || (board[row1 + 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 + 1][end_col] = 1;
	}

	// upward moves. mostly same as downward moves
	if (row1 - 1 >= 0) // check upper wall
	{
		if (board[row1 - 1][col1] == 0 || abs(board[row1 - 1][col1]) == 11 || (board[row1 - 1][col1] < 0) != (side * player < 0))
			possible_moves[row1 - 1][col1] = 1;

		if (col1 == 7)
			end_col = 0;
		else
			end_col = col1 + 1;
		if (board[row1 - 1][end_col] == 0 || abs(board[row1 - 1][end_col]) == 11 || (board[row1 - 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 1][end_col] = 1;

		if (col1 == 0)
			end_col = 7;
		else
			end_col = col1 - 1;
		if (board[row1 - 1][end_col] == 0 || abs(board[row1 - 1][end_col]) == 11 || (board[row1 - 1][end_col] < 0) != (side * player < 0))
			possible_moves[row1 - 1][end_col] = 1;
	}

	// check right move
	if (col1 == 7) // check if through right portal.
		end_col = 0;
	else
		end_col = col1 + 1;
	if (board[row1][end_col] == 0 || abs(board[row1][end_col]) == 11 || (board[row1][end_col] < 0) != (side * player < 0))
		possible_moves[row1][end_col] = 1;

	// check left move
	if (col1 == 0) // check if thorugh left portal
		end_col = 7;
	else
		end_col = col1 - 1;
	if (board[row1][end_col] == 0 || abs(board[row1][end_col]) == 11 || (board[row1][end_col] < 0) != (side * player < 0))
		possible_moves[row1][end_col] = 1;
}

// check to see if a given square is guarded by an enemy piece. used to determine if squares are "in check"
int Player::guarded(int board[8][8], int row, int col) // check if a specific square is being guarded by an enemy piece. returns 1 if so, 0 otherwise
{
	int possible_moves[8][8];
	initialize_board(possible_moves); // fill board with zeroes

	// loop through board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// if current space is an enemy piece, fill the grid with the spaces it is targetting
			if (board[i][j] != 0 && abs(board[i][j]) != 11 && (board[i][j] < 0) != (player < 0))
			{
				// switch case so that the current possible_attacks function is called based on the piece in the current square
				switch (abs(board[i][j])) {
					// we pass in "-1" for the side (fifth parameter) because we want to know where the enemy pieces can move, not the ally pieces
				case 1:
					pawn_possible_attacks(board, i, j, possible_moves, -1);
					break;
				case 2:
					rook_possible_moves(board, i, j, possible_moves, -1);
					break;
				case 3:
					knight_possible_moves(board, i, j, possible_moves, -1);
					break;
				case 4:
					bishop_possible_moves(board, i, j, possible_moves, -1);
					break;
				case 5:
					queen_possible_moves(board, i, j, possible_moves, -1);
					break;
				case 6:
					king_possible_attacks(board, i, j, possible_moves, -1);
					break;
				}
			}
		}
	}

	// results is a board filled with 1's and 0's. targeted spaces are marked 1.

	if (possible_moves[row][col] == 1) // if the square passed into the function is targeted (has a 1) then return 1
		return 1;
	else // square is open, meaning the king can move there or remain there or pass through the square while castling
		return 0;
}

// used to determine if there is a checkmate, stalemate, or neither. returns 1 if its neither, returns 0 if its a checkmate or stalemate
int Player::has_move_that_removes_check(int board[8][8]) // check all a player's moves and until one results in the king not being in check. returns 1 if possible move, 0 otherwise
{
	int possible_moves[8][8];
	int escaped = 0; // 

	// loop through the board looking for ally pieces
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != 0 && abs(board[i][j]) != 11 && (board[i][j] < 0) == (player < 0) && escaped == 0) // loop breaks when a move is found that does not result in check
			{
				initialize_board(possible_moves); // possible_moves board must be reset for each piece
				switch (abs(board[i][j])) {
					// possible_moves functions are called using 1 for side (fifth parameter) because we are looking at possible moves of ally pieces (not enemy)
				case 1:
					pawn_possible_moves(board, i, j, possible_moves, 1);
					break;
				case 2:
					rook_possible_moves(board, i, j, possible_moves, 1);
					break;
				case 3:
					knight_possible_moves(board, i, j, possible_moves, 1);
					break;
				case 4:
					bishop_possible_moves(board, i, j, possible_moves, 1);
					break;
				case 5:
					queen_possible_moves(board, i, j, possible_moves, 1);
					break;
				case 6:
					king_possible_attacks(board, i, j, possible_moves, 1);
				}

				// for the given piece, creates a hypothetical board where we move the piece to each place it can go. 
				// if the move results in no check, it returns 1 and stores it in "escaped" so that the loop breaks
				escaped = hyopthetical_board(board[i][j], i, j, board, possible_moves);
			}
		}
	}
	// 1 if move is found, 0 if not
	return escaped;
}

// given a piece type, coordinates of the piece, and an array with the possible moves of the piece, determines if it has a move that results in no check
int Player::hyopthetical_board(int piece, int piece_row, int piece_col, int board[8][8], int possible_moves[8][8])
{
	int temp_board[8][8]; // for copying from actual board
	// loop through board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (possible_moves[i][j] == 1) // square is a possible move for the piece
			{
				// dont want to modify the actualy king_row and king_col values, so we use temps
				int temp_king_row = 0;
				int temp_king_col = 0;
				copy_board(board, temp_board); // copy the actual board into the temp board
				if (abs(piece) == 1) // if piece is a pawn
				{
					if (abs(temp_board[i][j]) == 11)
					{
						temp_board[i - player][j] = 0; // removes pawn destroyed via en passant
					}
				}
				temp_board[i][j] = piece; // put the piece in possible square
				temp_board[piece_row][piece_col] = 0; // remove it from old square
				if (abs(piece) == 6) // if king is moved, then temp king coordinates store where the king moved to
				{
					temp_king_row = i;
					temp_king_col = j;
				}
				else // if non-king is moved, then the normal king coordinates are stored in temp coordinates
				{
					temp_king_row = king_row;
					temp_king_col = king_col;
				}

				if (!guarded(temp_board, temp_king_row, temp_king_col)) // if the king's square is not guarded in this temporary board state, return 1
					return 1;
			}
		}
	}
	// returns 0 if the piece did not have any move that resulted in no check. loop in outer function "has_move_that_removes_check" continues on to next piece
	return 0;
}



// Test class methods


Test::Test() // test constructor. calls all test methods with relevant cout statements
{
	if (test_board_evaluation_checkmate())
		cout << "Test function 1 passed\n";
	else
		cout << "test function 1 failed\n";

	if (test_board_evaluation_stalemate())
		cout << "Test function 2 passed\n";
	else
		cout << "test function 2 failed\n";

	if (test_board_evaluation_continue())
		cout << "Test function 3 passed\n";
	else
		cout << "test function 3 failed\n";

	if (test_conversions())
		cout << "Test function 4 passed\n";
	else
		cout << "test function 4 failed\n";

	if (test_confirm_start())
		cout << "Test function 5 passed\n";
	else
		cout << "test function 5 failed\n";
}

int Test::test_board_evaluation_checkmate() // test function 1
{
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	board[7][4] = 6;
	board[4][3] = -2;
	board[5][4] = -2;
	board[4][5] = -2;
	board[0][4] = -6;

	if (humans.evaluate_board(board, terminal1, terminal2) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Test::test_board_evaluation_stalemate() // test function 2
{
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	board[0][4] = -6;
	board[1][4] = 1;
	board[2][4] = 6;

	if (aliens.evaluate_board(board, terminal1, terminal2) == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Test::test_board_evaluation_continue() // test function 3
{
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	board[0][4] = -6;
	board[2][7] = -1;
	board[7][4] = 6;
	board[5][6] = 1;

	if (humans.evaluate_board(board, terminal1, terminal2) == 0)
		return 1;

	else
		return 0;
}

int Test::test_conversions() // test function 4
{
	return (y_to_row(290) == 1) && (x_to_col(102) == 0) && (row_to_y(2) == 368) && (col_to_x(1) == 187);
}

int Test::test_confirm_start() // test function 5
{
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	board[3][2] = 3;
	return humans.confirm_start(board, 3, 2);
}



// General functions



void set_up_board(int board[8][8], Piece* display_board[8][8]) // sets up board with pieces in starting position
{
	/*
	in 2D array:
	0 = empty
	1 = pawn
	2 = rook
	3 = knight
	4 = bishop
	5 = queen
	6 = king
	11 = en passant square

	positive or negative indicates humans or aliens, respectively

	*/
	// make every space empty at first

	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = 0;
			display_board[row][col] = nullptr;
		}
	}

	// then establish pieces

	// establish pawns

	for (int col = 0; col < 8; col++)
	{
		board[1][col] = -1;
		board[6][col] = 1;
		display_board[1][col] = new Pawn(row_to_y(1), col_to_x(col), -1); // fix equations later
		display_board[6][col] = new Pawn(row_to_y(6), col_to_x(col), 1);
	}

	//establish rooks

	board[0][0] = -2;
	board[0][7] = -2;
	board[7][0] = 2;
	board[7][7] = 2;
	display_board[0][0] = new Rook(row_to_y(0), col_to_x(0), -1);
	display_board[0][7] = new Rook(row_to_y(0), col_to_x(7), -1);
	display_board[7][0] = new Rook(row_to_y(7), col_to_x(0), 1);
	display_board[7][7] = new Rook(row_to_y(7), col_to_x(7), 1);

	//establish knights

	board[0][1] = -3;
	board[0][6] = -3;
	board[7][1] = 3;
	board[7][6] = 3;
	display_board[0][1] = new Knight(row_to_y(0), col_to_x(1), -1);
	display_board[0][6] = new Knight(row_to_y(0), col_to_x(6), -1);
	display_board[7][1] = new Knight(row_to_y(7), col_to_x(1), 1);
	display_board[7][6] = new Knight(row_to_y(7), col_to_x(6), 1);

	//establish bishops

	board[0][2] = -4;
	board[0][5] = -4;
	board[7][2] = 4;
	board[7][5] = 4;
	display_board[0][2] = new Bishop(row_to_y(0), col_to_x(2), -1);
	display_board[0][5] = new Bishop(row_to_y(0), col_to_x(5), -1);
	display_board[7][2] = new Bishop(row_to_y(7), col_to_x(2), 1);
	display_board[7][5] = new Bishop(row_to_y(7), col_to_x(5), 1);

	//establish queens

	board[0][3] = -5;
	board[7][3] = 5;
	display_board[0][3] = new Queen(row_to_y(0), col_to_x(3), -1);
	display_board[7][3] = new Queen(row_to_y(7), col_to_x(3), 1);

	//establish kings

	board[0][4] = -6;
	board[7][4] = 6;
	display_board[0][4] = new King(row_to_y(0), col_to_x(4), -1);
	display_board[7][4] = new King(row_to_y(7), col_to_x(4), 1);
}

void copy_board(int source[8][8], int destination[8][8]) // deep copy 2D array source to destination
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			destination[row][col] = source[row][col];
		}
	}
}

// 4 conversion functions that use simple formulas to convert back and forth between array indices and pixel locations

int y_to_row(int y)
{
	return (y - 217) / 60.5;
}

int x_to_col(int x)
{
	return (x - 98) / 59.5;
}

int row_to_y(int row)
{
	return 247 + row * 60.5;
}

int col_to_x(int col)
{
	return 128 + col * 59.5;
}

void print_board(int board[8][8]) // for debugging. prints 2D array
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (board[row][col] >= 0)
			{
				cout << " ";
			}
			cout << board[row][col];
		}
		cout << endl;
	}
	cout << endl;
}


// converts a piece's position (row 7-0, col 0-7) to letter and number (row 1-8, col A-H). for printing out where a piece moves to
string convert_to_letter_number(int row2, int col2)
{
	char let = col2 + 65; // converts col to correct letter
	char num = '0' + (8 - row2); // converts row to correct number

	// puts them into a string and returns it
	string converted;
	converted += let;
	converted += num;

	return converted;
}

// for printing out the piece that moved and piece that was destroyed, if there is one
string convert_to_piece_name(int board[8][8], int row, int col)
{
	switch (board[row][col]) {
	case 1:
	case 11:
		return "Repawn Drone";
	case 2:
		return "NASA Roocket";
	case 3:
		return "Night Fighter";
	case 4:
		return "Air Biship";
	case 5:
		return "Space Needle";
	case 6:
		return "Air Force One";
	case -1:
	case -11:
		return "Escape Pawn";
	case -2:
		return "Ragnarook";
	case -3:
		return "KryptoKnight";
	case -4:
		return "Star Biship";
	case -5:
		return "Xenomorph Queen";
	case -6:
		return "High Prophet";
	}
	return "Missing"; // for debugging
}

// fill board with zeroes (usually for resetting possible_moves array)
void initialize_board(int board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
}