#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "models/carddeck.h"

cardSet** CreateDeck(int numCards) {
	cardSet **tempDeck = NULL;
	
	if (numCards >= 0 && numCards <= MAX_CARDS_PER_SET) {
		tempDeck = malloc (sizeof(cardSet *)*MAX_CARD_TYPES);
		for(cardType i = 0; i < MAX_CARD_TYPES; i++) {
			tempDeck[i] = malloc (sizeof(cardSet));
			SetCardType (tempDeck[i], i);
			AddCards(tempDeck[i], numCards);
		}

		srand(time(NULL));
	}

	return tempDeck;
}

cardType GetRandomCardFromDeck(cardSet** deck) {
	cardType randType = 0;

	do {
		randType = rand() % MAX_CARD_TYPES;
	} while (GetNumCards(deck[randType]) <= 0);

	RemoveCards(deck[randType],1);

	return randType;
}

void AddCardsToDeck (cardSet** deck, cardType ct, int count) {
	if(ct < MAX_CARD_TYPES) {
		if (count > 0 && count < MAX_CARDS_PER_SET) {
			if ((GetNumCards(deck[ct]) + count) < MAX_CARDS_PER_SET) {
				AddCards(deck[ct], count);
			}
		}
	}
}

int RemoveCardsFromDeck (cardSet** deck, cardType ct) {
	int countRemoved = 0;

	if(ct < MAX_CARD_TYPES) {
		countRemoved = GetNumCards(deck[ct]);
		RemoveCards(deck[ct],countRemoved);
	}

	return countRemoved;
}

int DeckHasType (cardSet** deck, cardType ct) {
	int hasType = 0;

	if(ct < MAX_CARD_TYPES) {
		if(GetNumCards(deck[ct]) > 0) {
			hasType = 1;
		}
	}

	return hasType;
}

void PrintDeck (cardSet **deck) {
	for(cardType i = 0; i < MAX_CARD_TYPES; i++) {
		printf("%d %ss\n", GetNumCards(deck[i]), GetCardName(deck[i]));
	}
}

void DestructDeck (cardSet **deck) {
	for(cardType i = 0; i < MAX_CARD_TYPES; i++) {
		free(deck[i]);
		deck[i] = NULL;
	}
	free (deck);
	deck = NULL;
}
