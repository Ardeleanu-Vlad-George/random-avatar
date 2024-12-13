TRG := avagen

OBJ := obj/main.o

$(TRG): $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system

$(OBJ): obj/%.o : src/%.cpp
	g++ -c -o $@ $^ -I inc/

clean:
	rm $(OBJ) $(TRG)
