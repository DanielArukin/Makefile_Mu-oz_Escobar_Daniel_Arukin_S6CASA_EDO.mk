resultados.pdf : resultados.tex plots_muñoz_escobar_daniel_arukin_s6c2_edo.pdf plots_muñoz_escobar_daniel_arukin_s6casa_edo2.pdf

plots_muñoz_escobar_daniel_arukin_s6c2_edo.pdf : metodo_de_euler.dat metodo_de_Runge-Kutta_de_4to.dat plots_muñoz_escobar_daniel_arukin_s6c2_edo.py
	python3 plots_muñoz_escobar_daniel_arukin_s6c2_edo.py

plots_muñoz_escobar_daniel_arukin_s6casa_edo2.pdf : metod_de_euler_EDO2orden.dat metodo_de_LeapFrog_EDO2orden.dat plots_muñoz_escobar_daniel_arukin_s6casa_edo2.py
	python3 plots_muñoz_escobar_daniel_arukin_s6casa_edo2.py

metodo_de_euler.dat : Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO.cpp
	./a.out>>metodo_de_euler.dat

metodo_de_Runge-Kutta_de_4to.dat : Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO.cpp
	./a.out>>metodo_de_Runge-Kutta_de_4to.dat

metod_de_euler_EDO2orden.dat : Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO2orden.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO2orden.cpp
	./a.out>>metod_de_euler_EDO2orden.dat

metodo_de_LeapFrog_EDO2orden.dat : Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO2orden.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S6CASA_EDO2orden.cpp
	./a.out>>metodo_de_LeapFrog_EDO2orden.dat
