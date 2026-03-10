lab1:	lab1.c
	gcc -o lab1 lab1.c
	./lab1

lab2:	lab2.c
	gcc -o lab2 lab2.c
	./lab2

lab3:	lab3.c
	gcc -o lab3 lab3.c
	./lab3

lab4:	lab4.c
	gcc -o lab4 lab4.c
	./lab4

lab5:	lab5.c
	gcc -o lab5 lab5.c
	./lab5

lab6:	lab6.c
	gcc -o lab6 lab6.c
	./lab6 schedules.txt

lab7:	lab7.c
	gcc -o lab7 lab7.c
	./lab7 schedules.txt

lab8:	lab8.c
	gcc -o lab8 lab8.c
	./lab8 schedules.txt

pi_serial:	pi_serial.c
	gcc -o pi_serial pi_serial.c -lm
	./pi_serial 1

pi_mutex:	pi_mutex.c
	gcc -o pi_mutex pi_mutex.c -lm
	./pi_mutex 1

pi_semaphore:	pi_semaphore.c
	gcc -o pi_semaphore pi_semaphore.c -lm
	./pi_semaphore 1
# The clean command has been added by TA
clean:
	rm -f lab8
