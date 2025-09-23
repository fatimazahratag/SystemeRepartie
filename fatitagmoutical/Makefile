# Parameters
CLIENT = calcul_client
SERVER = calcul_server

# Source files for the client and server
SOURCES_CLNT.c = calcul_client.c
SOURCES_CLNT.h = calcul.h
SOURCES_SVC.c = calcul_server.c
SOURCES_SVC.h = calcul.h
SOURCES.x = calcul.x

# Generated targets (client and server code)
TARGETS = calcul.h calcul_clnt.c calcul_svc.c calcul_client.c calcul_server.c

# Objects for client and server
OBJECTS_CLNT = $(SOURCES_CLNT.c:%.c=%.o) $(TARGETS_CLNT.c:%.c=%.o)
OBJECTS_SVC = $(SOURCES_SVC.c:%.c=%.o) $(TARGETS_SVC.c:%.c=%.o)

# Compiler flags
CFLAGS += -I/usr/include/tirpc
LDLIBS += -lnsl
RPCGENFLAGS =

# Targets
all: $(CLIENT) $(SERVER)

# Generate the necessary files using rpcgen
$(TARGETS): $(SOURCES.x)
	rpcgen $(RPCGENFLAGS) $(SOURCES.x)

# Compile the client object files
$(OBJECTS_CLNT): $(SOURCES_CLNT.c) $(SOURCES_CLNT.h) $(TARGETS_CLNT.c)

# Compile the server object files
$(OBJECTS_SVC): $(SOURCES_SVC.c) $(SOURCES_SVC.h) $(TARGETS_SVC.c)

# Link the client executable
$(CLIENT): $(OBJECTS_CLNT)
	$(CC) -o $(CLIENT) $(OBJECTS_CLNT) $(LDLIBS)

# Link the server executable
$(SERVER): $(OBJECTS_SVC)
	$(CC) -o $(SERVER) $(OBJECTS_SVC) $(LDLIBS)

# Clean up generated files
clean:
	$(RM) core $(TARGETS) $(OBJECTS_CLNT) $(OBJECTS_SVC) $(CLIENT) $(SERVER)
