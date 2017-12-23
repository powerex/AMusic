cmake_minimum_required(VERSION 3.7)
project(AMusic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Date.cpp Date.h Human.cpp Human.h Musician.h Performer.cpp Performer.h Quartet.cpp Quartet.h Music.cpp Music.h Performance.cpp Performance.h MusicLibrary.cpp MusicLibrary.h IndexOfBoundException.cpp IndexOfBoundException.h Generator.h Generator.cpp)
add_executable(AMusic ${SOURCE_FILES} Date.cpp Date.h Human.cpp Human.h Musician.h Performer.cpp Performer.h Quartet.cpp Quartet.h Music.cpp Music.h Performance.cpp Performance.h MusicLibrary.cpp MusicLibrary.h Generator.h Generator.cpp)