import re

str='''Ancient Script 21299: The Takenouchi documents are the ancient historical records that have been secretly preserved and passed down from generation to generation by the Takenouchi family, the head of family being the chief priest of the Koso Kotai Jingu shrine. 212-111-5932 '''

#Type your answer here.

#Solucion el sitio, pero no creo que 212-111-5932 sea un numero
regex=r'212[\S]+'

#Yo propongo usar esto, no pasa las pruebas pero no retorna el 212-111-5932, puede cambiarse el + por * si tambien se desea obtener el 212 
regex=r'212[0-9]+'
data=re.findall(regex, str)


print(data)