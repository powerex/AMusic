cmake_minimum_required(VERSION 3.7)
project(AMusic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp source/Date.cpp header/Date.h source/Human.cpp header/Human.h header/Musician.h source/Performer.cpp header/Performer.h source/Quartet.cpp header/Quartet.h source/Music.cpp header/Music.h source/Performance.cpp header/Performance.h source/MusicLibrary.cpp header/MusicLibrary.h source/IndexOfBoundException.cpp header/IndexOfBoundException.h header/Generator.h source/Generator.cpp header/UnknowReadData.h)
add_executable(AMusic ${SOURCE_FILES} source/Date.cpp header/Date.h source/Human.cpp header/Human.h header/Musician.h source/Performer.cpp header/Performer.h source/Quartet.cpp header/Quartet.h source/Music.cpp header/Music.h source/Performance.cpp header/Performance.h source/MusicLibrary.cpp header/MusicLibrary.h header/Generator.h source/Generator.cpp header/UnknowReadData.h)