#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "models/carddeck.h"
#include "models/player.h"

player** CreatePlayerList(int numPlayers) {
	player **tempPlayerList = NULL;

	if (numPlayers > 0 && numPlayers <= MAX_PLAYERS) {
		tempPlayerList = malloc (sizeof(player*)*numPlayers);
		for(int i = 0; i < numPlayers; i++) {
			tempPlayerList[i] = malloc(sizeof(player));
			tempPlayerList[i]->deck = CreateDeck(0);
		}
	}

	return tempPlayerList;
}

void SetPlayerName (player *p, char *name) {
	p->name = name;
}

int DoYouHaveAny (player *p, cardType ct) {
	if(!(p != NULL && p->deck != NULL && ct < MAX_CARD_TYPES)) {
		return 0;
	}
	return p->deck[ct]->numCards > 0 ? 1 : 0;
}

player *CopyPlayer (player *p) {
	player *tempPlayer = NULL;
	char *name = NULL;

	if(p != NULL) {
		tempPlayer = malloc(sizeof(player));

		name = malloc(sizeof(char)*strlen(p->name));
		SetPlayerName(tempPlayer, name);

		tempPlayer->deck = CreateDeck(0);

		for(int i = 0; i < MAX_CARD_TYPES; i++) {
			AddCardsToDeck(tempPlayer->deck, i, GetNumCards(p->deck[i]));
		}
	}

	return tempPlayer;
}

void GiveCards (player *p, cardType ct, int count) {
	if(p != NULL && p->deck != NULL && ct < MAX_CARD_TYPES && count >= 0) {
		AddCardsToDeck(p->deck, ct, count);
	}
}

int TakeCards (player *p, cardType ct) {
	int tookCount = 0;

	if(p != NULL && p->deck != NULL && ct < MAX_CARD_TYPES) {
		tookCount = RemoveCardsFromDeck(p->deck, ct);
	}

	return tookCount;
}

int HasPlayableCards (player *p) {
	int hasPlayable = 0;
	int numCards = 0;

	if(p != NULL && p->deck != NULL) {

		for(int i = 0; i < MAX_CARD_TYPES; i++) {
			numCards = GetNumCards(p->deck[i]);
			printf("Inside Has Playable Cards (%d)? %d\n", numCards, i);
			if(numCards > 0 && numCards < MAX_CARDS_PER_SET) {
				hasPlayable = 1;
				break;
			}
		}

	}

	return hasPlayable;
}

int CardCount(player *p) {
	int totalCards = 0;

	if(p != NULL && p->deck != NULL) {

		for(int i = 0; i < MAX_CARD_TYPES; i++) {
			totalCards += GetNumCards(p->deck[i]);
		}

	}

	return totalCards;
}

 void PrintPlayer(player *p) {
 	if(p != NULL) {
 		printf("Player: %s\n", p->name);
 		if(p->deck != NULL) {
 			PrintDeck(p->deck);
 		}
 	}
 }

void DestructPlayer (player *p) {
	if(p != NULL) {
		if(p->name != NULL) {
			free(p->name);
			p->name = NULL;		
		}

		if(p->deck != NULL) {
			DestructDeck(p->deck);
		}
		
		free (p);
		p = NULL;
	}
}

void DestructPlayerList (player **p, int numPlayers) {
	if(p != NULL) {
		for (int i = 0; i < numPlayers; i++) {
			if (p[i] != NULL) {
				DestructPlayer(p[i]);
			}
		}
		free (p);
		p = NULL;
	}
}

