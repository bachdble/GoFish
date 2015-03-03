#include <stdio.h>
#include "models/cardset.h"
#include "test.h"

#ifdef ENABLE_TESTS

void play() {

	cardSet *card = CreateCardSet();

	printf("You have %d %s cards.\n", GetNumCards(card), GetCardName(card));

	SetCardType(card, SEAHORSE);
	AddCards(card, 1);

	printf("You have %d %s cards.\n", GetNumCards(card), GetCardName(card));

	DestructCard(card);
}

#endif