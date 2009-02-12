PROGRAM=parbat

PROGRAM_SOURCES = Parbat.cpp \
		  OverviewWindow.cpp \
		  AboutDialog.cpp

PROGRAM_OBJECTS = $(patsubst %.cpp, %.o, ${PROGRAM_SOURCES})

PKG_CONFIG_MODULES=gtkmm-2.4 libglademm-2.4

CXX=g++
CXX_FLAGS=-g -Wall
CXX_FLAGS+=`pkg-config ${PKG_CONFIG_MODULES} --cflags` `gdal-config --cflags`
LD_FLAGS=-g -Wall `pkg-config ${PKG_CONFIG_MODULES} --libs` `gdal-config --libs`

all: .check_makefile ${PROGRAM}

.check_makefile: Makefile
	@echo "Makefile has changed, forcing re-build"
	@make clean
	@touch ${@}

${PROGRAM}: ${PROGRAM_OBJECTS}
	${CXX} -o ${PROGRAM} ${PROGRAM_OBJECTS} ${LD_FLAGS}

PchApp.h.gch: PchApp.h
	${CXX} -c ${CXX_FLAGS} -o ${@} ${<}

%.o: %.cpp %.h PchApp.h.gch
	${CXX} -c ${CXX_FLAGS} -o ${@} ${<}

clean:
	@rm -f -v *.o

distclean: clean
	@rm -f -v PchApp.h.gch
	@rm -f -v ${PROGRAM}
	@rm -f -v *~
	@rm -f -v \#\*\#
