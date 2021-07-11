all: System

System: admin.h admin.cpp user.h user.cpp Employee.h Employee.cpp main.cpp
	g++ -o System main.cpp admin.cpp user.cpp Employee.cpp

clean:
	rm -f System
