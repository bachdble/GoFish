#ifndef CARDSET_H_
#define CARDSET_H_

#define MAX_CARDS_PER_SET 4

typedef enum cardTypes {
	BLUETANG,
	CLOWNFISH,
	DOLPHIN,
	LOBSTER,
	OCTOPUS,
	SEAHORSE,
	SHARK,
	STARFISH,
	STINGRAY,
	WHALE,
	MAX_CARD_TYPES
} cardType;

extern const char *cardNames[];

// Defined in cardset.c:
//
// const char *cardNames[] = {
// 	[BLUETANG] = "Blue Tang",
// 	[CLOWNFISH] = "Clownfish",
// 	[DOLPHIN] = "Dolphin",
// 	[LOBSTER] = "Lobster",
// 	[OCTOPUS] = "Octopus",
// 	[SEAHORSE] = "Seahorse",
// 	[SHARK] = "Shark",
// 	[STARFISH] = "Starfish",
// 	[STINGRAY] = "Stingray",
// 	[WHALE] = "Whale"
// };

typedef struct cardSet {
	cardType type;
	int numCards;
} cardSet;


/**
 * Creates a new card.  Type and num initialized to BLUETANG and 0.
 * Allocated memory must be freed elsewhere.
 *
 * @return The a new card.
 */
cardSet* CreateCardSet ();

/**
 * Returns the card type of the give card. 
 *
 * @param card A pointer to a card.
 * @return The card type
 */
cardType GetCardType (cardSet *card);

/**
 * Returns the string value of the card type.  Do not free the memory.
 *
 * @param card A pointer to a card.
 * @return The card type string value.
 */
const char* GetCardName (cardSet *card);

/**
 * Returns the string value of the card type.  Do not free the memory.
 *
 * @param cardType card A card type
 * @return The card type string value.
 */
const char* GetCardNameFromType (cardType type);

/**
 * Sets the card type. 
 *
 * @param card A pointer to a card.
 * @return 1 if successful, 0 if not
 */
int SetCardType (cardSet *card, cardType type);

/**
 * Gets the number of cards in the set.
 *
 * @param card A pointer to a card.
 * @return The number of the give card in the set.
 */
int GetNumCards (cardSet *card);

/**
 * Removes count cards from the given card set.  Returns true if successful, false otherwise.
 * If count > card.numCards, or if count < 0, then false. 
 *
 * @param card A pointer to a card.
 * @param count The number of cards to remove.
 * @return 1 if successful.  0 otherwise.
 */
int RemoveCards (cardSet *card, int count);

/**
 * Adds count cards to the given card set. 
 * Total cards can't ge greater than MAX_CARDS_PER_SET
 *
 * @param card A pointer to a card.
 * @param count The number of cards to remove.
 * @return 1 if successful.  0 otherwise.
 */
int AddCards (cardSet *card, int count);

/**
 * Frees the memory of a previously allocated card.
 *
 * @return None
 */
void DestructCard (cardSet *card);

#endif





