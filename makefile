bin: IS.c
	gcc $< -o $@
,PHONY: run class

run:
	./bin
clean:
	rm bin


q


