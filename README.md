The program asks you to create a Battleship of parameters of your choosing, but they most abide to the range. After you 
create your battleship, you fight until your ship is destroyed. It counts how many computer vessels you have fought. The 
computer vessels are always of default values, currently. The program then asks if you want to move after a fight. 
Currently, all computers exist at X,Y (0, 0) and range is not yet implemented so this is largely aesthetic. However, 
for future projects the eventual goal is have the user and computer move around and fire in turn based ways. As such, 
the unrelated Board already existing with movement functions is good. Destroyers are another class of ship so adding them and 
torpedoes (traditionally destroyers carry these and Battleships do not) will make "gameplay" more interesting and dynamic.
Naturally, it made sense to make the torpedoes a component class of the Destroyer and the Destroyer a subclass of the Battleship.