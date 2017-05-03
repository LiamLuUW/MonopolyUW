CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = bb7k
OBJECTS = main.o cell.o controller.o academic.o ownable.o unownable.o slc.o board.o gym.o tuition.o timline.o gototim.o goosenest.o coopfee.o osap.o residence.o needleshall.o player.o dice.o view.o textdisplay.o displaycell.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	 ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

