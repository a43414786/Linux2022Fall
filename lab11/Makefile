all: client server thread

.PHONY = clean client server

client: client.c
	gcc $< -o $@
server: server.c
	gcc $< -o $@
thread: thread.c
	gcc $< -lpthread -o $@


clean:
	rm client server