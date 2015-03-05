#include <stdio.h>
#include "models/stack.h"
#include "models/cardset.h"
#include "test.h"

#ifdef ENABLE_TESTS

void play() {
	// cardTest();
	stackTest();
}

void stackTest () {
	printf ("Stack test!\n");
}

void cardTest () {
	cardSet *card = CreateCardSet();

	printf("You have %d %s cards.\n", GetNumCards(card), GetCardName(card));

	SetCardType(card, SEAHORSE);
	AddCards(card, 1);

	printf("You have %d %s cards.\n", GetNumCards(card), GetCardName(card));

	DestructCard(card);
}

#endif