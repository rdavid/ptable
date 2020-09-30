DEPS="main.o"
redo-ifchange $DEPS
g++ -o $3 $DEPS
