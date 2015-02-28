#include "models/cardset.h"

#define MAX_CARDS_PER_SET 4

enum cardType_t {
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
};

typedef enum cardType_t cardType;

typedef struct {
	int numCards;
} cardSet;


/**
 * Returns the card type of the give card. 
 *
 * @param card A pointer to a card.
 * @return The card type
 */
cardType GetCardType (cardSet *card);

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







