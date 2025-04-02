# 2D Survivor

The aim is to create a small 3D game without the use of a game Engine. The game was  developed using C++.

The game includes
* A virtual camera that follows the player-controlled (hero) character at its centre 
* A number of NPCs that attack the character 
  * Generated randomly outside of camera view 
  * Their frequency increases over time
  * At least 4 different character types that differ in appearance, health and speed
* General NPC behaviour that directs them directly towards the player
  * One NPC behaviour makes it static but launches projectiles (4 Marks)
* Collision system
  * Hero vs NPCs (3 Marks)
  * Hero vs impassable terrain
  * Hero projectiles vs NPCs
  * NPC projectiles vs Hero
* The hero attacks the NPCs with at least two different types of attack (12 Marks)
  * A linear attack that targets closest NPC (has cooldown) – the attack runs automatically all the time
  * A special area of effect (AOE) attack that targets the top N max health NPC – triggerred by hero via separate button
  * A powerup that increases either the speed of the linear attack and number N of NPCs targetted by the AOE (2 Marks)
* A tile-based method (composed of a number of 32x32 pixel tiles) for displaying the background (16 Marks)
  * At least four different tile types (ie terrain types). One of which is impassable (eg water) for the hero. NPCs can traverse.  (5 Marks)
  * Data driven level loading, i.e. load the game world’s tiles and map from a custom file format (5 Marks) 
  * A version of the world which is infinite (with repeating tiles) (3 Marks)
  * A version with a fixed boundary (larger than what the screen displays) (3 Marks)

  * Score and FPS shown at the end (or during) (2 Marks)
* The ability to save the current state of the game 
This is the gameplay




https://github.com/user-attachments/assets/0f04bb2e-b645-4668-afe0-8427ed56e975

