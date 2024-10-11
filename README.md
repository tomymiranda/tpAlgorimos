# tpAlgorimos
# Centros de Investigación

La información sobre los centros de investigación estará almacenada en un archivo de texto llamado `centros.txt`, que deberá ser leído al iniciar la aplicación.  
En cada línea del archivo estará la información de un centro de investigación, separada por espacios:

- **código**: tres letras que identifican a cada centro,
- **nombre del centro**,
- **ciudad y país** donde se encuentra,
- **superficie** del centro en kilómetros cuadrados (número flotante),
- **#laboratorios**: cantidad de laboratorios con los que cuenta,
- **#proyectos_nacionales**: cantidad de proyectos nacionales que maneja,
- **#proyectos_internacionales**: cantidad de proyectos internacionales que maneja.

### Ejemplo de archivo `centros.txt`:

CSI Centro Científico de Innovación España 12.5 15 23 12
LAT Laboratorio Avanzado de Tecnología Brasil 8.7 8 12 18
CTA Centro de Tecnología Aplicada Argentina 6.2 10 20 8


## Menú de Opciones

La aplicación deberá mostrar un menú que permita al usuario realizar las siguientes acciones:

- Consultar por un centro de investigación en particular.
- Agregar un nuevo centro de investigación.
- Eliminar un centro de investigación.
- Mostrar todos los centros de investigación (ordenados por cualquiera de los atributos: nombre, país, superficie, etc.).

### Consideraciones:

- El archivo estará bien formado.
- La implementación deberá usar una tabla de hashing para almacenar y gestionar los centros de investigación.
- Se debe diseñar una función de hashing que asegure una buena dispersión de los datos.

# Proyectos Científicos

A partir de la lectura de un archivo de texto llamado `proyectos.txt`, que deberá realizarse inmediatamente después de la lectura del archivo `centros.txt`, se generará un grafo dirigido pesado que representa las colaboraciones entre distintos centros.

Cada línea del archivo `proyectos.txt` contendrá la información de un proyecto de colaboración entre dos centros, con los siguientes datos:

- **Código del centro de origen**,
- **Código del centro de destino**,
- **Costo del proyecto** (en miles de pesos),
- **Duración del proyecto** (en meses, número flotante).

### Ejemplo de archivo `proyectos.txt`:

CSI LAT 3500 12.5
LAT CTA 1200 8.7
CSI CTA 2800 10.0


## Funcionalidad de Búsqueda de Colaboración

La aplicación debe permitir al usuario ingresar los códigos de dos centros de investigación (centro de origen y centro de destino), y realizar las siguientes acciones:

1. Buscar la colaboración más económica (basado en el costo del proyecto).
2. Buscar la colaboración más rápida (basado en la duración del proyecto).

La aplicación debe mostrar el detalle del proyecto seleccionado, incluyendo el costo de cada tramo (si la búsqueda se basó en costos) o la duración (si la búsqueda se basó en tiempos), y el total del costo o duración de la colaboración completa.  
Si existen múltiples combinaciones óptimas, deberán mostrarse todas.  
Si no hay conexiones posibles, se deberá informar al usuario.
