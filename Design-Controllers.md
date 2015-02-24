## Initialize
* Create Player List
* Give 5 random cards to each player from the dealer deck
  
## Play
* Give game state to the view
* Get player input from the view  
* Handle the action
  * Quit:
    Quit the game  
  * Request Card:      

    Does requestee have the card?
		Yes
			GetCards from requestee
			Give them to requestor
			Set result message

		Win Check
			(false if any player has playable cards)
		No
			Set result message
    Make history log      
    
* Give result to the view  
* Loop