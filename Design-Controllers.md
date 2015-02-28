## Variables
````c
#include stdlib.h; // for rand
#include "headers/models/Stack.h";
#include "headers/models/model/CardSet.h";
#include "headers/models/CardDeck.h";
#include "headers/models/Player.h";
#include "headers/models/History.h";
#include "headers/view/Main.h";
#include "headers/controllers/Main.h";

int maxPlayers = 0;
int currentPlayer = 0;
cardSet[MAX_CARD_TYPES] dealerDeck;

int playerCount;
player *players = null;
````

#### Functions

* void Initialize()

	Initializes the game.

	```c
	// Initialize dealer deck cards.
	for(int i = 0; i < MAX_CARD_TYPES; i++) {
		AddCards(&cardSet[i],MAX_CARDS_PER_SET);
	}
	````

	Creates player list.

	````c
	playerCount = GetNumPlayers();
	players = malloc(playerCount * sizeof(player));
	````
	Divies 5 random cards from the deck to each player.

* void Play()

	The main play loop.

	Give game state to the view
	Get player input from the view  
	Handle the action
	Quit:

	  Quit the game  

	Request Card:      

	 Does requestee have the card?

	 Yes
	 GetCards from requestee
	 Give them to requestor
	 Set result message
	 
	 Win Check
	 (false if any player has playable cards)

	 No
	 Set result message
	 Make history log      
	    
	Give result to the view  
	Loop

* move* HandlePlayerAction (playerAction action)

	Returns a move object with the result of the action or null.