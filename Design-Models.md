## CardSet

A set of one card type.

* cardTypes

````c
enum cardType_t { BLUETANG, CLOWNFISH, DOLPHIN, LOBSTER, OCTOPUS, SEAHORSE, SHARK, STARFISH, STINGRAY, WHALE, MAX_CARD_TYPES }
typedef enum cardType_t cardType;
````

* cardNames

````c
const char *cardName[] = {
	[BLUETANG] = 'Blue Tang',
	[CLOWNFISH] = 'Clownfish',
	[DOLPHIN] = 'Dolphin',
	[LOBSTER] = 'Lobster',
	[OCTOPUS] = 'Octopus',
	[SEAHORSE] = 'Seahorse',
	[SHARK] = 'Shark',
	[STARFISH] = 'Starfish',
	[STINGRAY] = 'Stingray',
	[WHALE] = 'Whale'
};
````

* CardSet

````c
#define MAX_CARDS_PER_SET 4

typedef struct {
	int numCards;
} cardSet;
````

#### Functions

* cardType GetCardType (cardSet *card)

	Returns the card type (necessary? or should we just access it directly)

* int GetNumCards (cardSet *card)

	Gets the number of cards in the set (necessary? or should we just access it directly)

* bool RemoveCards (cardSet *card, int count)

	Removes count cards from the given card set.  Returns true if successful, false otherwise.
	If count > card.numCards, or if count < 0, then false.

* AddCards (cardSet *card, int count)

	Adds count cards to the given card set.

## Card Deck

List of Cards (similar to a player)

Needs rand (stdlib.h)

````c
cardSet[MAX_CARD_TYPES] dealerDeck;

// Initialize dealer deck cards.
for(int i = 0; i < MAX_CARD_TYPES; i++) {
	AddCards(&cardSet[i],MAX_CARDS_PER_SET);
}
````

#### Functions

* cardType GetRandomCard()

	Removes and returns a random card from the deck.

* void AddCards (cardType ct, int count)

	Add count cards of cardType type to the deck.

* int RemoveCares (cardType ct)

	Removes all of the cards of type cardType from the deck and
	returns the number removed.

* bool HasType (cardType ct)

	Returns true if the deck contains at least one of cardType, false otherwise.

## Player

````c
typedef struct {
	cardSet[MAX_CARD_TYPES] deck; // Best way to do this?  Easiest method: cardSet[MAX_CARD_TYPES] deck;
	char *name;
	int playerType; // (0 for human, 1 for computer ... will only do 0's for now)	
} player;


#define MAX_PLAYERS 4;
int playerCount;
````

#### Functions

* bool DoYouHaveAny (player *p, cardType ct)

	Returns true if player has any of cardType in the deck.

* void AddCards(player *p, cardType ct, int count)

	Adds count cardTypes to players cardDeck.

* int TakeCards (player *p, cardType ct)

	Removes all of cardType from the players cardDeck and returns the numCards removed.

* cardDeck GetBookList (player *p)

	Returns a list of cardTypes where the player has all 4 cards  (Is this necessary?)

* bool HasPlayableCards (player *p)

	Returns true if the player has any cards not in a book

* void DestructPlayers (players *p)
	
	Free player memory including the name char*.
	
	````c
	player *players = malloc(playerCount * sizeof(player));

	for (int i = 0; i < numPlayers; i++) {
		free (player[i].name);
	}

	free (players);
	````

## Move History

The history of moves.

List of move structs.

````c
typdef struct {
	player *requestor; // History code should not delete the player memory ... player model will take care of that.
	player *requestee; // Just set it to null.
	cardType card;
	int count;
} move;

move *history;
````

#### Functions

* bool AddMove (player* requestor, player* requestee, cardType card, int count)

	Adds a move to the history list.  Returns true if successful.

* move* UndoLastMove ()

	Removes the last move from the history.  Returns true if successful.
	Don't implement this yet ... not sure if we'll use it.
	Will also have to pu stuff back 

* move* GetLastMoveSetFor (player *p)

	Returns the most recent set of moves for the given player.
	A player may make several moves before the turn is over.
	But, how do we know how many records are in the set?
	And who manages the memory?

* void DestructHistory (move *mv)

	Free the move memory.
	Sets the requestor and requestee to null.  That memory is handled by the player model.