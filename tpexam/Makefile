# Compiler and flags
CC = gcc
CFLAGS = -I/usr/include/tirpc
LDFLAGS = -lnsl -ltirpc

# Source files
SOURCES = contact_svc.c contact_xdr.c
OBJECTS = $(SOURCES:.c=.o)
CLIENT_SOURCES = contact_client.c contact_clnt.c contact_xdr.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

# Generate source files from RPC definition
contact_svc.c contact_xdr.c contact.h contact_clnt.c: contact.x
	rpcgen contact.x

# Compile the server
server: $(OBJECTS)
	$(CC) -o server $(OBJECTS) $(LDFLAGS)

# Compile the client
client: $(CLIENT_OBJECTS)
	$(CC) -o client $(CLIENT_OBJECTS) $(LDFLAGS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up
clean:
	rm -f *.o server client
