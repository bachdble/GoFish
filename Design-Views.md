Needs stdio.h

Probably used by the controller initializer
	Get # Players
	Get Player Names
	Get Player Type (computer or person) (probably won't do this now)

Probably used in the play loop
	Show Player State
		Cards, sorted: count and type
		
	Show Game State
		Other Player names (& type, eventually)
			# cards
			books
			card requests from their last turn
				what, who, result
				
	Ask for player action
		options:
			Quit
			Ask for card from <player> (repeated for each oponent)
			
	Show action result (w/ pause? for taking turns since it's played on the same compy)
		"You got n cardType(s)"
			and possibly: "You got another book!"
		or
		"Go Fish!"
