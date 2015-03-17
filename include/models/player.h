#ifndef PLAYER_H_
#define PLAYER_H_

#include "models/cardset.h"
#include "models/carddeck.h"

#define MAX_PLAYERS 4
#define HUMAN 0
#define AI_1 1

typedef struct player {
	cardSet** deck;
	char *name;
	int playerType; // (0 for human, 1 for computer ... will only do 0's for now)	
} player;

/**
 * Creat a new player list.
 *
 * @param int numPlayers The number of players to create.
 *
 * @return A list of players.
 */
player** CreatePlayerList(int numPlayer);

/**
 * Sets the player's name
 *
 * @param player *p The player.
 * @param char *name The name to set.
 */
void SetPlayerName (player *p, char *name);

/**
 * Returns 1 if player has any of cardType in the deck, 0 otherwise.
 *
 * @param player *p The player object.
 * @param cardType ct The card type to test against.
 *
 * @return 1 if the player has any of cardType, 0 otherwise.
 */
int DoYouHaveAny (player *p, cardType ct);

/**
 * Returns a copy of player p.  The memory must be freed elsewhere.
 *
 * @param player *p A player object.
 *
 * @param A copy of the player object.
 */
player *CopyPlayer (player *p);

/**
 * Adds count cardTypes to players cardDeck.
 *
 * @param player *p A player object.
 * @param cardType ct The card type to add.
 * @param int count The number of cards to add.
 */
void GiveCards (player *p, cardType ct, int count);

/**
 * Removes all of cardType from the players cardDeck and returns the numCards removed.
 *
 * @param player *p The player object.
 * @param cardType ct The card type to take.
 *
 * @param The number of card removed.
 */
 int TakeCards (player *p, cardType ct);

/**
 * Returns a list of cardTypes where the player has all 4 cards  (Is this necessary?)
 * The memory must be freed elsewhere.
 *
 * @param player *p The player object.
 *
 * @param A new pointer to the cardDeck.
 */
 // cardDeck* GetBookList (player *p);

/**
 * Returns 1 if the player has any cards not in a book, 0 otherwise.
 *
 * @param player *p The player object
 *
 * @param 1 if the player has any playable cards, 0 otherwise.
 */
 int HasPlayableCards (player *p);

/**
 * Returns the total number of cards the player has.
 *
 * @param player *p The player object.
 *
 * @param The total number of cards the player has.
 */
 int CardCount(player *p);

/**
 * Prints the player info to the screen
 *
 * @param player *p The player object.
 */
 void PrintPlayer(player *p);

/**
 * Free memory for inside player object;
 *
 * @param player *p The player object.
 */
 void DestructPlayer (player *p);


/**
 * Free player memory including the name char*.
 *
 * @param player *p The list of all players.
 */
 void DestructPlayerList (player **p, int numPlayers);
	

#endif