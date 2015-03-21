#ifndef MOVEHISTORY_H_
#define MOVEHISTORY_H_

#include "models/stack.h"
#include "models/cardset.h"
#include "models/carddeck.h"
#include "models/player.h"

typedef struct move {
	int requestorNumber;
	int requesteeNumber;
	player *requestor; // This should be an independent copy of the player as it existed just after the move was executed.
	player *requestee; // The Destruct method should release this memory.
	cardType card;
	int count;
} move;

typedef stack history;

/**
 * Create a move object.
 *
 * @param player **p The player list.
 * @param int requestorNumber The index of the requesting player.
 * @param int requesteeNumber The index of the rquesting player.
 * @param cardType card The card type requested.
 * @param int count The number of cards switched from the requestee to the requestor.
 *
 * @return A move object.
 */
move* CreateMove (player **p, int requestorNumber, int requesteeNumber, cardType card, int count);

/**
 * Add a move to the history.
 *
 * @param history *mh The history stack object.  If this is NULL, assumes this is the first item and initializes the history.
 * @param move *mv The move object.
 *
 * @return history* The history object.
 */
history* AddMove (history *mh, move *mv);

/**
 * See the last move.  Don't destroy the object.
 *
 * @param history *mh The history stack object.
 * @return move* The last move object.
 */
move* SeeLastMove (history *mh);

/**
 * Undo the last move.  Frees the memory.
 * Don't implement this yet.  Not sure if it'll be used.
 * Will also have to put things back.
 *
 * @param history *mh The history stack object.
 *
 * @return 1 if successful, 0 otherwise.
 */
// int UndoLastMove (history *mh);

/**
 * Returns a new history stack containing the last moves for the given player in descending order.
 * The returned history is all new memory.  Make sure to destroy it with DestructHistory()
 *
 * @param history *mh The history stack object.
 * @param int requestorNumber The index of the player whos last moves to return
 *
 * @return history* The set of moves.
 */
// history* GetLastMoveSetFor (history *mh, int requestorNumber);

/**
 * Frees the history stack and all of it's moves.
 * Call DestructPlayer on both requestor and requestee, then free requestor and requestee and set to null.
 * Frees the stack memory too by calling DestructStack (mh), then sets mh to null.
 *
 * @param history *mh The history stack object.
 */
void DestructHistory (history *mh);

#endif