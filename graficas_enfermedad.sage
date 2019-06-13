f(x,confiabilidad) = (x/100)*confiabilidad/((x/100)*confiabilidad + (1-x/100)*(1-confiabilidad))

var('y')
colores = ["red", "blue", "green", "magenta", "orange", "black", "purple"]
porcentajesX = [0.01, 0.1, 1,10,20,50,100]

def nice_string(x):
    s = list(str(x))
    while len(s) > 0 and '.' in s and s[-1] == '0':
        s.pop()
    return "".join(s)

P = sum([plot(
              f(x,y/100),y,0,100,
              #ymin=0,ymax=1,
              color=colores[i], legend_color=colores[i], 
              legend_label="Porcentaje que padece X: " + nice_string(x) + "%"
            )
            for i,x in enumerate(porcentajesX)
        ]
    )

P.show(dpi=300,frame=True,
       axes_labels=("Confiabilidad de la prueba","Probabilidad de tener X con prueba positiva"), 
       fontsize=11, 
       show_legend=True,
       axes_labels_size=1.,
       legend_loc=(0.05,0.7),
       legend_fancybox=False,
       legend_font_size='small',
       axes=False)

P.save("grafica_enfermedad.png",
       dpi=300,frame=True,
       axes_labels=("Confiabilidad de la prueba","Probabilidad de tener X con prueba positiva"), 
       fontsize=11, 
       show_legend=True,
       axes_labels_size=1.,
       legend_loc=(0.05,0.7),
       legend_fancybox=False,
       legend_font_size='small',
       axes=False)
