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

Requires rand (stdlib.h)

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
#include "headers/models/CardSet.h";
#include "headers/models/CardDeck.h";

typedef struct {
	cardSet[MAX_CARD_TYPES] deck; // Best way to do this?  Easiest method: cardSet[MAX_CARD_TYPES] deck;
	char *name;
	int playerType; // (0 for human, 1 for computer ... will only do 0's for now)	
} player;


#define MAX_PLAYERS 4;

````

#### Functions

* bool DoYouHaveAny (player *p, cardType ct)

	Returns true if player has any of cardType in the deck.

* player *CopyPlayer (player *p)

	Returns a copy of player p.

* void AddCards(player *p, cardType ct, int count)

	Adds count cardTypes to players cardDeck.

* int TakeCards (player *p, cardType ct)

	Removes all of cardType from the players cardDeck and returns the numCards removed.

* cardDeck GetBookList (player *p)

	Returns a list of cardTypes where the player has all 4 cards  (Is this necessary?)

* bool HasPlayableCards (player *p)

	Returns true if the player has any cards not in a book

* int CardCount(player *p)

	Returns the total number of cards the player has.

* void DestructPlayer (player *p)

	Free memory for inside player object;

	````c
	free(player.name);
	````

* void DestructPlayers (players *p)
	
	Free player memory including the name char*.
	
	````c
	player *players = malloc(playerCount * sizeof(player));

	for (int i = 0; i < numPlayers; i++) {
		DestructPlayer(Player[i]);
	}

	free (players);
	````

## Move History

The history of moves.

List of move structs.

````c
typdef struct {
	int requestingPlayerNumber;
	int requesteePlayerNumber;
	player *requestor; // This should be an independent copy of the player as it existed just after the move was executed.
	player *requestee; // The Destruct method should release this memory.
	cardType card;
	int count;
} move;

// Stack from Utils.h
typedef stack history;

history *moveHistory;
````

#### Functions

* move* CreateMove (players *p, int requestorNumber, int requesteeNumber, cardType card, int count)

	Returns a new move object.

* void AddMove (history *mh, move *mv)

	Adds a move to the history list.

* bool UndoLastMove (history *mh)

	Removes the last move from the history.
	Returns true if successful.
	Don't implement this yet ... not sure if we'll use it.
	Will also have to put stuff back.

* history* GetLastMoveSetFor (history *mh, player *p)

	Returns a new history stack containing the last moves for the given player in descending order.
	And who frees the memory?  Use DestructHistory when on it done.

* void DestructHistory (history *mh)

	Free the move memory.
	Call DestructPlayer on both requestor and requestee, then free requestor and requestee and set to null.
	Frees the stack memory too by calling DestructStack (mh), then sets mh to null.






