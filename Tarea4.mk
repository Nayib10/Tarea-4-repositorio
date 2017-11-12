#Compila y ejecuta el archivo Ondas.c
.PHONY : compilerun
compilerun : Ondas.c
	cc Ondas.c -o Ondas.x
	./Ondas.x
.PHONY : clean
#grafica los resultados
graficar: 
	python plots.py
#borra archivos
clean :
	rm -f Ondas.x
