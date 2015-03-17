#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/stack.h"
#include "models/cardset.h"
#include "models/carddeck.h"
#include "models/player.h"
#include "test.h"

#ifdef ENABLE_TESTS

void play() {
	// pointerPlay();
	// cardTest();
	// stackTest();
	// cardDeckTest();
	playerTest();
}

void playerTest() {
	printf("Player test!\n");

	int numPlayers = 4;

	char *name = malloc(sizeof(char)*4);
	player *p1 = NULL;

	memcpy(name, "Joe", sizeof(char)*3);

	player **playerList = CreatePlayerList(numPlayers);

	SetPlayerName(playerList[0],name);

	PrintPlayer(playerList[0]);
	printf("Player has %s ? %s (%d total cards)\n", cardNames[1], (DoYouHaveAny(playerList[0], 1) ? "Yes" : "No"), CardCount(playerList[0]));

	GiveCards(playerList[0], BLUETANG, 4);
	GiveCards(playerList[0], CLOWNFISH, 1);
	GiveCards(playerList[0], SHARK, 1);
	PrintPlayer(playerList[0]);
	printf("Player has %s ? %s (%d total cards)\n", cardNames[1], (DoYouHaveAny(playerList[0], 1) ? "Yes" : "No"), CardCount(playerList[0]));

	printf("Took %d %ss\n", TakeCards(playerList[0], 1), cardNames[1]);
	printf("Player has %s ? %s (%d total cards)\n", cardNames[1], (DoYouHaveAny(playerList[0], 1) ? "Yes" : "No"), CardCount(playerList[0]));
	PrintPlayer(playerList[0]);

	printf("Has Playable Cards? %s\n", (HasPlayableCards(playerList[0]) ? "Yes": "No"));

	p1 = CopyPlayer(playerList[0]);

	DestructPlayerList(playerList, numPlayers);

	DestructPlayer(p1);
}

void cardDeckTest() {
	printf("Card Deck test!\n");

	cardType ct;


	dealerDeck = CreateDeck(MAX_CARDS_PER_SET);

	PrintDeck(dealerDeck);

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

	PrintDeck(dealerDeck);

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

void pointerPlayCh(intStruct *isp, int number) {
	isp->number = number;
}

void pointerPlay() {
	static int MAX = 10;
	intStruct **numArryP;

	numArryP = malloc(sizeof(intStruct*)*MAX);

	for(int i = 0; i < MAX; i++ ) {
		numArryP[i] = malloc(sizeof(intStruct));
		// '*' means to get the value of the pointer.
		// These two statements are synonymous.
		// (*numArryP[i]).number = i;
		// numArryP[i]->number = i;
		pointerPlayCh(numArryP[i],i);
		
		printf("%d\n", numArryP[i]->number);
	}

	for(int i = 0; i < MAX; i++ ) {
		free(numArryP[i]);
	}

	free (numArryP);
}

#endif