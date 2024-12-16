TRG := avagen

OBJ := obj/main.o obj/io.o obj/comp.o obj/img_comp.o

$(TRG): $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system

$(OBJ): obj/%.o : src/%.cpp
	g++ -g -c -o $@ $^ -I inc/

clean:
	rm $(OBJ) $(TRG)
