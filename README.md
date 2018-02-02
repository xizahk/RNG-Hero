Game Title: RNG Hero  
Goal: Reach x round

Classes:  
Player  
A player has combat stats: HP and Atk and non-combat stat: gold. 
Player starts with 100 HP, 10 Atk, and 0 Gold by default.

Game  
A game handles the completion of rounds and processing of events. It is initialized with a Player and target round as parameter. 
  - Game starts with the function call start()

Mechanics:  
Round  
The player starts on round 1 and each round is represented by the roll of an imaginary dice
  - Next round is triggered by completion of random event

Events  
RNG has ⅓ chance of rolling a fight encounter, a shop encounter, or an event encounter
  - Fight encounter - Player fights an enemy
    - Monster HP, Atk, and Gold calculated based on round number
      - HP = Round# * 2
      - Atk = Round# / 4
      - Gold = Round# * 5
    - Player has two choices:
      - “Fight”: Fight monster - reduce Player HP by Enemy Atk and Enemy HP by Player Atk. Successfully defeating the enemy increases Player gold by amount of gold carried by the enemy.
      - “Flee”: Probability of success = min(1, Player.Atk / Enemy.HP). Successfully fleeing ends enemy encounter without gaining gold from monster.
  - Shop encounter - Player visits a shop and can purchase stat upgrades
    - 10 gold cost for +1 of either (“HP” or “ATK”)
      - Player is prompted to enter an integer input for each stat (HP and ATK) which indicates the number of each stat to purchase
  - Event encounter - Player is given the opportunity to choose whether whether to roll the RNG of luck
    - Choosing “yes” rolls a dice (from 0 to 1) where > .5 means +1 stat to the player’s HP and Atk and < .5 means -1 stat to the player’s HP and Atk
      - Player Atk cannot be reduced to < 1
    - Choosing “no” ends the round

End game conditions:  
The game is over when
  1) The Player has <= 0 HP. OR
  2) When the player reaches the target round.
