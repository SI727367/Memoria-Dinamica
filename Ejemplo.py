color1 = None
color2 = None

def pideColores():
	global color1
	global color2

	color1 = input("Ingresa el primer color\n	~>")
	color2 = input("Ingresa el segundo color\n	~>")

def mezclacolores():
	
	global color1
	global color2

	if color1 == "rojo":
		if color2 == "azul":
			print("purpura")
		elif color2 == "amarillo":
			print("anaranjado")
		else:
			print("No es color primario")
	elif color1 == "azul":
			if color2 == "rojo":
				print("purpura")
			elif color2 == "amarillo":
				print("verde")
			else:
				print("No es color primario")
	elif color1 == "amarillo":
			if color2 == "rojo":
				print("anaranjado")
			elif color2 == "azul":
				print("verde")
			else:
				print("No es color primario")
	else:
		print("No es color primario")
	


pideColores()
mezclacolores()