## CardSet

A set of one card type.

* cardTypes enum

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

* typecard CardSet struct

````c
typedef struct {
	cardType type;
	int numCards;
} cardSet;
````

#### Functions

* cardType GetCardType (cardSet*)

Returns the card type (necessary? or should we just access it directly)

* int GetNumCards (cardSet*)

Gets the number of cards in the set (necessary? or should we just access it directly)

* bool RemoveCards (cardSet*, count)

Removes count cards from the given card set.  Returns true if successful, false otherwise.
If count > card.numCards, or if count < 0, then false.

* AddCards (cardSet*, count)

Adds count cards to the given card set.

## Card Deck

List of Cards (similar to a player)

Needs rand (stdlib.h)

#### Functions

* cardType GetRandomCard()

Removes and returns a random card from the deck.

* void AddCards (cardType, count)

Add count cards of cardType type to the deck.

* int RemoveCares (cardType)

Removes all of the cards of type cardType from the deck and
returns the #removed.

* bool HasType (cardType)

Returns true if the deck contains at least one of cardType, false otherwise.


## Move History

The history of moves.

List of move structs.

````c
typdef struct {
	player requestor;
	player requestee;
	cardType card;
	int count;
} move;
	
````

#### Functions

* bool AddMove (move)

Adds a move to the history list.  Returns true if successful.

* bool UndoLastMove ()

Removes the last move from the history.  Returns true if successful.
Don't implement this yet ... not sure if we'll use it.

* history GetLastMoveSetFor (player)

Returns the most recent set of moves for the given player.
A player may make several moves before the turn is over.

## Player

````c
typedef struct {
	cardSet[10] deck; // Best way to do this?  Easiest method: cardSet[10] deck;
	char* name;
	int playerType; // (0 for human, 1 for computer ... will only do 0's for now)	
} player;

````

#### Functions

* bool DoYouHaveAny (player, cardType)

Returns true if player has any of cardType in the deck.

* void AddCards(player, cardType, count)

Adds count cardTypes to players cardDeck.

* int TakeCards (player, cardType)

Removes all of cardType from the players cardDeck and returns the numCards removed.

* cardDeck GetBookList (player)

Returns a list of cardTypes where the player has all 4 cards  (Is this necessary?)

* bool HasPlayableCards (player)

Returns true if the player has any cards not in a book
