# in EC327, we use the g++ compiler
# therefore, we define the GCC variable
GCC = g++ -std=c++11
# a target to compile the Checkpoint2 which depends on all object-files
# and which links all object-files into an executable
PA3: main.o Building.o PokemonCenter.o PokemonGym.o Point2D.o Vector2D.o GameObject.o Trainer.o main.o Model.o View.o GameCommand.o WildPokemon.o
	$(GCC) main.o Building.o PokemonCenter.o PokemonGym.o Point2D.o Vector2D.o GameObject.o Trainer.o GameCommand.o Model.o View.o WildPokemon.o -o PA3
# a target to compile the TestCheckpoint1.cpp into an object-file
main.o: main.cpp
	$(GCC) -c main.cpp
# a target to compile the Trainer.cpp into an object-file
Trainer.o: Trainer.cpp
# a target to compile the Point2D.cpp into an object-file
Building.o: Building.cpp
	$(GCC) -c Building.cpp
# a target to compile the Vector2D.cpp into an object-file
PokemoneCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp
PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp
# a target to compile the Point2D.cpp into an object-file
Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp
# a target to compile the Vector2D.cpp into an object-file
Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp
GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp
GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp
Model.o: Model.cpp
	$(GCC) -c Model.cpp
View.o: View.cpp
	$(GCC) -c View.cpp
# a target to delete all object-files and executables
WildPokemon.o: WildPokemon.cpp
	$(GCC) -c WildPokemon.cpp
clean:
	rm main.o Building.o PokemonCenter.o PokemonGym.o PA3 Point2D.o Vector2D.o GameObject.o View.o Model.o Trainer.o GameCommand.o WildPokemon.o