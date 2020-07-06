#include "PA9.h"

int main(void)
{
	// run test functions
	Test test_functions;


	int game_state = 0; // changes to 1 if checkmate and 2 if stalemate

	// terminal1 and terminal2 hold strings that display relevant messages. They are updated throughout the game
	string terminal1 = "Welcome to Space Chess!";
	string terminal2 = "Aliens have invaded! Humans have first strike advantage.";

	//establish players
	Player humans = {1, 7, 4 };
	Player aliens = {-1, 0, 4 };
	int turn = 1; // 1 when it's humans' turn, -1 when it's aliens' turn

	//establish 2 boards - one for the chess computational algorithms, and a parallel board for displaying of chess pieces using SFML
	int board[8][8]; // 2D int array for chess computations
	Piece* display_board[8][8]; // 2D array of pointers to Piece objects for display purposes. This is why virtual functions are necessary for derived methods

	set_up_board(board, display_board);


	Piece* grabbed_piece = nullptr; // points to piece object that's being dragged
	int is_piece_grabbed = false; // becomes true while piece is being dragged

	int row1, col1, row2, col2; // designates 

	int needs_evaluation = 0; // 0 if nothing has changed, 1 if it has. Checkmate/stalemate is checked whenever this is 1.

	// pieces displayed for promotion

	Rook human_rook(150, 245, 1);
	Knight human_knight(150, 305, 1);
	Bishop human_bishop(150, 365, 1);
	Queen human_queen(150, 425, 1);

	Rook alien_rook(750, 245, -1);
	Knight alien_knight(750, 305, -1);
	Bishop alien_bishop(750, 365, -1);
	Queen alien_queen(750, 425, -1);


	//Create Window
	sf::RenderWindow window(sf::VideoMode(673, 793), "Space Chess");
	window.setFramerateLimit(30);

	// font for display text
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Arial font not loaded";
	}

	// setting up white text in top left of screen. 2 variables are set for secondary messages 
	sf::Text text1;
	sf::Text text2;
	text1.setFont(font);
	text2.setFont(font);
	text1.setCharacterSize(23);
	text2.setCharacterSize(23);
	text1.setFillColor(sf::Color::White);
	text2.setFillColor(sf::Color::White);
	text1.setPosition(5, 0);
	text2.setPosition(5, 30);

	// get background image
	sf::Texture background_texture;
	if (!background_texture.loadFromFile("ChessBackground.jpg"))
	{
		cout << "Background was not loaded properly";
	}

	// convert background image to sprite
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture);

	//Game Loop
	while (window.isOpen())
	{
		
		int x = sf::Mouse::getPosition(window).x;
		int y = sf::Mouse::getPosition(window).y;

		if (y > 222 && y < 704)
		{
			if (x > 63 && x < 83) // if mouse goes through orange wormhole
			{
				sf::Mouse::setPosition(sf::Vector2i(568, y), window); // come out orange wormhole
			}
			if (x > 589 && x < 609) // if mouse goes through orange wormhole
			{
				sf::Mouse::setPosition(sf::Vector2i(103, y), window); // come out blue wormhole
			}
		}

		if (needs_evaluation && !humans.get_promotion() && !aliens.get_promotion()) // a turn just finished and promotion is not pending
		{
			if (turn == 1) // human turn
				game_state = humans.evaluate_board(board, terminal1, terminal2); // determine if continue game
			else // alien turn
				game_state = aliens.evaluate_board(board, terminal1, terminal2);
			needs_evaluation = 0;
		}


		sf::Event event;
		while (window.pollEvent(event))
		{


			if ((sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle)) && game_state == 0) // if right or middle mouse clicked and game still going
			{
				if (is_piece_grabbed) // and piece grabbed
				{
					// drop piece back in original spot
					is_piece_grabbed = false; 
					display_board[row1][col1] = grabbed_piece;
					display_board[row1][col1]->update_flame_position(row_to_y(row1), col_to_x(col1));
					display_board[row1][col1]->update_ship_position(row_to_y(row1), col_to_x(col1));
				}
			}


			if (event.type == sf::Event::MouseButtonPressed && !sf::Mouse::isButtonPressed(sf::Mouse::Right) && !sf::Mouse::isButtonPressed(sf::Mouse::Middle) && game_state == 0) // if left button pressed and game still going
			{

				x = sf::Mouse::getPosition(window).x;
				y = sf::Mouse::getPosition(window).y;

				int piece_promoted = 0;

				if (humans.get_promotion()) // if humans can promote
				{
					if (y > 120 && y < 180 && x > 215 && x < 455) // if clicked in promotion box
					{
						terminal2 = "";
						if (x < 275) // if clicked rook
						{
							piece_promoted = 2;
							terminal1 = "NASA Roocket rescued from the Mothership Hanger!";
						}
						else if (x < 335) // if clicked knight
						{
							piece_promoted = 3;
							terminal1 = "Night Fighter rescued from the Mothership Hanger!";
						}
						else if (x < 395) // if clicked bishop
						{
							piece_promoted = 4;
							terminal1 = "Air Biship rescued from the Mothership Hanger!";
						}
						else // if clicked queen
						{
							piece_promoted = 5;
							terminal1 = "Space Needle rescued from the Mothership Hanger!";
						}
						humans.finish_promotion(board, display_board, piece_promoted); // set promotion to false and promote the piece
					}
				}
				else if (aliens.get_promotion()) // same as above but for aliens
				{
					if (y > 720 && y < 780 && x > 215 && x < 455)
					{
						terminal2 = "";
						if (x < 275)
						{
							piece_promoted = 2;
							terminal1 = "Ragnarook retrieved from Area 51!";
						}
						else if (x < 335)
						{
							piece_promoted = 3;
							terminal1 = "KryptoKnight retrieved from Area 51!";
						}
						else if (x < 395)
						{
							piece_promoted = 4;
							terminal1 = "Star Biship retrieved from Area 51!";
						}
						else
						{
							piece_promoted = 5;
							terminal1 = "Xenomorph Queen retrieved from Area 51!";
						}
						aliens.finish_promotion(board, display_board, piece_promoted);
					}
				}
				else // normal gameplay proceeds
				{
					if (y > 217 && y < 700 && x > 98 && x < 574) // if clicked on board
					{

						row1 = y_to_row(y); // convert click to row and col start
						col1 = x_to_col(x);

						if (turn == 1)
						{
							if (humans.confirm_start(board, row1, col1))
							{
								is_piece_grabbed = true; // now dragging a piece
								grabbed_piece = display_board[row1][col1]; // grabbed_piece now points to that piece
								display_board[row1][col1] = nullptr; // its original space now appears empty
							}
						}
						else
						{
							if (aliens.confirm_start(board, row1, col1)) // same as above
							{
								is_piece_grabbed = true;
								grabbed_piece = display_board[row1][col1];
								display_board[row1][col1] = nullptr;
							}
						}
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Right) && !sf::Mouse::isButtonPressed(sf::Mouse::Middle) && game_state == 0) // if left click is released and game is still playing
			{

				x = sf::Mouse::getPosition(window).x; // collect current mouse coordinates
				y = sf::Mouse::getPosition(window).y;

				if (is_piece_grabbed) // if dragging piece
				{
					if (y > 220 && y < 700 && x > 95 && x < 575) // if clicked board
					{
						row2 = y_to_row(y); // convert to row and col end position
						col2 = x_to_col(x);

						if (turn == 1) // humans' turn
						{
							if (humans.make_move(board, display_board, row1, col1, row2, col2, terminal1, terminal2)) // move was able to be made
							{
								turn = -1;
								needs_evaluation = 1;
							}
							else // make piece go back to spot it was picked up from
							{
								display_board[row1][col1] = grabbed_piece;
								display_board[row1][col1]->update_flame_position(row_to_y(row1), col_to_x(col1));
								display_board[row1][col1]->update_ship_position(row_to_y(row1), col_to_x(col1));
							}
						}
						else // aliens' turn
						{
							if (aliens.make_move(board, display_board, row1, col1, row2, col2, terminal1, terminal2))
							{
								turn = 1;
								needs_evaluation = 1;
							}
							else
							{
								display_board[row1][col1] = grabbed_piece;
								display_board[row1][col1]->update_flame_position(row_to_y(row1), col_to_x(col1));
								display_board[row1][col1]->update_ship_position(row_to_y(row1), col_to_x(col1));
							}
						}
					}
					else // piece was grabbed but it wasn't set on the board
					{
						// put piece back in original position and display relevant print statement
						display_board[row1][col1] = grabbed_piece;
						display_board[row1][col1]->update_flame_position(row_to_y(row1), col_to_x(col1));
						display_board[row1][col1]->update_ship_position(row_to_y(row1), col_to_x(col1));
						terminal1 = "Ships must stay in the asteroid field!";
						terminal2 = "";
					}
				}
				is_piece_grabbed = false; // no longer draggin gpiece
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Render
		window.clear();
		window.draw(background_sprite);
		text1.setString(terminal1);
		text2.setString(terminal2);
		window.draw(text1);
		window.draw(text2);
		
		// draw the pieces sitting on the board, but not the flames since it isn't "flying" (being dragged around)
		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				if (display_board[row][col] != nullptr) // if not empty space
				{
					display_board[row][col]->display_ship(window);
				}
			}
		}

		if (is_piece_grabbed) //dragging piece
		{
			// constantly redisplay the piece in the new mouse position to let viewer see it be dragged arround
			grabbed_piece->update_flame_position(sf::Mouse::getPosition(window).y, sf::Mouse::getPosition(window).x);
			grabbed_piece->update_ship_position(sf::Mouse::getPosition(window).y, sf::Mouse::getPosition(window).x);
			grabbed_piece->display_flames(window);
			grabbed_piece->display_ship(window);
		}

		if (humans.get_promotion()) // humans can promote
		{
			// display ships on the mothership that can be selected (no flames)
			human_rook.display_ship(window);
			human_knight.display_ship(window);
			human_bishop.display_ship(window);
			human_queen.display_ship(window);
		}

		if (aliens.get_promotion()) // aliens can promote
		{
			// display ships on Earth that can be selected (no flames)
			alien_rook.display_ship(window);
			alien_knight.display_ship(window);
			alien_bishop.display_ship(window);
			alien_queen.display_ship(window);
		}
	
		window.display();
	}
	return 0;
}