#g++ -std=c++11 -m64 -g -o sildeco sildeco.cpp -I/home/ga49zos/tools/opt/gurobi800/linux64/include/ -L/home/ga49zos/tools/opt/gurobi800/linux64/lib/ -lgurobi_g++5.2 -lgurobi80 -lpthread -lm
#export GUROBI_HOME="/nas/ei/home/ge75yof/tools/opt/gurobi811/linux64"
#export PATH="${PATH}:${GUROBI_HOME}/bin"
#export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${GUROBI_HOME}/lib"
#export LD_LIBRARY_PATH="${GUROBI_HOME}/lib"
#export GRB_LICENSE_FILE=/nas/ei/home/ge75yof/gurobi_"$HOSTNAME".lic

g++ -std=c++11 -m64 -g -o main_nt main_nt.cpp -I /home/ge75yof/tools/opt/gurobi811/linux64/include/ -L /home/ge75yof/tools/opt/gurobi811/linux64/lib/ -lgurobi_g++5.2 -lgurobi81 -lpthread -lm -lgsl -lgslcblas

if [ "$1" == "0" ]; then
	echo "
		Case: 2-Comb
		"
	time ./main_nt ExtractedInfo/output20190325/201903251056/190325EDAIDESFORTMT/objects.txt ExtractedInfo/output20190325/201903251056/190325EDAIDESFORTMT/conflict.txt 20 90000 10 Result/0325-2-comb Sub_op_sol/0325-2-comb
elif [ "$1" == "1" ]; then
	echo "
		Case: 0326-1
		"
	time ./main_nt ExtractedInfo/output20190326/260319/20190326_1/190326EDALAPLACE1/objects.txt ExtractedInfo/output20190326/260319/20190326_1/190326EDALAPLACE1/conflict.txt 3 3600 5 Result/0326-1 Sub_op_sol/0326-1
elif [ "$1" == "2" ]; then
	echo "
		Case: 0326-2
		"
	time ./main_nt ExtractedInfo/output20190326/260319/20190326_2/190326EDALAPLACE2/objects.txt ExtractedInfo/output20190326/260319/20190326_2/190326EDALAPLACE2/conflict.txt 18 3600 10 Result/0326-2 Sub_op_sol/0326-2
elif [ "$1" == "3" ]; then
	echo "
		Case: 0326-3
		"
	time ./main_nt ExtractedInfo/output20190326/260319/20190326_3/190326EDALAPLACE3/objects.txt ExtractedInfo/output20190326/260319/20190326_3/190326EDALAPLACE3/conflict.txt 12 3600 10 Result/0326-3 Sub_op_sol/0326-3
elif [ "$1" == "4" ]; then
	echo "
		Case: 0326-4
		"
	time ./main_nt ExtractedInfo/output20190326/260319/20190326_4/190326EDALAPLACE4/objects.txt ExtractedInfo/output20190326/260319/20190326_4/190326EDALAPLACE4/conflict.txt 16 3600 10 Result/0326-4 Sub_op-sol/0326-4
elif [ "$1" == "5" ]; then
	echo "
		Case: 0326-5
		"
	time ./main_nt ExtractedInfo/output20190326/260319/20190326_5/190326EDALAPLACE5/objects.txt ExtractedInfo/output20190326/260319/20190326_5/190326EDALAPLACE5/conflict.txt 3 3600 10 Result/0326-5 Sub_op_sol/0326-5
else
	echo "NON-supported case!!!!!"
fi
# example:
# $1 (input, obj path): 	../ExtractedInfo/output0418/layer1/objects.txt
# $2 (input, obj conflict: 	../ExtractedInfo/output0418/layer1/conflict.txt
# $3 (time threshold): 		30
# $4 (output common name):	../Result/layer1

