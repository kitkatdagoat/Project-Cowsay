all: newcow readingcow tamagoshi_cow wildcow

newcow: new_cowbis.c
	clang -Wall -Werror -Wno-unused -g -DDEBUG -o newcow new_cowbis.c

readingcow: reading_cow.c
	clang -Wall -Werror -Wno-unused -g -DDEBUG -o readingcow reading_cow.c

tamagoshi_cow: Tamagoshi-vache.c
	clang -Wall -Werror -Wno-unused -g -DDEBUG -o tamagoshi_cow Tamagoshi-vache.c

wildcow: wildcow.c
	clang -Wall -Werror -Wno-unused -g -DDEBUG -o wildcow wildcow.c

# clean:
# 	rm -f newcow readingcow tamagoshi_cow wildcow
