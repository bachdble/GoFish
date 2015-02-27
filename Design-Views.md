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

* void ShowPlayerState (<params?>)

	Cards, sorted: count and type
	TODESIGN

* void ShowGameState (<params?>)

	Other Player names (& type, eventually)

	cards
	books
	card requests from their last turn: what, who, result
	TODESIGN
			
* playerAction GetPlayerAction (player *p)

	options:
	
	Quit
	Ask for card from <player> (repeated for each oponent)

	````c
	enym playerAction_t {QUIT, ASK_FOR_CARD}
	typedef enum playerAction_t playerAction;
	````
	TODESIGN

		
* void ShowActionResult (<params?>)

	(w/ pause? for taking turns since it's played on the same compy)
	"You got n cardType(s)"
	and possibly: "You got another book!"
	or
	"Go Fish!"
	TODESIGN
