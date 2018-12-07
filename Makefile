run: sesc-postfix
	./sesc-postfix
	
sesc-postfix: sesc-postfix.c
	gcc -Wall -std=c11 sesc-postfix.c -o sesc-postfix postfix.c

build: sesc-postfix