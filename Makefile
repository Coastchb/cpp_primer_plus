myFirst.o: myFirst.cpp
	g++ -c myFirst.cpp
	@echo 'ok'
	echo 'haha'

.PHONY: clean

clean:
	@rm -rf myFirst.o myFirst