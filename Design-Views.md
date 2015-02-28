Needs stdio.h

## Probably used by the controller initializer

### Functions

* int GetNumPlayers ()

	Gets the number of players from the user up to MAX_PLAYERS.

* char* GetPlayerName ()

	Gets a player name from the user.  Allocates memory.  The player model will free it.

* playerType GetPlayerType ()

	Gets the player type from the user.  Either "Person" or "Computer".
	Will not implement now.

	````c
	enym playerType_t {PERSON, COMPUTER}
	typedef enum playerType_t playerType;
	````

* aiLevel GetAILevel ()

	Get the AI level from the user.
	Will not implement now.	

	````c
	enym aiLevel_t {BEGINNER_AI, INTERMEDIATE_AI, EXPERT_AI}
	typedef enum aiLevel_t aiLevel;
	````


## Probably used in the play loop

* void ShowPlayerState (player *p, bool showCards)

	Cards, sorted: count and type

	"%s\n\r", playerName
	"\tBooks\n"
	for each card where cardCount == 4
		"\t%d x %s\n\r", cardCount, CardName
	if no books printed, then print "No Books"
	if showCards
	"\tCards:\n"
	for each card where cardCount > 0 and cardCound < 4
		"\t%d x %s\n\r", cardCount, CardName
	if no cards printed, then print "No Cards"
	else
		print the total number of cards the player has (CardCount(p))
	"\n\r"

* void ShowGameState (history *h, player *currentPlayer)

	Other Player names (and type, eventually)

	(For each move, until we reach a move with the currentPlayer):
	The first time we see each player:
	ShowPlayerState(requestor, false)
	For each move:
	Show the result of the move: "%s requested from %s.  %d cards given. ", cardType, requesteePlayerNumber, count
	"\n\r"
			
* playerAction GetPlayerAction (player *p)

	options:
	
	Quit
	Ask for card from <player> (repeated for each oponent)

	````c
	enym playerAction_t {QUIT, ASK_FOR_CARD}
	typedef enum playerAction_t playerAction;
	````
		
* void ShowActionResult (move *mv)

	(w/ pause for taking turns since it's played on the same compy?)
	"You got n cardType(s)"
	and possibly: "You got another book!"
	or
	"Go Fish!"






