OBJECTS = autocomplete.o SortingList.o term.o CS216PA3.o
HEADERS = autocomplete.h SortingList.h term.h
CS216PA3: $(OBJECTS)
	g++ -o CS216PA3 $(OBJECTS)
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f $(OBJECTS) CS216PA3
