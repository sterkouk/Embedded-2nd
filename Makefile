#Simple make file
#compile and run the timer for tests
#Then use the cross_compil_file.h
#to cross compile the file

CC=gcc
OUT=executable


make:
	  clear
		$(CC) zsun_timer.c -o $(OUT)

12_samples:
		clear
		$(CC) zsun_timer.c -o $(OUT)
		./$(OUT) 12 24 65   #get 12 samples in total time 24 seconds ->one sample each 2 seconds


120_samples:
				clear
				$(CC) zsun_timer.c -o $(OUT)
				./$(OUT) 120 240 65

clear:
	 	 rm -r *.txt

run:
	./$(OUT) 10 1
