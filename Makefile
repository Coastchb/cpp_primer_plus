subdirs = ch_5

myFirst.o: myFirst.cpp
	g++ -c myFirst.cpp # show and execute
	@echo 'the command only to execute'
	echo 'the command to show and execute'

	@echo "make level:" ${MAKELEVEL}
	make -w -C ch_5/






.PHONY: clean

clean:
	@echo "make level:" ${MAKELEVEL}
	@rm -rf myFirst.o myFirst
	make -w -C ch_5/ clean


