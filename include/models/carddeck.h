#ifndef CARDDECK_H_
#define CARDDECK_H_

#include "models/cardset.h"

// cardSet dealerDeck[MAX_CARD_TYPES];
cardSet *dealerDeck;

/**
 * Initializes the card deck.
 *
 * @param cardSet* deck The deck.
 */
cardSet* CreateDeck();

/**
 * Removes and returns a random card from the deck.
 *
 * @param cardSet* deck The deck.
 *
 * @return A random cardType from the deck.
 */
cardType GetRandomCardFromDeck(cardSet* deck);

/**
 * Add count cards of cardType type to the deck.
 *
 * @param cardSet* deck The deck.
 * @param cardType ct A card type.
 * @param int count The number of cards to add.
 */
void AddCardsToDeck (cardSet* deck, cardType ct, int count);

/**
 * Removes all of the cards of type cardType from the deck and
 *
 * @param cardSet* deck The deck.
 * @param cardType ct The type of card to remove.
 *
 * @return The number removed.
 */
int RemoveCardsFromDeck (cardSet* deck, cardType ct);

/**
 * Returns true if the deck contains at least one of cardType, false otherwise.
 *
 * @param cardSet* deck The deck.
 * @param cardType ct The card to check for.
 *
 * @return 1 if the card exists, 0 otherwise
 */
int DeckHasType (cardSet* deck, cardType ct);

/**
 * Frees the memory of a previously allocated a cardSet*
 *
 * @param cardSet* deck The Deck to free.
 *
 */
void DestructDeck (cardSet* deck);

#endif