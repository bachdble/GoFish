#include <stdlib.h>
#include "models/cardset.h"

const char *cardNames[] = {
	[BLUETANG] = "Blue Tang",
	[CLOWNFISH] = "Clownfish",
	[DOLPHIN] = "Dolphin",
	[LOBSTER] = "Lobster",
	[OCTOPUS] = "Octopus",
	[SEAHORSE] = "Seahorse",
	[SHARK] = "Shark",
	[STARFISH] = "Starfish",
	[STINGRAY] = "Stingray",
	[WHALE] = "Whale"
};

cardSet* CreateCardSet () {
	cardSet *newCard;

	newCard = malloc(sizeof(cardSet));

	newCard->type = BLUETANG;
	newCard->numCards = 0;

	return newCard;
}

cardType GetCardType (cardSet *card) {
	return card->type;
}

const char *GetCardName (cardSet *card) {
	return cardNames[GetCardType(card)];
}

int SetCardType (cardSet *card, cardType type) {
	if(type > 0 && type < MAX_CARD_TYPES) {
		card->type = type;
		return 1;
	}

	return 0;
}

int GetNumCards (cardSet *card) {
	return card->numCards;
}

int RemoveCards (cardSet *card, int count) {
	if (count > card->numCards || count < 0) {
		return 0;
	}

	card->numCards = card->numCards - count;
	return 1;
}

int AddCards (cardSet *card, int count) {
	int temp;
	temp = card->numCards + count;

	if(count > 0 && temp <= MAX_CARDS_PER_SET) {
		card->numCards = temp;
		return 1;
	}

	return 0;
}

void DestructCard (cardSet *card) {
	free (card);
	card = NULL;
}






