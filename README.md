# COMP315
COMP315 2015 Group Project

This is the COMP 315 : Advanced Programming project for Group 14.

This project is built using C++ and openGL by means of GLUT / FreeGLUT.

This project is cross platform and will be compiled for Windows, OSX, and Linux and hence is made using common libraries. 

This Project is the intelectual property of the colaborators and of the University of Kwa-Zulu Natal.

Happy Coding. 


Here follows our project specification: 

1) Project theme:

Space-based asteroid shooter/Base defense/tower defense. The player is a spaceship looking to defend their home planet (the NPC) from a neverending cluster of asteroids that is approaching the planet. The asteroids approach in waves, steadily increasing in number and size until the player eventually loses. The player can shoot down the asteroids using their weapon, which can have a number of effects - large asteroids break down into 2 medium sized asteroids, medium into 2 small ones, and small are destroyed by the players weapon. The player must shoot all the asteroids down before they reach the base, whilst avoiding crashing into them. If the player crashes into the asteroids, they take damage. After taking enough damage, the player dies and the game ends. The same applies to the base. After taking enough damage, the base can "explode" and the player loses the game. After about twenty waves, the player wins.  



2) Player
2.1) Basic actions list:

Listed below are the possible actions that can be taken by the player:

'w' - throttle up
's' - throttle down
'a' - strafe left
'd' - strafe right
'LMB' - shoot

mouse movements will be used to alter the players view of the world. 
 
2.2) advanced actions list
'q' - spin view counterclockwise (optional)
'e' - spin view clockwise (optional)
'esc' - pause game bring up menu
'Shift' - strafe "up"
'Ctrl'- strafe "down"

Additional movements to be added later as needed. Potentially add multiple action listeners to track pressed keys



3)NPC &or dynamic aspects of world 
3.1) Basic NPC behaviour and state (single entity)
THE BASE
the base remains relatively stationary, possibly with a very slow rotate function. Beyond that, the base only has a health value. The base is at full health in its initial state and health will decrease if the player allows an asteroid to collide with it. The base reaching 0 health is considered a failure state.

THE ASTEROIDS
The asteroids are dynamically spawned NPCs. They will spawn from the edges of the world space and increase in number over time. They apporach the base from a single direction, heading for an approximate area of the base. they move at a constant speed, and are unaffected by any external force. They exist states of varying size and asteroid splitting will be triggered by the player sucessfully shooting them.

3.2) list any extensions
Momentum changes with collisions. Explosive asteroid splitting. Varying asteroid trajection affected by the home planet's 'gravity'. Visual changes of state as the base decreases in health. Additional npc enemy and friendly ships. 



4) World environment
4.1) Basic world environment
The basic world environment is relatively empty, however we can map a texture onto a large background to mirror space. 
The game space during the testing phase will consist of the spherical base and radially incoming asteroids.

4.2) Additional lighting, materials and effects
A single point light could be implemented to simulate a primary star in the "planetary system". 
Additional textures could be used for the background asteroids, and ship. 
Lighting effects and textures(texture changes?) could be added to simulate explosions triggered by certain types of collisions. Extra lighting and texture effects could be added to weapons and weapon fire, and the asteroids (eg. a trail effect). 
Additional artefacts could be added to the base for aesthetics.
Throttle effects.


5)List 2-3 possible major extensions

-Possible implementation of multiplayer within the confines of the game. 
-Extending available character weapons - secondary weapons, special one use weapons etc
-Gaussian sphere to change vector heading when approaching planet
-Healing effect on ship via some game mechanic
-explosion effect (opacity decrease as sphere increases, until sphere reaches 0 opacity, after which it can be removed)
-add "pew pew" noises to game shooting
-additional movement graphics (invisible movementat the moment)

