Models
	CardSet
	
		A set of one card type.
	
		typecard CardSet struct
			type
			numCards
		
		cardTypes enum
			typedef
			MAX_CARD_TYPES is last value which eq the previous
		
		Functions
			// Returns the card type (necessary? or should we just access it directly)
			cardType GetCardType (card*)
		
			// Gets the number of cards in the set (necessary? or should we just access it directly)
			int GetNumCards (card*)
		
			// Removes count cards from the given card set.  Returns true if successful, false otherwise.
			// If count > card.numCards, or if count < 0, then false.
			bool RemoveCards (card*, count)
		
			//	Adds count cards to the given card set.
			AddCards (card*, count)
		
	Card Deck
		
		List of Cards (similar to a player)
		
		Needs rand (stdlib.h)
		
		Functions
		
			// Removes and returns a random card from the deck.
			cardType GetRandomCard()
		
			// Add count cards of cardType type to the deck.
			void AddCards (cardType, count)
		
			// Removes all of the cards of type cardType from the deck and
			// returns the #removed.
			int RemoveCares (cardType)
		
			// Returns true if the deck contains at least one of cardType, false otherwise.
			bool HasType (cardType)
		
	Move History
	
		The history of moves.
		
		List of move structs.
		
		(typedef?) move struct
			player requestor
			player requestee
			cardType card
			int count
			
		Functions
		
			// Adds a move to the history list.  Returns true if successful.
			bool AddMove (move)
		
			// Removes the last move from the history.  Returns true if successful.
			// Don't implement this yet ... not sure if we'll use it.
			bool UndoLastMove ()
		
			// Returns the most recent set of moves for the given player.
			// A player may make several moves before the turn is over.
			history GetLastMoveSetFor (player)
		
	Player
	
		player struct
			cardDeck
			char* name
			int playerType (0 for human, 1 for computer ... will only do 0's for now)
			
		Functions
			
			// Returns true if player has any of cardType in the deck.
			bool DoYouHaveAny (player, cardType)
			
			// Adds count cardTypes to players cardDeck.
			void AddCards(player, cardType, count)
			
			// Removes all of cardType from the players cardDeck and returns the numCards removed.
			int TakeCards (player, cardType)
			
			// Returns a list of cardTypes where the player has all 4 cards  (Is this necessary?)
			cardDeck GetBookList (player)
			
			// Returns true if the player has any cards not in a book
			bool HasPlayableCards (player)