#Compila y ejecuta el archivo Ondas.c
compilerun : Ondas.c
	cc Ondas.c -o Ondas.x
	./Ondas.x
clean : 
	rm -f *.x
	
	
	
	
