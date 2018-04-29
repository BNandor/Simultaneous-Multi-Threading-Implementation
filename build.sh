if [ ! $# -eq 1 ]
then 
	echo 'usage:'$0' source.cpp'
	exit 1
fi
g++ $1 PARALLEL.h -std=c++11 -lpthread 
