#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/stack.h"
#include "models/cardset.h"
#include "models/carddeck.h"
#include "test.h"

#ifdef ENABLE_TESTS

void play() {
	// cardTest();
	// stackTest();
	cardDeckTest();
}

void printDeck (cardSet *deck) {
	for(cardType i = 0; i < MAX_CARD_TYPES; i++) {
		printf("%d %s's\n", GetNumCards(&deck[i]), GetCardName(&deck[i]));
	}
}

void cardDeckTest() {
	printf("Card Deck test!\n");

	cardType ct;


	dealerDeck = CreateDeck();

	printDeck(dealerDeck);

	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	ct = GetRandomCardFromDeck(dealerDeck);
	printf("Got a %s!\n", cardNames[ct]);
	printf("Has type a %s %d!\n", cardNames[ct], DeckHasType(dealerDeck,ct));;

	AddCardsToDeck(dealerDeck, ct, 1);
	printf("Got a %s!\n", cardNames[ct]);

	printDeck(dealerDeck);

	DestructDeck(dealerDeck);
}

void printIntStack (stack *stk) {
	stack *tempStk = stk;
	int *iptr;
	printf("Printing Stack:\n");
	while(tempStk != NULL) {
		iptr = Peek(tempStk);
		printf("%d\n", *iptr);
		tempStk = tempStk->next;
	}
	printf("\n");
}

void stackTest () {
	printf ("Stack test!\n");

	int *iptr = malloc(sizeof(int));
	*iptr = 10;
	stack *myStack = InitStack(iptr);
	printIntStack(myStack);

	iptr = malloc(sizeof(int));
	*iptr = 20;
	Push (&myStack, iptr);
	printIntStack(myStack);

	iptr = Pop (&myStack);
	free(iptr);
	printIntStack(myStack);

	iptr = Pop (&myStack);
	free(iptr);
	printIntStack(myStack);

	DestructStack(&myStack);
	printIntStack(myStack);

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