#include <unistd.h> // fork/pipe
#include <stdio.h> // scanf/printf
#include <sys/wait.h> // waitpid

const int SIZE = 1e6; // 1000000

int main(){

	int arr[SIZE];
	for(int i=0; i<SIZE; i++){
		arr[i] = 1;
	}


	int fd[2]; // file descriptor
	pipe(fd);
	int pid = fork();

	int inicio, final;
	if(pid == 0){ // estamos en el hijo
		close(fd[0]);
		inicio = SIZE/2+1;
		final = SIZE-1;
	}
	else{ // estamos en el padre
		close(fd[1]);
		inicio = 0;
		final = SIZE/2;
	}

	int suma = 0;
	for(int i=inicio; i<=final; i++){
		suma += arr[i];
	}

	if(pid == 0){ // hijo
		write(fd[1], &suma, sizeof(int));
	}
	else{ // padre
		waitpid(pid, NULL, 0); // esperamos que el hijo termine
		int suma_hijo;
		read(fd[0], &suma_hijo, sizeof(int));
		int suma_total = suma+suma_hijo;
		printf("La suma total es: %d\n", suma_total);
	}

	return 0;
}
