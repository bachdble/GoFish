#include <stdlib.h>
#include "models/player.h"
#include "models/movehistory.h"

// Stack from Utils.h
// history *moveHistory;

move* CreateMove (player **p, int requestorNumber, int requesteeNumber, cardType card, int count) {
	move *tempMove = NULL;

	if(p != NULL) {
		tempMove = malloc(sizeof(move));

		tempMove->requestorNumber = requestorNumber;
		tempMove->requesteeNumber = requesteeNumber;
		tempMove->card = card;
		tempMove->count = count;
		tempMove->requestor = CopyPlayer(p[requestorNumber]);
		tempMove->requestee = CopyPlayer(p[requesteeNumber]);
	}

	return tempMove;
}

history* AddMove (history *mh, move *mv) {
	if(mh == NULL) {
		mh = InitStack(mv);
	} else {
		Push(&mh, mv);
	}

	return mh;
}

move* SeeLastMove (history *mh) {
	return Peek(&mh);
}

// int UndoLastMove (history *mh) {
// }

// history* GetLastMoveSetFor (history *mh, int requestorNumber) {
// 	return NULL;
// }

void DestructHistory (history *mh) {
	move *tempMove = NULL;
	player *tempPlayer = NULL;

	do {
		tempMove = Pop(&mh);

		tempPlayer = tempMove->requestor;
		DestructPlayer (tempPlayer);

		tempPlayer = tempMove->requestee;
		DestructPlayer (tempPlayer);

		free(tempMove);
	} while (mh != NULL);

	tempMove = NULL;
	tempPlayer = NULL;
}