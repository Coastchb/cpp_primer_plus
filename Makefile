myFirst.o: myFirst.cpp
	g++ -c myFirst.cpp # show and execute
	@echo 'the command only to execute'
	echo 'the command to show and execute'

.PHONY: clean

clean:
	@rm -rf myFirst.o myFirst
